#pragma once
#include "loginwindow.h"

namespace Ui {
	class ThrowWidget;
}

class ThrowWidget :public QWidget 
{
	Q_OBJECT
public:
	ThrowWidget(QWidget *parent = nullptr);
	~ThrowWidget();
};