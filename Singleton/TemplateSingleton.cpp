#include "TemplateSingleton.h"

template <class T> T* Singleton<T>::m_pInstance = NULL;

Logger::Logger()
{}

Logger::~Logger()
{
    Close();
}

void Logger::Write(std::string message)
{
    if (ofs.is_open() && ofs.good())
        ofs << message;
}

bool Logger::Open(std::string fileName)
{
    Close();
    ofs.open(fileName, ios::app);
    return !ofs.fail();
}

bool Logger::Close()
{
    if (ofs.is_open())
    {
        ofs.close();
        return true;
    }
    return false;
}

int main()
{
    Logger* logger = Singleton<Logger>::Instance();
    logger->Open("TemplateSingleton.txt");
    logger->Write("This is an example of template singleton class.");
    logger->Close();
    return 0;
}