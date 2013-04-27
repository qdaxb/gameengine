#include "StdAfx.h"
#include "CriticalSectionLock.h"

CriticalSectionLock::CriticalSectionLock(void)
{
	::InitializeCriticalSectionAndSpinCount( &m_csLock, 4000 );
}

CriticalSectionLock::~CriticalSectionLock(void)
{
	::DeleteCriticalSection( &m_csLock );
}

void CriticalSectionLock::Lock()
{
	::EnterCriticalSection( &m_csLock );
}

void CriticalSectionLock::UnLock()
{
	::LeaveCriticalSection( &m_csLock );
}
