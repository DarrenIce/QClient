#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	tp = new ThrowPkm(this);
	tp->hide();
    lw=new LoginWindow;
	timer = new QTimer(this);
	QObject::connect(lw, &LoginWindow::LoginInfo, this, &MainWindow::SendLoginInfo);
    QObject::connect(lw,&LoginWindow::showmainwindow,this,&MainWindow::showmainwindow);
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
	QObject::connect(this, &MainWindow::throwpkm, tp, &ThrowPkm::throwpkm);
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
	ui->username->setText(QString::fromStdString(UPtr->username));
	ui->winnum->setText(QString::number(UPtr->WinNum));
	ui->lossnum->setText(QString::number(UPtr->LossNum));
	ui->winrate->setText(QString::number(UPtr->WinRate));
	ui->pmnum->setText(QString::number(UPtr->PmNum));
	ui->fulllevel->setText(QString::number(UPtr->PerPmNum));
	ui->achinum->setText(QString::number(UPtr->AchNum));
	switch (UPtr->AchLevel[0])
	{
	case 1:ui->titel1->setStyleSheet("font:bold,color:white");
	case 2:ui->titel1->setStyleSheet("font:bold,color:green");
	case 3:ui->titel1->setStyleSheet("font:bold,color:darkGreen");
	case 4:ui->titel1->setStyleSheet("font:bold,color:blue");
	case 5:ui->titel1->setStyleSheet("font:bold,color:darkBlue");
	case 6:ui->titel1->setStyleSheet("font:bold,color:yellow");
	case 7:ui->titel1->setStyleSheet("font:bold,color:darkYellow");
	case 8:ui->titel1->setStyleSheet("font:bold,color:magenta");
	case 9:ui->titel1->setStyleSheet("font:bold,color:darkMagenta");
	case 10:ui->titel1->setStyleSheet("font:bold,color:red");
	}
	ui->titel1->setText(QString::fromStdString(UPtr->Ach[0]));
	switch (UPtr->AchLevel[1])
	{
	case 1:ui->titel2->setStyleSheet("font:bold,color:white");
	case 2:ui->titel2->setStyleSheet("font:bold,color:green");
	case 3:ui->titel2->setStyleSheet("font:bold,color:darkGreen");
	case 4:ui->titel2->setStyleSheet("font:bold,color:blue");
	case 5:ui->titel2->setStyleSheet("font:bold,color:darkBlue");
	case 6:ui->titel2->setStyleSheet("font:bold,color:yellow");
	case 7:ui->titel2->setStyleSheet("font:bold,color:darkYellow");
	case 8:ui->titel2->setStyleSheet("font:bold,color:magenta");
	case 9:ui->titel2->setStyleSheet("font:bold,color:darkMagenta");
	case 10:ui->titel2->setStyleSheet("font:bold,color:red");
	}
	ui->titel2->setText(QString::fromStdString(UPtr->Ach[1]));
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
		if ((*i)->grade == 100)
			UPtr->PerPmNum++;
    }
	ui->pmnum->setText(QString::number(UPtr->PmNum));
	ui->fulllevel->setText(QString::number(UPtr->PerPmNum));
}
void MainWindow::ChangeUserOp(QListWidgetItem *item)
{
	int r = ui->PMList->row(item);
	Pptr = pv.at(r);
	ui->name->setText(QString::fromStdString(Pptr->name));
	ui->id->setText(QString::number(Pptr->id));
	ui->nicky->setText(QString::fromStdString(Pptr->nicky));
	ui->grade->setText(QString::number(Pptr->grade));
	ui->exp->setText(QString::number(Pptr->Exp));
	ui->hp->setText(QString::number(Pptr->Hp.InitialValue));
	ui->atk->setText(QString::number(Pptr->Atk.InitialValue));
	ui->sat->setText(QString::number(Pptr->Sat.InitialValue));
	ui->def->setText(QString::number(Pptr->Def.InitialValue));
	ui->sdf->setText(QString::number(Pptr->Sdf.InitialValue));
	ui->spe->setText(QString::number(Pptr->Spe.InitialValue));
	ui->skillnum->setText(QString::number(Pptr->al_have_skills));
	if (Pptr->skill_bar[0] == -1)
		ui->skillbar1->setText("NULL");
	else if (Pptr->skill_bar[0] == 0)
	{
		ui->skillbar1->setText("Attack");
	}
	else
		ui->skillbar1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	if (Pptr->skill_bar[1] == -1)
		ui->skillbar2->setText("NULL");
	else if (Pptr->skill_bar[1] == 0)
	{
		ui->skillbar2->setText("Attack");
	}
	else
		ui->skillbar2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	if (Pptr->skill_bar[2] == -1)
		ui->skillbar3->setText("NULL");
	else if (Pptr->skill_bar[2] == 0)
	{
		ui->skillbar3->setText("Attack");
	}
	else
		ui->skillbar3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	if (Pptr->skill_bar[3] == -1)
		ui->skillbar4->setText("NULL");
	else if (Pptr->skill_bar[3] == 0)
	{
		ui->skillbar4->setText("Attack");
	}
	else
		ui->skillbar4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	switch (Pptr->nature)
	{
	case 1:ui->nature->setText("Hardy"); break;
	case 2:ui->nature->setText("Lonely"); break;
	case 3:ui->nature->setText("Brave"); break;
	case 4:ui->nature->setText("Adamant"); break;
	case 5:ui->nature->setText("Naughty"); break;
	case 6:ui->nature->setText("Bold"); break;
	case 7:ui->nature->setText("Docile"); break;
	case 8:ui->nature->setText("Relaxed"); break;
	case 9:ui->nature->setText("Impish"); break;
	case 10:ui->nature->setText("Lax"); break;
	case 11:ui->nature->setText("Timid"); break;
	case 12:ui->nature->setText("Hasty"); break;
	case 13:ui->nature->setText("Serious"); break;
	case 14:ui->nature->setText("Jolly"); break;
	case 15:ui->nature->setText("Naive"); break;
	case 16:ui->nature->setText("Modest"); break;
	case 17:ui->nature->setText("Mild"); break;
	case 18:ui->nature->setText("Quiet"); break;
	case 19:ui->nature->setText("Bashful"); break;
	case 20:ui->nature->setText("Rash"); break;
	case 21:ui->nature->setText("Calm"); break;
	case 22:ui->nature->setText("Gentle"); break;
	case 23:ui->nature->setText("Sassy"); break;
	case 24:ui->nature->setText("Careful"); break;
	case 25:ui->nature->setText("Quirky"); break;
	}
	switch (Pptr->Ppt)
	{
	case 1:ui->property->setText("Normal"); break;
	case 2:ui->property->setText("Fire"); break;
	case 3:ui->property->setText("Bug"); break;
	case 4:ui->property->setText("Water"); break;
	case 5:ui->property->setText("Poison"); break;
	case 6:ui->property->setText("Electric"); break;
	case 7:ui->property->setText("Flying"); break;
	case 8:ui->property->setText("Grass"); break;
	case 9:ui->property->setText("Ground"); break;
	case 10:ui->property->setText("Ice"); break;
	case 11:ui->property->setText("Fighting"); break;
	case 12:ui->property->setText("Psychic"); break;
	case 13:ui->property->setText("Rock"); break;
	case 14:ui->property->setText("Ghost"); break;
	case 15:ui->property->setText("Dragon"); break;
	case 16:ui->property->setText("Dark"); break;
	case 17:ui->property->setText("Steel"); break;
	case 18:ui->property->setText("Fairy"); break;
	}
}
void MainWindow::ChangePmOp()
{
	ui->name2->setText(QString::fromStdString(PMptr->name));
	ui->hp2->setText(QString::number(PMptr->Hp.InitialValue));
	ui->atk2->setText(QString::number(PMptr->Atk.InitialValue));
	ui->sat2->setText(QString::number(PMptr->Sat.InitialValue));
	ui->def2->setText(QString::number(PMptr->Def.InitialValue));
	ui->sdf2->setText(QString::number(PMptr->Sdf.InitialValue));
	ui->spe2->setText(QString::number(PMptr->Spe.InitialValue));
	if (PMptr->skill_bar[0] == -1)
		ui->skillbar2_1->setText("NULL");
	else if (PMptr->skill_bar[0] == 0)
	{
		ui->skillbar2_1->setText("Attack");
	}
	else
		ui->skillbar2_1->setText(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[0]]].name));
	if (PMptr->skill_bar[1] == -1)
		ui->skillbar2_2->setText("NULL");
	else if (PMptr->skill_bar[1] == 0)
	{
		ui->skillbar2_2->setText("Attack");
	}
	else
		ui->skillbar2_2->setText(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[1]]].name));
	if (PMptr->skill_bar[2] == -1)
		ui->skillbar2_3->setText("NULL");
	else if (PMptr->skill_bar[2] == 0)
	{
		ui->skillbar2_3->setText("Attack");
	}
	else
		ui->skillbar2_3->setText(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[2]]].name));
	if (PMptr->skill_bar[3] == -1)
		ui->skillbar2_4->setText("NULL");
	else if (PMptr->skill_bar[3] == 0)
	{
		ui->skillbar2_4->setText("Attack");
	}
	else
		ui->skillbar2_4->setText(QString::fromStdString(PMptr->skills[PMptr->skill_list[PMptr->skill_bar[3]]].name));
	switch (PMptr->nature)
	{
	case 1:ui->nature2->setText("Hardy"); break;
	case 2:ui->nature2->setText("Lonely"); break;
	case 3:ui->nature2->setText("Brave"); break;
	case 4:ui->nature2->setText("Adamant"); break;
	case 5:ui->nature2->setText("Naughty"); break;
	case 6:ui->nature2->setText("Bold"); break;
	case 7:ui->nature2->setText("Docile"); break;
	case 8:ui->nature2->setText("Relaxed"); break;
	case 9:ui->nature2->setText("Impish"); break;
	case 10:ui->nature2->setText("Lax"); break;
	case 11:ui->nature2->setText("Timid"); break;
	case 12:ui->nature2->setText("Hasty"); break;
	case 13:ui->nature2->setText("Serious"); break;
	case 14:ui->nature2->setText("Jolly"); break;
	case 15:ui->nature2->setText("Naive"); break;
	case 16:ui->nature2->setText("Modest"); break;
	case 17:ui->nature2->setText("Mild"); break;
	case 18:ui->nature2->setText("Quiet"); break;
	case 19:ui->nature2->setText("Bashful"); break;
	case 20:ui->nature2->setText("Rash"); break;
	case 21:ui->nature2->setText("Calm"); break;
	case 22:ui->nature2->setText("Gentle"); break;
	case 23:ui->nature2->setText("Sassy"); break;
	case 24:ui->nature2->setText("Careful"); break;
	case 25:ui->nature2->setText("Quirky"); break;
	}
	switch (PMptr->Ppt)
	{
	case 1:ui->property2->setText("Normal"); break;
	case 2:ui->property2->setText("Fire"); break;
	case 3:ui->property2->setText("Bug"); break;
	case 4:ui->property2->setText("Water"); break;
	case 5:ui->property2->setText("Poison"); break;
	case 6:ui->property2->setText("Electric"); break;
	case 7:ui->property2->setText("Flying"); break;
	case 8:ui->property2->setText("Grass"); break;
	case 9:ui->property2->setText("Ground"); break;
	case 10:ui->property2->setText("Ice"); break;
	case 11:ui->property2->setText("Fighting"); break;
	case 12:ui->property2->setText("Psychic"); break;
	case 13:ui->property2->setText("Rock"); break;
	case 14:ui->property2->setText("Ghost"); break;
	case 15:ui->property2->setText("Dragon"); break;
	case 16:ui->property2->setText("Dark"); break;
	case 17:ui->property2->setText("Steel"); break;
	case 18:ui->property2->setText("Fairy"); break;
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
}
void MainWindow::ShowSkill()
{
	QMessageBox msg;
	char cont[256];
	sprintf_s(cont, "You get a new skill,named '%s'", Pptr->skills[Pptr->skill_list[Pptr->al_have_skills - 1]].name.c_str());
	msg.setText(QString::fromStdString(cont));
	msg.setInformativeText("Do you want it?");
	QPushButton* replace1 = (msg.addButton("Replace skill 1", QMessageBox::AcceptRole));
	QPushButton* replace2 = (msg.addButton("Replace skill 2", QMessageBox::AcceptRole));
	QPushButton* replace3 = (msg.addButton("Replace skill 3", QMessageBox::AcceptRole));
	QPushButton* replace4 = (msg.addButton("Replace skill 4", QMessageBox::AcceptRole));
	QPushButton* no = (msg.addButton("Don't replace", QMessageBox::RejectRole));
	msg.setDefaultButton(no);
	msg.exec();
	if (msg.clickedButton() == replace1)
	{
		Pptr->skill_bar[0] = Pptr->al_have_skills - 1;
		ui->Skill1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	}
	else if (msg.clickedButton() == replace2)
	{
		Pptr->skill_bar[1] = Pptr->al_have_skills - 1;
		ui->Skill2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	}
	else if (msg.clickedButton() == replace3)
	{
		Pptr->skill_bar[2] = Pptr->al_have_skills - 1;
		ui->Skill3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	}
	else if (msg.clickedButton() == replace4)
	{
		Pptr->skill_bar[3] = Pptr->al_have_skills - 1;
		ui->Skill4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	}
	ui->skillnum->setText(QString::number(Pptr->al_have_skills));
	if (Pptr->skill_bar[0] == -1)
		ui->skillbar1->setText("NULL");
	else if (Pptr->skill_bar[0] == 0)
	{
		ui->skillbar1->setText("Attack");
	}
	else
		ui->skillbar1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	if (Pptr->skill_bar[1] == -1)
		ui->skillbar2->setText("NULL");
	else if (Pptr->skill_bar[1] == 0)
	{
		ui->skillbar2->setText("Attack");
	}
	else
		ui->skillbar2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	if (Pptr->skill_bar[2] == -1)
		ui->skillbar3->setText("NULL");
	else if (Pptr->skill_bar[2] == 0)
	{
		ui->skillbar3->setText("Attack");
	}
	else
		ui->skillbar3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	if (Pptr->skill_bar[3] == -1)
		ui->skillbar4->setText("NULL");
	else if (Pptr->skill_bar[3] == 0)
	{
		ui->skillbar4->setText("Attack");
	}
	else
		ui->skillbar4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
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
			for (auto i = strs.begin();i != strs.end(); i++)
			{
				ui->FightInfo->append(QString::fromStdString((*i)));
			}
		}
		strs.clear();
		ui->PmHp->setValue((PMptr->Hp.FightValue * 100) / PMptr->Hp.InitialValue);
		if (time2 == 0 && PMptr->Hp.FightValue != 0)
		{
			time2 = PMptr->SpeedMap();
			PMptr->select_skill = PMptr->r.get(0, 3);
			PMptr->Fight(Pptr,strs);
			for (auto i = strs.begin(); i != strs.end(); i++)
			{
				ui->FightInfo->append(QString::fromStdString((*i)));
			}
		}
		strs.clear();
		ui->UserHp->setValue((Pptr->Hp.FightValue*100) / Pptr->Hp.InitialValue );
	}
	if (Pptr->Hp.FightValue == 0)
	{
		UPtr->LossNum++;
		UPtr->UpdateWinRate();
		ui->lossnum->setText(QString::number(UPtr->LossNum));
		ui->winrate->setText(QString::number(UPtr->WinRate));
		emit UserLoss(UPtr);
		timer->stop();
		ui->StartMatch->setEnabled(false);
		ui->UserHp->setValue(100);
		ui->PmHp->setValue(100);
		if (choosematch == 2)
		{
			emit throwpm();
			//随机显示用户三只精灵
			//如果不足三只全部显示
			//用户挑选一只扔掉
			//如果用户精灵变0，则随机送一只初始给用户
		}
	}
	else if (PMptr->Hp.FightValue == 0)
	{
		int bl = Pptr->grade;
		int bs = Pptr->al_have_skills;
		Pptr->AddExp(PMptr->grade);
		ui->exp->setText(QString::number(Pptr->Exp));
		int al = Pptr->grade;
		int as = Pptr->al_have_skills;
		if (bs != as)
		{
			emit showskill();
		}
		if (bl != al)
		{
			ui->grade->setText(QString::number(Pptr->grade));
			ui->hp->setText(QString::number(Pptr->Hp.InitialValue));
			ui->atk->setText(QString::number(Pptr->Atk.InitialValue));
			ui->sat->setText(QString::number(Pptr->Sat.InitialValue));
			ui->def->setText(QString::number(Pptr->Def.InitialValue));
			ui->sdf->setText(QString::number(Pptr->Sdf.InitialValue));
			ui->spe->setText(QString::number(Pptr->Spe.InitialValue));
		}
		//如果升级，技能替换的设计，更新界面属性
		//后续考虑弹窗提示升级
		UPtr->WinNum++;
		UPtr->UpdateWinRate();
		ui->winnum->setText(QString::number(UPtr->WinNum));
		ui->winrate->setText(QString::number(UPtr->WinRate));
		if (bl != al&&al == 100)
		{
			UPtr->PerPmNum++;
			UPtr->PerPmAch();
			switch (UPtr->AchLevel[1])
			{
			case 1:ui->titel2->setStyleSheet("font:bold,color:white");
			case 2:ui->titel2->setStyleSheet("font:bold,color:green");
			case 3:ui->titel2->setStyleSheet("font:bold,color:darkGreen");
			case 4:ui->titel2->setStyleSheet("font:bold,color:blue");
			case 5:ui->titel2->setStyleSheet("font:bold,color:darkBlue");
			case 6:ui->titel2->setStyleSheet("font:bold,color:yellow");
			case 7:ui->titel2->setStyleSheet("font:bold,color:darkYellow");
			case 8:ui->titel2->setStyleSheet("font:bold,color:magenta");
			case 9:ui->titel2->setStyleSheet("font:bold,color:darkMagenta");
			case 10:ui->titel2->setStyleSheet("font:bold,color:red");
			}
			ui->titel2->setText(QString::fromStdString(UPtr->Ach[2]));
		}
		timer->stop();
		ui->StartMatch->setEnabled(false);
		ui->UserHp->setValue(100);
		ui->PmHp->setValue(100);
		if (choosematch == 2)
		{
			UPtr->PmNum++;
			emit AddPm(PMptr);
			showpms(UPtr->username);
		}
		emit UserWin(UPtr, pv);
	}
	//循环体 双方FightValue不为零时循环
	//每次循环中两个定时器自减，减到0发动攻击并重新初始化定时器
	//怪物在每次攻击前随机select_skill值
	//写四个函数对应四个button 按下相应button 则select_skill值改变
	//有一方死亡则退出循环，并发送信号，让Client发送数据
	//用户赢了则根据怪物等级增加经验，失败无损失（升级赛）
}
//在状态栏滚动在线用户信息
//界面的美化
//线程优化
void MainWindow::Throwpm()
{
	emit throwpkm(UPtr, pv);
	tp->show();
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
}