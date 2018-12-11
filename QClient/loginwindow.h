#pragma once


#include "ui_loginwindow.h"
#include "client.h"

class LoginWindow : public QWidget
{
	Q_OBJECT

public:
	LoginWindow(QWidget *parent = Q_NULLPTR);
	~LoginWindow();
	void closeEvent(QCloseEvent * event);
	void paintEvent(QPaintEvent *event);
public slots:
	void login();
	void signup();
signals:
	void LoginInfo(const std::string &username, const std::string &password, int &state);
	void SignupInfo(const std::string &username, const std::string &password, int &state);
	void showmainwindow();
	void showpms(const std::string &username);
	void ext();
private:
	Ui::LoginWindow ui;

protected:
	bool eventFilter(QObject *obj, QEvent *event);

};
