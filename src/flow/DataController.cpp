#include "StdAfx.h"
#include "DataController.h"
#include "OperateAble.h"
#include "lex.h"
#include "Utils.h"
#include "GameDebugger.h"
void yyerror(char *msg) {
	GameDebugger::OutPut(wstring(ASCIItoUNICODE(msg)));
}
extern "C" int yywrap(void) {
	return 1;
}
int yyparse ();
DataController::DataController(OperateAble* oa)
{
	m_oOperateAble=oa;
}

DataController::~DataController(void)
{

}
int DataController::GetInt(std::wstring exp)
{
	void* var=GetVariable(exp);
	if(var!=NULL)
		return *(int*)var;
	return 0;
}
float DataController::GetFloat(std::wstring exp)
{
	void* var=GetVariable(exp);
	if(var!=NULL)
		return *(float*)var;
	return 0;
}
std::wstring DataController::GetString(std::wstring exp)
{
	void* var=GetVariable(exp);
	if(var!=NULL)
		return *(std::wstring*)var;
	return exp;
}
void* DataController::GetVariable(std::wstring exp)
{
	GameData* var;
	IAction* action;
	var=m_oOperateAble->GetExecutingOperate()->GetVariable(exp);
	if(var->getType()!=Empty)
		return var;
	action=m_oOperateAble->GetExecutingOperate()->GetParent();
	do 
	{
		var=action->GetVariable(exp);
		if(var->getType()!=Empty)
			return var;
		action=action->GetParent();
	} while (action!=NULL);


	return NULL;
}

GameData* DataController::GetData( std::wstring exp )
{
	GameData* data=rootData.getValue(exp);
	if(data==NULL)
		rootData.SetValue(0,exp);
	return rootData.getValue(exp);
}


void DataController::RunExp( char* exp )
{
	yy_scan_string(CutBrace(exp));
	yyparse();
}

char* DataController::CutBrace(char* ex)
{
	wstring exp(ASCIItoUNICODE(ex));
	int begin=exp.find_first_of('{');
	int end=exp.find_first_of('}');
	if(begin<0||end<0)
		return ex;
	for(;begin>=0&&end>=0;)
	{
	wstring pad(exp.substr(begin+1,end-begin-1));
	wstring com(((GameData*)GetVariable(pad))->toString());
	exp.replace(begin,end-begin+1,com);
	begin=exp.find_first_of('{');
	end=exp.find_first_of('}');
	}
	
	const wchar_t* tbuffer=exp.c_str();
	char* buffer=UNICODEtoASCII(tbuffer);
	return buffer;
}
