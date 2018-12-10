/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *PMList;
    QPushButton *UpgradeMatch;
    QPushButton *DuelMatch;
    QProgressBar *UserHp;
    QProgressBar *PmHp;
    QPushButton *Skill1;
    QPushButton *Skill2;
    QPushButton *Skill3;
    QPushButton *Skill4;
    QSpinBox *IdBox;
    QLabel *PM_ID;
    QSpinBox *LevelBox;
    QLabel *PM_LEVEL;
    QPushButton *CreatePm;
    QLabel *Ppic;
    QLabel *PMpic;
    QTextBrowser *FightInfo;
    QPushButton *StartMatch;
    QPushButton *Exit;
    QTableWidget *UserTable;
    QTableWidget *UserPm;
    QTableWidget *SerPm;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(1129, 873);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PMList = new QListWidget(centralWidget);
        PMList->setObjectName(QString::fromUtf8("PMList"));
        PMList->setGeometry(QRect(190, 0, 161, 261));
        PMList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        UpgradeMatch = new QPushButton(centralWidget);
        UpgradeMatch->setObjectName(QString::fromUtf8("UpgradeMatch"));
        UpgradeMatch->setGeometry(QRect(690, 700, 91, 23));
        UpgradeMatch->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        DuelMatch = new QPushButton(centralWidget);
        DuelMatch->setObjectName(QString::fromUtf8("DuelMatch"));
        DuelMatch->setGeometry(QRect(690, 730, 91, 23));
        DuelMatch->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        UserHp = new QProgressBar(centralWidget);
        UserHp->setObjectName(QString::fromUtf8("UserHp"));
        UserHp->setGeometry(QRect(390, 310, 251, 20));
        UserHp->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"	 color: rgb(255, 255, 255);\n"
