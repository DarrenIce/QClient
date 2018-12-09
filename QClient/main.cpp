#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* mw=new MainWindow;
    mw->show();
    Client *clt=new Client();
    QObject::connect(mw,&MainWindow::LoginInfo,clt,&Client::SendLoginInfo);
    QObject::connect(mw->lw,&LoginWindow::SignupInfo,clt,&Client::SendSignupInfo);
    QObject::connect(mw,&MainWindow::displaypms,clt,&Client::displaypms);
    mw->setVisible(false);
    return a.exec();
}
