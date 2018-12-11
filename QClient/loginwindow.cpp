#include "loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	ui.lineEdit->setMaxLength(16);
	ui.lineEdit->setPlaceholderText(QStringLiteral("Username"));
	ui.lineEdit_2->setMaxLength(16);
	ui.lineEdit_2->installEventFilter(this);
	ui.lineEdit_2->setContextMenuPolicy(Qt::NoContextMenu);
	ui.lineEdit_2->setPlaceholderText(QStringLiteral("Password"));
	ui.lineEdit_2->setEchoMode(QLineEdit::Password);
	connect(ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(login()));
	connect(ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(signup()));
	ui.label_3->hide();
}

LoginWindow::~LoginWindow()
{
}
void LoginWindow::login()
{
	//获取文本框中的信息
	std::string username;
	std::string password;
	QString strU = ui.lineEdit->text();
	QString strP = ui.lineEdit_2->text();
	username = strU.toStdString();
	password = strP.toStdString();
	int state = 0;
	emit LoginInfo(username, password, state);
	if (state == 1)
	{
		this->hide();
		emit showmainwindow();
		emit showpms(username);
	}
	else if (state == 2)
	{
		ui.label_3->setText("User dose not exist.");
		ui.label_3->show();
	}
	else if (state == 3)
	{
		ui.label_3->setText("User has Logged in. Please connect with admininister.");
		ui.label_3->show();
	}
	else if (state == 4)
	{
		ui.label_3->setText("Wrong password.");
		ui.label_3->show();
	}
}
void LoginWindow::signup()
{
	std::string username;
	std::string password;
	QString strU = ui.lineEdit->text();
	QString strP = ui.lineEdit_2->text();
	username = strU.toStdString();
	password = strP.toStdString();
	std::regex repPattern1("^[a-zA-Z][a-zA-Z0-9_]{4,15}$");
	std::regex repPattern2("^(?![0-9]+$)(?![a-zA-Z]+$)[0-9A-Za-z]{8,15}$");
	if (!regex_match(username, repPattern1))
	{
		ui.label_3->setText("invalid username.");
		ui.label_3->show();
	}
	else if (!regex_match(password, repPattern2))
	{
		ui.label_3->setText("invalid password.");
		ui.label_3->show();
	}
	else
	{
		int state = 0;
		emit SignupInfo(username, password, state);
		if (state == 1)
		{
			ui.label_3->setText("Sign up successfully.");
			ui.label_3->show();
		}
		else if (state == 2)
		{
			ui.label_3->setText("User already exists.");
			ui.label_3->show();
		}
	}
}
bool LoginWindow::eventFilter(QObject *obj, QEvent *event)
{
	QLineEdit *pLineEdit = qobject_cast<QLineEdit*>(obj);
	if (pLineEdit != NULL)
	{
		switch (event->type())
		{
		case QEvent::MouseMove:
			return true;
		case QEvent::MouseButtonDblClick:
			return true;
		case QEvent::KeyPress:
		{
			QKeyEvent *pKeyEvent = static_cast<QKeyEvent*>(event);
			if (pKeyEvent->matches(QKeySequence::SelectAll) || pKeyEvent->matches(QKeySequence::Copy) || pKeyEvent->matches(QKeySequence::Paste))
			{
				return true;
			}
		}
		}
	}
	return QObject::eventFilter(obj, event);
}
void LoginWindow::closeEvent(QCloseEvent * event)
{
	emit ext();
	QApplication* app;
	app->exit(0);
}
void LoginWindow::paintEvent(QPaintEvent *event)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}