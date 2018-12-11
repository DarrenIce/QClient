#pragma once

#include <QWidget>
#include "ui_throwpkm.h"
#include "loginwindow.h"

class ThrowPkm : public QWidget
{
	Q_OBJECT

public:
	ThrowPkm(QWidget *parent = Q_NULLPTR);
	~ThrowPkm();
	Ui::ThrowPkm ui;
};
