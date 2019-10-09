#ifndef _TEMPLATE_SINGLETON_H_
#define _TEMPLATE_SINGLETON_H_

#include <iostream>
#include <cassert>
#include <string>
#include <fstream>

using namespace std;

template <class T>
class Singleton
{
    public:
        static T* Instance()
        {
            if (!m_pInstance)
                m_pInstance = new T;
                assert(m_pInstance != NULL);
                return m_pInstance;
        }
    
    protected:
        Singleton();
        ~Singleton();
    
    private:
        Singleton(Singleton const&);
        Singleton& operator=(Singleton const&);
    
        static T* m_pInstance;
};


class Logger
{
    private:
        fstream ofs;
    public:
        Logger();
        ~Logger();
        bool Open(std::string);
        bool Close();
        void Write(std::string);
};

#endif