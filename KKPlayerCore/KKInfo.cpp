/**************************kkplayer*********************************************/
/*******************Copyright (c) Saint ******************/
/******************Author: Saint *********************/
/*******************Author e-mail: lssaint@163.com ******************/
/*******************Author qq: 784200679 ******************/
/*******************KKPlayer  WWW: http://www.70ic.com/KKplayer ********************************/
/*************************date��2015-6-25**********************************************/
#include "stdafx.h"
#include "KKInfo.h"
CKKMutex::CKKMutex(void)
{
	m_KKMutex=NULL;
#ifdef WIN32
	m_KKMutex=::CreateMutex(NULL,FALSE,NULL);
#endif
}

void CKKMutex::Lock()
{
#ifdef WIN32
	::WaitForSingleObject(m_KKMutex, INFINITE);
#endif
}
void CKKMutex::UnLock()
{
#ifdef WIN32
    ::ReleaseMutex(m_KKMutex);
#endif
}
CKKMutex::~CKKMutex(void)
{
#ifdef WIN32
	::CloseHandle(m_KKMutex);
#endif	
}
