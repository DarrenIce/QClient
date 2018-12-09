#pragma once
#include "InitSock.h"
#include "pokemon.h"
#include "pokemons.h"
#include <QMessageBox>
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QLabel>
#include <QLineEdit>
#include <QtWidgets>
#include <vector>
#include <regex>

#define SER_PORT 4396
#define BUF_SIZE 1024
#define MAX_PMS 100
#define ACHI_NUM 10

typedef struct user {
	int WinNum;
	int LossNum;
	int PmNum;
	int PerPmNum;
	char username[20];
	char password[20];
}UserInfo;

typedef struct su {
	char username[20];
	char password[20];
}Info;

class User {
public:
	std::string username;
	std::string password;
	int WinNum;
	int LossNum;
	double WinRate;
	int PmNum;
	int PerPmNum;
	int AchNum;
	int AchLevel[ACHI_NUM];
	std::string Ach[ACHI_NUM];
	User(UserInfo info)
	{
		username = info.username;
		password = info.password;
		WinNum = info.WinNum;
		LossNum = info.LossNum;
		WinRate = (double)WinNum / LossNum;
		PmNum = info.PmNum;
		PerPmNum = info.PerPmNum;
		AchNum = 0;
		for (int i = 0; i < ACHI_NUM; i++)
			AchLevel[i] = 0;
		if (PmNum >= 10)
			AchNum++;
		if (PerPmNum >= 10)
			AchNum++;
		PmAch();
		PerPmAch();
	}
	void PmAch()
	{
		if (PmNum < 10)
		{
			Ach[0] = "萌新收集者";
			AchLevel[0] = 1;
		}
		else if (PmNum < 20)
		{
			Ach[0] = "入门收集者";
			AchLevel[0] = 2;
		}
		else if (PmNum < 30)
		{
			Ach[0] = "初阶收集者";
			AchLevel[0] = 3;
		}
		else if (PmNum < 40)
		{
			Ach[0] = "中阶收集者";
			AchLevel[0] = 4;
		}
		else if (PmNum < 50)
		{
			Ach[0] = "高阶收集者";
			AchLevel[0] = 5;
		}
		else if (PmNum < 60)
		{
			Ach[0] = "铜牌收集者";
			AchLevel[0] = 6;
		}
		else if (PmNum < 70)
		{
			Ach[0] = "银牌收集者";
			AchLevel[0] = 7;
		}
		else if (PmNum < 80)
		{
			Ach[0] = "金牌收集者";
			AchLevel[0] = 8;
		}
		else if (PmNum < 90)
		{
			Ach[0] = "狂热收集者";
			AchLevel[0] = 9;
		}
		else
		{
			Ach[0] = "收集机器";
			AchLevel[0] = 10;
		}
	}
	void PerPmAch()
	{
		if (PmNum < 10)
		{
			Ach[1] = "新人训练师";
			AchLevel[1] = 1;
		}
		else if (PmNum < 20)
		{
			Ach[1] = "入门训练师";
			AchLevel[1] = 2;
		}
		else if (PmNum < 30)
		{
			Ach[1] = "初阶训练师";
			AchLevel[1] = 3;
		}
		else if (PmNum < 40)
		{
			Ach[1] = "中阶训练师";
			AchLevel[1] = 4;
		}
		else if (PmNum < 50)
		{
			Ach[1] = "高阶训练师";
			AchLevel[1] = 5;
		}
		else if (PmNum < 60)
		{
			Ach[1] = "铜牌训练师";
			AchLevel[1] = 6;
		}
		else if (PmNum < 70)
		{
			Ach[1] = "银牌训练师";
			AchLevel[1] = 7;
		}
		else if (PmNum < 80)
		{
			Ach[1] = "金牌训练师";
			AchLevel[1] = 8;
		}
		else if (PmNum < 90)
		{
			Ach[1] = "训练大师";
			AchLevel[1] = 9;
		}
		else
		{
			Ach[1] = "训练机器";
			AchLevel[1] = 10;
		}
	}
	void UpdateWinRate()
	{
		WinRate = (double)WinNum / LossNum;
	}
};

class Client:public QMainWindow
{
    Q_OBJECT
public:
    SOCKET client;
    std::string sendtext;
    char buff[BUF_SIZE];
    Client();

    void SendLoginInfo(const std::string &username,const std::string &password,int &state, UserInfo &userinfo);
    void SendSignupInfo(const std::string &username,const std::string &password,int &state);
    void displaypms(const std::string &username,std::vector<Pokemon*> &vec);
};

