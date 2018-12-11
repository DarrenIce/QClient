/********************************************************************************
** Form generated from reading UI file 'otheruser.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHERUSER_H
#define UI_OTHERUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OtherUser
{
public:
    QTableWidget *UserTable;
    QListWidget *PMList;
    QTableWidget *UserPm;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *OtherUser)
    {
        if (OtherUser->objectName().isEmpty())
            OtherUser->setObjectName(QString::fromUtf8("OtherUser"));
        OtherUser->resize(331, 671);
        UserTable = new QTableWidget(OtherUser);
        if (UserTable->columnCount() < 1)
            UserTable->setColumnCount(1);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setForeground(brush);
        UserTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (UserTable->rowCount() < 10)
            UserTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        UserTable->setVerticalHeaderItem(9, __qtablewidgetitem10);
        UserTable->setObjectName(QString::fromUtf8("UserTable"));
        UserTable->setEnabled(true);
        UserTable->setGeometry(QRect(0, 40, 171, 331));
        UserTable->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PMList = new QListWidget(OtherUser);
        PMList->setObjectName(QString::fromUtf8("PMList"));
        PMList->setGeometry(QRect(0, 410, 171, 261));
        PMList->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        PMList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        UserPm = new QTableWidget(OtherUser);
        if (UserPm->columnCount() < 1)
            UserPm->setColumnCount(1);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        __qtablewidgetitem11->setForeground(brush1);
        UserPm->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        if (UserPm->rowCount() < 18)
            UserPm->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(3, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(4, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(5, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(6, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(7, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(8, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(9, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(10, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(11, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(12, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(13, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(14, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(15, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(16, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(17, __qtablewidgetitem29);
        UserPm->setObjectName(QString::fromUtf8("UserPm"));
        UserPm->setGeometry(QRect(170, 40, 161, 571));
        UserPm->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserPm->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label_2 = new QLabel(OtherUser);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 10, 61, 21));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(OtherUser);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(40, 380, 81, 21));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(OtherUser);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(220, 10, 61, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_4->setAlignment(Qt::AlignCenter);

        retranslateUi(OtherUser);

        QMetaObject::connectSlotsByName(OtherUser);
    } // setupUi

    void retranslateUi(QWidget *OtherUser)
    {
        OtherUser->setWindowTitle(QApplication::translate("OtherUser", "OtherUser", nullptr));
        QTableWidgetItem *___qtablewidgetitem = UserTable->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("OtherUser", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = UserTable->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("OtherUser", "WinNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = UserTable->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("OtherUser", "LossNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = UserTable->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("OtherUser", "WinRate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = UserTable->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("OtherUser", "PM Num", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = UserTable->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("OtherUser", "FullLevel", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = UserTable->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("OtherUser", "AchiNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = UserTable->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("OtherUser", "Title1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = UserTable->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("OtherUser", "Titel2", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = UserTable->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("OtherUser", "Title3", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = UserPm->verticalHeaderItem(0);
        ___qtablewidgetitem10->setText(QApplication::translate("OtherUser", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = UserPm->verticalHeaderItem(1);
        ___qtablewidgetitem11->setText(QApplication::translate("OtherUser", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = UserPm->verticalHeaderItem(2);
        ___qtablewidgetitem12->setText(QApplication::translate("OtherUser", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = UserPm->verticalHeaderItem(3);
        ___qtablewidgetitem13->setText(QApplication::translate("OtherUser", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = UserPm->verticalHeaderItem(4);
        ___qtablewidgetitem14->setText(QApplication::translate("OtherUser", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = UserPm->verticalHeaderItem(5);
        ___qtablewidgetitem15->setText(QApplication::translate("OtherUser", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = UserPm->verticalHeaderItem(6);
        ___qtablewidgetitem16->setText(QApplication::translate("OtherUser", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = UserPm->verticalHeaderItem(7);
        ___qtablewidgetitem17->setText(QApplication::translate("OtherUser", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = UserPm->verticalHeaderItem(8);
        ___qtablewidgetitem18->setText(QApplication::translate("OtherUser", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = UserPm->verticalHeaderItem(9);
        ___qtablewidgetitem19->setText(QApplication::translate("OtherUser", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = UserPm->verticalHeaderItem(10);
        ___qtablewidgetitem20->setText(QApplication::translate("OtherUser", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = UserPm->verticalHeaderItem(11);
        ___qtablewidgetitem21->setText(QApplication::translate("OtherUser", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = UserPm->verticalHeaderItem(12);
        ___qtablewidgetitem22->setText(QApplication::translate("OtherUser", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = UserPm->verticalHeaderItem(13);
        ___qtablewidgetitem23->setText(QApplication::translate("OtherUser", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = UserPm->verticalHeaderItem(14);
        ___qtablewidgetitem24->setText(QApplication::translate("OtherUser", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = UserPm->verticalHeaderItem(15);
        ___qtablewidgetitem25->setText(QApplication::translate("OtherUser", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = UserPm->verticalHeaderItem(16);
        ___qtablewidgetitem26->setText(QApplication::translate("OtherUser", "Skill3", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = UserPm->verticalHeaderItem(17);
        ___qtablewidgetitem27->setText(QApplication::translate("OtherUser", "Skill4", nullptr));
        label_2->setText(QApplication::translate("OtherUser", "UserInfo", nullptr));
        label_3->setText(QApplication::translate("OtherUser", "PokemonList", nullptr));
        label_4->setText(QApplication::translate("OtherUser", "Pokemon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OtherUser: public Ui_OtherUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHERUSER_H
