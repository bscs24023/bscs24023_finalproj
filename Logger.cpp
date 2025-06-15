#include "Logger.h"
#include <iostream>
#include <ctime>

using namespace std;

Logger* Logger::instance = nullptr;

Logger::Logger() {}

Logger::~Logger() 
{
    cleanup();
}

Logger& Logger::getInstance() 
{
    if (!instance) 
    {
        instance = new Logger();
    }
    return *instance;
}

void Logger::initialize(const string& filename) 
{
    file.open(filename);
    
    if (!file.is_open()) 
    {
        cout << "File not opened" << endl;
    }
}

void Logger::cleanup() 
{
    if (file.is_open()) 
    {
        file.close();
    }
}

void Logger::writeError(const string& error_message) 
{
    if (file.is_open()) 
    {
        time_t now = time(nullptr);
        file << "Error at "<< ctime(&now) << "ERROR: " << error_message << endl;
    }
}