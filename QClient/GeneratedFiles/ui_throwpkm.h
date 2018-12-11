/********************************************************************************
** Form generated from reading UI file 'throwpkm.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THROWPKM_H
#define UI_THROWPKM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThrowPkm
{
public:
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableWidget *UserPm_1;
    QTableWidget *UserPm_2;
    QTableWidget *UserPm_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;

    void setupUi(QWidget *ThrowPkm)
    {
        if (ThrowPkm->objectName().isEmpty())
            ThrowPkm->setObjectName(QString::fromUtf8("ThrowPkm"));
        ThrowPkm->resize(752, 708);
        pushButton_3 = new QPushButton(ThrowPkm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(560, 650, 75, 23));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        pushButton = new QPushButton(ThrowPkm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 650, 81, 21));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        pushButton_2 = new QPushButton(ThrowPkm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(350, 650, 75, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        UserPm_1 = new QTableWidget(ThrowPkm);
        if (UserPm_1->columnCount() < 1)
            UserPm_1->setColumnCount(1);
        QBrush brush(QColor(0, 0, 0, 255));
        brush.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setForeground(brush);
        UserPm_1->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (UserPm_1->rowCount() < 18)
            UserPm_1->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(14, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(15, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(16, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        UserPm_1->setVerticalHeaderItem(17, __qtablewidgetitem18);
        UserPm_1->setObjectName(QString::fromUtf8("UserPm_1"));
        UserPm_1->setGeometry(QRect(90, 50, 161, 571));
        UserPm_1->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserPm_1->setEditTriggers(QAbstractItemView::NoEditTriggers);
        UserPm_2 = new QTableWidget(ThrowPkm);
        if (UserPm_2->columnCount() < 1)
            UserPm_2->setColumnCount(1);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        __qtablewidgetitem19->setForeground(brush1);
        UserPm_2->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        if (UserPm_2->rowCount() < 18)
            UserPm_2->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(0, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(1, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(2, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(3, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(4, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(5, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(6, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(7, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(8, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(9, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(10, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(11, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(12, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(13, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(14, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(15, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(16, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        UserPm_2->setVerticalHeaderItem(17, __qtablewidgetitem37);
        UserPm_2->setObjectName(QString::fromUtf8("UserPm_2"));
        UserPm_2->setGeometry(QRect(510, 50, 161, 571));
        UserPm_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserPm_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        UserPm_3 = new QTableWidget(ThrowPkm);
        if (UserPm_3->columnCount() < 1)
            UserPm_3->setColumnCount(1);
        QBrush brush2(QColor(0, 0, 0, 255));
        brush2.setStyle(Qt::NoBrush);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        __qtablewidgetitem38->setForeground(brush2);
        UserPm_3->setHorizontalHeaderItem(0, __qtablewidgetitem38);
        if (UserPm_3->rowCount() < 18)
            UserPm_3->setRowCount(18);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(0, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(1, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(2, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(3, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(4, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(5, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(6, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(7, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(8, __qtablewidgetitem47);
        QTableWidgetItem *__qtablewidgetitem48 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(9, __qtablewidgetitem48);
        QTableWidgetItem *__qtablewidgetitem49 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(10, __qtablewidgetitem49);
        QTableWidgetItem *__qtablewidgetitem50 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(11, __qtablewidgetitem50);
        QTableWidgetItem *__qtablewidgetitem51 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(12, __qtablewidgetitem51);
        QTableWidgetItem *__qtablewidgetitem52 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(13, __qtablewidgetitem52);
        QTableWidgetItem *__qtablewidgetitem53 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(14, __qtablewidgetitem53);
        QTableWidgetItem *__qtablewidgetitem54 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(15, __qtablewidgetitem54);
        QTableWidgetItem *__qtablewidgetitem55 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(16, __qtablewidgetitem55);
        QTableWidgetItem *__qtablewidgetitem56 = new QTableWidgetItem();
        UserPm_3->setVerticalHeaderItem(17, __qtablewidgetitem56);
        UserPm_3->setObjectName(QString::fromUtf8("UserPm_3"));
        UserPm_3->setGeometry(QRect(300, 50, 161, 571));
        UserPm_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        UserPm_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        label_4 = new QLabel(ThrowPkm);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(560, 20, 61, 20));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_4->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(ThrowPkm);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(350, 20, 61, 20));
        label_5->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_5->setAlignment(Qt::AlignCenter);
        label_6 = new QLabel(ThrowPkm);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(140, 20, 61, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_6->setAlignment(Qt::AlignCenter);

        retranslateUi(ThrowPkm);

        QMetaObject::connectSlotsByName(ThrowPkm);
    } // setupUi

    void retranslateUi(QWidget *ThrowPkm)
    {
        ThrowPkm->setWindowTitle(QApplication::translate("ThrowPkm", "ThrowPkm", nullptr));
        pushButton_3->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
        pushButton->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
        pushButton_2->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
        QTableWidgetItem *___qtablewidgetitem = UserPm_1->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = UserPm_1->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ThrowPkm", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = UserPm_1->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = UserPm_1->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = UserPm_1->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = UserPm_1->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ThrowPkm", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = UserPm_1->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ThrowPkm", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = UserPm_1->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = UserPm_1->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = UserPm_1->verticalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = UserPm_1->verticalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = UserPm_1->verticalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = UserPm_1->verticalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = UserPm_1->verticalHeaderItem(13);
        ___qtablewidgetitem13->setText(QApplication::translate("ThrowPkm", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = UserPm_1->verticalHeaderItem(14);
        ___qtablewidgetitem14->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = UserPm_1->verticalHeaderItem(15);
        ___qtablewidgetitem15->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = UserPm_1->verticalHeaderItem(16);
        ___qtablewidgetitem16->setText(QApplication::translate("ThrowPkm", "Skill3", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = UserPm_1->verticalHeaderItem(17);
        ___qtablewidgetitem17->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = UserPm_2->verticalHeaderItem(0);
        ___qtablewidgetitem18->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = UserPm_2->verticalHeaderItem(1);
        ___qtablewidgetitem19->setText(QApplication::translate("ThrowPkm", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = UserPm_2->verticalHeaderItem(2);
        ___qtablewidgetitem20->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = UserPm_2->verticalHeaderItem(3);
        ___qtablewidgetitem21->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = UserPm_2->verticalHeaderItem(4);
        ___qtablewidgetitem22->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = UserPm_2->verticalHeaderItem(5);
        ___qtablewidgetitem23->setText(QApplication::translate("ThrowPkm", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = UserPm_2->verticalHeaderItem(6);
        ___qtablewidgetitem24->setText(QApplication::translate("ThrowPkm", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = UserPm_2->verticalHeaderItem(7);
        ___qtablewidgetitem25->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = UserPm_2->verticalHeaderItem(8);
        ___qtablewidgetitem26->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = UserPm_2->verticalHeaderItem(9);
        ___qtablewidgetitem27->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = UserPm_2->verticalHeaderItem(10);
        ___qtablewidgetitem28->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = UserPm_2->verticalHeaderItem(11);
        ___qtablewidgetitem29->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = UserPm_2->verticalHeaderItem(12);
        ___qtablewidgetitem30->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = UserPm_2->verticalHeaderItem(13);
        ___qtablewidgetitem31->setText(QApplication::translate("ThrowPkm", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = UserPm_2->verticalHeaderItem(14);
        ___qtablewidgetitem32->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = UserPm_2->verticalHeaderItem(15);
        ___qtablewidgetitem33->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = UserPm_2->verticalHeaderItem(16);
        ___qtablewidgetitem34->setText(QApplication::translate("ThrowPkm", "Skill3", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = UserPm_2->verticalHeaderItem(17);
        ___qtablewidgetitem35->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = UserPm_3->verticalHeaderItem(0);
        ___qtablewidgetitem36->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = UserPm_3->verticalHeaderItem(1);
        ___qtablewidgetitem37->setText(QApplication::translate("ThrowPkm", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = UserPm_3->verticalHeaderItem(2);
        ___qtablewidgetitem38->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = UserPm_3->verticalHeaderItem(3);
        ___qtablewidgetitem39->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = UserPm_3->verticalHeaderItem(4);
        ___qtablewidgetitem40->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = UserPm_3->verticalHeaderItem(5);
        ___qtablewidgetitem41->setText(QApplication::translate("ThrowPkm", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = UserPm_3->verticalHeaderItem(6);
        ___qtablewidgetitem42->setText(QApplication::translate("ThrowPkm", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = UserPm_3->verticalHeaderItem(7);
        ___qtablewidgetitem43->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = UserPm_3->verticalHeaderItem(8);
        ___qtablewidgetitem44->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = UserPm_3->verticalHeaderItem(9);
        ___qtablewidgetitem45->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = UserPm_3->verticalHeaderItem(10);
        ___qtablewidgetitem46->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = UserPm_3->verticalHeaderItem(11);
        ___qtablewidgetitem47->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem48 = UserPm_3->verticalHeaderItem(12);
        ___qtablewidgetitem48->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem49 = UserPm_3->verticalHeaderItem(13);
        ___qtablewidgetitem49->setText(QApplication::translate("ThrowPkm", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem50 = UserPm_3->verticalHeaderItem(14);
        ___qtablewidgetitem50->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem51 = UserPm_3->verticalHeaderItem(15);
        ___qtablewidgetitem51->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem52 = UserPm_3->verticalHeaderItem(16);
        ___qtablewidgetitem52->setText(QApplication::translate("ThrowPkm", "Skill3", nullptr));
        QTableWidgetItem *___qtablewidgetitem53 = UserPm_3->verticalHeaderItem(17);
        ___qtablewidgetitem53->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        label_4->setText(QApplication::translate("ThrowPkm", "Pokemon", nullptr));
        label_5->setText(QApplication::translate("ThrowPkm", "Pokemon", nullptr));
        label_6->setText(QApplication::translate("ThrowPkm", "Pokemon", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThrowPkm: public Ui_ThrowPkm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THROWPKM_H
