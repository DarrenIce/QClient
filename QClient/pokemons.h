#pragma once
#include "pokemon.h"


class Venusaur : public Pokemon{//003-���ܻ�
public:
	Venusaur();//��ʼ������
	Venusaur(int level);
	Venusaur(PMList pmlist);//�û���¼ʱ��ԭ
	//void Evolve();//����
};
class Charizard : public Pokemon{//006-�����
public:
	Charizard();//��ʼ������
	Charizard(int level);
	Charizard(PMList pmlist);//�û���¼ʱ��ԭ
	//void Evolve();//����
};
class Blastoise : public Pokemon {//009-ˮ����
public:
	Blastoise();//��ʼ������
	Blastoise(int level);
	Blastoise(PMList pmlist);//�û���¼ʱ��ԭ
	//void Evolve();//����
};