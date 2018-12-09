#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lw=new LoginWindow;
	QObject::connect(lw, &LoginWindow::LoginInfo, this, &MainWindow::SendLoginInfo);
    QObject::connect(lw,&LoginWindow::showmainwindow,this,&MainWindow::showmainwindow);
    QObject::connect(lw,&LoginWindow::showpms,this,&MainWindow::showpms);
	QObject::connect(ui->PMList, &QListWidget::itemClicked, this, &MainWindow::ChangeUserOp);
	QObject::connect(ui->CreatePm, SIGNAL(clicked(bool)), this, SLOT(CreatePm()));
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
    delete ui;
}
void MainWindow::SendLoginInfo(const std::string &username, const std::string &password, int &state)
{
	UserInfo userinfo;
	emit LoginInfo(username, password, state, userinfo);
	UPtr = new User(userinfo);
	if (state == 1)
	{
		//ui->username
	}
}
void MainWindow::showmainwindow()
{
    this->setVisible(true);
}
void MainWindow::showpms(const std::string &username)
{
    emit displaypms(username,pv);

    for (auto i = pv.begin(); i != pv.end(); i++)
    {
        QListWidgetItem* item=new QListWidgetItem;
        QString qs;
        qs=QString::fromStdString((*(*i)).name);
        item->setText(qs);
        ui->PMList->addItem(item);
    }
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
	ui->name2->setText(QString::fromStdString(Pptr->name));
	ui->hp2->setText(QString::number(Pptr->Hp.InitialValue));
	ui->atk2->setText(QString::number(Pptr->Atk.InitialValue));
	ui->sat2->setText(QString::number(Pptr->Sat.InitialValue));
	ui->def2->setText(QString::number(Pptr->Def.InitialValue));
	ui->sdf2->setText(QString::number(Pptr->Sdf.InitialValue));
	ui->spe2->setText(QString::number(Pptr->Spe.InitialValue));
	if (Pptr->skill_bar[0] == -1)
		ui->skillbar2_1->setText("NULL");
	else if (Pptr->skill_bar[0] == 0)
	{
		ui->skillbar2_1->setText("Attack");
	}
	else
		ui->skillbar2_1->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[0]]].name));
	if (Pptr->skill_bar[1] == -1)
		ui->skillbar2_2->setText("NULL");
	else if (Pptr->skill_bar[1] == 0)
	{
		ui->skillbar2_2->setText("Attack");
	}
	else
		ui->skillbar2_2->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[1]]].name));
	if (Pptr->skill_bar[2] == -1)
		ui->skillbar2_3->setText("NULL");
	else if (Pptr->skill_bar[2] == 0)
	{
		ui->skillbar2_3->setText("Attack");
	}
	else
		ui->skillbar2_3->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[2]]].name));
	if (Pptr->skill_bar[3] == -1)
		ui->skillbar2_4->setText("NULL");
	else if (Pptr->skill_bar[3] == 0)
	{
		ui->skillbar2_4->setText("Attack");
	}
	else
		ui->skillbar2_4->setText(QString::fromStdString(Pptr->skills[Pptr->skill_list[Pptr->skill_bar[3]]].name));
	switch (Pptr->nature)
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
	switch (Pptr->Ppt)
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
}
void MainWindow::Fight1()
{
	//根据速度分段映射两个定时器给用户和怪物
	int time1 = Pptr->SpeedMap();
	int time2 = PMptr->SpeedMap();
	Pptr->FightInitial();
	PMptr->FightInitial();
	while (Pptr->Hp.FightValue != 0 && PMptr->Hp.FightValue != 0)
	{
		time1--;
		time2--;
		if (time1 == 0 && Pptr->Hp.FightValue != 0)
		{
			time1 = Pptr->SpeedMap();
			Pptr->Fight(PMptr);
		}
		if (time2 == 0 && PMptr->Hp.FightValue != 0)
		{
			time2 = PMptr->SpeedMap();
			PMptr->select_skill = PMptr->r.get(0, 3);
			PMptr->Fight(Pptr);
		}
	}
	if (Pptr->Hp.FightValue == 0)
	{
		UPtr->LossNum++;
		UPtr->UpdateWinRate();
		//数据通信，更新表
		//user_table负场+1
	}
	else if (PMptr->Hp.FightValue == 0)
	{
		Pptr->AddExp(PMptr->grade);
		//如果升级，技能替换的设计
		UPtr->WinNum++;
		UPtr->UpdateWinRate();
		//数据通信，更新两张表
		//user_table胜场+1,可能更新满级精灵数
		//可能更改成就等级，刷新标签
		//pokemon_table更新精灵等级和经验
		//可能更新技能数，技能bar
	}
	//循环体 双方FightValue不为零时循环
	//每次循环中两个定时器自减，减到0发动攻击并重新初始化定时器
	//怪物在每次攻击前随机select_skill值
	//写四个函数对应四个button 按下相应button 则select_skill值改变
	//有一方死亡则退出循环，并发送信号，让Client发送数据
	//用户赢了则根据怪物等级增加经验，失败无损失（升级赛）
}
//在状态栏滚动在线用户信息
//user_table增加胜场 败场 拥有精灵数 满级精灵数 
//客户端计算胜率 ，根据拥有精灵数 满级精灵数显示相应成就（牌子）并显示
//界面的美化
//线程优化