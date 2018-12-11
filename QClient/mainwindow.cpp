#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
	chooseskill = 0;
	ui->setupUi(this);
	tp = new ThrowPkm();
	tp->hide();
    lw=new LoginWindow;
	ou = new OtherUser;
	ou->hide();
	sr = new SkillReplace;
	sr->hide();
	timer = new QTimer(this);
	timer2 = new QTimer(this);
	timer2->start(10000);
	ui->UserTable->horizontalHeader()->setVisible(false);
	ui->UserPm->horizontalHeader()->setVisible(false);
	ui->SerPm->horizontalHeader()->setVisible(false);
	QObject::connect(lw, &LoginWindow::LoginInfo, this, &MainWindow::SendLoginInfo);
    QObject::connect(lw,&LoginWindow::showmainwindow,this,&MainWindow::showmainwindow);
	QObject::connect(ou, &OtherUser::showmainwindow, this, &MainWindow::showmainwindow);
	QObject::connect(sr, &SkillReplace::showmainwindow, this, &MainWindow::showmainwindow);
	QObject::connect(lw,&LoginWindow::showpms,this,&MainWindow::showpms);
	QObject::connect(ui->PMList, &QListWidget::itemClicked, this, &MainWindow::ChangeUserOp);
	QObject::connect(ui->CreatePm, SIGNAL(clicked(bool)), this, SLOT(CreatePm()));
	QObject::connect(ui->Skill1, SIGNAL(clicked(bool)), this, SLOT(SkillBar1()));
	QObject::connect(ui->Skill2, SIGNAL(clicked(bool)), this, SLOT(SkillBar2()));
	QObject::connect(ui->Skill3, SIGNAL(clicked(bool)), this, SLOT(SkillBar3()));
	QObject::connect(ui->Skill4, SIGNAL(clicked(bool)), this, SLOT(SkillBar4()));
	QObject::connect(ui->UpgradeMatch, SIGNAL(clicked(bool)), this, SLOT(GradeUpMatch()));
	QObject::connect(ui->DuelMatch, SIGNAL(clicked(bool)), this, SLOT(DuelMatch()));
	QObject::connect(ui->StartMatch, SIGNAL(clicked(bool)), this, SLOT(StartMatch()));
	QObject::connect(timer, SIGNAL(timeout()), this, SLOT(Fight()));
	QObject::connect(ui->Exit, SIGNAL(clicked(bool)), this, SLOT(Exit()));
	QObject::connect(this, &MainWindow::showskill, this, &MainWindow::ShowSkill);
	QObject::connect(this, &MainWindow::throwpm, this, &MainWindow::Throwpm);
	QObject::connect(tp->ui.pushButton, SIGNAL(clicked(bool)), this, SLOT(push1()));
	QObject::connect(tp->ui.pushButton_2, SIGNAL(clicked(bool)), this, SLOT(push2()));
	QObject::connect(tp->ui.pushButton_3, SIGNAL(clicked(bool)), this, SLOT(push3()));
	QObject::connect(this, &MainWindow::requestsend1, this, &MainWindow::fightinfo1);
	QObject::connect(this, &MainWindow::requestsend2, this, &MainWindow::fightinfo2);
	QObject::connect(timer2, SIGNAL(timeout()), this, SLOT(onlineuser()));
	QObject::connect(ui->UserList, &QListWidget::itemDoubleClicked, this, &MainWindow::showuserinfo);
	QObject::connect(ou->ui.PMList, &QListWidget::itemClicked, this, &MainWindow::ChangeOtherOp);
	QObject::connect(sr->ui.Skills, &QListWidget::itemClicked, this, &MainWindow::changechoose);
	QObject::connect(sr->ui.Skill1, SIGNAL(clicked(bool)), this, SLOT(change1()));
	QObject::connect(sr->ui.Skill2, SIGNAL(clicked(bool)), this, SLOT(change2()));
	QObject::connect(sr->ui.Skill3, SIGNAL(clicked(bool)), this, SLOT(change3()));
	QObject::connect(sr->ui.Skill4, SIGNAL(clicked(bool)), this, SLOT(change4()));
	lw->show();
	if (ui->IdBox->value() == 3)
	{
		PMptr = new Venusaur(ui->LevelBox->value());
		ChangePmOp();
	}
	else if (ui->IdBox->value() == 6)
	{
		PMptr = new Charizard(ui->LevelBox->value());
		ChangePmOp();
	}
	else if (ui->IdBox->value() == 9)
	{
		PMptr = new Blastoise(ui->LevelBox->value());
		ChangePmOp();
	}

}
MainWindow::~MainWindow()
{
	exit();
	delete ui;
}
void MainWindow::SendLoginInfo(const std::string &username, const std::string &password, int &state)
{
	UserInfo userinfo;
	emit LoginInfo(username, password, state, userinfo);
	UPtr = new User(userinfo);
	if (state == 1)
	{
		FlashUserInfo();
	}
}
void MainWindow::showmainwindow()
{
    this->setVisible(true);
}
void MainWindow::FlashUserInfo()
{
	UPtr->PmAch();
	UPtr->PerPmAch();
	ui->UserTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(UPtr->username)));
	ui->UserTable->setItem(1, 0, new QTableWidgetItem(QString::number(UPtr->WinNum)));
	ui->UserTable->setItem(2, 0, new QTableWidgetItem(QString::number(UPtr->LossNum)));
	ui->UserTable->setItem(3, 0, new QTableWidgetItem(QString::number(UPtr->WinRate)));
	ui->UserTable->setItem(4, 0, new QTableWidgetItem(QString::number(UPtr->PmNum)));
	ui->UserTable->setItem(5, 0, new QTableWidgetItem(QString::number(UPtr->PerPmNum)));
	ui->UserTable->setItem(6, 0, new QTableWidgetItem(QString::number(UPtr->AchNum)));
	QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(UPtr->Ach[0]));
	switch (UPtr->AchLevel[0])
	{
	case 1:item->setTextColor(QColor(0, 0, 0)); break;
	case 2:item->setTextColor(QColor(170, 255, 0)); break;
	case 3:item->setTextColor(QColor(112, 168, 0)); break;
	case 4:item->setTextColor(QColor(170, 255, 255)); break;
	case 5:item->setTextColor(QColor(136, 204, 204)); break;
	case 6:item->setTextColor(QColor(255, 255, 127)); break;
	case 7:item->setTextColor(QColor(222, 222, 110)); break;
	case 8:item->setTextColor(QColor(170, 170, 255)); break;
	case 9:item->setTextColor(QColor(121, 121, 181)); break;
	case 10:item->setTextColor(QColor(255, 0, 0)); break;
	}
	ui->UserTable->setItem(7, 0, item);
	QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(UPtr->Ach[1]));
	switch (UPtr->AchLevel[1])
	{
	case 1:item2->setTextColor(QColor(0, 0, 0)); break;
	case 2:item2->setTextColor(QColor(170, 255, 0)); break;
	case 3:item2->setTextColor(QColor(112, 168, 0)); break;
	case 4:item2->setTextColor(QColor(170, 255, 255)); break;
	case 5:item2->setTextColor(QColor(136, 204, 204)); break;
	case 6:item2->setTextColor(QColor(255, 255, 127)); break;
	case 7:item2->setTextColor(QColor(222, 222, 110)); break;
	case 8:item2->setTextColor(QColor(170, 170, 255)); break;
	case 9:item2->setTextColor(QColor(121, 121, 181)); break;
	case 10:item2->setTextColor(QColor(255, 0, 0)); break;
	}
	ui->UserTable->setItem(8, 0, item2);
	ui->Skill1->setEnabled(false);
	ui->Skill2->setEnabled(false);
	ui->Skill3->setEnabled(false);
	ui->Skill4->setEnabled(false);
	ui->UpgradeMatch->setEnabled(false);
	ui->DuelMatch->setEnabled(false);
}
void MainWindow::showpms(const std::string &username)
{
	pv.clear();
	ui->PMList->clear();
	emit displaypms(username,pv);
	UPtr->PmNum = pv.size();
	UPtr->PerPmNum = 0;
    for (auto i = pv.begin(); i != pv.end(); i++)
    {
        QListWidgetItem* item=new QListWidgetItem;
        QString qs;
        qs=QString::fromStdString((*(*i)).name);
        item->setText(qs);
        ui->PMList->addItem(item);
		if ((*i)->grade >= 15)
			UPtr->PerPmNum++;
    }
	ui->UserTable->setItem(4, 0, new QTableWidgetItem(QString::number(UPtr->PmNum)));
	ui->UserTable->setItem(5, 0, new QTableWidgetItem(QString::number(UPtr->PerPmNum)));
}
void MainWindow::ChangeUserOp(QListWidgetItem *item)
{
	int r = ui->PMList->row(item);
	Pptr = pv.at(r);
	ui->UserPm->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(Pptr->name)));
	ui->UserPm->setItem(1, 0, new QTableWidgetItem(QString::number(Pptr->id)));
	ui->UserPm->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(Pptr->nicky)));
	ui->UserPm->setItem(3, 0, new QTableWidgetItem(QString::number(Pptr->grade)));
	ui->UserPm->setItem(4, 0, new QTableWidgetItem(QString::number(Pptr->Exp)));
	ui->UserPm->setItem(7, 0, new QTableWidgetItem(QString::number(Pptr->Hp.InitialValue)));
	ui->UserPm->setItem(8, 0, new QTableWidgetItem(QString::number(Pptr->Atk.InitialValue)));
	ui->UserPm->setItem(9, 0, new QTableWidgetItem(QString::number(Pptr->Sat.InitialValue)));
	ui->UserPm->setItem(10, 0, new QTableWidgetItem(QString::number(Pptr->Def.InitialValue)));
	ui->UserPm->setItem(11, 0, new QTableWidgetItem(QString::number(Pptr->Sdf.InitialValue)));
	ui->UserPm->setItem(12, 0, new QTableWidgetItem(QString::number(Pptr->Spe.InitialValue)));
	ui->UserPm->setItem(13, 0, new QTableWidgetItem(QString::number(Pptr->al_have_skills)));
	if (Pptr->skill_bar[0] == -1)
		ui->UserPm->setItem(14, 0, new QTableWidgetItem("NULL"));
	else
		ui->UserPm->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name)));
	if (Pptr->skill_bar[1] == -1)
		ui->UserPm->setItem(15, 0, new QTableWidgetItem("NULL"));
	else
		ui->UserPm->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name)));
	if (Pptr->skill_bar[2] == -1)
		ui->UserPm->setItem(16, 0, new QTableWidgetItem("NULL"));
	else
		ui->UserPm->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name)));
	if (Pptr->skill_bar[3] == -1)
		ui->UserPm->setItem(17, 0, new QTableWidgetItem("NULL"));
	else
		ui->UserPm->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name)));
	switch (Pptr->nature)
	{
	case 1:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
	case 2:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
	case 3:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Brave")); break;
	case 4:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
	case 5:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
	case 6:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Bold")); break;
	case 7:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Docile")); break;
	case 8:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
	case 9:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Impish")); break;
	case 10:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Lax")); break;
	case 11:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Timid")); break;
	case 12:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
	case 13:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Serious")); break;
	case 14:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
	case 15:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Naive")); break;
	case 16:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Modest")); break;
	case 17:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Mild")); break;
	case 18:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
	case 19:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
	case 20:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Rash")); break;
	case 21:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Calm")); break;
	case 22:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
	case 23:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
	case 24:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Careful")); break;
	case 25:ui->UserPm->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
	}
	switch (Pptr->Ppt)
	{
	case 1:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Normal")); break;
	case 2:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Fire")); break;
	case 3:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Bug")); break;
	case 4:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Water")); break;
	case 5:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Poison")); break;
	case 6:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Electric")); break;
	case 7:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Flying")); break;
	case 8:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Grass")); break;
	case 9:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Ground")); break;
	case 10:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Ice")); break;
	case 11:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
	case 12:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
	case 13:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Rock")); break;
	case 14:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
	case 15:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
	case 16:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Dark")); break;
	case 17:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Steel")); break;
	case 18:ui->UserPm->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
	}
	if (Pptr->skill_bar[0] == -1)
	{
		ui->Skill1->setText("NULL");
	}
	else
	{
		ui->Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	}
	if (Pptr->skill_bar[1] == -1)
	{
		ui->Skill2->setText("NULL");
	}
	else
	{
		ui->Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	}
	if (Pptr->skill_bar[2] == -1)
	{
		ui->Skill3->setText("NULL");
	}
	else
	{
		ui->Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	}
	if (Pptr->skill_bar[3] == -1)
	{
		ui->Skill4->setText("NULL");
	}
	else
	{
		ui->Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	}
	if (Pptr->id == 3)
	{
		ui->Ppic->setPixmap(QPixmap(":/images/images/003Venusaur.png"));
	}
	else if (Pptr->id == 6)
	{
		ui->Ppic->setPixmap(QPixmap(":/images/images/006Charizard.png"));
	}
	else if (Pptr->id == 9)
	{
		ui->Ppic->setPixmap(QPixmap(":/images/images/009Blastoise.png"));
	}
}
void MainWindow::ChangePmOp()
{
	ui->SerPm->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(PMptr->name)));
	ui->SerPm->setItem(1, 0, new QTableWidgetItem(QString::number(PMptr->id)));
	ui->SerPm->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(PMptr->nicky)));
	ui->SerPm->setItem(3, 0, new QTableWidgetItem(QString::number(PMptr->grade)));
	ui->SerPm->setItem(4, 0, new QTableWidgetItem(QString::number(PMptr->Exp)));
	ui->SerPm->setItem(7, 0, new QTableWidgetItem(QString::number(PMptr->Hp.InitialValue)));
	ui->SerPm->setItem(8, 0, new QTableWidgetItem(QString::number(PMptr->Atk.InitialValue)));
	ui->SerPm->setItem(9, 0, new QTableWidgetItem(QString::number(PMptr->Sat.InitialValue)));
	ui->SerPm->setItem(10, 0, new QTableWidgetItem(QString::number(PMptr->Def.InitialValue)));
	ui->SerPm->setItem(11, 0, new QTableWidgetItem(QString::number(PMptr->Sdf.InitialValue)));
	ui->SerPm->setItem(12, 0, new QTableWidgetItem(QString::number(PMptr->Spe.InitialValue)));
	ui->SerPm->setItem(13, 0, new QTableWidgetItem(QString::number(PMptr->al_have_skills)));
	if (PMptr->skill_bar[0] == -1)
		ui->SerPm->setItem(14, 0, new QTableWidgetItem("NULL"));
	else
		ui->SerPm->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[0]]].name)));
	if (PMptr->skill_bar[1] == -1)
		ui->SerPm->setItem(15, 0, new QTableWidgetItem("NULL"));
	else
		ui->SerPm->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[1]]].name)));
	if (PMptr->skill_bar[2] == -1)
		ui->SerPm->setItem(16, 0, new QTableWidgetItem("NULL"));
	else
		ui->SerPm->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[2]]].name)));
	if (PMptr->skill_bar[3] == -1)
		ui->SerPm->setItem(17, 0, new QTableWidgetItem("NULL"));
	else
		ui->SerPm->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[3]]].name)));
	switch (PMptr->nature)
	{
	case 1:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
	case 2:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
	case 3:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Brave")); break;
	case 4:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
	case 5:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
	case 6:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Bold")); break;
	case 7:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Docile")); break;
	case 8:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
	case 9:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Impish")); break;
	case 10:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Lax")); break;
	case 11:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Timid")); break;
	case 12:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
	case 13:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Serious")); break;
	case 14:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
	case 15:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Naive")); break;
	case 16:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Modest")); break;
	case 17:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Mild")); break;
	case 18:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
	case 19:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
	case 20:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Rash")); break;
	case 21:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Calm")); break;
	case 22:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
	case 23:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
	case 24:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Careful")); break;
	case 25:ui->SerPm->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
	}
	switch (PMptr->Ppt)
	{
	case 1:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Normal")); break;
	case 2:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Fire")); break;
	case 3:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Bug")); break;
	case 4:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Water")); break;
	case 5:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Poison")); break;
	case 6:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Electric")); break;
	case 7:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Flying")); break;
	case 8:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Grass")); break;
	case 9:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Ground")); break;
	case 10:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Ice")); break;
	case 11:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
	case 12:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
	case 13:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Rock")); break;
	case 14:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
	case 15:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
	case 16:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Dark")); break;
	case 17:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Steel")); break;
	case 18:ui->SerPm->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
	}
	if (PMptr->id == 3)
	{
		ui->PMpic->setPixmap(QPixmap(":/images/images/003Venusaur.png"));
	}
	else if (PMptr->id == 6)
	{
		ui->PMpic->setPixmap(QPixmap(":/images/images/006Charizard.png"));
	}
	else if (PMptr->id == 9)
	{
		ui->PMpic->setPixmap(QPixmap(":/images/images/009Blastoise.png"));
	}
}
void MainWindow::CreatePm()
{
	if (ui->IdBox->value() == 3)
	{
		PMptr = new Venusaur(ui->LevelBox->value());
		ChangePmOp();
	}
	else if (ui->IdBox->value() == 6)
	{
		PMptr = new Charizard(ui->LevelBox->value());
		ChangePmOp();
	}
	else if (ui->IdBox->value() == 9)
	{
		PMptr = new Blastoise(ui->LevelBox->value());
		ChangePmOp();
	}
	ui->UpgradeMatch->setEnabled(true);
	ui->DuelMatch->setEnabled(true);
}
void MainWindow::GradeUpMatch()
{
	ui->StartMatch->setEnabled(true);
	if (Pptr->skill_bar[0] == -1)
	{
		ui->Skill1->setText("NULL");
		ui->Skill1->setEnabled(false);
	}
	else
	{
		ui->Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
		ui->Skill1->setEnabled(true);
	}
	if (Pptr->skill_bar[1] == -1)
	{
		ui->Skill2->setText("NULL");
		ui->Skill2->setEnabled(false);
	}
	else
	{
		ui->Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
		ui->Skill2->setEnabled(true);
	}
	if (Pptr->skill_bar[2] == -1)
	{
		ui->Skill3->setText("NULL");
		ui->Skill3->setEnabled(false);
	}
	else
	{
		ui->Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
		ui->Skill3->setEnabled(true);
	}
	if (Pptr->skill_bar[3] == -1)
	{
		ui->Skill4->setText("NULL");
		ui->Skill4->setEnabled(false);
	}
	else
	{
		ui->Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
		ui->Skill4->setEnabled(true);
	}
	time1 = Pptr->SpeedMap();
	time2 = PMptr->SpeedMap();
	Pptr->FightInitial();
	PMptr->FightInitial();
	strs.clear();
	choosematch = 1;
}
void MainWindow::DuelMatch()
{
	ui->StartMatch->setEnabled(true);
	if (Pptr->skill_bar[0] == -1)
	{
		ui->Skill1->setText("NULL");
		ui->Skill1->setEnabled(false);
	}
	else
	{
		ui->Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
		ui->Skill1->setEnabled(true);
	}
	if (Pptr->skill_bar[1] == -1)
	{
		ui->Skill2->setText("NULL");
		ui->Skill2->setEnabled(false);
	}
	else
	{
		ui->Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
		ui->Skill2->setEnabled(true);
	}
	if (Pptr->skill_bar[2] == -1)
	{
		ui->Skill3->setText("NULL");
		ui->Skill3->setEnabled(false);
	}
	else
	{
		ui->Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
		ui->Skill3->setEnabled(true);
	}
	if (Pptr->skill_bar[3] == -1)
	{
		ui->Skill4->setText("NULL");
		ui->Skill4->setEnabled(false);
	}
	else
	{
		ui->Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
		ui->Skill4->setEnabled(true);
	}
	time1 = Pptr->SpeedMap();
	time2 = PMptr->SpeedMap();
	Pptr->FightInitial();
	PMptr->FightInitial();
	strs.clear();
	choosematch = 2;
}
void MainWindow::StartMatch()
{
	timer->start(200);
	ui->PMList->setEnabled(false);
	ui->Exit->setEnabled(false);
	ui->CreatePm->setEnabled(false);
	ui->StartMatch->setEnabled(false);
	ui->UpgradeMatch->setEnabled(false);
	ui->DuelMatch->setEnabled(false);
}
void MainWindow::ShowSkill()
{
	sr->ui.Skills->clear();
	for (int i = 0; i <= Pptr->al_have_skills; i++)
	{
		QListWidgetItem* item = new QListWidgetItem;
		QString qs;
		qs = QString::fromStdString(Pptr->skills[Pptr->skill_list[i]].name);
		item->setText(qs);
		sr->ui.Skills->addItem(item);
	}
	if (Pptr->skill_bar[0] == -1)
	{
		sr->ui.Skill1->setText("NULL");
	}
	else
	{
		sr->ui.Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	}
	if (Pptr->skill_bar[1] == -1)
	{
		sr->ui.Skill2->setText("NULL");
	}
	else
	{
		sr->ui.Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	}
	if (Pptr->skill_bar[2] == -1)
	{
		sr->ui.Skill3->setText("NULL");
	}
	else
	{
		sr->ui.Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	}
	if (Pptr->skill_bar[3] == -1)
	{
		sr->ui.Skill4->setText("NULL");
	}
	else
	{
		sr->ui.Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	}
	sr->show();
	hide();
}
void MainWindow::Fight()
{
	if (Pptr->Hp.FightValue != 0 && PMptr->Hp.FightValue != 0)
	{
		time1--;
		time2--;
		if (time1 == 0 && Pptr->Hp.FightValue != 0)
		{
			time1 = Pptr->SpeedMap();
			Pptr->Fight(PMptr,strs);
			emit requestsend1();
		}
		if (time2 == 0 && PMptr->Hp.FightValue != 0)
		{
			time2 = PMptr->SpeedMap();
			PMptr->select_skill = PMptr->r.get(0, 3);
			PMptr->Fight(Pptr,strs);
			emit requestsend2();
		}
	}
	if (Pptr->Hp.FightValue == 0)
	{
		UPtr->LossNum++;
		UPtr->UpdateWinRate();
		timer->stop();
		//ui->StartMatch->setEnabled(false);
		ui->UserHp->setValue(100);
		ui->PmHp->setValue(100);
		if (choosematch == 2)
		{
			emit throwpm();
			UPtr->PmNum--;
			if (UPtr->PmNum == 0)
			{
				std::vector<int> temp;
				for (int i = 1; i <= 3; i++)
				{
					temp.push_back(i*3);
				}
				random_shuffle(temp.begin(), temp.end());
				int k = temp.at(0);
				if (k == 3)
				{
					Pptr = new Venusaur();
					pv.push_back(Pptr);
				}
				else if (k == 6)
				{
					Pptr = new Charizard();
					pv.push_back(Pptr);
				}
				else if (k == 9)
				{
					Pptr = new Blastoise();
					pv.push_back(Pptr);
				}
				AddPm(Pptr);
			}
			showpms(UPtr->username);
		}
		FlashUserInfo();
		emit UserLoss(UPtr);
		ui->PMList->setEnabled(true);
		ui->Exit->setEnabled(true);
		ui->CreatePm->setEnabled(true);
		ui->StartMatch->setEnabled(true);
		ui->UpgradeMatch->setEnabled(true);
		ui->DuelMatch->setEnabled(true);
	}
	else if (PMptr->Hp.FightValue == 0)
	{
		int bl = Pptr->grade;
		int bs = Pptr->al_have_skills;
		Pptr->AddExp(PMptr->grade);
		ui->UserPm->setItem(4, 0, new QTableWidgetItem(QString::number(Pptr->Exp)));
		int al = Pptr->grade;
		int as = Pptr->al_have_skills;
		/*if (bs != as)
		{
			emit showskill();
		}*/
		if (bl != al)
		{
			emit showskill();
			ui->UserPm->setItem(3, 0, new QTableWidgetItem(QString::number(Pptr->grade)));
			ui->UserPm->setItem(7, 0, new QTableWidgetItem(QString::number(Pptr->Hp.InitialValue)));
			ui->UserPm->setItem(8, 0, new QTableWidgetItem(QString::number(Pptr->Atk.InitialValue)));
			ui->UserPm->setItem(9, 0, new QTableWidgetItem(QString::number(Pptr->Sat.InitialValue)));
			ui->UserPm->setItem(10, 0, new QTableWidgetItem(QString::number(Pptr->Def.InitialValue)));
			ui->UserPm->setItem(11, 0, new QTableWidgetItem(QString::number(Pptr->Sdf.InitialValue)));
			ui->UserPm->setItem(12, 0, new QTableWidgetItem(QString::number(Pptr->Spe.InitialValue)));
		}
		//如果升级，技能替换的设计，更新界面属性
		//后续考虑弹窗提示升级
		//要把经验保存回服务器
		UPtr->WinNum++;
		UPtr->UpdateWinRate();
		FlashUserInfo();
		if (bl != al&&al == 15)
		{
			UPtr->PerPmNum++;
			UPtr->PerPmAch();
			QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(UPtr->Ach[1]));
			switch (UPtr->AchLevel[1])
			{
			case 1:item->setTextColor(QColor(255, 255, 255)); break;
			case 2:item->setTextColor(QColor(170, 255, 0)); break;
			case 3:item->setTextColor(QColor(112, 168, 0)); break;
			case 4:item->setTextColor(QColor(170, 255, 255)); break;
			case 5:item->setTextColor(QColor(136, 204, 204)); break;
			case 6:item->setTextColor(QColor(255, 255, 127)); break;
			case 7:item->setTextColor(QColor(222, 222, 110)); break;
			case 8:item->setTextColor(QColor(170, 170, 255)); break;
			case 9:item->setTextColor(QColor(121, 121, 181)); break;
			case 10:item->setTextColor(QColor(255, 0, 0)); break;
			}
			ui->UserTable->setItem(8, 0, item);
		}
		timer->stop();
		ui->StartMatch->setEnabled(false);
		ui->UserHp->setValue(100);
		ui->PmHp->setValue(100);
		emit UserWin(UPtr, pv);
		if (choosematch == 2)
		{
			UPtr->PmNum++;
			emit AddPm(PMptr);
			showpms(UPtr->username);
		}
		ui->PMList->setEnabled(true);
		ui->Exit->setEnabled(true);
		ui->CreatePm->setEnabled(true);
		ui->StartMatch->setEnabled(true);
		ui->UpgradeMatch->setEnabled(true);
		ui->DuelMatch->setEnabled(true);
	}
	//循环体 双方FightValue不为零时循环
	//每次循环中两个定时器自减，减到0发动攻击并重新初始化定时器
	//怪物在每次攻击前随机select_skill值
	//写四个函数对应四个button 按下相应button 则select_skill值改变
	//有一方死亡则退出循环，并发送信号，让Client发送数据
	//用户赢了则根据怪物等级增加经验，失败无损失（升级赛）
}
void MainWindow::fightinfo1()
{
	ui->FightInfo->setTextColor(QColor(255, 0, 0));
	for (auto i = strs.begin(); i != strs.end(); i++)
	{
		ui->FightInfo->append(QString::fromStdString((*i)));
	}
	strs.clear();
	ui->PmHp->setValue((PMptr->Hp.FightValue * 100) / PMptr->Hp.InitialValue);
	ui->UserHp->setValue((Pptr->Hp.FightValue * 100) / Pptr->Hp.InitialValue);
}
void MainWindow::fightinfo2()
{
	ui->FightInfo->setTextColor(QColor(0, 141, 212));
	for (auto i = strs.begin(); i != strs.end(); i++)
	{
		ui->FightInfo->append(QString::fromStdString((*i)));
	}
	strs.clear();
	ui->PmHp->setValue((PMptr->Hp.FightValue * 100) / PMptr->Hp.InitialValue);
	ui->UserHp->setValue((Pptr->Hp.FightValue * 100) / Pptr->Hp.InitialValue);
}
//界面的美化
void MainWindow::Throwpm()
{
	tp->show();
	hide();
	int size = pv.size();
	if (size == 1)
	{
		pm[0] = 0;
		pm[1] = -1;
		pm[2] = -1;
		tp->ui.pushButton_2->setEnabled(false);
		tp->ui.pushButton_3->setEnabled(false);
	}
	else if (size == 2)
	{
		pm[0] = 0;
		pm[1] = 1;
		pm[2] = -1;
		tp->ui.pushButton_3->setEnabled(false);
	}
	else if (size == 3)
	{
		pm[0] = 0;
		pm[1] = 1;
		pm[2] = 2;
	}
	else
	{
		std::vector<int> temp;
		for (int i = 0; i < size; i++)
		{
			temp.push_back(i);
		}
		random_shuffle(temp.begin(), temp.end());
		pm[0] = temp.at(0);
		pm[1] = temp.at(1);
		pm[2] = temp.at(2);
	}
	Pokemon* p;
	p = pv.at(pm[0]);
	{
		tp->ui.UserPm_1->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(p->name)));
		tp->ui.UserPm_1->setItem(1, 0, new QTableWidgetItem(QString::number(p->id)));
		tp->ui.UserPm_1->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(p->nicky)));
		tp->ui.UserPm_1->setItem(3, 0, new QTableWidgetItem(QString::number(p->grade)));
		tp->ui.UserPm_1->setItem(4, 0, new QTableWidgetItem(QString::number(p->Exp)));
		tp->ui.UserPm_1->setItem(7, 0, new QTableWidgetItem(QString::number(p->Hp.InitialValue)));
		tp->ui.UserPm_1->setItem(8, 0, new QTableWidgetItem(QString::number(p->Atk.InitialValue)));
		tp->ui.UserPm_1->setItem(9, 0, new QTableWidgetItem(QString::number(p->Sat.InitialValue)));
		tp->ui.UserPm_1->setItem(10, 0, new QTableWidgetItem(QString::number(p->Def.InitialValue)));
		tp->ui.UserPm_1->setItem(11, 0, new QTableWidgetItem(QString::number(p->Sdf.InitialValue)));
		tp->ui.UserPm_1->setItem(12, 0, new QTableWidgetItem(QString::number(p->Spe.InitialValue)));
		tp->ui.UserPm_1->setItem(13, 0, new QTableWidgetItem(QString::number(p->al_have_skills)));
		if (p->skill_bar[0] == -1)
			tp->ui.UserPm_1->setItem(14, 0, new QTableWidgetItem("NULL"));
		else
			tp->ui.UserPm_1->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[0]]].name)));
		if (p->skill_bar[1] == -1)
			tp->ui.UserPm_1->setItem(15, 0, new QTableWidgetItem("NULL"));
		else
			tp->ui.UserPm_1->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[1]]].name)));
		if (p->skill_bar[2] == -1)
			tp->ui.UserPm_1->setItem(16, 0, new QTableWidgetItem("NULL"));
		else
			tp->ui.UserPm_1->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[2]]].name)));
		if (p->skill_bar[3] == -1)
			tp->ui.UserPm_1->setItem(17, 0, new QTableWidgetItem("NULL"));
		else
			tp->ui.UserPm_1->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[3]]].name)));
		switch (p->nature)
		{
		case 1:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
		case 2:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
		case 3:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Brave")); break;
		case 4:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
		case 5:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
		case 6:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Bold")); break;
		case 7:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Docile")); break;
		case 8:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
		case 9:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Impish")); break;
		case 10:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Lax")); break;
		case 11:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Timid")); break;
		case 12:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
		case 13:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Serious")); break;
		case 14:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
		case 15:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Naive")); break;
		case 16:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Modest")); break;
		case 17:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Mild")); break;
		case 18:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
		case 19:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
		case 20:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Rash")); break;
		case 21:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Calm")); break;
		case 22:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
		case 23:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
		case 24:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Careful")); break;
		case 25:tp->ui.UserPm_1->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
		}
		switch (p->Ppt)
		{
		case 1:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Normal")); break;
		case 2:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Fire")); break;
		case 3:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Bug")); break;
		case 4:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Water")); break;
		case 5:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Poison")); break;
		case 6:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Electric")); break;
		case 7:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Flying")); break;
		case 8:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Grass")); break;
		case 9:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Ground")); break;
		case 10:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Ice")); break;
		case 11:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
		case 12:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
		case 13:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Rock")); break;
		case 14:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
		case 15:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
		case 16:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Dark")); break;
		case 17:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Steel")); break;
		case 18:tp->ui.UserPm_1->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
		}
	}
	if (pm[1] != -1)
	{
		p = pv.at(pm[1]);
		{
			tp->ui.UserPm_2->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(p->name)));
			tp->ui.UserPm_2->setItem(1, 0, new QTableWidgetItem(QString::number(p->id)));
			tp->ui.UserPm_2->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(p->nicky)));
			tp->ui.UserPm_2->setItem(3, 0, new QTableWidgetItem(QString::number(p->grade)));
			tp->ui.UserPm_2->setItem(4, 0, new QTableWidgetItem(QString::number(p->Exp)));
			tp->ui.UserPm_2->setItem(7, 0, new QTableWidgetItem(QString::number(p->Hp.InitialValue)));
			tp->ui.UserPm_2->setItem(8, 0, new QTableWidgetItem(QString::number(p->Atk.InitialValue)));
			tp->ui.UserPm_2->setItem(9, 0, new QTableWidgetItem(QString::number(p->Sat.InitialValue)));
			tp->ui.UserPm_2->setItem(10, 0, new QTableWidgetItem(QString::number(p->Def.InitialValue)));
			tp->ui.UserPm_2->setItem(11, 0, new QTableWidgetItem(QString::number(p->Sdf.InitialValue)));
			tp->ui.UserPm_2->setItem(12, 0, new QTableWidgetItem(QString::number(p->Spe.InitialValue)));
			tp->ui.UserPm_2->setItem(13, 0, new QTableWidgetItem(QString::number(p->al_have_skills)));
			if (p->skill_bar[0] == -1)
				tp->ui.UserPm_2->setItem(14, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_2->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[0]]].name)));
			if (p->skill_bar[1] == -1)
				tp->ui.UserPm_2->setItem(15, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_2->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[1]]].name)));
			if (p->skill_bar[2] == -1)
				tp->ui.UserPm_2->setItem(16, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_2->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[2]]].name)));
			if (p->skill_bar[3] == -1)
				tp->ui.UserPm_2->setItem(17, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_2->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[3]]].name)));
			switch (p->nature)
			{
			case 1:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
			case 2:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
			case 3:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Brave")); break;
			case 4:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
			case 5:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
			case 6:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Bold")); break;
			case 7:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Docile")); break;
			case 8:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
			case 9:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Impish")); break;
			case 10:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Lax")); break;
			case 11:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Timid")); break;
			case 12:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
			case 13:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Serious")); break;
			case 14:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
			case 15:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Naive")); break;
			case 16:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Modest")); break;
			case 17:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Mild")); break;
			case 18:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
			case 19:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
			case 20:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Rash")); break;
			case 21:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Calm")); break;
			case 22:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
			case 23:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
			case 24:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Careful")); break;
			case 25:tp->ui.UserPm_2->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
			}
			switch (p->Ppt)
			{
			case 1:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Normal")); break;
			case 2:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Fire")); break;
			case 3:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Bug")); break;
			case 4:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Water")); break;
			case 5:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Poison")); break;
			case 6:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Electric")); break;
			case 7:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Flying")); break;
			case 8:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Grass")); break;
			case 9:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Ground")); break;
			case 10:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Ice")); break;
			case 11:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
			case 12:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
			case 13:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Rock")); break;
			case 14:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
			case 15:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
			case 16:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Dark")); break;
			case 17:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Steel")); break;
			case 18:tp->ui.UserPm_2->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
			}
		}
	}
	if (pm[2] != -1)
	{
		p = pv.at(pm[2]);
		{
			tp->ui.UserPm_3->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(p->name)));
			tp->ui.UserPm_3->setItem(1, 0, new QTableWidgetItem(QString::number(p->id)));
			tp->ui.UserPm_3->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(p->nicky)));
			tp->ui.UserPm_3->setItem(3, 0, new QTableWidgetItem(QString::number(p->grade)));
			tp->ui.UserPm_3->setItem(4, 0, new QTableWidgetItem(QString::number(p->Exp)));
			tp->ui.UserPm_3->setItem(7, 0, new QTableWidgetItem(QString::number(p->Hp.InitialValue)));
			tp->ui.UserPm_3->setItem(8, 0, new QTableWidgetItem(QString::number(p->Atk.InitialValue)));
			tp->ui.UserPm_3->setItem(9, 0, new QTableWidgetItem(QString::number(p->Sat.InitialValue)));
			tp->ui.UserPm_3->setItem(10, 0, new QTableWidgetItem(QString::number(p->Def.InitialValue)));
			tp->ui.UserPm_3->setItem(11, 0, new QTableWidgetItem(QString::number(p->Sdf.InitialValue)));
			tp->ui.UserPm_3->setItem(12, 0, new QTableWidgetItem(QString::number(p->Spe.InitialValue)));
			tp->ui.UserPm_3->setItem(13, 0, new QTableWidgetItem(QString::number(p->al_have_skills)));
			if (p->skill_bar[0] == -1)
				tp->ui.UserPm_3->setItem(14, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_3->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[0]]].name)));
			if (p->skill_bar[1] == -1)
				tp->ui.UserPm_3->setItem(15, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_3->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[1]]].name)));
			if (p->skill_bar[2] == -1)
				tp->ui.UserPm_3->setItem(16, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_3->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[2]]].name)));
			if (p->skill_bar[3] == -1)
				tp->ui.UserPm_3->setItem(17, 0, new QTableWidgetItem("NULL"));
			else
				tp->ui.UserPm_3->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(p->skills[p->skill_list[p->skill_bar[3]]].name)));
			switch (p->nature)
			{
			case 1:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
			case 2:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
			case 3:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Brave")); break;
			case 4:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
			case 5:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
			case 6:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Bold")); break;
			case 7:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Docile")); break;
			case 8:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
			case 9:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Impish")); break;
			case 10:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Lax")); break;
			case 11:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Timid")); break;
			case 12:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
			case 13:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Serious")); break;
			case 14:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
			case 15:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Naive")); break;
			case 16:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Modest")); break;
			case 17:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Mild")); break;
			case 18:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
			case 19:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
			case 20:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Rash")); break;
			case 21:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Calm")); break;
			case 22:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
			case 23:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
			case 24:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Careful")); break;
			case 25:tp->ui.UserPm_3->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
			}
			switch (p->Ppt)
			{
			case 1:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Normal")); break;
			case 2:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Fire")); break;
			case 3:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Bug")); break;
			case 4:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Water")); break;
			case 5:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Poison")); break;
			case 6:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Electric")); break;
			case 7:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Flying")); break;
			case 8:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Grass")); break;
			case 9:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Ground")); break;
			case 10:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Ice")); break;
			case 11:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
			case 12:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
			case 13:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Rock")); break;
			case 14:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
			case 15:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
			case 16:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Dark")); break;
			case 17:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Steel")); break;
			case 18:tp->ui.UserPm_3->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
			}
		}
	}
}
void MainWindow::SkillBar1()
{
	Pptr->select_skill = 0;
}
void MainWindow::SkillBar2()
{
	Pptr->select_skill = 1;
}
void MainWindow::SkillBar3()
{
	Pptr->select_skill = 2;
}
void MainWindow::SkillBar4()
{
	Pptr->select_skill = 3;
}
void MainWindow::Exit()
{
	emit exit();
	hide();
}
void MainWindow::push1()
{
	int j = 0;
	Pokemon* p;
	for (auto i = pv.begin(); i != pv.end(); i++)
	{
		if (j == pm[0])
		{
			p = (*i);
			emit erasepm(p->onlyid);
			i = pv.erase(i);
			show();
			tp->hide();
			showpms(UPtr->username);
			return;
		}
		j++;
	}
}
void MainWindow::push2()
{
	int j = 0;
	Pokemon* p;
	for (auto i = pv.begin(); i != pv.end(); i++)
	{
		if (j == pm[1])
		{
			p = (*i);
			emit erasepm(p->onlyid);
			i = pv.erase(i);
			show();
			tp->hide();
			showpms(UPtr->username);
			return;
		}
		j++;
	}
}
void MainWindow::push3()
{
	int j = 0;
	Pokemon* p;
	for (auto i = pv.begin(); i != pv.end(); i++)
	{
		if (j == pm[2])
		{
			p = (*i); 
			emit erasepm(p->onlyid);
			i = pv.erase(i);
			show();
			tp->hide();
			showpms(UPtr->username);
			return;
		}
		j++;
	}
}
void MainWindow::onlineuser()
{
	userlist.clear();
	int counter = ui->UserList->count();
	for (int i = 0; i < counter; i++)
	{
		QListWidgetItem *item = ui->UserList->takeItem(0);
		delete item;
	}
	emit requestuser(userlist);
	for (auto i = userlist.begin(); i != userlist.end(); i++)
	{
		ui->UserList->addItem(QString::fromStdString((*i)->username));
	}
}
void MainWindow::closeEvent(QCloseEvent * event)
{
	emit exit();
	QApplication* app;
	app->exit(0);
}
void MainWindow::showuserinfo(QListWidgetItem *item1)
{
	int r = ui->UserList->row(item1);
	ouPtr = userlist.at(r);
	ou->ui.UserTable->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(ouPtr->username)));
	ou->ui.UserTable->setItem(1, 0, new QTableWidgetItem(QString::number(ouPtr->WinNum)));
	ou->ui.UserTable->setItem(2, 0, new QTableWidgetItem(QString::number(ouPtr->LossNum)));
	ou->ui.UserTable->setItem(3, 0, new QTableWidgetItem(QString::number(ouPtr->WinRate)));
	ou->ui.UserTable->setItem(4, 0, new QTableWidgetItem(QString::number(ouPtr->PmNum)));
	ou->ui.UserTable->setItem(5, 0, new QTableWidgetItem(QString::number(ouPtr->PerPmNum)));
	ou->ui.UserTable->setItem(6, 0, new QTableWidgetItem(QString::number(ouPtr->AchNum)));
	QTableWidgetItem *item = new QTableWidgetItem(QString::fromStdString(ouPtr->Ach[0]));
	switch (ouPtr->AchLevel[0])
	{
	case 1:item->setTextColor(QColor(0, 0, 0)); break;
	case 2:item->setTextColor(QColor(170, 255, 0)); break;
	case 3:item->setTextColor(QColor(112, 168, 0)); break;
	case 4:item->setTextColor(QColor(170, 255, 255)); break;
	case 5:item->setTextColor(QColor(136, 204, 204)); break;
	case 6:item->setTextColor(QColor(255, 255, 127)); break;
	case 7:item->setTextColor(QColor(222, 222, 110)); break;
	case 8:item->setTextColor(QColor(170, 170, 255)); break;
	case 9:item->setTextColor(QColor(121, 121, 181)); break;
	case 10:item->setTextColor(QColor(255, 0, 0)); break;
	}
	ou->ui.UserTable->setItem(7, 0, item);
	QTableWidgetItem *item2 = new QTableWidgetItem(QString::fromStdString(ouPtr->Ach[1]));
	switch (ouPtr->AchLevel[1])
	{
	case 1:item2->setTextColor(QColor(0, 0, 0)); break;
	case 2:item2->setTextColor(QColor(170, 255, 0)); break;
	case 3:item2->setTextColor(QColor(112, 168, 0)); break;
	case 4:item2->setTextColor(QColor(170, 255, 255)); break;
	case 5:item2->setTextColor(QColor(136, 204, 204)); break;
	case 6:item2->setTextColor(QColor(255, 255, 127)); break;
	case 7:item2->setTextColor(QColor(222, 222, 110)); break;
	case 8:item2->setTextColor(QColor(170, 170, 255)); break;
	case 9:item2->setTextColor(QColor(121, 121, 181)); break;
	case 10:item2->setTextColor(QColor(255, 0, 0)); break;
	}
	ou->ui.UserTable->setItem(8, 0, item2);
	opv.clear();
	ou->ui.PMList->clear();
	emit displaypms(ouPtr->username, opv);
	for (auto i = opv.begin(); i != opv.end(); i++)
	{
		QListWidgetItem* item3 = new QListWidgetItem;
		QString qs;
		qs = QString::fromStdString((*(*i)).name);
		item3->setText(qs);
		ou->ui.PMList->addItem(item3);
	}
	ou->show();
	hide();
}
void MainWindow::ChangeOtherOp(QListWidgetItem *item)
{
	int r = ou->ui.PMList->row(item);
	optr = opv.at(r);
	ou->ui.UserPm->setItem(0, 0, new QTableWidgetItem(QString::fromStdString(optr->name)));
	ou->ui.UserPm->setItem(1, 0, new QTableWidgetItem(QString::number(optr->id)));
	ou->ui.UserPm->setItem(2, 0, new QTableWidgetItem(QString::fromStdString(optr->nicky)));
	ou->ui.UserPm->setItem(3, 0, new QTableWidgetItem(QString::number(optr->grade)));
	ou->ui.UserPm->setItem(4, 0, new QTableWidgetItem(QString::number(optr->Exp)));
	ou->ui.UserPm->setItem(7, 0, new QTableWidgetItem(QString::number(optr->Hp.InitialValue)));
	ou->ui.UserPm->setItem(8, 0, new QTableWidgetItem(QString::number(optr->Atk.InitialValue)));
	ou->ui.UserPm->setItem(9, 0, new QTableWidgetItem(QString::number(optr->Sat.InitialValue)));
	ou->ui.UserPm->setItem(10, 0, new QTableWidgetItem(QString::number(optr->Def.InitialValue)));
	ou->ui.UserPm->setItem(11, 0, new QTableWidgetItem(QString::number(optr->Sdf.InitialValue)));
	ou->ui.UserPm->setItem(12, 0, new QTableWidgetItem(QString::number(optr->Spe.InitialValue)));
	ou->ui.UserPm->setItem(13, 0, new QTableWidgetItem(QString::number(optr->al_have_skills)));
	if (optr->skill_bar[0] == -1)
		ou->ui.UserPm->setItem(14, 0, new QTableWidgetItem("NULL"));
	else
		ou->ui.UserPm->setItem(14, 0, new QTableWidgetItem(QString::fromStdString(optr->skills[optr->skill_list[optr->skill_bar[0]]].name)));
	if (optr->skill_bar[1] == -1)
		ou->ui.UserPm->setItem(15, 0, new QTableWidgetItem("NULL"));
	else
		ou->ui.UserPm->setItem(15, 0, new QTableWidgetItem(QString::fromStdString(optr->skills[optr->skill_list[optr->skill_bar[1]]].name)));
	if (optr->skill_bar[2] == -1)
		ou->ui.UserPm->setItem(16, 0, new QTableWidgetItem("NULL"));
	else
		ou->ui.UserPm->setItem(16, 0, new QTableWidgetItem(QString::fromStdString(optr->skills[optr->skill_list[optr->skill_bar[2]]].name)));
	if (optr->skill_bar[3] == -1)
		ou->ui.UserPm->setItem(17, 0, new QTableWidgetItem("NULL"));
	else
		ou->ui.UserPm->setItem(17, 0, new QTableWidgetItem(QString::fromStdString(optr->skills[optr->skill_list[optr->skill_bar[3]]].name)));
	switch (optr->nature)
	{
	case 1:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Hardy")); break;
	case 2:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Lonely")); break;
	case 3:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Brave")); break;
	case 4:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Adamant")); break;
	case 5:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Naughty")); break;
	case 6:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Bold")); break;
	case 7:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Docile")); break;
	case 8:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Relaxed")); break;
	case 9:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Impish")); break;
	case 10:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Lax")); break;
	case 11:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Timid")); break;
	case 12:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Hasty")); break;
	case 13:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Serious")); break;
	case 14:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Jolly")); break;
	case 15:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Naive")); break;
	case 16:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Modest")); break;
	case 17:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Mild")); break;
	case 18:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Quiet")); break;
	case 19:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Bashful")); break;
	case 20:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Rash")); break;
	case 21:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Calm")); break;
	case 22:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Gentle")); break;
	case 23:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Sassy")); break;
	case 24:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Careful")); break;
	case 25:ou->ui.UserPm->setItem(5, 0, new QTableWidgetItem("Quirky")); break;
	}
	switch (optr->Ppt)
	{
	case 1:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Normal")); break;
	case 2:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Fire")); break;
	case 3:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Bug")); break;
	case 4:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Water")); break;
	case 5:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Poison")); break;
	case 6:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Electric")); break;
	case 7:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Flying")); break;
	case 8:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Grass")); break;
	case 9:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Ground")); break;
	case 10:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Ice")); break;
	case 11:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Fighting")); break;
	case 12:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Psychic")); break;
	case 13:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Rock")); break;
	case 14:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Ghost")); break;
	case 15:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Dragon")); break;
	case 16:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Dark")); break;
	case 17:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Steel")); break;
	case 18:ou->ui.UserPm->setItem(6, 0, new QTableWidgetItem("Fairy")); break;
	}
}
void MainWindow::changechoose(QListWidgetItem *item)
{
	chooseskill= sr->ui.Skills->row(item);
}
void MainWindow::change1()
{
	Pptr->skill_bar[0] = chooseskill;
	ui->Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	sr->ui.Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
}
void MainWindow::change2()
{
	Pptr->skill_bar[1] = chooseskill;
	ui->Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	sr->ui.Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
}
void MainWindow::change3()
{
	Pptr->skill_bar[2] = chooseskill;
	ui->Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	sr->ui.Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
}
void MainWindow::change4()
{
	Pptr->skill_bar[3] = chooseskill;
	ui->Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	sr->ui.Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
}