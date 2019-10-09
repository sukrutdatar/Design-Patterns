#include "InheritanceSingleton.h"

SingletonBase* SingletonBase::m_pInstance = NULL;

SingletonBase::SingletonBase(int initialValueX) 
: m_dataX(initialValueX)
{
}

bool SingletonBase::Exists()
{
    return (m_pInstance != NULL);
}

SingletonBase* SingletonBase::Instance()
{
    if (m_pInstance == NULL)
        cout << endl << "Object has not been created.";

    return m_pInstance;    
}

SingletonDerived::SingletonDerived(int initialValueX, int initialValueY) 
: SingletonBase(initialValueX)
{
    m_dataY = initialValueY;
}


void SingletonDerived::Create(int initialValueX, int initialValueY)
{
    if (m_pInstance)
        std::cout << endl << "Singleton has already been created.";
    else
        m_pInstance = new SingletonDerived(initialValueX, initialValueY);
}

int main()
{
    SingletonBase::Instance(); // returns NULL as creation has to be done in Derived class only.
    
    SingletonDerived::Create(10, 5);
    SingletonDerived::Instance()->SetDataX(50);
    cout << endl << SingletonDerived::Instance()->GetDataX();

    SingletonDerived::Instance()->SetDataY(20);
    cout << endl << SingletonDerived::Instance()->GetDataY();
    
    return 0;
}
