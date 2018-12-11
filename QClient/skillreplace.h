#pragma once

#include <QWidget>
#include "ui_skillreplace.h"
#include <QCloseEvent>

class SkillReplace : public QWidget
{
	Q_OBJECT

public:
	SkillReplace(QWidget *parent = Q_NULLPTR);
	~SkillReplace();
	Ui::SkillReplace ui;
	void closeEvent(QCloseEvent * event)
	{
		emit showmainwindow();
		hide();
	}
signals:
	void showmainwindow();
};
