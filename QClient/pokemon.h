#pragma once
#include<string>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define MAX_NAME 100

//暂时没有考虑实现蓄力的状况，以及部分复杂判定的技能也进行了简化
//双判定技能暂时没有实现,仅考虑了主判定
//第一版没有对种族值修正，所以精灵间差距较大
//没有双属性
//暂时不实现进化机制，直接为最终精灵的1级
//暂时不考虑努力值
//每个精灵初始化一个数组，表示从低等级到高等级会学会的技能编号
enum PPT
{
	Normal=1,Fire,Bug,Water,//一般系，火系，虫系，水系
	Poison,Electric,Flying,Grass,Ground,//毒系，电系，飞行系，草系，地面系
	Ice,Fighting,Psychic,Rock,//冰系，格斗系，超能力系，岩石系
	Ghost,Dragon,Dark,Steel,Fairy//幽灵系，龙系，恶系，钢系，妖精系
};

enum Nature
{
	Hardy=1,Lonely,Brave,Adamant,Naughty,//勤奋，怕寂寞，勇敢，固执，顽皮
	Bold,Docile,Relaxed,Impish,Lax,//大胆，坦率，悠闲，淘气，乐天
	Timid,Hasty,Serious,Jolly,Naive,//胆小，急躁，认真，爽朗，天真
	Modest,Mild,Quiet,Bashful,Rash,//内敛，慢吞吞，冷静，害羞，马虎
	Calm,Gentle,Sassy,Careful,Quirky//温和，温顺，自大，慎重，浮躁
};

enum Kind
{
	Physical=1,Special,Change//物理，特殊，变化
};//技能类型

enum AdditionalEffect
{
	Nu=0,AtkUp,AtkUpp,AtkDn,AtkDnn,SatUp,SatUpp,SatDn,SatDnn,DefUp,DefUpp,DefDn,DefDnn,SdfUp,SdfUpp,SdfDn,SdfDnn,SpeUp,SpeUpp,SpeDn,SpeDnn,
	//对应物理攻击，属性攻击，物理防御，属性防御，攻击间隔的提高和降低
	AccUp,AccUpp,AccDn,AccDnn,EvaUp,EvaUpp,EvaDn,EvaDnn,CthUp,CthUpp,CthDn,CthDnn,
	//命中、闪避、会心的提高和降低
	poison, paralyze,burn,freeze,sleep,confusion,flinch,leech,reflect,
	//中毒，麻痹，烧伤，冰冻，睡眠，混乱，害怕，寄生,反弹
	heal,drain,deleech,protect,combo
	//回复,吸取，解除寄生,保护,连击
};//技能附加效果

typedef struct Attvalue {
	int RacialValue;//种族值
	int IndividualValue;//个体值
	int BaseStats;//基础点数（努力值）
}AttValue;//属性值数据结构

class Move {
public:
	std::string name;//技能名称
	int levelreq;//所需等级
	bool learn;//是否已学会
	bool able;//是否在技能栏
	PPT ppt;//技能属性
	Kind kind;//技能类型
	int power;//威力
	double accuracy;//命中，为0表示必中
	int pp;//可使用次数
	int residual;//剩余次数
	AdditionalEffect ae;//技能追加效果
	double pb;//施放概率，为0表示必中
};//技能

class Stats {
public:
	int LastLevelValue;//上一个等级面板值
	int InitialValue;//面板值
	int BaseLevel;//战斗能力基础等级
	int ActuallLevel;//战斗能力实际等级
	int FightValue;//战斗实际能力值
};//能力值

typedef struct pm {
    int num;
    int id;
    int grade;
    int exp;
    int nature;
    int Str, Int, Phy, Sta, Res, Agi;
    int ppt;
    int skills;
    int skillbar[4];
    char name[MAX_NAME];
    char nicky[MAX_NAME];
}PMList;

class RandomNumber {
public:
	RandomNumber() {
		srand(time(0));
	}
	int get(int begin = 0, int end = 1) {
		return rand() % (end - begin + 1) + begin;
	}
};

class Pokemon {
public:
	RandomNumber r;
	std::string name;//精灵名称
	int onlyid;
	int id;//精灵ID
	std::string nicky;//昵称
	int grade;//精灵等级
	int Exp;//当前等级的经验值;
	Nature nature;//性格
	//属性值
	AttValue Str;//力量
	AttValue Int;//智力
	AttValue Phy;//体力
	AttValue Sta;//耐力--对应物理防御
	AttValue Res;//抗性--对应魔法防御
	AttValue Agi;//敏捷
	//能力值（实际体现）
	Stats Atk;//物理攻击
	Stats Sat;//属性攻击
	Stats Hp;	//血量
	Stats Def;//物理防御
	Stats Sdf;//属性防御
	Stats Spe;//攻击间隔

	PPT Ppt;//属性
	PPT Ppt2;//副属性
	bool isside;//是否有副属性
	Move Attack;//普通攻击

	int CthBL;//会心等级
	int CthAl;
	int Acc;//命中率
	int AccBL;//命中率能力基础值
	int AccAL;//命中率能力实际值
	int Eva;//回避率
	int EvaBL;//回避率能力基础值
	int EvaAl;//回避率能力实际值
	//精灵战斗中附加的效果
	//存储附加的效果，第一列存储效果名，第二列存储持续回合数
	//effs存储附加效果数量
	int effs[10];

	Move skills[1000];
	int al_have_skills;//已经拥有的技能数
	int skill_list[100];
	int skill_bar[4];//技能栏 0为普通攻击 -1为没有放置技能
	int select_skill;
	int remainedpp[4];

	Pokemon();//初始化
	//void getPMname();//给精灵命名
	void getNature();//获取性格
	void LevelUp();//升级
	void AddExp(int gra);//增加经验
	void map();//从属性映射到能力值
	void SaveLastLevelValue();//保存上一等级能力值

    //void FirstSave(std::string username, sqlite3 *db);
	//void Save();
	void Display();

	//性格修正函数
	double AtkModify();
	double SatModify();
	double DefModify();
	double SdfModify();
	double SpeModify();
	//战斗能力修正函数
	void FightInitial();
	void FightModify();
	double PptRestraint(PPT AnoPpt);//属性克制函数
	void Fight(Pokemon* pm);
	int SpeedMap();
	int Accuracy(Pokemon* pm);
};



class DataSave {
	std::string name;//精灵名称
	int id;//精灵ID
	std::string nicky;//昵称
	int grade;//精灵等级
	int Exp;//当前等级的经验值;
	Nature nature;//性格
	 //属性值
	AttValue Str;//力量
	AttValue Int;//智力
	AttValue Phy;//体力
	AttValue Sta;//耐力--对应物理防御
	AttValue Res;//抗性--对应魔法防御
	AttValue Agi;//敏捷
	 //能力值（实际体现）
	Stats Atk;//物理攻击
	Stats Sat;//属性攻击
	Stats Hp;	//血量
	Stats Def;//物理防御
	Stats Sdf;//属性防御
	Stats Spe;//攻击间隔

	PPT Ppt;//属性

	int al_have_skills[1000];//已经拥有的技能：0号位存储已经有的技能数n，后续n个存储对应的技能编号
	int skill_bar[5];//技能栏：0位存储技能栏有几个技能，1234存储技能
	
};
