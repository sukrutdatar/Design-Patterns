#ifndef _CLASSIC_SINGLETON_H_
#define _CLASSIC_SINGLETON_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Logger
{
    public:
        static Logger* Instance();
        bool OpenFile(std::string);
        void WriteToFile(std::string);
        bool CloseFile();
        
    private:
        Logger() {};
        Logger(Logger const&) {};
        Logger& operator=(Logger const&) {};

        static Logger* m_pInstance;
        ofstream ofs;
};
#endif