" }\n"
" \n"
" QProgressBar::chunk {\n"
"     background-color: rgb(255, 85, 127);\n"
"     width: 20px;\n"
" }\n"
""));
        UserHp->setValue(100);
        UserHp->setInvertedAppearance(false);
        PmHp = new QProgressBar(centralWidget);
        PmHp->setObjectName(QString::fromUtf8("PmHp"));
        PmHp->setGeometry(QRect(660, 310, 251, 21));
        PmHp->setStyleSheet(QString::fromUtf8("QProgressBar {\n"
"     border: 2px solid grey;\n"
"     border-radius: 5px;\n"
"     text-align: center;\n"
"	 color: rgb(255, 255, 255);\n"
" }\n"
" \n"
" QProgressBar::chunk {\n"
"     background-color: rgb(255, 85, 127);\n"
"     width: 20px;\n"
" }"));
        PmHp->setValue(100);
        Skill1 = new QPushButton(centralWidget);
        Skill1->setObjectName(QString::fromUtf8("Skill1"));
        Skill1->setGeometry(QRect(480, 540, 75, 23));
        Skill1->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill2 = new QPushButton(centralWidget);
        Skill2->setObjectName(QString::fromUtf8("Skill2"));
        Skill2->setGeometry(QRect(570, 540, 75, 23));
        Skill2->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill3 = new QPushButton(centralWidget);
        Skill3->setObjectName(QString::fromUtf8("Skill3"));
        Skill3->setGeometry(QRect(660, 540, 75, 23));
        Skill3->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill4 = new QPushButton(centralWidget);
        Skill4->setObjectName(QString::fromUtf8("Skill4"));
        Skill4->setGeometry(QRect(750, 540, 75, 23));
        Skill4->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        IdBox = new QSpinBox(centralWidget);
        IdBox->setObjectName(QString::fromUtf8("IdBox"));
        IdBox->setGeometry(QRect(890, 660, 42, 22));
        IdBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        IdBox->setMinimum(1);
        IdBox->setMaximum(999);
        PM_ID = new QLabel(centralWidget);
        PM_ID->setObjectName(QString::fromUtf8("PM_ID"));
        PM_ID->setGeometry(QRect(830, 660, 54, 12));
        LevelBox = new QSpinBox(centralWidget);
        LevelBox->setObjectName(QString::fromUtf8("LevelBox"));
        LevelBox->setGeometry(QRect(890, 690, 42, 22));
        LevelBox->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        LevelBox->setMinimum(1);
        LevelBox->setMaximum(100);
        PM_LEVEL = new QLabel(centralWidget);
        PM_LEVEL->setObjectName(QString::fromUtf8("PM_LEVEL"));
        PM_LEVEL->setGeometry(QRect(830, 690, 54, 12));
        CreatePm = new QPushButton(centralWidget);
        CreatePm->setObjectName(QString::fromUtf8("CreatePm"));
        CreatePm->setGeometry(QRect(860, 730, 75, 23));
        CreatePm->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Ppic = new QLabel(centralWidget);
        Ppic->setObjectName(QString::fromUtf8("Ppic"));
        Ppic->setGeometry(QRect(500, 400, 54, 12));
        PMpic = new QLabel(centralWidget);
        PMpic->setObjectName(QString::fromUtf8("PMpic"));
        PMpic->setGeometry(QRect(770, 410, 54, 12));
        FightInfo = new QTextBrowser(centralWidget);
        FightInfo->setObjectName(QString::fromUtf8("FightInfo"));
        FightInfo->setGeometry(QRect(370, 0, 731, 261));
        StartMatch = new QPushButton(centralWidget);
        StartMatch->setObjectName(QString::fromUtf8("StartMatch"));
        StartMatch->setEnabled(false);
        StartMatch->setGeometry(QRect(590, 720, 75, 23));
        StartMatch->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Exit = new QPushButton(centralWidget);
        Exit->setObjectName(QString::fromUtf8("Exit"));
        Exit->setGeometry(QRect(10, 780, 75, 23));
        Exit->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        UserTable = new QTableWidget(centralWidget);
        if (UserTable->columnCount() < 1)
            UserTable->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        UserTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (UserTable->rowCount() < 9)
            UserTable->setRowCount(9);
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
        UserTable->setObjectName(QString::fromUtf8("UserTable"));
        UserTable->setEnabled(true);
        UserTable->setGeometry(QRect(10, 10, 171, 301));
        UserTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        UserPm = new QTableWidget(centralWidget);
        if (UserPm->columnCount() < 1)
            UserPm->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        UserPm->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        if (UserPm->rowCount() < 17)
            UserPm->setRowCount(17);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(5, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(6, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(7, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(8, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(9, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(10, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(11, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(12, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(13, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(14, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(15, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        UserPm->setVerticalHeaderItem(16, __qtablewidgetitem27);
        UserPm->setObjectName(QString::fromUtf8("UserPm"));
        UserPm->setGeometry(QRect(190, 270, 161, 541));
        UserPm->setEditTriggers(QAbstractItemView::NoEditTriggers);
        SerPm = new QTableWidget(centralWidget);
        if (SerPm->columnCount() < 1)
            SerPm->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        SerPm->setHorizontalHeaderItem(0, __qtablewidgetitem28);
        if (SerPm->rowCount() < 17)
            SerPm->setRowCount(17);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(0, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(1, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(2, __qtablewidgetitem31);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(3, __qtablewidgetitem32);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(4, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(5, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(6, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(7, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(8, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(9, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(10, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(11, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(12, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(13, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(14, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(15, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        SerPm->setVerticalHeaderItem(16, __qtablewidgetitem45);
        SerPm->setObjectName(QString::fromUtf8("SerPm"));
        SerPm->setGeometry(QRect(940, 270, 161, 541));
        SerPm->setEditTriggers(QAbstractItemView::NoEditTriggers);
        MainWindow->setCentralWidget(centralWidget);
        UserPm->raise();
        PMList->raise();
        UpgradeMatch->raise();
        DuelMatch->raise();
        UserHp->raise();
        PmHp->raise();
        Skill1->raise();
        Skill2->raise();
        Skill3->raise();
        Skill4->raise();
        IdBox->raise();
        PM_ID->raise();
        LevelBox->raise();
        PM_LEVEL->raise();
        CreatePm->raise();
        Ppic->raise();
        PMpic->raise();
        FightInfo->raise();
        StartMatch->raise();
        Exit->raise();
        UserTable->raise();
        SerPm->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1129, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        UpgradeMatch->setText(QApplication::translate("MainWindow", "Upgrade Match", nullptr));
        DuelMatch->setText(QApplication::translate("MainWindow", "Duel Match", nullptr));
        Skill1->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill4->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        PM_ID->setText(QApplication::translate("MainWindow", "PM Id", nullptr));
        PM_LEVEL->setText(QApplication::translate("MainWindow", "PM Level", nullptr));
        CreatePm->setText(QApplication::translate("MainWindow", "Create PM", nullptr));
        Ppic->setText(QApplication::translate("MainWindow", "Ppic", nullptr));
        PMpic->setText(QApplication::translate("MainWindow", "PMpic", nullptr));
        StartMatch->setText(QApplication::translate("MainWindow", "StartMatch", nullptr));
        Exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        QTableWidgetItem *___qtablewidgetitem = UserTable->verticalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Username", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = UserTable->verticalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "WinNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = UserTable->verticalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "LossNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = UserTable->verticalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "WinRate", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = UserTable->verticalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "PM Num", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = UserTable->verticalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "FullLevel", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = UserTable->verticalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "AchiNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = UserTable->verticalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Title1", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = UserTable->verticalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Title3", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = UserPm->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = UserPm->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = UserPm->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = UserPm->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = UserPm->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = UserPm->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = UserPm->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = UserPm->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = UserPm->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = UserPm->verticalHeaderItem(9);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = UserPm->verticalHeaderItem(10);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = UserPm->verticalHeaderItem(11);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = UserPm->verticalHeaderItem(12);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = UserPm->verticalHeaderItem(13);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = UserPm->verticalHeaderItem(14);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = UserPm->verticalHeaderItem(15);
        ___qtablewidgetitem24->setText(QApplication::translate("MainWindow", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = UserPm->verticalHeaderItem(16);
        ___qtablewidgetitem25->setText(QApplication::translate("MainWindow", "Skill4", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = SerPm->verticalHeaderItem(0);
        ___qtablewidgetitem26->setText(QApplication::translate("MainWindow", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = SerPm->verticalHeaderItem(1);
        ___qtablewidgetitem27->setText(QApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = SerPm->verticalHeaderItem(2);
        ___qtablewidgetitem28->setText(QApplication::translate("MainWindow", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = SerPm->verticalHeaderItem(3);
        ___qtablewidgetitem29->setText(QApplication::translate("MainWindow", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = SerPm->verticalHeaderItem(4);
        ___qtablewidgetitem30->setText(QApplication::translate("MainWindow", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = SerPm->verticalHeaderItem(5);
        ___qtablewidgetitem31->setText(QApplication::translate("MainWindow", "Nature", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = SerPm->verticalHeaderItem(6);
        ___qtablewidgetitem32->setText(QApplication::translate("MainWindow", "Property", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = SerPm->verticalHeaderItem(7);
        ___qtablewidgetitem33->setText(QApplication::translate("MainWindow", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = SerPm->verticalHeaderItem(8);
        ___qtablewidgetitem34->setText(QApplication::translate("MainWindow", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = SerPm->verticalHeaderItem(9);
        ___qtablewidgetitem35->setText(QApplication::translate("MainWindow", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = SerPm->verticalHeaderItem(10);
        ___qtablewidgetitem36->setText(QApplication::translate("MainWindow", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = SerPm->verticalHeaderItem(11);
        ___qtablewidgetitem37->setText(QApplication::translate("MainWindow", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = SerPm->verticalHeaderItem(12);
        ___qtablewidgetitem38->setText(QApplication::translate("MainWindow", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = SerPm->verticalHeaderItem(13);
        ___qtablewidgetitem39->setText(QApplication::translate("MainWindow", "SkillNum", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = SerPm->verticalHeaderItem(14);
        ___qtablewidgetitem40->setText(QApplication::translate("MainWindow", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = SerPm->verticalHeaderItem(15);
        ___qtablewidgetitem41->setText(QApplication::translate("MainWindow", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = SerPm->verticalHeaderItem(16);
        ___qtablewidgetitem42->setText(QApplication::translate("MainWindow", "Skill4", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
