#pragma once
#include "loginwindow.h"

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
	User* UPtr;
    PMList pmlist[MAX_PMS];
    std::vector<Pokemon*>pv;
    Pokemon* Pptr;
	Pokemon* PMptr;
	int time1;
	int time2;
	std::vector<std::string>strs;
	QTimer* timer;
	int timer_id;
	void SendLoginInfo(const std::string &username, const std::string &password, int &state);
    void showmainwindow();
    void showpms(const std::string &username);
	void ChangeUserOp(QListWidgetItem *item);
	void ChangePmOp();
	
public slots:
	void CreatePm();
	void SkillBar1();
	void SkillBar2();
	void SkillBar3();
	void SkillBar4();
	void GradeUpMatch();
	void StartMatch();
	void Fight();
	void Exit();
signals:
    void displaypms(const std::string &username,std::vector<Pokemon*> &vec);
	void LoginInfo(const std::string &username, const std::string &password, int &state, UserInfo &userinfo);
	void UserLoss(User* uptr);
	void UserWin(User* uptr, std::vector<Pokemon*> &vec);
	void exit();
private:
    Ui::MainWindow *ui;
};
