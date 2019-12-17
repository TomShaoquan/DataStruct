#include<WinSock2.h>
#include<iostream>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;

#define MAX_CLNT 256
SOCKET clientSocks[MAX_CLNT];

int clntCnt = 0;
HANDLE hMutex;

void SendMsg(char* szMsg, int iLen)
{
	int i;
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		send(clientSocks[i], szMsg, iLen, 0);
	}
	ReleaseMutex(hMutex);
}

//�̴߳�����
unsigned int WINAPI HandleClient(void* arg)
{
	//���ղ���
	SOCKET hClntSock = *((SOCKET*)arg);

	int iLen = 0,i;
	char szMsg[BUFSIZ] = { 0 };

	/*while (iLen=recv(hClntSock,szMsg,BUFSIZ,0)!=0)
	{
		SendMsg(szMsg, iLen);
	}*/
	while (true)
	{
		//�Ͽ�����-1
		iLen = recv(hClntSock, szMsg, BUFSIZ, 0);
		//printf("recv msg:%s len:%d\n", szMsg, iLen);
		if (iLen != -1)
		{
			SendMsg(szMsg, iLen);
		}
		else
		{
			break;
		}
	}
	printf("��ʱ������Ŀ:%d\n", clntCnt);
	//ĳ�����ӶϿ�
	WaitForSingleObject(hMutex, INFINITE);
	for (i = 0; i < clntCnt; i++)
	{
		if (clientSocks[i] == hClntSock)
		{
			while (i<clntCnt)
			{
				clientSocks[i] = clientSocks[i + 1];
				i++;
			}
			break;
		}
	}
	clntCnt--;
	printf("��ʱ������Ŀ:%d\n", clntCnt);

	ReleaseMutex(hMutex);
	closesocket(hClntSock);
	return 0;
}
int main()
{
	//1.��ʼ���׽���
	WORD wVersion;
	WSADATA wsaData;
	HANDLE hThread;
	int err;
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
	//�����������
	hMutex = CreateMutex(NULL, FALSE, NULL);

	//2.�����׽���
	SOCKET sockSrv = socket(AF_INET, SOCK_STREAM, 0);
	//3.�󶨵�����
	SOCKADDR_IN addrSrv;

	addrSrv.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	if (SOCKET_ERROR == bind(sockSrv, (SOCKADDR*)& addrSrv, sizeof(SOCKADDR)))
	{
		printf("bind error:%d", GetLastError());
		return -1;
	}

	//4.����
	listen(sockSrv, 10);

	cout << "Server start at port:6000" << endl;
	SOCKADDR_IN addrCli;
	int len = sizeof(SOCKADDR);

	while (true)
	{
		//5.������������
		SOCKET sockCon = accept(sockSrv, (SOCKADDR*)& addrCli, &len);

		WaitForSingleObject(hMutex, INFINITE);
		clientSocks[clntCnt++] = sockCon;
		ReleaseMutex(hMutex);

		hThread=(HANDLE)_beginthreadex(NULL, 0, HandleClient,
			(void*)& sockCon, 0, NULL);
		
		printf("Connect client IP:%s\n", inet_ntoa(addrCli.sin_addr));
		printf("Connect client num:%d\n", clntCnt);
	}

	//�ر��׽���
	closesocket(sockSrv);

	//�����׽���
	WSACleanup();
	system("pause");

	return 0;
}