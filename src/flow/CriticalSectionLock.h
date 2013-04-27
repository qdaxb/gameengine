#ifndef _CRITICALSECTIONLOCK_H_
#define _CRITICALSECTIONLOCK_H_

#pragma once

class CriticalSectionLock
{
public:
	CriticalSectionLock(void);
	~CriticalSectionLock(void);
public:
	void Lock();
	void UnLock();
protected:
	CRITICAL_SECTION m_csLock;
private:
	
};

#endif