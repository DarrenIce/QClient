/********************************************************************************
** Form generated from reading UI file 'skillreplace.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKILLREPLACE_H
#define UI_SKILLREPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SkillReplace
{
public:
    QPushButton *Skill1;
    QPushButton *Skill2;
    QPushButton *Skill3;
    QPushButton *Skill4;
    QLabel *label_6;
    QListWidget *Skills;

    void setupUi(QWidget *SkillReplace)
    {
        if (SkillReplace->objectName().isEmpty())
            SkillReplace->setObjectName(QString::fromUtf8("SkillReplace"));
        SkillReplace->resize(274, 388);
        Skill1 = new QPushButton(SkillReplace);
        Skill1->setObjectName(QString::fromUtf8("Skill1"));
        Skill1->setGeometry(QRect(190, 60, 75, 23));
        Skill1->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill2 = new QPushButton(SkillReplace);
        Skill2->setObjectName(QString::fromUtf8("Skill2"));
        Skill2->setGeometry(QRect(190, 100, 75, 23));
        Skill2->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill3 = new QPushButton(SkillReplace);
        Skill3->setObjectName(QString::fromUtf8("Skill3"));
        Skill3->setGeometry(QRect(190, 140, 75, 23));
        Skill3->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        Skill4 = new QPushButton(SkillReplace);
        Skill4->setObjectName(QString::fromUtf8("Skill4"));
        Skill4->setGeometry(QRect(190, 180, 75, 23));
        Skill4->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        label_6 = new QLabel(SkillReplace);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(50, 10, 81, 20));
        label_6->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 127);\n"
"	border: 2px solid green;\n"
"    border-radius: 4px;"));
        label_6->setAlignment(Qt::AlignCenter);
        Skills = new QListWidget(SkillReplace);
        Skills->setObjectName(QString::fromUtf8("Skills"));
        Skills->setGeometry(QRect(10, 40, 161, 331));

        retranslateUi(SkillReplace);

        QMetaObject::connectSlotsByName(SkillReplace);
    } // setupUi

    void retranslateUi(QWidget *SkillReplace)
    {
        SkillReplace->setWindowTitle(QApplication::translate("SkillReplace", "SkillReplace", nullptr));
        Skill1->setText(QApplication::translate("SkillReplace", "PushButton", nullptr));
        Skill2->setText(QApplication::translate("SkillReplace", "PushButton", nullptr));
        Skill3->setText(QApplication::translate("SkillReplace", "PushButton", nullptr));
        Skill4->setText(QApplication::translate("SkillReplace", "PushButton", nullptr));
        label_6->setText(QApplication::translate("SkillReplace", "Skill List", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SkillReplace: public Ui_SkillReplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKILLREPLACE_H
