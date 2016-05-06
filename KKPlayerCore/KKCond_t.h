#include "stdafx.h"
#include "KKMutex.h"
#ifndef KKCond_t_H_
#define KKCond_t_H_
//��������ʵ��
class CKKCond_t
{
    public:
	       CKKCond_t(void);
	       ~CKKCond_t(void);
		   //����
           int ResetCond();
		   int SetCond();
		   int WaitCond(int ms);

    private:
#ifdef WIN32_KK
		HANDLE m_hWait;
#else
		pthread_cond_t  m_hWait;
		//volatile long m_hWait;
        CKKMutex m_Mutex;
#endif
};
#endif