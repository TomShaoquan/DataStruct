#include<WinSock2.h>
#include<iostream>
#include<process.h>

#pragma comment(lib,"ws2_32.lib")

using namespace std;
char szName[BUFSIZ] = "[DEFAULT]";
char szMsg[BUFSIZ];

//������Ϣ�̴߳�����
unsigned int WINAPI SendMsg(void* arg)
{
	//���ղ���
	SOCKET hClntSock = *((SOCKET*)arg);
	char szNameMsg[BUFSIZ];
	while (true)
	{
		//����
		fgets(szMsg, BUFSIZ, stdin);

		//�˳�����
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

//������Ϣ�̴߳�����
unsigned int WINAPI RecvMsg(void* arg)
{
	//���ղ���
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
	//1.��ʼ���׽���
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
	//2.�����׽���
	SOCKET sockCli = socket(AF_INET, SOCK_STREAM, 0);

	SOCKADDR_IN addrSrv;
	addrSrv.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	addrSrv.sin_family = AF_INET;
	addrSrv.sin_port = htons(6000);

	//3.���ӷ�����
	if (SOCKET_ERROR == connect(sockCli, (SOCKADDR*)& addrSrv, sizeof(SOCKADDR)))
	{
		printf("connect error:%d", GetLastError());
		return -1;
	}

	hSendThread = (HANDLE)_beginthreadex(NULL, 0, SendMsg,
		(void*)& sockCli, 0, NULL);

	hRecvThread = (HANDLE)_beginthreadex(NULL, 0, RecvMsg,
		(void*)& sockCli, 0, NULL);
	
	//�ȴ��ں��źŷ����仯
	WaitForSingleObject(hSendThread, INFINITE);
	WaitForSingleObject(hRecvThread, INFINITE);
	//�ر��׽���
	closesocket(sockCli);

	//�����׽���
	WSACleanup();

	system("pause");
	return 0;
}