#pragma once
#include <string>
class configur
{
	private:
		int numOfCamera;
		int numMessagesInMinute;
		std::string ip;
		int port;
	public:
		int getNumOfCamera();
		int getNumMessagesInMinute();
		std::string getIp();
		int getPort();
		void fillConfig();
		configur();
		void insertData(std::string, std::string);
};

