#include "ClassicSingleton.h"

Logger* Logger::m_pInstance = NULL;

Logger* Logger::Instance()
{
    if (!m_pInstance)
        m_pInstance = new Logger();
    return m_pInstance;
}

bool Logger::OpenFile(std::string fileName)
{
    CloseFile();
    ofs.open(fileName, ios::app);
    return !ofs.fail();
}

bool Logger::CloseFile()
{
    if (ofs.is_open())
    {
        ofs.close();
        return true;
    }
    return false;
}

void Logger::WriteToFile(std::string message)
{
    if (ofs.is_open() && ofs.good())
    {
        ofs << message;
    }
}

int main()
{
    Logger* logger = Logger::Instance();
    logger->OpenFile("ClassicSingleton.txt");
    logger->WriteToFile("This is an example of classic singleton class.");
    logger->CloseFile();
    return 0;
}