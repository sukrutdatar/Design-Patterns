#ifndef _INHERITANCE_SINGLETON_H_
#define _INHERITANCE_SINGLETON_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class SingletonBase
{
    public:
        static SingletonBase* Instance();
        static bool Exists();
        inline int GetDataX() { return m_dataX; };
        inline void SetDataX(int x) { m_dataX = x; };
        virtual int GetDataY() = 0;
        virtual void SetDataY(int y)  = 0;
    
    protected:
        SingletonBase(int);
        virtual ~SingletonBase() {};
        static SingletonBase* m_pInstance;
        
    private:
        int m_dataX;
};

class SingletonDerived : public SingletonBase
{
    public:
        static void Create(int, int);
        virtual inline int GetDataY() { return m_dataY; };
        virtual inline void SetDataY(int y) { m_dataY = y; };
    
    protected:
        SingletonDerived(int, int);
        virtual ~SingletonDerived() {};
    
    private:
        int m_dataY;
};
#endif