#include<WinSock2.h>
#include<iostream>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;
char szName[BUFSIZ] = "[DEFAULT]";
char szMsg[BUFSIZ];

//发送消息线程处理函数
unsigned int WINAPI SendMsg(void* arg)
{
	//接收参数
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[BUFSIZ];
	while (true)
	{
		//阻塞
		fgets(szMsg, BUFSIZ, stdin);

		//退出机制
		if (!strcmp(szMsg, "q\n") || !strcmp(szMsg, "Q\n"))
		{
			closesocket(hClntSock);
			exit(0);

		}
		sprintf_s(szNameMsg,BUFSIZ, "%s %s", szName, szMsg);
		send(hClntSock, szNameMsg, strlen(szNameMsg), 0);

	}
	return 0;
}

//接收消息线程处理函数
unsigned int WINAPI RecvMsg(void* arg)
{
	//接收参数
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[BUFSIZ];
	int iLen = 0;
	while (true)
	{
		iLen = recv(hClntSock, szNameMsg, BUFSIZ, 0);
		if (iLen == -1)
		{
			return -1;
		}
		szNameMsg[iLen] = 0;
		fputs(szNameMsg, stdout);

	}
	return 0;
}



int main(int argc,char* argv[])
{
	//1.初始化套接字
	WORD wVersion;
	WSADATA wsaData;
	int err;

	HANDLE hSendThread, hRecvThread;

	wVersion = MAKEWORD(1, 1);
	err = WSAStartup(wVersion, &wsaData);
	if (err != 0)
	{
		return err;
	}
	if (LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		WSACleanup();
		return -1;
	}

	sprintf_s(szName,sizeof(szName),"[%s]", argv[1]);
	//2.创建套接字
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	//3.连接服务器
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)& addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect error:%d", GetLastError());
		return -1;
	}

	hSendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg,
		(void*)& sockCli, 0, NULL);

	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg,
		(void*)& sockCli, 0, NULL);
	
	//等待内核信号发生变化
	WaitForSingleObject(hSendThread, INFINITE);
	WaitForSingleObject(hRecvThread, INFINITE);
	//关闭套接字
	closesocket(sockCli);

	//清理套接字
	WSACleanup();

	system("pause");
	return 0;
}