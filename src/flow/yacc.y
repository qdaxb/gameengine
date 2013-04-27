
%{
#include <math.h>
#include <malloc.h>  // _alloca is used by the parser
#include <string.h>  // strcpy
#include <tchar.h>
#include "Utils.h"
#include "GameData.h"  //gamedata
#include "datacontroller.h"
#include "lex.h"       // the lexer
void yyerror (char *msg);
DataController* dataController;
GameData expData;
%}

%union {
      float     num;
      char*		str;
      GameData*  data;
}

%token <num> NUM      /*������*/
%token AND		/*�߼���*/
%token OR		/*�߼���*/
%token NOT		/*�߼���*/
%token EQUAL	/*�߼����*/
%token OPEN_PAR CLOSE_PAR	/*����*/
%token ASSIGN	/*��ֵ*/
%token <str>  STR
%token <str> VAR LVAR ARG
%token DOT
%token ADD
%token SUB
%token DIV
%token MUL
%token ERROR_TOKEN
%token POW
%token MORE
%token LESS
%type <data> exp
//%type <tnode>  equal_expression 
%type <data> assign_expression
%type <str> var;
%left ASSIGN
%left MORE LESS EQUAL
%left SUB ADD DOT   /*����+,-����Ϊ����*/
%left MUL DIV   /*Խ�������ȼ�Խ��*/
%left NEG       /*���ڸ����������ͬ,��������һ������ע��,������˵��*/
%right POW      /*������Ϊ�ҽ��*/
%right NOT
%%
input:          /*��������ǿմ�,��ʹ������һ��ʼ�ͽ��յ�EOF�����ڷ�������*/
        | exp  {expData.SetValue(*$1);} /*Ҳ������һ��*/
        |assign_expression
;

exp:      NUM                { $$ =new GameData();$$->SetValue($1);         }
		| var				 { $$ =new GameData(*(dataController->GetData(ASCIItoUNICODE($1))));	}
                /*���ʽ���Խ�Ϊһ������,��ʱ��ֵ���������ֵΪ������*/
        | exp ADD exp        { $$ =new GameData(*$1 + *$3);free($1);free($3);    }
                /*���ʽ����Ϊһ�����ʽ������һ��,��Ӧ������ֵҲ���,��ͬ*/
        | exp SUB exp        { $$ =new GameData();$$->SetValue(*$1 - *$3);free($1);free($3);    }
        | exp MUL exp        { $$ = new GameData();$$->SetValue($1->toFloat() * $3->toFloat());free($1);free($3);    }
        | exp DIV exp        { $$ =new GameData();$$->SetValue($1->toFloat() / $3->toFloat());free($1);free($3);    }
        | SUB exp  %prec NEG { $$ = new GameData();$$->SetValue(-*$2);free($2);        }
                /*���������﷨�ṹ���������ȼ���NEG��ͬ*/
        /*| exp POW exp        { $$ = pow ($1, $3); }*/
        | OPEN_PAR exp CLOSE_PAR        { $$ = new GameData(*$2);free($2);         }
		| exp EQUAL exp		{ $$=new GameData();$$->SetValue($1->compareTo(*$3)==0?1:0);free($1);free($3);	}
		| NOT exp			{ $$=new GameData();$$->SetValue($2->toInt()==1?0:1);free($2);	}
		| exp MORE exp		{ $$=new GameData();$$->SetValue($1->compareTo(*$3)==1?1:0);free($1);free($3);	}
		| exp LESS exp		{ $$=new GameData();$$->SetValue($1->compareTo(*$3)==-1?1:0);free($1);free($3);	}
		| STR				{$$=new GameData();$$->SetValue(ASCIItoUNICODE($1));delete[] $1;			}

;
var:	 VAR 				{$$=$1;}
		|LVAR				{$$=$1;}
		|ARG				{
								GameData* d=(GameData*)dataController->GetVariable(ASCIItoUNICODE($1));
								$$=UNICODEtoASCII(d->toString());
							}
		| var DOT var	{
								$$=new char[strlen($1)+strlen($3)+2];
								strcpy($$,$1);
								strcat($$,".");
								strcat($$,$3);
						}
		|VAR  ARG		{
								$$=new char[strlen($1)+strlen($2)+2];
								strcpy($$,$1);
								GameData* d=(GameData*)dataController->GetVariable(ASCIItoUNICODE($2));
								strcat($$,UNICODEtoASCII(d->toString()));
							}
;
assign_expression
	: var ASSIGN exp	 { 
						
							if($1[0]=='#')
							{
							$1++;
							((GameData*)dataController->GetVariable(ASCIItoUNICODE($1)))->SetValue(*$3); 
							}
							else
							dataController->GetData(ASCIItoUNICODE($1))->SetValue(*$3); 
						}

;

%%
