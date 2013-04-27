%{

#ifdef MSVC
#define  isatty _isatty  // for some reason isatty is called _isatty in VC..
#endif


#define  _LEX_CPP_   // make sure our variables get created
#include "lex.h"
#include "yacc.h"
#include <stdlib.h>
#include <string.h> 
extern "C" int yywrap ();
void parsenumber();
void StringConstant();
%}
%%
"{#"[a-zA-Z0-9]+"}" {yylval.str=new char[strlen(yytext)-2];yytext[strlen(yytext)-1]='\0';strcpy (yylval.str, &yytext[2]);return ARG;}
"#"([a-zA-Z0-9]+)+	{   yylval.str = new char[strlen(yytext)+1];   strcpy (yylval.str, yytext);return LVAR;}
[a-zA-Z][a-zA-Z0-9]*	{   yylval.str = new char[strlen(yytext)+1];   strcpy (yylval.str, yytext);return VAR;}
[0-9]+	{parsenumber();return NUM;}
[0-9]+"."([0-9])+	{parsenumber();return NUM;}
"=="	{return EQUAL;}
"="		{return ASSIGN;}
"!"		{return NOT;}
"&&"	{return AND;}
"||"	{return OR;}
\n       {lineno++;}  
"+"		{return ADD;}
"-"		{return SUB;}
"*"		{return MUL;}
"/"		{return DIV;}
"^"		{return POW;}
">"		{return MORE;}
"<"		{return LESS;}
"("		{return OPEN_PAR;}
")"		{return CLOSE_PAR;}
\'[^\"]*\'	{StringConstant ();return STR;}
"."		{return DOT;}
.	{return ERROR_TOKEN;}
%%
void parsenumber(){
	yylval.num=atof(yytext);
}

void StringConstant()  {
   int l = strlen(yytext)-2;
   yylval.str = new char[l+1];
   strncpy (yylval.str, &yytext[1], l); yylval.str[l] = 0;
}