
#define _CRT_SECURE_NO_WARNINGS
#include "simulator.h"
#include "configur.h"

//0556707712 מירי 

//void main() {
//	discovery d(1, 2, 3.5, 4);
//	d.parseMessage();
//	discovery d2();
//}

void main() {
	simulator* s = new simulator();
	std::cout << "good!!\n";
	if (s != NULL) {
		s->begin();
		std::cout << "very good!!\n";
		s->printAllCmera();
		delete(s);
	}
}

//לא שולח! שרת-לקוח!!

//#include <iostream>
//#include <winsock2.h>
//#include <ws2tcpip.h>
//#pragma comment(lib, "Ws2_32.lib")
//
//using namespace std;
//
//
//int main(int argc, char* argv[])
//{
//	string buffer = "hello.";
//
//	if (argc > 1)
//	{
//		buffer = argv[1];
//	}
//
//	WSADATA wsa_data;
//	SOCKADDR_IN addr;
//
//	WSAStartup(MAKEWORD(2, 0), &wsa_data);
//	const auto server = socket(AF_INET, SOCK_STREAM, 0);
//
//	InetPton(AF_INET, PCWSTR("127.0.0.1"), &addr.sin_addr.s_addr);
//
//	addr.sin_family = AF_INET;
//	addr.sin_port = htons(5555);
//
//	connect(server, reinterpret_cast<SOCKADDR*>(&addr), sizeof(addr));
//	cout << "Connected to server!" << endl;
//
//	send(server, buffer.c_str(), buffer.length(), 0);
//	cout << "Message sent!" << endl;
//
//	closesocket(server);
//	WSACleanup();
//	cout << "Socket closed." << endl << endl;
//}