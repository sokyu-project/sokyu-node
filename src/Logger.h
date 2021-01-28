#ifndef LOGGER_H
#define LOGGER_H

#include <string>

class Logger
{
    public:
        Logger();
        virtual ~Logger();

        static void info(std::string message);
        static void warning(std::string message);
        static void error(std::string message);

    protected:

    private:
        static void print(std::string message);
};

#endif // LOGGER_H
