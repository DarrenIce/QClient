#pragma once
#include "client.h"


class LoginWindow : public QMainWindow
{
    Q_OBJECT
public:
    LoginWindow(QWidget *parent = 0);
	void closeEvent(QCloseEvent * event);
    //~LoginWindow();
//声明私有成员
private:
    QPushButton *pButton1;
    QPushButton *pButton2;
	QPushButton *exit;
    QLabel *pUserName;
    QLabel *pLogin;
    QLabel *errorop;
    //后期考虑用combobox实现
    QLineEdit *pNameEdit;
    QLineEdit *pLoginEdit;
protected:
    bool eventFilter(QObject *obj, QEvent *event);
//创建槽
public slots:
    void login();
    void signup();
	void Exit();
signals:
    void LoginInfo(const std::string &username,const std::string &password,int &state);
    void SignupInfo(const std::string &username,const std::string &password,int &state);
    void showmainwindow();
    void showpms(const std::string &username);
	void ext();
};

