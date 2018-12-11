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
Client::~Client()
{
	::closesocket(client);
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
	::recv(client, buff, sizeof(buff), 0);
	::send(client, username.c_str(), username.size(), 0);
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
void Client::UserLoss(User* uptr)
{
	char buffer[10] = "LOSS1";
	UserInfo user;
	user.LossNum = uptr->LossNum;
	user.PmNum = uptr->PmNum;
	user.PerPmNum = uptr->PerPmNum;
	strcpy(user.username, uptr->username.c_str());
	::send(client, buffer, sizeof(buffer), 0);
	::recv(client, buffer, sizeof(buffer), 0);
	::send(client, (char*)&user, sizeof(UserInfo), 0);
}
void Client::UserWin(User* uptr, std::vector<Pokemon*> &vec)
{
	char buffer[10] = "WIN1";
	::send(client, buffer, sizeof(buffer), 0);
	UserInfo user;
	strcpy(user.username,uptr->username.c_str());
	strcpy(user.password, uptr->password.c_str());
	user.WinNum = uptr->WinNum;
	user.LossNum = uptr->LossNum;
	user.PmNum = uptr->PmNum;
	user.PerPmNum = uptr->PerPmNum;
	PMList pmlist[MAX_PMS];
	int j = 0;
	for (auto i = vec.begin(); i != vec.end(); i++)
	{
		j++;
		pmlist[j].onlyid = (*i)->onlyid;
		pmlist[j].grade = (*i)->grade;
		pmlist[j].exp = (*i)->Exp;
		pmlist[j].skills = (*i)->al_have_skills;
		pmlist[j].skillbar[0] = (*i)->skill_bar[0];
		pmlist[j].skillbar[1] = (*i)->skill_bar[1];
		pmlist[j].skillbar[2] = (*i)->skill_bar[2];
		pmlist[j].skillbar[3] = (*i)->skill_bar[3];
	}
	pmlist[0].num = j;
	::recv(client, buffer, sizeof(buffer), 0);
	::send(client, (char*)&user, sizeof(UserInfo), 0);
	::recv(client, buffer, sizeof(buffer), 0);
	::send(client, (char*)pmlist, sizeof(PMList)*(pmlist[0].num + 1), 0);
}
void Client::exit()
{
	char buffer[10] = "3";
	::send(client, buffer, sizeof(buffer), 0);
	::closesocket(client);
	QApplication* app;
	app->exit(0);
}
void Client::AddPm(Pokemon* ptr)
{
	PMList pm;
	pm.id = ptr->id;
	pm.grade = ptr->grade;
	pm.exp = ptr->Exp;
	pm.Str = ptr->Str.IndividualValue;
	pm.Int = ptr->Int.IndividualValue;
	pm.Phy = ptr->Phy.IndividualValue;
	pm.Sta = ptr->Sta.IndividualValue;
	pm.Res = ptr->Res.IndividualValue;
	pm.Agi = ptr->Agi.IndividualValue;
	pm.skills = ptr->al_have_skills;
	pm.skillbar[0] = ptr->skill_bar[0];
	pm.skillbar[1] = ptr->skill_bar[1];
	pm.skillbar[2] = ptr->skill_bar[2];
	pm.skillbar[3] = ptr->skill_bar[3];
	strcpy(pm.name, ptr->name.c_str());
	strcpy(pm.nicky, ptr->nicky.c_str());
	pm.nature = ptr->nature;
	pm.ppt = ptr->Ppt;

	char buffer[10] = "ADD";
	::send(client, buffer, sizeof(buffer), 0);
	::recv(client, buffer, sizeof(buffer), 0);
	::send(client, (char*)&pm, sizeof(PMList), 0);
}
void Client::erasepm(int onlyid)
{
	char buffer[10] = "ERASE";
	::send(client, buffer, sizeof(buffer), 0);
	::recv(client, buffer, sizeof(buffer), 0);
	::send(client, (char*)&onlyid, sizeof(onlyid), 0);
}
void Client::requestuser(std::vector<User*> &uiv)
{
	char buffer[10] = "4";
	::send(client, buffer, sizeof(buffer), 0);
	UserInfo users[MAX_USERS];
	::recv(client, (char*)users, sizeof(users), 0);
	for (int i = 1; i <= users[0].LossNum; i++)
	{
		uiv.push_back(new User(users[i]));
	}
}