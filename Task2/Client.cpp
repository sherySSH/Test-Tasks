#include "Poco/Net/SocketAddress.h"
#include "Poco/Net/StreamSocket.h"
#include "Poco/Net/SocketStream.h"
#include "Poco/Net/ServerSocket.h"
#include "Poco/StreamCopier.h"
#include "Poco/FileStream.h"

#include <iostream>
#include <string>

using namespace Poco::Net;
using namespace Poco;
using namespace std;

int main(int argc, char** argv)
{


	//Binding the IP address with Port number of Client
	SocketAddress serverAddr("localhost", 9999);

	cout << "Client Started..." << endl;

	//using StreamSocket to eastablish the TCP connection
	StreamSocket client;
	client.connect(serverAddr);
	SocketStream sendData(client);

	string filename = "E:\\Afiniti\\flower_client.jpg";

	FileOutputStream fetchImage(filename, ios::binary);

	Poco::StreamCopier::copyStream(sendData, fetchImage);


	return 0;
}