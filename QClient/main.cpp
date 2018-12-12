#include "mainwindow.h"
#include <QApplication>
//添加六角图表示个体值情况
//添加精灵
//添加动画
//人性化提示
//ui美化

//ChangeUserOp\ChangePmOp\CreatePm\Fight\Server::AddPm
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mw=new MainWindow;
    mw->show();
    Client *clt=new Client();
    QObject::connect(mw,&MainWindow::LoginInfo,clt,&Client::SendLoginInfo);
    QObject::connect(mw->lw,&LoginWindow::SignupInfo,clt,&Client::SendSignupInfo);
    QObject::connect(mw,&MainWindow::displaypms,clt,&Client::displaypms);
	QObject::connect(mw, &MainWindow::UserLoss, clt, &Client::UserLoss);
	QObject::connect(mw, &MainWindow::UserWin, clt, &Client::UserWin);
	QObject::connect(mw, &MainWindow::exit, clt, &Client::exit);
	QObject::connect(mw->lw, &LoginWindow::ext, clt, &Client::exit);
	QObject::connect(mw, &MainWindow::AddPm, clt, &Client::AddPm);
	QObject::connect(mw, &MainWindow::erasepm, clt, &Client::erasepm);
	QObject::connect(mw, &MainWindow::requestuser, clt, &Client::requestuser);
    mw->setVisible(false);
	a.setQuitOnLastWindowClosed(true);
	mw->lw->setStyleSheet("QWidget#LoginWindow{background-image:url(:/images/images/login.jpg)}");
    return a.exec();
}
