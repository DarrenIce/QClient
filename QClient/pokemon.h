#pragma once
#include<string>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

#define MAX_NAME 100

//��ʱû�п���ʵ��������״�����Լ����ָ����ж��ļ���Ҳ�����˼�
//˫�ж�������ʱû��ʵ��,�����������ж�
//��һ��û�ж�����ֵ���������Ծ������ϴ�
//û��˫����
//��ʱ��ʵ�ֽ������ƣ�ֱ��Ϊ���վ����1��
//��ʱ������Ŭ��ֵ
//ÿ�������ʼ��һ�����飬��ʾ�ӵ͵ȼ����ߵȼ���ѧ��ļ��ܱ��
enum PPT
{
	Normal=1,Fire,Bug,Water,//һ��ϵ����ϵ����ϵ��ˮϵ
	Poison,Electric,Flying,Grass,Ground,//��ϵ����ϵ������ϵ����ϵ������ϵ
	Ice,Fighting,Psychic,Rock,//��ϵ����ϵ��������ϵ����ʯϵ
	Ghost,Dragon,Dark,Steel,Fairy//����ϵ����ϵ����ϵ����ϵ������ϵ
};

enum Nature
{
	Hardy=1,Lonely,Brave,Adamant,Naughty,//�ڷܣ��¼�į���¸ң���ִ����Ƥ
	Bold,Docile,Relaxed,Impish,Lax,//�󵨣�̹�ʣ����У�����������
	Timid,Hasty,Serious,Jolly,Naive,//��С�����꣬���棬ˬ�ʣ�����
	Modest,Mild,Quiet,Bashful,Rash,//�����������̣��侲�����ߣ���
	Calm,Gentle,Sassy,Careful,Quirky//�ºͣ���˳���Դ����أ�����
};

enum Kind
{
	Physical=1,Special,Change//�������⣬�仯
};//��������

enum AdditionalEffect
{
	Nu=0,AtkUp,AtkUpp,AtkDn,AtkDnn,SatUp,SatUpp,SatDn,SatDnn,DefUp,DefUpp,DefDn,DefDnn,SdfUp,SdfUpp,SdfDn,SdfDnn,SpeUp,SpeUpp,SpeDn,SpeDnn,
	//��Ӧ�����������Թ�����������������Է����������������ߺͽ���
	AccUp,AccUpp,AccDn,AccDnn,EvaUp,EvaUpp,EvaDn,EvaDnn,CthUp,CthUpp,CthDn,CthDnn,
	//���С����ܡ����ĵ���ߺͽ���
	poison, paralyze,burn,freeze,sleep,confusion,flinch,leech,reflect,
	//�ж�����ԣ����ˣ�������˯�ߣ����ң����£�����,����
	heal,drain,deleech,protect,combo
	//�ظ�,��ȡ���������,����,����
};//���ܸ���Ч��

typedef struct Attvalue {
	int RacialValue;//����ֵ
	int IndividualValue;//����ֵ
	int BaseStats;//����������Ŭ��ֵ��
}AttValue;//����ֵ���ݽṹ

class Move {
public:
	std::string name;//��������
	int levelreq;//����ȼ�
	bool learn;//�Ƿ���ѧ��
	bool able;//�Ƿ��ڼ�����
	PPT ppt;//��������
	Kind kind;//��������
	int power;//����
	double accuracy;//���У�Ϊ0��ʾ����
	int pp;//��ʹ�ô���
	int residual;//ʣ�����
	AdditionalEffect ae;//����׷��Ч��
	double pb;//ʩ�Ÿ��ʣ�Ϊ0��ʾ����
};//����

class Stats {
public:
	int LastLevelValue;//��һ���ȼ����ֵ
	int InitialValue;//���ֵ
	int BaseLevel;//ս�����������ȼ�
	int ActuallLevel;//ս������ʵ�ʵȼ�
	int FightValue;//ս��ʵ������ֵ
};//����ֵ

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
	std::string name;//��������
	int onlyid;
	int id;//����ID
	std::string nicky;//�ǳ�
	int grade;//����ȼ�
	int Exp;//��ǰ�ȼ��ľ���ֵ;
	Nature nature;//�Ը�
	//����ֵ
	AttValue Str;//����
	AttValue Int;//����
	AttValue Phy;//����
	AttValue Sta;//����--��Ӧ�������
	AttValue Res;//����--��Ӧħ������
	AttValue Agi;//����
	//����ֵ��ʵ�����֣�
	Stats Atk;//������
	Stats Sat;//���Թ���
	Stats Hp;	//Ѫ��
	Stats Def;//�������
	Stats Sdf;//���Է���
	Stats Spe;//�������

	PPT Ppt;//����
	PPT Ppt2;//������
	bool isside;//�Ƿ��и�����
	Move Attack;//��ͨ����

	int CthBL;//���ĵȼ�
	int CthAl;
	int Acc;//������
	int AccBL;//��������������ֵ
	int AccAL;//����������ʵ��ֵ
	int Eva;//�ر���
	int EvaBL;//�ر�����������ֵ
	int EvaAl;//�ر�������ʵ��ֵ
	//����ս���и��ӵ�Ч��
	//�洢���ӵ�Ч������һ�д洢Ч�������ڶ��д洢�����غ���
	//effs�洢����Ч������
	int effs[10];

	Move skills[1000];
	int al_have_skills;//�Ѿ�ӵ�еļ�����
	int skill_list[100];
	int skill_bar[4];//������ 0Ϊ��ͨ���� -1Ϊû�з��ü���
	int select_skill;
	int remainedpp[4];

	Pokemon();//��ʼ��
	//void getPMname();//����������
	void getNature();//��ȡ�Ը�
	void LevelUp();//����
	void AddExp(int gra);//���Ӿ���
	void map();//������ӳ�䵽����ֵ
	void SaveLastLevelValue();//������һ�ȼ�����ֵ

    //void FirstSave(std::string username, sqlite3 *db);
	//void Save();
	void Display();

	//�Ը���������
	double AtkModify();
	double SatModify();
	double DefModify();
	double SdfModify();
	double SpeModify();
	//ս��������������
	void FightInitial();
	void FightModify();
	double PptRestraint(PPT AnoPpt);//���Կ��ƺ���
	void Fight(Pokemon* pm);
	int SpeedMap();
	int Accuracy(Pokemon* pm);
};



class DataSave {
	std::string name;//��������
	int id;//����ID
	std::string nicky;//�ǳ�
	int grade;//����ȼ�
	int Exp;//��ǰ�ȼ��ľ���ֵ;
	Nature nature;//�Ը�
	 //����ֵ
	AttValue Str;//����
	AttValue Int;//����
	AttValue Phy;//����
	AttValue Sta;//����--��Ӧ�������
	AttValue Res;//����--��Ӧħ������
	AttValue Agi;//����
	 //����ֵ��ʵ�����֣�
	Stats Atk;//������
	Stats Sat;//���Թ���
	Stats Hp;	//Ѫ��
	Stats Def;//�������
	Stats Sdf;//���Է���
	Stats Spe;//�������

	PPT Ppt;//����

	int al_have_skills[1000];//�Ѿ�ӵ�еļ��ܣ�0��λ�洢�Ѿ��еļ�����n������n���洢��Ӧ�ļ��ܱ��
	int skill_bar[5];//��������0λ�洢�������м������ܣ�1234�洢����
	
};
