#pragma once
#include "throwpkm.h"
#include "skillreplace.h"
#include "otheruser.h"


namespace Ui{
class MainWindow;
}


class MainWindow:public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    LoginWindow *lw;
	ThrowPkm* tp;
	SkillReplace* sr;
	OtherUser* ou;
	User* UPtr;
	User* ouPtr;
    PMList pmlist[MAX_PMS];
    std::vector<Pokemon*>pv;
	std::vector<Pokemon*>opv;
    Pokemon* Pptr;
	Pokemon* PMptr;
	Pokemon* optr;
	int time1;
	int time2;
	std::vector<std::string>strs;
	std::vector<User*>userlist;
	QTimer* timer;
	QTimer* timer2; //定时查看是否有用户登录
	int timer_id;
	int choosematch;
	int chooseskill;
	int pm[3];
	void SendLoginInfo(const std::string &username, const std::string &password, int &state);
    void showmainwindow();
    void showpms(const std::string &username);
	void ChangeUserOp(QListWidgetItem *item);
	void ChangeOtherOp(QListWidgetItem *item);
	void ChangePmOp();
	void FlashUserInfo();
	void ShowSkill();
	void Throwpm();
	void closeEvent(QCloseEvent * event);
public slots:
	void CreatePm();
	void SkillBar1();
	void SkillBar2();
	void SkillBar3();
	void SkillBar4();
	void GradeUpMatch();
	void DuelMatch();
	void StartMatch();
	void Fight();
	void Exit();
	void push1();
	void push2();
	void push3();
	void fightinfo1();
	void fightinfo2();
	void onlineuser();
	void showuserinfo(QListWidgetItem *item1);
	void changechoose(QListWidgetItem *item);
	void change1();
	void change2();
	void change3();
	void change4();
signals:
    void displaypms(const std::string &username,std::vector<Pokemon*> &vec);
	void LoginInfo(const std::string &username, const std::string &password, int &state, UserInfo &userinfo);
	void UserLoss(User* uptr);
	void UserWin(User* uptr, std::vector<Pokemon*> &vec);
	void exit();
	void AddPm(Pokemon* ptr);
	void showskill();
	void throwpm();
	void erasepm(int onlyid);
	void requestsend1();
	void requestsend2();
	void requestuser(std::vector<User*> &uiv);
private:
    Ui::MainWindow *ui;
};
