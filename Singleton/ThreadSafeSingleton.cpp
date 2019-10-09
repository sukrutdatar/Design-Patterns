#include "ThreadSafeSingleton.h"

ThreadSafeSingleton_CallOnce* ThreadSafeSingleton_CallOnce::m_pInstance = NULL;
std::once_flag ThreadSafeSingleton_CallOnce::m_initInstanceFlag;


ThreadSafeSingleton_Mutex* ThreadSafeSingleton_Mutex::m_pInstance = NULL;
std::mutex ThreadSafeSingleton_Mutex::m_mutex;

int main()
{
    std::thread t1 = std::thread(
        []() {
            this_thread::sleep_for(chrono::nanoseconds(1));
            std::cout << endl << ThreadSafeSingleton_CallOnce::Instance();
        }
    );

    std::thread t2 = std::thread(
        []() {
            std::cout << endl << ThreadSafeSingleton_CallOnce::Instance();
        }
    );

    std::cout << endl << ThreadSafeSingleton_CallOnce::Instance();
    t1.join();
    t2.join();


    
    std::thread t3 = std::thread(
        []() {
            this_thread::sleep_for(chrono::nanoseconds(1));
            std::cout << endl << ThreadSafeSingleton_Mutex::Instance();
        }
    );

    std::thread t4 = std::thread(
        []() {
            std::cout << endl << ThreadSafeSingleton_Mutex::Instance();
        }
    );

    std::cout << endl << ThreadSafeSingleton_Mutex::Instance();
    t3.join();
    t4.join();

    std::thread t5 = std::thread(
        []() {
            this_thread::sleep_for(chrono::nanoseconds(1));
            std::cout << endl << &ThreadSafeSingleton_StaticVar::Instance();
        }
    );

    std::thread t6 = std::thread(
        []() {
            std::cout << endl << &ThreadSafeSingleton_StaticVar::Instance();
        }
    );

    std::cout << endl << &ThreadSafeSingleton_StaticVar::Instance();
    t5.join();
    t6.join();


    return 0;
}