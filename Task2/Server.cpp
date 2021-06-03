//#include "Poco/Net/SocketAddress.h"
//#include "Poco/Net/StreamSocket.h"
//#include "Poco/Net/SocketStream.h"
//#include "Poco/Net/ServerSocket.h"
//#include "Poco/StreamCopier.h"
//#include "Poco/FileStream.h"
//#include "Poco/Timespan.h"
//#include <fstream>
//
//#include <iostream>
//#include <string>
//
//using namespace Poco::Net;
//using namespace Poco;
//using namespace std;
//
//int main(int argc, char** argv)
//{	
//
//	
//	//Binding the IP address with Port number of Client
//	SocketAddress serverAddr("localhost", 9999);
//	ServerSocket server(serverAddr);
//
//	cout << "Server Started..." << endl;
//
//	Timespan timespan(25000);
//
//	const string path = "E:\\Afiniti\\";
//	const string filename = "recv_img.jpg";
//	ofstream recvFile(path+filename);
//	recvFile.close();
//
//	//polling
//	while (1) {
//
//		//using StreamSocket to eastablish the TCP connection
//		if (server.poll(timespan , Socket::SELECT_READ)) {
//			StreamSocket tcp = server.acceptConnection();
//
//			SocketStream receiveData(tcp);
//			////here we are opening the file to write it via InputFileStream
//			
//			FileInputStream outputFile(path+filename, std::ios::binary);
//			////here we will use stream copier to copy the outputstream
//			////into the FileInputStream stream
//			StreamCopier::copyStream(outputFile, receiveData);
//		}
//	}
//	
//	return 0;
//}