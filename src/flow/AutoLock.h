#ifndef _AUTOLOCK_H_
#define _AUTOLOCK_H_

template<typename LockType>
class AutoLock
{
public:
	inline AutoLock( LockType& lock )
	{
		m_Lock = &lock;
		m_Lock->Lock();
	}

	inline ~AutoLock()
	{
		m_Lock->UnLock();
	}

private:

	LockType* m_Lock;
};

#endif