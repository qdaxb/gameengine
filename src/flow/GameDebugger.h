#pragma once
#include "gameTestDlg.h"
#include <string>

class GameDebugger
{
private:
	static GameDebugger debugger_instance;
	 CgameTestDlg* m_pdlg;
public:
	GameDebugger(void);
	~GameDebugger(void);
	static void OutPut(std::wstring message);
	static void Init(CgameTestDlg* pdlg);
};
