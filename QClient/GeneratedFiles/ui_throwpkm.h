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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ThrowPkm
{
public:
    QPushButton *pushButton_3;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_3;
    QPushButton *pushButton;
    QTableWidget *tableWidget_2;
    QPushButton *pushButton_2;

    void setupUi(QWidget *ThrowPkm)
    {
        if (ThrowPkm->objectName().isEmpty())
            ThrowPkm->setObjectName(QString::fromUtf8("ThrowPkm"));
        ThrowPkm->resize(752, 607);
        pushButton_3 = new QPushButton(ThrowPkm);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(550, 550, 75, 23));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        tableWidget = new QTableWidget(ThrowPkm);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem15);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(90, 40, 151, 481));
        tableWidget_3 = new QTableWidget(ThrowPkm);
        if (tableWidget_3->columnCount() < 1)
            tableWidget_3->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_3->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        if (tableWidget_3->rowCount() < 15)
            tableWidget_3->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(1, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(2, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(3, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(4, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(5, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(6, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(7, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(8, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(9, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(10, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(11, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(12, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(13, __qtablewidgetitem30);
        QTableWidgetItem *__qtablewidgetitem31 = new QTableWidgetItem();
        tableWidget_3->setVerticalHeaderItem(14, __qtablewidgetitem31);
        tableWidget_3->setObjectName(QString::fromUtf8("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(510, 40, 151, 481));
        pushButton = new QPushButton(ThrowPkm);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(130, 550, 81, 21));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));
        tableWidget_2 = new QTableWidget(ThrowPkm);
        if (tableWidget_2->columnCount() < 1)
            tableWidget_2->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem32 = new QTableWidgetItem();
        tableWidget_2->setHorizontalHeaderItem(0, __qtablewidgetitem32);
        if (tableWidget_2->rowCount() < 15)
            tableWidget_2->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem33 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(0, __qtablewidgetitem33);
        QTableWidgetItem *__qtablewidgetitem34 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(1, __qtablewidgetitem34);
        QTableWidgetItem *__qtablewidgetitem35 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(2, __qtablewidgetitem35);
        QTableWidgetItem *__qtablewidgetitem36 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(3, __qtablewidgetitem36);
        QTableWidgetItem *__qtablewidgetitem37 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(4, __qtablewidgetitem37);
        QTableWidgetItem *__qtablewidgetitem38 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(5, __qtablewidgetitem38);
        QTableWidgetItem *__qtablewidgetitem39 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(6, __qtablewidgetitem39);
        QTableWidgetItem *__qtablewidgetitem40 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(7, __qtablewidgetitem40);
        QTableWidgetItem *__qtablewidgetitem41 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(8, __qtablewidgetitem41);
        QTableWidgetItem *__qtablewidgetitem42 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(9, __qtablewidgetitem42);
        QTableWidgetItem *__qtablewidgetitem43 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(10, __qtablewidgetitem43);
        QTableWidgetItem *__qtablewidgetitem44 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(11, __qtablewidgetitem44);
        QTableWidgetItem *__qtablewidgetitem45 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(12, __qtablewidgetitem45);
        QTableWidgetItem *__qtablewidgetitem46 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(13, __qtablewidgetitem46);
        QTableWidgetItem *__qtablewidgetitem47 = new QTableWidgetItem();
        tableWidget_2->setVerticalHeaderItem(14, __qtablewidgetitem47);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(300, 40, 151, 481));
        pushButton_2 = new QPushButton(ThrowPkm);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(340, 550, 75, 23));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton{border: 2px solid grey;\n"
"	background:rgb(131, 197, 197);\n"
"	border-radius: 8px;}\n"
"QPushButton:hover{border-color:rgb(183,203,188);}\n"
"QPushButton:pressed{border-color:gray}"));

        retranslateUi(ThrowPkm);

        QMetaObject::connectSlotsByName(ThrowPkm);
    } // setupUi

    void retranslateUi(QWidget *ThrowPkm)
    {
        ThrowPkm->setWindowTitle(QApplication::translate("ThrowPkm", "ThrowPkm", nullptr));
        pushButton_3->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ThrowPkm", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem2->setText(QApplication::translate("ThrowPkm", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem3->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem4->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem5->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem6->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem7->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem8->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem9->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem10->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem11->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem12->setText(QApplication::translate("ThrowPkm", "Skills", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem13->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem14->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem15->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_3->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QApplication::translate("ThrowPkm", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_3->verticalHeaderItem(0);
        ___qtablewidgetitem17->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_3->verticalHeaderItem(1);
        ___qtablewidgetitem18->setText(QApplication::translate("ThrowPkm", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_3->verticalHeaderItem(2);
        ___qtablewidgetitem19->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget_3->verticalHeaderItem(3);
        ___qtablewidgetitem20->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget_3->verticalHeaderItem(4);
        ___qtablewidgetitem21->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget_3->verticalHeaderItem(5);
        ___qtablewidgetitem22->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget_3->verticalHeaderItem(6);
        ___qtablewidgetitem23->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableWidget_3->verticalHeaderItem(7);
        ___qtablewidgetitem24->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableWidget_3->verticalHeaderItem(8);
        ___qtablewidgetitem25->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableWidget_3->verticalHeaderItem(9);
        ___qtablewidgetitem26->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableWidget_3->verticalHeaderItem(10);
        ___qtablewidgetitem27->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableWidget_3->verticalHeaderItem(11);
        ___qtablewidgetitem28->setText(QApplication::translate("ThrowPkm", "Skills", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableWidget_3->verticalHeaderItem(12);
        ___qtablewidgetitem29->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableWidget_3->verticalHeaderItem(13);
        ___qtablewidgetitem30->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem31 = tableWidget_3->verticalHeaderItem(14);
        ___qtablewidgetitem31->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        pushButton->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
        QTableWidgetItem *___qtablewidgetitem32 = tableWidget_2->horizontalHeaderItem(0);
        ___qtablewidgetitem32->setText(QApplication::translate("ThrowPkm", "Data", nullptr));
        QTableWidgetItem *___qtablewidgetitem33 = tableWidget_2->verticalHeaderItem(0);
        ___qtablewidgetitem33->setText(QApplication::translate("ThrowPkm", "Name", nullptr));
        QTableWidgetItem *___qtablewidgetitem34 = tableWidget_2->verticalHeaderItem(1);
        ___qtablewidgetitem34->setText(QApplication::translate("ThrowPkm", "Id", nullptr));
        QTableWidgetItem *___qtablewidgetitem35 = tableWidget_2->verticalHeaderItem(2);
        ___qtablewidgetitem35->setText(QApplication::translate("ThrowPkm", "Nicky", nullptr));
        QTableWidgetItem *___qtablewidgetitem36 = tableWidget_2->verticalHeaderItem(3);
        ___qtablewidgetitem36->setText(QApplication::translate("ThrowPkm", "Grade", nullptr));
        QTableWidgetItem *___qtablewidgetitem37 = tableWidget_2->verticalHeaderItem(4);
        ___qtablewidgetitem37->setText(QApplication::translate("ThrowPkm", "Exp", nullptr));
        QTableWidgetItem *___qtablewidgetitem38 = tableWidget_2->verticalHeaderItem(5);
        ___qtablewidgetitem38->setText(QApplication::translate("ThrowPkm", "Hp", nullptr));
        QTableWidgetItem *___qtablewidgetitem39 = tableWidget_2->verticalHeaderItem(6);
        ___qtablewidgetitem39->setText(QApplication::translate("ThrowPkm", "Atk", nullptr));
        QTableWidgetItem *___qtablewidgetitem40 = tableWidget_2->verticalHeaderItem(7);
        ___qtablewidgetitem40->setText(QApplication::translate("ThrowPkm", "Sat", nullptr));
        QTableWidgetItem *___qtablewidgetitem41 = tableWidget_2->verticalHeaderItem(8);
        ___qtablewidgetitem41->setText(QApplication::translate("ThrowPkm", "Def", nullptr));
        QTableWidgetItem *___qtablewidgetitem42 = tableWidget_2->verticalHeaderItem(9);
        ___qtablewidgetitem42->setText(QApplication::translate("ThrowPkm", "Sdf", nullptr));
        QTableWidgetItem *___qtablewidgetitem43 = tableWidget_2->verticalHeaderItem(10);
        ___qtablewidgetitem43->setText(QApplication::translate("ThrowPkm", "Spe", nullptr));
        QTableWidgetItem *___qtablewidgetitem44 = tableWidget_2->verticalHeaderItem(11);
        ___qtablewidgetitem44->setText(QApplication::translate("ThrowPkm", "Skills", nullptr));
        QTableWidgetItem *___qtablewidgetitem45 = tableWidget_2->verticalHeaderItem(12);
        ___qtablewidgetitem45->setText(QApplication::translate("ThrowPkm", "Skill1", nullptr));
        QTableWidgetItem *___qtablewidgetitem46 = tableWidget_2->verticalHeaderItem(13);
        ___qtablewidgetitem46->setText(QApplication::translate("ThrowPkm", "Skill2", nullptr));
        QTableWidgetItem *___qtablewidgetitem47 = tableWidget_2->verticalHeaderItem(14);
        ___qtablewidgetitem47->setText(QApplication::translate("ThrowPkm", "Skill4", nullptr));
        pushButton_2->setText(QApplication::translate("ThrowPkm", "Select this", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThrowPkm: public Ui_ThrowPkm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THROWPKM_H
