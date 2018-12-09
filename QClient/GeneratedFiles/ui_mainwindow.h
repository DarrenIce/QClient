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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QListWidget *PMList;
    QWidget *formLayoutWidget;
    QFormLayout *UserOp;
    QLabel *Name;
    QLabel *name;
    QLabel *Id;
    QLabel *id;
    QLabel *Nicky;
    QLabel *nicky;
    QLabel *Grade;
    QLabel *grade;
    QLabel *Exp;
    QLabel *exp;
    QLabel *Nature;
    QLabel *nature;
    QLabel *Property;
    QLabel *property;
    QLabel *Hp;
    QLabel *hp;
    QLabel *Atk;
    QLabel *atk;
    QLabel *Sat;
    QLabel *sat;
    QLabel *Def;
    QLabel *def;
    QLabel *Sdf;
    QLabel *sdf;
    QLabel *Spe;
    QLabel *spe;
    QLabel *SkillNum;
    QLabel *skillnum;
    QLabel *SkillBar1;
    QLabel *skillbar1;
    QLabel *SkillBar2;
    QLabel *SkillBar3;
    QLabel *SkillBar4;
    QLabel *skillbar2;
    QLabel *skillbar3;
    QLabel *skillbar4;
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
    QWidget *formLayoutWidget_2;
    QFormLayout *PmOp;
    QLabel *Name2;
    QLabel *name2;
    QLabel *Nature2;
    QLabel *nature2;
    QLabel *Property2;
    QLabel *property2;
    QLabel *Hp2;
    QLabel *hp2;
    QLabel *Atk2;
    QLabel *Sat2;
    QLabel *sat2;
    QLabel *Def2;
    QLabel *def2;
    QLabel *Sdf2;
    QLabel *sdf2;
    QLabel *Spe2;
    QLabel *spe2;
    QLabel *SkillBar2_1;
    QLabel *skillbar2_1;
    QLabel *SkillBar2_2;
    QLabel *skillbar2_2;
    QLabel *SkillBar2_3;
    QLabel *skillbar2_3;
    QLabel *SkillBar2_4;
    QLabel *skillbar2_4;
    QLabel *atk2;
    QPushButton *CreatePm;
    QLabel *Ppic;
    QLabel *PMpic;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout;
    QLabel *UserName;
    QLabel *username;
    QLabel *WinNum;
    QLabel *winnum;
    QLabel *LossNum;
    QLabel *lossnum;
    QLabel *WinRate;
    QLabel *winrate;
    QLabel *PMNum;
    QLabel *pmnum;
    QLabel *FullLevel;
    QLabel *fulllevel;
    QLabel *AchiNum;
    QLabel *achinum;
    QLabel *Titel1;
    QLabel *titel1;
    QLabel *Titel2;
    QLabel *titel2;
    QLabel *Titel3;
    QLabel *titel3;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(994, 713);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        PMList = new QListWidget(centralWidget);
        PMList->setObjectName(QString::fromUtf8("PMList"));
        PMList->setGeometry(QRect(230, 0, 161, 271));
        formLayoutWidget = new QWidget(centralWidget);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 280, 161, 356));
        UserOp = new QFormLayout(formLayoutWidget);
        UserOp->setSpacing(6);
        UserOp->setContentsMargins(11, 11, 11, 11);
        UserOp->setObjectName(QString::fromUtf8("UserOp"));
        UserOp->setContentsMargins(0, 0, 0, 0);
        Name = new QLabel(formLayoutWidget);
        Name->setObjectName(QString::fromUtf8("Name"));

        UserOp->setWidget(0, QFormLayout::LabelRole, Name);

        name = new QLabel(formLayoutWidget);
        name->setObjectName(QString::fromUtf8("name"));

        UserOp->setWidget(0, QFormLayout::FieldRole, name);

        Id = new QLabel(formLayoutWidget);
        Id->setObjectName(QString::fromUtf8("Id"));

        UserOp->setWidget(1, QFormLayout::LabelRole, Id);

        id = new QLabel(formLayoutWidget);
        id->setObjectName(QString::fromUtf8("id"));

        UserOp->setWidget(1, QFormLayout::FieldRole, id);

        Nicky = new QLabel(formLayoutWidget);
        Nicky->setObjectName(QString::fromUtf8("Nicky"));

        UserOp->setWidget(2, QFormLayout::LabelRole, Nicky);

        nicky = new QLabel(formLayoutWidget);
        nicky->setObjectName(QString::fromUtf8("nicky"));

        UserOp->setWidget(2, QFormLayout::FieldRole, nicky);

        Grade = new QLabel(formLayoutWidget);
        Grade->setObjectName(QString::fromUtf8("Grade"));

        UserOp->setWidget(3, QFormLayout::LabelRole, Grade);

        grade = new QLabel(formLayoutWidget);
        grade->setObjectName(QString::fromUtf8("grade"));

        UserOp->setWidget(3, QFormLayout::FieldRole, grade);

        Exp = new QLabel(formLayoutWidget);
        Exp->setObjectName(QString::fromUtf8("Exp"));

        UserOp->setWidget(4, QFormLayout::LabelRole, Exp);

        exp = new QLabel(formLayoutWidget);
        exp->setObjectName(QString::fromUtf8("exp"));

        UserOp->setWidget(4, QFormLayout::FieldRole, exp);

        Nature = new QLabel(formLayoutWidget);
        Nature->setObjectName(QString::fromUtf8("Nature"));

        UserOp->setWidget(5, QFormLayout::LabelRole, Nature);

        nature = new QLabel(formLayoutWidget);
        nature->setObjectName(QString::fromUtf8("nature"));

        UserOp->setWidget(5, QFormLayout::FieldRole, nature);

        Property = new QLabel(formLayoutWidget);
        Property->setObjectName(QString::fromUtf8("Property"));

        UserOp->setWidget(6, QFormLayout::LabelRole, Property);

        property = new QLabel(formLayoutWidget);
        property->setObjectName(QString::fromUtf8("property"));

        UserOp->setWidget(6, QFormLayout::FieldRole, property);

        Hp = new QLabel(formLayoutWidget);
        Hp->setObjectName(QString::fromUtf8("Hp"));

        UserOp->setWidget(7, QFormLayout::LabelRole, Hp);

        hp = new QLabel(formLayoutWidget);
        hp->setObjectName(QString::fromUtf8("hp"));

        UserOp->setWidget(7, QFormLayout::FieldRole, hp);

        Atk = new QLabel(formLayoutWidget);
        Atk->setObjectName(QString::fromUtf8("Atk"));

        UserOp->setWidget(8, QFormLayout::LabelRole, Atk);

        atk = new QLabel(formLayoutWidget);
        atk->setObjectName(QString::fromUtf8("atk"));

        UserOp->setWidget(8, QFormLayout::FieldRole, atk);

        Sat = new QLabel(formLayoutWidget);
        Sat->setObjectName(QString::fromUtf8("Sat"));

        UserOp->setWidget(9, QFormLayout::LabelRole, Sat);

        sat = new QLabel(formLayoutWidget);
        sat->setObjectName(QString::fromUtf8("sat"));

        UserOp->setWidget(9, QFormLayout::FieldRole, sat);

        Def = new QLabel(formLayoutWidget);
        Def->setObjectName(QString::fromUtf8("Def"));

        UserOp->setWidget(10, QFormLayout::LabelRole, Def);

        def = new QLabel(formLayoutWidget);
        def->setObjectName(QString::fromUtf8("def"));

        UserOp->setWidget(10, QFormLayout::FieldRole, def);

        Sdf = new QLabel(formLayoutWidget);
        Sdf->setObjectName(QString::fromUtf8("Sdf"));

        UserOp->setWidget(11, QFormLayout::LabelRole, Sdf);

        sdf = new QLabel(formLayoutWidget);
        sdf->setObjectName(QString::fromUtf8("sdf"));

        UserOp->setWidget(11, QFormLayout::FieldRole, sdf);

        Spe = new QLabel(formLayoutWidget);
        Spe->setObjectName(QString::fromUtf8("Spe"));

        UserOp->setWidget(12, QFormLayout::LabelRole, Spe);

        spe = new QLabel(formLayoutWidget);
        spe->setObjectName(QString::fromUtf8("spe"));

        UserOp->setWidget(12, QFormLayout::FieldRole, spe);

        SkillNum = new QLabel(formLayoutWidget);
        SkillNum->setObjectName(QString::fromUtf8("SkillNum"));

        UserOp->setWidget(13, QFormLayout::LabelRole, SkillNum);

        skillnum = new QLabel(formLayoutWidget);
        skillnum->setObjectName(QString::fromUtf8("skillnum"));

        UserOp->setWidget(13, QFormLayout::FieldRole, skillnum);

        SkillBar1 = new QLabel(formLayoutWidget);
        SkillBar1->setObjectName(QString::fromUtf8("SkillBar1"));

        UserOp->setWidget(14, QFormLayout::LabelRole, SkillBar1);

        skillbar1 = new QLabel(formLayoutWidget);
        skillbar1->setObjectName(QString::fromUtf8("skillbar1"));

        UserOp->setWidget(14, QFormLayout::FieldRole, skillbar1);

        SkillBar2 = new QLabel(formLayoutWidget);
        SkillBar2->setObjectName(QString::fromUtf8("SkillBar2"));

        UserOp->setWidget(15, QFormLayout::LabelRole, SkillBar2);

        SkillBar3 = new QLabel(formLayoutWidget);
        SkillBar3->setObjectName(QString::fromUtf8("SkillBar3"));

        UserOp->setWidget(16, QFormLayout::LabelRole, SkillBar3);

        SkillBar4 = new QLabel(formLayoutWidget);
        SkillBar4->setObjectName(QString::fromUtf8("SkillBar4"));

        UserOp->setWidget(17, QFormLayout::LabelRole, SkillBar4);

        skillbar2 = new QLabel(formLayoutWidget);
        skillbar2->setObjectName(QString::fromUtf8("skillbar2"));

        UserOp->setWidget(15, QFormLayout::FieldRole, skillbar2);

        skillbar3 = new QLabel(formLayoutWidget);
        skillbar3->setObjectName(QString::fromUtf8("skillbar3"));

        UserOp->setWidget(16, QFormLayout::FieldRole, skillbar3);

        skillbar4 = new QLabel(formLayoutWidget);
        skillbar4->setObjectName(QString::fromUtf8("skillbar4"));

        UserOp->setWidget(17, QFormLayout::FieldRole, skillbar4);

        UpgradeMatch = new QPushButton(centralWidget);
        UpgradeMatch->setObjectName(QString::fromUtf8("UpgradeMatch"));
        UpgradeMatch->setGeometry(QRect(720, 190, 91, 23));
        DuelMatch = new QPushButton(centralWidget);
        DuelMatch->setObjectName(QString::fromUtf8("DuelMatch"));
        DuelMatch->setGeometry(QRect(720, 220, 91, 23));
        UserHp = new QProgressBar(centralWidget);
        UserHp->setObjectName(QString::fromUtf8("UserHp"));
        UserHp->setGeometry(QRect(180, 280, 251, 20));
        UserHp->setValue(100);
        PmHp = new QProgressBar(centralWidget);
        PmHp->setObjectName(QString::fromUtf8("PmHp"));
        PmHp->setGeometry(QRect(540, 280, 251, 23));
        PmHp->setValue(100);
        Skill1 = new QPushButton(centralWidget);
        Skill1->setObjectName(QString::fromUtf8("Skill1"));
        Skill1->setGeometry(QRect(300, 550, 75, 23));
        Skill2 = new QPushButton(centralWidget);
        Skill2->setObjectName(QString::fromUtf8("Skill2"));
        Skill2->setGeometry(QRect(390, 550, 75, 23));
        Skill3 = new QPushButton(centralWidget);
        Skill3->setObjectName(QString::fromUtf8("Skill3"));
        Skill3->setGeometry(QRect(480, 550, 75, 23));
        Skill4 = new QPushButton(centralWidget);
        Skill4->setObjectName(QString::fromUtf8("Skill4"));
        Skill4->setGeometry(QRect(570, 550, 75, 23));
        IdBox = new QSpinBox(centralWidget);
        IdBox->setObjectName(QString::fromUtf8("IdBox"));
        IdBox->setGeometry(QRect(920, 140, 42, 22));
        IdBox->setMinimum(1);
        IdBox->setMaximum(999);
        PM_ID = new QLabel(centralWidget);
        PM_ID->setObjectName(QString::fromUtf8("PM_ID"));
        PM_ID->setGeometry(QRect(860, 140, 54, 12));
        LevelBox = new QSpinBox(centralWidget);
        LevelBox->setObjectName(QString::fromUtf8("LevelBox"));
        LevelBox->setGeometry(QRect(920, 170, 42, 22));
        LevelBox->setMinimum(1);
        LevelBox->setMaximum(100);
        PM_LEVEL = new QLabel(centralWidget);
        PM_LEVEL->setObjectName(QString::fromUtf8("PM_LEVEL"));
        PM_LEVEL->setGeometry(QRect(860, 170, 54, 12));
        formLayoutWidget_2 = new QWidget(centralWidget);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(810, 270, 178, 256));
        PmOp = new QFormLayout(formLayoutWidget_2);
        PmOp->setSpacing(6);
        PmOp->setContentsMargins(11, 11, 11, 11);
        PmOp->setObjectName(QString::fromUtf8("PmOp"));
        PmOp->setContentsMargins(0, 0, 0, 0);
        Name2 = new QLabel(formLayoutWidget_2);
        Name2->setObjectName(QString::fromUtf8("Name2"));

        PmOp->setWidget(0, QFormLayout::LabelRole, Name2);

        name2 = new QLabel(formLayoutWidget_2);
        name2->setObjectName(QString::fromUtf8("name2"));

        PmOp->setWidget(0, QFormLayout::FieldRole, name2);

        Nature2 = new QLabel(formLayoutWidget_2);
        Nature2->setObjectName(QString::fromUtf8("Nature2"));

        PmOp->setWidget(1, QFormLayout::LabelRole, Nature2);

        nature2 = new QLabel(formLayoutWidget_2);
        nature2->setObjectName(QString::fromUtf8("nature2"));

        PmOp->setWidget(1, QFormLayout::FieldRole, nature2);

        Property2 = new QLabel(formLayoutWidget_2);
        Property2->setObjectName(QString::fromUtf8("Property2"));

        PmOp->setWidget(2, QFormLayout::LabelRole, Property2);

        property2 = new QLabel(formLayoutWidget_2);
        property2->setObjectName(QString::fromUtf8("property2"));

        PmOp->setWidget(2, QFormLayout::FieldRole, property2);

        Hp2 = new QLabel(formLayoutWidget_2);
        Hp2->setObjectName(QString::fromUtf8("Hp2"));

        PmOp->setWidget(3, QFormLayout::LabelRole, Hp2);

        hp2 = new QLabel(formLayoutWidget_2);
        hp2->setObjectName(QString::fromUtf8("hp2"));

        PmOp->setWidget(3, QFormLayout::FieldRole, hp2);

        Atk2 = new QLabel(formLayoutWidget_2);
        Atk2->setObjectName(QString::fromUtf8("Atk2"));

        PmOp->setWidget(4, QFormLayout::LabelRole, Atk2);

        Sat2 = new QLabel(formLayoutWidget_2);
        Sat2->setObjectName(QString::fromUtf8("Sat2"));

        PmOp->setWidget(5, QFormLayout::LabelRole, Sat2);

        sat2 = new QLabel(formLayoutWidget_2);
        sat2->setObjectName(QString::fromUtf8("sat2"));

        PmOp->setWidget(5, QFormLayout::FieldRole, sat2);

        Def2 = new QLabel(formLayoutWidget_2);
        Def2->setObjectName(QString::fromUtf8("Def2"));

        PmOp->setWidget(6, QFormLayout::LabelRole, Def2);

        def2 = new QLabel(formLayoutWidget_2);
        def2->setObjectName(QString::fromUtf8("def2"));

        PmOp->setWidget(6, QFormLayout::FieldRole, def2);

        Sdf2 = new QLabel(formLayoutWidget_2);
        Sdf2->setObjectName(QString::fromUtf8("Sdf2"));

        PmOp->setWidget(7, QFormLayout::LabelRole, Sdf2);

        sdf2 = new QLabel(formLayoutWidget_2);
        sdf2->setObjectName(QString::fromUtf8("sdf2"));

        PmOp->setWidget(7, QFormLayout::FieldRole, sdf2);

        Spe2 = new QLabel(formLayoutWidget_2);
        Spe2->setObjectName(QString::fromUtf8("Spe2"));

        PmOp->setWidget(8, QFormLayout::LabelRole, Spe2);

        spe2 = new QLabel(formLayoutWidget_2);
        spe2->setObjectName(QString::fromUtf8("spe2"));

        PmOp->setWidget(8, QFormLayout::FieldRole, spe2);

        SkillBar2_1 = new QLabel(formLayoutWidget_2);
        SkillBar2_1->setObjectName(QString::fromUtf8("SkillBar2_1"));

        PmOp->setWidget(9, QFormLayout::LabelRole, SkillBar2_1);

        skillbar2_1 = new QLabel(formLayoutWidget_2);
        skillbar2_1->setObjectName(QString::fromUtf8("skillbar2_1"));

        PmOp->setWidget(9, QFormLayout::FieldRole, skillbar2_1);

        SkillBar2_2 = new QLabel(formLayoutWidget_2);
        SkillBar2_2->setObjectName(QString::fromUtf8("SkillBar2_2"));

        PmOp->setWidget(10, QFormLayout::LabelRole, SkillBar2_2);

        skillbar2_2 = new QLabel(formLayoutWidget_2);
        skillbar2_2->setObjectName(QString::fromUtf8("skillbar2_2"));

        PmOp->setWidget(10, QFormLayout::FieldRole, skillbar2_2);

        SkillBar2_3 = new QLabel(formLayoutWidget_2);
        SkillBar2_3->setObjectName(QString::fromUtf8("SkillBar2_3"));

        PmOp->setWidget(11, QFormLayout::LabelRole, SkillBar2_3);

        skillbar2_3 = new QLabel(formLayoutWidget_2);
        skillbar2_3->setObjectName(QString::fromUtf8("skillbar2_3"));

        PmOp->setWidget(11, QFormLayout::FieldRole, skillbar2_3);

        SkillBar2_4 = new QLabel(formLayoutWidget_2);
        SkillBar2_4->setObjectName(QString::fromUtf8("SkillBar2_4"));

        PmOp->setWidget(12, QFormLayout::LabelRole, SkillBar2_4);

        skillbar2_4 = new QLabel(formLayoutWidget_2);
        skillbar2_4->setObjectName(QString::fromUtf8("skillbar2_4"));

        PmOp->setWidget(12, QFormLayout::FieldRole, skillbar2_4);

        atk2 = new QLabel(formLayoutWidget_2);
        atk2->setObjectName(QString::fromUtf8("atk2"));

        PmOp->setWidget(4, QFormLayout::FieldRole, atk2);

        CreatePm = new QPushButton(centralWidget);
        CreatePm->setObjectName(QString::fromUtf8("CreatePm"));
        CreatePm->setGeometry(QRect(890, 210, 75, 23));
        Ppic = new QLabel(centralWidget);
        Ppic->setObjectName(QString::fromUtf8("Ppic"));
        Ppic->setGeometry(QRect(270, 400, 54, 12));
        PMpic = new QLabel(centralWidget);
        PMpic->setObjectName(QString::fromUtf8("PMpic"));
        PMpic->setGeometry(QRect(640, 400, 54, 12));
        formLayoutWidget_3 = new QWidget(centralWidget);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 0, 161, 271));
        formLayout = new QFormLayout(formLayoutWidget_3);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        UserName = new QLabel(formLayoutWidget_3);
        UserName->setObjectName(QString::fromUtf8("UserName"));

        formLayout->setWidget(0, QFormLayout::LabelRole, UserName);

        username = new QLabel(formLayoutWidget_3);
        username->setObjectName(QString::fromUtf8("username"));

        formLayout->setWidget(0, QFormLayout::FieldRole, username);

        WinNum = new QLabel(formLayoutWidget_3);
        WinNum->setObjectName(QString::fromUtf8("WinNum"));

        formLayout->setWidget(1, QFormLayout::LabelRole, WinNum);

        winnum = new QLabel(formLayoutWidget_3);
        winnum->setObjectName(QString::fromUtf8("winnum"));

        formLayout->setWidget(1, QFormLayout::FieldRole, winnum);

        LossNum = new QLabel(formLayoutWidget_3);
        LossNum->setObjectName(QString::fromUtf8("LossNum"));

        formLayout->setWidget(2, QFormLayout::LabelRole, LossNum);

        lossnum = new QLabel(formLayoutWidget_3);
        lossnum->setObjectName(QString::fromUtf8("lossnum"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lossnum);

        WinRate = new QLabel(formLayoutWidget_3);
        WinRate->setObjectName(QString::fromUtf8("WinRate"));

        formLayout->setWidget(3, QFormLayout::LabelRole, WinRate);

        winrate = new QLabel(formLayoutWidget_3);
        winrate->setObjectName(QString::fromUtf8("winrate"));

        formLayout->setWidget(3, QFormLayout::FieldRole, winrate);

        PMNum = new QLabel(formLayoutWidget_3);
        PMNum->setObjectName(QString::fromUtf8("PMNum"));

        formLayout->setWidget(4, QFormLayout::LabelRole, PMNum);

        pmnum = new QLabel(formLayoutWidget_3);
        pmnum->setObjectName(QString::fromUtf8("pmnum"));

        formLayout->setWidget(4, QFormLayout::FieldRole, pmnum);

        FullLevel = new QLabel(formLayoutWidget_3);
        FullLevel->setObjectName(QString::fromUtf8("FullLevel"));

        formLayout->setWidget(5, QFormLayout::LabelRole, FullLevel);

        fulllevel = new QLabel(formLayoutWidget_3);
        fulllevel->setObjectName(QString::fromUtf8("fulllevel"));

        formLayout->setWidget(5, QFormLayout::FieldRole, fulllevel);

        AchiNum = new QLabel(formLayoutWidget_3);
        AchiNum->setObjectName(QString::fromUtf8("AchiNum"));

        formLayout->setWidget(6, QFormLayout::LabelRole, AchiNum);

        achinum = new QLabel(formLayoutWidget_3);
        achinum->setObjectName(QString::fromUtf8("achinum"));

        formLayout->setWidget(6, QFormLayout::FieldRole, achinum);

        Titel1 = new QLabel(formLayoutWidget_3);
        Titel1->setObjectName(QString::fromUtf8("Titel1"));

        formLayout->setWidget(7, QFormLayout::LabelRole, Titel1);

        titel1 = new QLabel(formLayoutWidget_3);
        titel1->setObjectName(QString::fromUtf8("titel1"));

        formLayout->setWidget(7, QFormLayout::FieldRole, titel1);

        Titel2 = new QLabel(formLayoutWidget_3);
        Titel2->setObjectName(QString::fromUtf8("Titel2"));

        formLayout->setWidget(8, QFormLayout::LabelRole, Titel2);

        titel2 = new QLabel(formLayoutWidget_3);
        titel2->setObjectName(QString::fromUtf8("titel2"));

        formLayout->setWidget(8, QFormLayout::FieldRole, titel2);

        Titel3 = new QLabel(formLayoutWidget_3);
        Titel3->setObjectName(QString::fromUtf8("Titel3"));

        formLayout->setWidget(9, QFormLayout::LabelRole, Titel3);

        titel3 = new QLabel(formLayoutWidget_3);
        titel3->setObjectName(QString::fromUtf8("titel3"));

        formLayout->setWidget(9, QFormLayout::FieldRole, titel3);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 994, 23));
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
        Name->setText(QApplication::translate("MainWindow", "Name", nullptr));
        Id->setText(QApplication::translate("MainWindow", "ID", nullptr));
        Nicky->setText(QApplication::translate("MainWindow", "Nicky", nullptr));
        Grade->setText(QApplication::translate("MainWindow", "Grade", nullptr));
        Exp->setText(QApplication::translate("MainWindow", "Exp", nullptr));
        Nature->setText(QApplication::translate("MainWindow", "Nature", nullptr));
        Property->setText(QApplication::translate("MainWindow", "Property", nullptr));
        Hp->setText(QApplication::translate("MainWindow", "Hp", nullptr));
        Atk->setText(QApplication::translate("MainWindow", "Atk", nullptr));
        Sat->setText(QApplication::translate("MainWindow", "Sat", nullptr));
        Def->setText(QApplication::translate("MainWindow", "Def", nullptr));
        Sdf->setText(QApplication::translate("MainWindow", "Sdf", nullptr));
        Spe->setText(QApplication::translate("MainWindow", "Spe", nullptr));
        SkillNum->setText(QApplication::translate("MainWindow", "SkillNum", nullptr));
        SkillBar1->setText(QApplication::translate("MainWindow", "SkillBar1", nullptr));
        SkillBar2->setText(QApplication::translate("MainWindow", "SkillBar2", nullptr));
        SkillBar3->setText(QApplication::translate("MainWindow", "SkillBar3", nullptr));
        SkillBar4->setText(QApplication::translate("MainWindow", "SkillBar4", nullptr));
        UpgradeMatch->setText(QApplication::translate("MainWindow", "Upgrade Match", nullptr));
        DuelMatch->setText(QApplication::translate("MainWindow", "Duel Match", nullptr));
        Skill1->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill2->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill3->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        Skill4->setText(QApplication::translate("MainWindow", "PushButton", nullptr));
        PM_ID->setText(QApplication::translate("MainWindow", "PM Id", nullptr));
        PM_LEVEL->setText(QApplication::translate("MainWindow", "PM Level", nullptr));
        Name2->setText(QApplication::translate("MainWindow", "Name", nullptr));
        Nature2->setText(QApplication::translate("MainWindow", "Nature", nullptr));
        Property2->setText(QApplication::translate("MainWindow", "Property", nullptr));
        Hp2->setText(QApplication::translate("MainWindow", "Hp", nullptr));
        Atk2->setText(QApplication::translate("MainWindow", "Atk", nullptr));
        Sat2->setText(QApplication::translate("MainWindow", "Sat", nullptr));
        Def2->setText(QApplication::translate("MainWindow", "Def", nullptr));
        Sdf2->setText(QApplication::translate("MainWindow", "Sdf", nullptr));
        Spe2->setText(QApplication::translate("MainWindow", "Spe", nullptr));
        SkillBar2_1->setText(QApplication::translate("MainWindow", "SkillBar1", nullptr));
        SkillBar2_2->setText(QApplication::translate("MainWindow", "SkillBar2", nullptr));
        SkillBar2_3->setText(QApplication::translate("MainWindow", "SkillBar3", nullptr));
        SkillBar2_4->setText(QApplication::translate("MainWindow", "SkillBar4", nullptr));
        CreatePm->setText(QApplication::translate("MainWindow", "Create PM", nullptr));
        Ppic->setText(QApplication::translate("MainWindow", "Ppic", nullptr));
        PMpic->setText(QApplication::translate("MainWindow", "PMpic", nullptr));
        UserName->setText(QApplication::translate("MainWindow", "Username", nullptr));
        username->setText(QString());
        WinNum->setText(QApplication::translate("MainWindow", "WinNum", nullptr));
        winnum->setText(QString());
        LossNum->setText(QApplication::translate("MainWindow", "LossNum", nullptr));
        lossnum->setText(QString());
        WinRate->setText(QApplication::translate("MainWindow", "WinRate", nullptr));
        winrate->setText(QString());
        PMNum->setText(QApplication::translate("MainWindow", "PM Num", nullptr));
        pmnum->setText(QString());
        FullLevel->setText(QApplication::translate("MainWindow", "FullLevel", nullptr));
        fulllevel->setText(QString());
        AchiNum->setText(QApplication::translate("MainWindow", "AchiNum", nullptr));
        achinum->setText(QString());
        Titel1->setText(QApplication::translate("MainWindow", "Titel1", nullptr));
        titel1->setText(QString());
        Titel2->setText(QApplication::translate("MainWindow", "Titel2", nullptr));
        titel2->setText(QString());
        Titel3->setText(QApplication::translate("MainWindow", "Titel3", nullptr));
        titel3->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
