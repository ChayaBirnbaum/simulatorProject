#include "configur.h"
#include <sstream>
#include <fstream>
#include <iostream>

void configur::insertData(std::string key, std::string value) {
    if (key == "numOfCamera")
    {
        numOfCamera = stoi(value);
        return;
    }
    if (key == "numMessagesInMinute")
    {
        numMessagesInMinute = stoi(value);
        return;
    }
    if (key == "ip")
    {
        ip = value;
        return;
    }
    if (key == "port")
    {
        port = stoi(value);
        return;
    }
}

void configur::fillConfig() {

    std::ifstream configFile("config.txt");
    if (configFile.is_open())
    {
        std::string line;
        while (getline(configFile, line))
        {
            std::istringstream is_line(line);
            std::string key;
            if (std::getline(is_line, key, '='))
            {
                std::string value;
                if (std::getline(is_line, value))
                    insertData(key, value);
            }
        }
    }
    else
    {
        std::cout << "Couldn't open config file for reading.\n";
    }
    configFile.close();
}

configur::configur() {
    fillConfig();
}

int configur::getNumOfCamera() {
    return numOfCamera;
}

int configur::getNumMessagesInMinute() {
    return numMessagesInMinute;
}

std::string configur::getIp() {
    return ip;
}

int configur::getPort() {
    return port;
}