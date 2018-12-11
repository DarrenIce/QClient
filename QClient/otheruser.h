#pragma once

#include <QWidget>
#include <QCloseEvent>
#include "ui_otheruser.h"

class OtherUser : public QWidget
{
	Q_OBJECT

public:
	OtherUser(QWidget *parent = Q_NULLPTR);
	~OtherUser();
	Ui::OtherUser ui;
	void closeEvent(QCloseEvent * event)
	{
		emit showmainwindow();
		hide();
	}
signals:
	void showmainwindow();
};
