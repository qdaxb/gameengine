#include "StdAfx.h"
#include "GameDebugger.h"
#include <string>

GameDebugger GameDebugger::debugger_instance;

GameDebugger::GameDebugger(void)
{
}

GameDebugger::~GameDebugger(void)
{
}

void GameDebugger::OutPut(std::wstring message)
{
	debugger_instance.m_pdlg->AddMessage(message);
}

void GameDebugger::Init(CgameTestDlg* pdlg)
{
	debugger_instance.m_pdlg=pdlg;
}
