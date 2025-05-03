#ifndef RTW_WINDOWS_H
#define RTW_WINDOWS_H

/*
 * Copyright 2011-2022 The MathWorks, Inc.
 *
 * File: rtw_windows.h
 *
 * Abstract:
 *  Function prototypes and defines windows mutex/semaphores
 */
#include <windows.h>

#define rtw_win_mutex_create( mutexDW ) \
    *(mutexDW) = CreateMutex(NULL, 0U, NULL); 

#define rtw_win_mutex_wait( mutexDW ) \
    WaitForSingleObject(mutexDW, INFINITE);

#define rtw_win_mutex_release( mutexDW ) \
    ReleaseMutex(mutexDW);

#define rtw_win_mutex_close( mutexDW ) \
    CloseHandle(mutexDW);

#define rtw_win_sem_create( semaphoreDW, initVal ) \
	*(semaphoreDW) = ((initVal) == 0) ? \
	CreateSemaphore(NULL, 0, 1, NULL) : \
	CreateSemaphore(NULL, (initVal), (initVal), NULL);

#define rtw_win_sem_wait( semaphoreDW ) \
    WaitForSingleObject(semaphoreDW, INFINITE);

#define rtw_win_sem_release( semaphoreDW ) \
    ReleaseSemaphore(semaphoreDW, 1, NULL);

#define rtw_win_sem_close( semaphoreDW ) \
    CloseHandle(semaphoreDW);


#endif /* RTW_WINDOWS_H */
