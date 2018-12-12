#pragma once
#include "pokemon.h"

class Bulbasaur : public Pokemon {//001-妙蛙种子
public:
	Bulbasaur();//初始化精灵
	Bulbasaur(int level);
	Bulbasaur(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Ivysaur : public Pokemon {//002-妙蛙草
public:
	Ivysaur();//初始化精灵
	Ivysaur(int level);
	Ivysaur(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Venusaur : public Pokemon{//003-妙蛙花
public:
	Venusaur();//初始化精灵
	Venusaur(int level);
	Venusaur(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};
class Charmander : public Pokemon {//004-小火龙
public:
	Charmander();//初始化精灵
	Charmander(int level);
	Charmander(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Charmeleon : public Pokemon {//005-火恐龙
public:
	Charmeleon();//初始化精灵
	Charmeleon(int level);
	Charmeleon(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Charizard : public Pokemon{//006-喷火龙
public:
	Charizard();//初始化精灵
	Charizard(int level);
	Charizard(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};
class Squirtle : public Pokemon {//007-杰尼龟
public:
	Squirtle();//初始化精灵
	Squirtle(int level);
	Squirtle(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Wartortle : public Pokemon {//008-卡咪龟
public:
	Wartortle();//初始化精灵
	Wartortle(int level);
	Wartortle(PMList pmlist);//用户登录时还原
							//void Evolve();//进化
};
class Blastoise : public Pokemon {//009-水箭龟
public:
	Blastoise();//初始化精灵
	Blastoise(int level);
	Blastoise(PMList pmlist);//用户登录时还原
	//void Evolve();//进化
};
class Pidgey : public Pokemon {//010-波波
public:
	Pidgey();//初始化精灵
	Pidgey(int level);
	Pidgey(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Pidgeotto : public Pokemon {//011-比比鸟
public:
	Pidgeotto();//初始化精灵
	Pidgeotto(int level);
	Pidgeotto(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Pidgeot : public Pokemon {//012-大比鸟
public:
	Pidgeot();//初始化精灵
	Pidgeot(int level);
	Pidgeot(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Pikachu : public Pokemon {//013-皮卡丘
public:
	Pikachu();//初始化精灵
	Pikachu(int level);
	Pikachu(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Raichu : public Pokemon {//014-雷丘
public:
	Raichu();//初始化精灵
	Raichu(int level);
	Raichu(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Clefairy : public Pokemon {//015-皮皮
public:
	Clefairy();//初始化精灵
	Clefairy(int level);
	Clefairy(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};
class Clefable : public Pokemon {//016-皮可西
public:
	Clefable();//初始化精灵
	Clefable(int level);
	Clefable(PMList pmlist);//用户登录时还原
							 //void Evolve();//进化
};