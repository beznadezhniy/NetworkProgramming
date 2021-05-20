/* все что закомменчено - было изучение темы методом проб и ошибок ^_^ */
#pragma comment (lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <fstream>
#include <WS2tcpip.h>
#pragma warning(disable:4996)
#define LENGTH 512

/* 
SOCKET Socket, Sub;
WSADATA Winsock;
sockaddr_in Addr;
int Addrlen = sizeof(sockaddr_in);
char Buffer[256];
char* Str;
sockaddr_in IncomingAddress;
int AddressLen = sizeof(IncomingAddress);
*/

/*void FileSend(SOCKET FileSendSocket, char* FilePath)
{
    streampos filesize = 0;
    ifstream in(FilePath, ios::binary);
    ZeroMemory(&sendbuf, sendbuflen);

    if (in.is_open())
    {
        while (1)
        {
            in.read(sendbuf, sendbuflen);
            if (in.eof())
            {
                cout << "End of File sending from Client" << endl;
                in.close();
                break;
            }
            else
            {
                send(FileSendSocket, sendbuf, sendbuflen, 0);
                ZeroMemory(&sendbuf, sendbuflen);
            }
        }
    }

}
*/



using namespace std;
int main(int argc, char* argv[])
{

	//WASStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{ 
		cout << "Error " << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, 0);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConn;
	newConn = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
	if (newConn == 0)
	{
		cout << "error №2\n";
	}
	else
	{
		cout << "Client Connected!\n";
		char msg[256] = "Hello! It's my first network program!";
		send(newConn, msg, sizeof(msg), 0);
	} 
/*   if (Sub = accept(Socket, (sockaddr*)&IncomingAddress, &AddressLen))
    {
        char* ClientIP = inet_ntoa(IncomingAddress.sin_addr);
        int ClientPort = ntohs(IncomingAddress.sin_port);
        printf("Client conncted!\n");
        printf("IP: %s:%d\n", ClientIP, ClientPort);

        printf("Sending file .. \n"); FILE* File;
        char* Buffer;
        unsigned long Size;

        File = fopen("C:\\Prog.exe", "rb");
        if (!File)
        {
            printf("Error while readaing the file\n");
            goto End;
        }

        fseek(File, 0, SEEK_END);
        Size = ftell(File);
        fseek(File, 0, SEEK_SET);

        Buffer = new char[Size];

        fread(Buffer, Size, 1, File);
        char cSize[MAX_PATH];
        sprintf(cSize, "%i", Size);

        fclose(File);

        send(Sub, cSize, MAX_PATH, 0); // File size
        send(Sub, Buffer, Size, 0); // File Binary
        free(Buffer);

    End:
        closesocket(Sub);
        closesocket(Socket);
        WSACleanup();
    }
    getchar();
 */
    system("PAUSE");
	return 0;
}
