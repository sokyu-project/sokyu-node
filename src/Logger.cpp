#include "Logger.h"

#include <string>
#include <iostream>
#include <ctime>

Logger::Logger()
{
    //ctor
}

Logger::~Logger()
{
    //dtor
}

void Logger::info(std::string message)
{
    Logger::print(" "+message);
}

void Logger::warning(std::string message)
{
    Logger::print("[WARNING] "+message);
}

void Logger::error(std::string message)
{
    Logger::print("[ERROR] "+message);
}

void Logger::print(std::string message)
{
    time_t now = time(0);
    tm *time = localtime(&now);

    std::cout << "[" << 1900+time->tm_year << "-" << 1+time->tm_mon << "-" << time->tm_mday << " "
    << time->tm_hour << ":" << time->tm_min << ":" << time->tm_sec << "]"
    << message << std::endl;
}
