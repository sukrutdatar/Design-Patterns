#ifndef _THREADSAFE_SINGLETON_H_
#define _THREADSAFE_SINGLETON_H_

#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
using namespace std;

class ThreadSafeSingleton_CallOnce
{
    private:
         
        static void Init()
        {
            cout << endl << "Init()";
            m_pInstance = new ThreadSafeSingleton_CallOnce();
        }
    public:
        static ThreadSafeSingleton_CallOnce* Instance()
        {
            std::call_once(m_initInstanceFlag, ThreadSafeSingleton_CallOnce::Init);
            return m_pInstance;
        }

    private:
        ThreadSafeSingleton_CallOnce() {};
        ~ThreadSafeSingleton_CallOnce() {};
        ThreadSafeSingleton_CallOnce& operator=(ThreadSafeSingleton_CallOnce const&);
        
        static ThreadSafeSingleton_CallOnce* m_pInstance;
        static std::once_flag m_initInstanceFlag;
};


class ThreadSafeSingleton_Mutex
{
    public:
        static ThreadSafeSingleton_Mutex* Instance()
        {
            std::lock_guard<mutex> lock(mutex);
            if (!m_pInstance)
                m_pInstance = new ThreadSafeSingleton_Mutex();
            return m_pInstance;
        }

    private:
        ThreadSafeSingleton_Mutex() {};
        ~ThreadSafeSingleton_Mutex() {};
        ThreadSafeSingleton_Mutex& operator=(ThreadSafeSingleton_Mutex const&);
        
        static ThreadSafeSingleton_Mutex* m_pInstance;
        static std::mutex m_mutex;
};


class ThreadSafeSingleton_StaticVar
{
    public:
        static ThreadSafeSingleton_StaticVar& Instance()
        {
            static ThreadSafeSingleton_StaticVar instance;
            return instance;
        }
    
    private:
        ThreadSafeSingleton_StaticVar() {};
        ~ThreadSafeSingleton_StaticVar() {};
        ThreadSafeSingleton_StaticVar(const ThreadSafeSingleton_StaticVar&) = delete; // explicity disabled function
        ThreadSafeSingleton_StaticVar& operator=(const ThreadSafeSingleton_StaticVar&) = delete;
};

#endif