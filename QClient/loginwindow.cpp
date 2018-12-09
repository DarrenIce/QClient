#include "loginwindow.h"

#include <qwidget.h>
#include <qpainter.h>
#include <qpixmap.h>
#include <QtGui>
#include <QMessageBox>
#include <QPalette>
LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //设置窗口大小
    this->resize(500,300);
    this->setWindowTitle("Login");
    //标签--账号、密码
    pUserName = new QLabel("Username:",this);
    pUserName->setGeometry(180,100,70,30);
    pLogin = new QLabel("Password:",this);
    pLogin->setGeometry(180,130,70,30);
    //文本框--账号密码输入
    pNameEdit = new QLineEdit(this);
    pNameEdit->setGeometry(250,100,100,20);
    pNameEdit->setPlaceholderText(QStringLiteral("Username"));
    pNameEdit->setMaxLength(16);
    pLoginEdit = new QLineEdit(this);
    pLoginEdit->setGeometry(250,130,100,20);
    pLoginEdit->installEventFilter(this);
    pLoginEdit->setContextMenuPolicy(Qt::NoContextMenu);
    pLoginEdit->setPlaceholderText(QStringLiteral("Password"));
    pLoginEdit->setEchoMode(QLineEdit::Password);
    pLoginEdit->setMaxLength(16);
    //登陆按钮
    pButton1 = new QPushButton("Login",this);
    pButton1->setGeometry(175,200,50,35);
    connect(pButton1,SIGNAL(clicked(bool)),this,SLOT(login()));
    pButton2 = new QPushButton("Sign up",this);
    pButton2->setGeometry(325,200,50,35);
    connect(pButton2,SIGNAL(clicked(bool)),this,SLOT(signup()));
    errorop=new QLabel("Error",this);
    errorop->setGeometry(10,10,300,30);
    errorop->hide();
    QApplication::setQuitOnLastWindowClosed(false);
}

void LoginWindow::login()
{
    //获取文本框中的信息
    std::string username;
    std::string password;
    QString strU = pNameEdit ->text();
    QString strP = pLoginEdit->text();
    username=strU.toStdString();
    password=strP.toStdString();
    int state=0;
    emit LoginInfo(username,password,state);
    if (state==1)
    {
        this->hide();
        emit showmainwindow();
        emit showpms(username);
    }
    else if (state==2)
    {
        errorop->setText("User dose not exist.");
        errorop->show();
    }
    else if (state==3)
    {
        errorop->setText("User has Logged in. Please connect with admininister.");
        errorop->show();
    }
    else if (state==4)
    {
        errorop->setText("Wrong password.");
        errorop->show();
    }
}
void LoginWindow::signup()
{
    std::string username;
    std::string password;
    QString strU = pNameEdit ->text();
    QString strP = pLoginEdit->text();
    username=strU.toStdString();
    password=strP.toStdString();
    std::regex repPattern1("^[a-zA-Z][a-zA-Z0-9_]{4,15}$");
    std::regex repPattern2("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,15}$");
    if(!regex_match(username, repPattern1))
    {
        errorop->setText("invalid username.");
        errorop->show();
    }
    else if(!regex_match(password, repPattern2))
    {
        errorop->setText("invalid password.");
        errorop->show();
    }
    else
    {
        int state=0;
        emit SignupInfo(username,password,state);
        if (state==1)
        {
            errorop->setText("Sign up successfully.");
            errorop->show();
        }
        else if (state==2)
        {
            errorop->setText("User already exists.");
            errorop->show();
        }
    }
}
bool LoginWindow::eventFilter(QObject *obj,QEvent *event)
{
    QLineEdit *pLineEdit = qobject_cast<QLineEdit*>(obj);
    if (pLineEdit!=NULL)
    {
        switch(event->type())
        {
        case QEvent::MouseMove:
            return true;
        case QEvent::MouseButtonDblClick:
            return true;
        case QEvent::KeyPress:
        {
            QKeyEvent *pKeyEvent = static_cast<QKeyEvent*>(event);
            if (pKeyEvent->matches(QKeySequence::SelectAll)||pKeyEvent->matches(QKeySequence::Copy)||pKeyEvent->matches(QKeySequence::Paste))
            {
                return true;
            }
        }
        }
    }
    return QObject::eventFilter(obj,event);
}
