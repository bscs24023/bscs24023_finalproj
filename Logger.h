#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream>
using namespace std;

class Logger 
{
    private:
        static Logger* instance;
        ofstream file;
        
        Logger();  
        ~Logger();

        Logger(const Logger&) = delete;
        Logger& operator=(const Logger&) = delete;
        
    public:
        static Logger& getInstance();
        void initialize(const string& filename);
        void cleanup();
        void writeError(const string& error_message);
};

#endif