// stdio_t1.cpp :
//

#include <iostream>
#include <string>
#include <thread>
#include <Windows.h>

using std::thread;
int main()
{
	::Sleep(10000);
	thread([] {
		while (true) {
			std::string strOut;
			if (std::getline(std::cin, strOut)) {

				//std::cout << strOut.c_str() << std::endl;

				if (strOut.find("initialized") != -1) {
					// std::cout << "{\"jsonrpc\":\"2.0\",\"id\":0,\"result\":{\"protocolVersion\":\"2024-11-05\",\"capabilities\":{\"prompts\":{\"listChanged\":false},\"resources\":{\"subscribe\":false,\"listChanged\":false},\"tools\":{\"listChanged\":false}},\"serverInfo\":{\"name\":\"hello moto\",\"version\":\"0.1\"}}}" << std::endl;
					continue;
				}
				if (strOut.find("initialize") != -1) {
					std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 34);// ID processing for different inputs
					//std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 10);
					// "{\"id\":\"9c0d0aee204640eaacdb13f531689279-1\",\"jsonrpc\":\"2.0\",\"result\":{\"capabilities\":{\"tools\":{\"listChanged\":false}},\"protocolVersion\":\"2024-11-05\",\"serverInfo\":{\"name\":\"echo_server\",\"version\":\"1.0.0.1\"}}}"
					std::cout << "{\"id\":\"" << sID.c_str() << "\",\"jsonrpc\":\"2.0\",\"result\":{\"capabilities\":{\"tools\":{\"listChanged\":false}},\"protocolVersion\":\"2024-11-05\",\"serverInfo\":{\"name\":\"echo_server\",\"version\":\"1.0.0.1\"}}}" << std::endl;
					continue;
				}

				if (strOut.find("tools/list") != -1) {
					std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 34);// ID processing for different inputs
					//std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 10);
					std::cout << "{\"id\":\"" << sID.c_str() << "\",\"jsonrpc\":\"2.0\",\"result\":{\"tools\":[{\"description\":\"Receive the data sent by the client and then return the exact same data to the client.\",\"inputSchema\":{\"properties\":{\"input\":{\"description\":\"client input data\",\"type\":\"string\"}},\"required\":[\"input\"],\"type\":\"object\"},\"name\":\"echo\"}]}}" << std::endl;
					continue;
				}
				if (strOut.find("tools/call") != -1) {
					if (strOut.find("\"name\":\"echo\"") != -1) {
						std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 34);// ID processing for different inputs
						//std::string sID = strOut.substr(strOut.find("id\":\"") + 5, 10);
						std::cout << "{\"jsonrpc\":\"2.0\",\"id\":\"" << sID.c_str() << "\",\"result\":{\"isError\":false,\"content\":[{\"type\":\"text\",\"text\":\"Hello, sInput!\"}]}}" << std::endl;
					}
					else {

					}
					continue;
				}
			}
			// {"jsonrpc":"2.0","id":"e72836d39c134d489c8f9cd18feb69b3-1","method":"initialize","params":{"protocolVersion":"2024-11-05","capabilities":{},"clientInfo":{"name":"Email.MCPClient","version":"1.0.0.0"}}}
		}
	}).detach();
	//thread([] {
	//	std::cout << "" << std::endl;
	//}).detach();
	HANDLE hd = CreateEvent(NULL, NULL, false, L"anble");
	WaitForSingleObject(hd, INFINITE);
	//std::cout << "Hello World!\n";

	system("pause");
	system("pause");
	system("pause");
	system("pause");
	system("pause");
}
