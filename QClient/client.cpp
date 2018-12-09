#include "client.h"


CInitSock initSock;

Client::Client()
{

    client=::socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    if (client == INVALID_SOCKET)
    {
        QMessageBox::critical(NULL,"Client error","Failed socket");
    }
    sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(SER_PORT);
    servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
    if (::connect(client, (sockaddr*)&servAddr, sizeof(servAddr)) == -1)
    {
        QMessageBox::critical(NULL,"Client error","Failed connect");
    }
}

void Client::SendLoginInfo(const std::string &username,const std::string &password,int &state, UserInfo &userinfo)
{
	Info login;
    strcpy(login.username,username.c_str());
    strcpy(login.password,password.c_str());
    char buff[10]="2";
    ::send(client,buff,sizeof(buff),0);
    ::recv(client,buff,sizeof(buff),0);
    ::send(client,(char*)&login,sizeof(Info),0);
    char buffer;
	int rev=::recv(client,(char*)&buffer,1,0);
    state=buffer -'0';
	if (state == 1)
	{
		::send(client, (char*)&buffer, 1, 0);
		::recv(client, (char*)&userinfo, sizeof(UserInfo), 0);
	}
}
void Client::SendSignupInfo(const std::string &username,const std::string &password,int &state)
{
    Info signup;
    strcpy(signup.username,username.c_str());
    strcpy(signup.password,password.c_str());
    char buff[10]="1";
    ::send(client,buff,sizeof(buff),0);
    ::recv(client,buff,sizeof(buff),0);
    ::send(client,(char*)&signup,sizeof(Info),0);
    char buffer[100];
    ::recv(client,buffer,100,0);
    state=buffer[0]-'0';
}
void Client::displaypms(const std::string &username,std::vector<Pokemon*>& vec)
{
    PMList pmlist[MAX_PMS];
    char buff[10]="5";
    ::send(client,buff,sizeof(buff),0);
	//int rev = ::recv(client, buff, sizeof(buff), 0);
	int rev = ::recv(client, (char*)pmlist, (unsigned int)sizeof(PMList) * MAX_PMS, 0);
    
    if (pmlist[0].num == 0)
    {
        QMessageBox::critical(NULL,"Client error","An error occurred while querying.");
    }
    else
    {
        for (int i = 1; i <= pmlist[0].num; i++)
        {
            if ( 3 == pmlist[i].id)
            {
                vec.push_back(new Venusaur(pmlist[i]));
            }
            else if (pmlist[i].id == 6)
            {
                vec.push_back(new Charizard(pmlist[i]));
            }
            else if (pmlist[i].id == 9)
            {
                vec.push_back(new Blastoise(pmlist[i]));
            }
        }
    }
}
