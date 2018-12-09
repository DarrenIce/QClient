#pragma once
#include "pokemon.h"


class Venusaur : public Pokemon{//003-妙蛙花
public:
	Venusaur();//初始化精灵
	Venusaur(int level);
	Venusaur(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};
class Charizard : public Pokemon{//006-喷火龙
public:
	Charizard();//初始化精灵
	Charizard(int level);
	Charizard(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};
class Blastoise : public Pokemon {//009-水箭龟
public:
	Blastoise();//初始化精灵
	Blastoise(int level);
	Blastoise(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};