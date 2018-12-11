/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_3;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(390, 241);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/images/images/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        LoginWindow->setWindowIcon(icon);
        LoginWindow->setAutoFillBackground(false);
        LoginWindow->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(LoginWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 60, 71, 21));
        label->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 100, 71, 20));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_2->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(LoginWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(170, 60, 113, 20));
        lineEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        lineEdit_2 = new QLineEdit(LoginWindow);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(170, 100, 113, 20));
        lineEdit_2->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        pushButton = new QPushButton(LoginWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(110, 160, 75, 23));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        pushButton_2 = new QPushButton(LoginWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(200, 160, 75, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(60, 130, 231, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(255, 0, 0);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Login", nullptr));
        label->setText(QApplication::translate("LoginWindow", "Username", nullptr));
        label_2->setText(QApplication::translate("LoginWindow", "Password", nullptr));
        pushButton->setText(QApplication::translate("LoginWindow", "Signup", nullptr));
        pushButton_2->setText(QApplication::translate("LoginWindow", "Login", nullptr));
        label_3->setText(QApplication::translate("LoginWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
