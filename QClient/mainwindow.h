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
	void SendLoginInfo(const std::string &username, const std::string &password, int &state);
    void showmainwindow();
    void showpms(const std::string &username);
	void ChangeUserOp(QListWidgetItem *item);
	void ChangePmOp();
	void Fight1();
public slots:
	void CreatePm();
signals:
    void displaypms(const std::string &username,std::vector<Pokemon*> &vec);
	void LoginInfo(const std::string &username, const std::string &password, int &state, UserInfo &userinfo);
private:
    Ui::MainWindow *ui;
};
