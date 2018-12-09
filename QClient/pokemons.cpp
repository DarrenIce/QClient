#include "pokemons.h"
//妙蛙种子、杰尼龟、小火龙、波波、皮卡丘、皮皮
Venusaur::Venusaur()
{
	id = 3;
	name = "Venusaur";
	nicky = "Venusaur";
	Ppt = Grass;
	Ppt2 = Poison;
	isside = true;
	//妙蛙花种族值
	Phy.RacialValue = 80;
	Str.RacialValue = 82;
	Sta.RacialValue = 83;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 80;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 1;
	skill_list[2] = 2;
	skill_list[3] = 3;
	skill_list[4] = 4;
	skill_list[5] = 5;
	skill_list[6] = 6;
	skill_list[7] = 7;
	skill_list[8] = 8;
	skill_list[9] = 9;
	skill_list[10] = 10;
	skill_list[11] = 11;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = Attack.pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Venusaur::Venusaur(int level)
{
	id = 3;
	name = "Venusaur";
	nicky = "Venusaur";
	Ppt = Grass;
	Ppt2 = Poison;
	grade = level;
	isside = true;
	//妙蛙花种族值
	Phy.RacialValue = 80;
	Str.RacialValue = 82;
	Sta.RacialValue = 83;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 80;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 1;
	skill_list[2] = 2;
	skill_list[3] = 3;
	skill_list[4] = 4;
	skill_list[5] = 5;
	skill_list[6] = 6;
	skill_list[7] = 7;
	skill_list[8] = 8;
	skill_list[9] = 9;
	skill_list[10] = 10;
	skill_list[11] = 11;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;
	int count = 0;
	for (int i = 11; i >= 0&&count<4; i--)
	{
		if (skills[skill_list[i]].levelreq < grade)
		{
			skill_bar[count] = i;
			remainedpp[count] = skills[skill_list[i]].pp;
			count++;
		}
	}
}
Venusaur::Venusaur(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Venusaur";
	nicky = pmlist.nicky;
	switch (pmlist.nature)
	{
	case 1:nature = Hardy; break;
	case 2:nature = Lonely; break;
	case 3:nature = Brave; break;
	case 4:nature = Adamant; break;
	case 5:nature = Naughty; break;
	case 6:nature = Bold; break;
	case 7:nature = Docile; break;
	case 8:nature = Relaxed; break;
	case 9:nature = Impish; break;
	case 10:nature = Lax; break;
	case 11:nature = Timid; break;
	case 12:nature = Hasty; break;
	case 13:nature = Serious; break;
	case 14:nature = Jolly; break;
	case 15:nature = Naive; break;
	case 16:nature = Modest; break;
	case 17:nature = Mild; break;
	case 18:nature = Quiet; break;
	case 19:nature = Bashful; break;
	case 20:nature = Rash; break;
	case 21:nature = Calm; break;
	case 22:nature = Gentle; break;
	case 23:nature = Sassy; break;
	case 24:nature = Careful; break;
	case 25:nature = Quirky; break;
	}
	switch (pmlist.ppt)
	{
	case 1:Ppt = Normal; break;
	case 2:Ppt = Fire; break;
	case 3:Ppt = Bug; break;
	case 4:Ppt = Water; break;
	case 5:Ppt = Poison; break;
	case 6:Ppt = Electric; break;
	case 7:Ppt = Flying; break;
	case 8:Ppt = Grass; break;
	case 9:Ppt = Ground; break;
	case 10:Ppt = Ice; break;
	case 11:Ppt = Fighting; break;
	case 12:Ppt = Psychic; break;
	case 13:Ppt = Rock; break;
	case 14:Ppt = Ghost; break;
	case 15:Ppt = Dragon; break;
	case 16:Ppt = Dark; break;
	case 17:Ppt = Steel; break;
	case 18:Ppt = Fairy; break;
	}
	Phy.IndividualValue = pmlist.Phy;
	Int.IndividualValue = pmlist.Int;
	Str.IndividualValue = pmlist.Str;
	Sta.IndividualValue = pmlist.Sta;
	Res.IndividualValue = pmlist.Res;
	Agi.IndividualValue = pmlist.Agi;
	Phy.RacialValue = 80;
	Str.RacialValue = 82;
	Sta.RacialValue = 83;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 80;
	map();
	Attack.ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 1;
	skill_list[2] = 2;
	skill_list[3] = 3;
	skill_list[4] = 4;
	skill_list[5] = 5;
	skill_list[6] = 6;
	skill_list[7] = 7;
	skill_list[8] = 8;
	skill_list[9] = 9;
	skill_list[10] = 10;
	skill_list[11] = 11;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Charizard::Charizard()
{
	id = 6;
	name = "Charizard";
	nicky = "Charizard";
	Ppt = Fire;
	isside = false;

	Phy.RacialValue = 78;
	Str.RacialValue = 84;
	Sta.RacialValue = 78;
	Int.RacialValue = 109;
	Res.RacialValue = 85;
	Agi.RacialValue = 100;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 12;
	skill_list[1] = 13;
	skill_list[2] = 14;
	skill_list[3] = 15;
	skill_list[4] = 16;
	skill_list[5] = 17;
	skill_list[6] = 18;
	skill_list[7] = 19;
	skill_list[8] = 20;
	skill_list[9] = 21;
	skill_list[10] = 22;
	skill_list[11] = 23;
	skill_list[12] = 24;
	skill_list[13] = 25;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = Attack.pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Charizard::Charizard(int level)
{
	id = 6;
	name = "Charizard";
	nicky = "Charizard";
	Ppt = Fire;
	isside = false;
	grade = level;
	Phy.RacialValue = 78;
	Str.RacialValue = 84;
	Sta.RacialValue = 78;
	Int.RacialValue = 109;
	Res.RacialValue = 85;
	Agi.RacialValue = 100;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 12;
	skill_list[1] = 13;
	skill_list[2] = 14;
	skill_list[3] = 15;
	skill_list[4] = 16;
	skill_list[5] = 17;
	skill_list[6] = 18;
	skill_list[7] = 19;
	skill_list[8] = 20;
	skill_list[9] = 21;
	skill_list[10] = 22;
	skill_list[11] = 23;
	skill_list[12] = 24;
	skill_list[13] = 25;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	int count = 0;
	for (int i = 11; i >= 0 && count<4; i--)
	{
		if (skills[skill_list[i]].levelreq < grade)
		{
			skill_bar[count] = i;
			remainedpp[count] = skills[skill_list[i]].pp;
			count++;
		}
	}
}
Charizard::Charizard(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Charizard";
	nicky = pmlist.nicky;
	switch (pmlist.nature)
	{
	case 1:nature = Hardy; break;
	case 2:nature = Lonely; break;
	case 3:nature = Brave; break;
	case 4:nature = Adamant; break;
	case 5:nature = Naughty; break;
	case 6:nature = Bold; break;
	case 7:nature = Docile; break;
	case 8:nature = Relaxed; break;
	case 9:nature = Impish; break;
	case 10:nature = Lax; break;
	case 11:nature = Timid; break;
	case 12:nature = Hasty; break;
	case 13:nature = Serious; break;
	case 14:nature = Jolly; break;
	case 15:nature = Naive; break;
	case 16:nature = Modest; break;
	case 17:nature = Mild; break;
	case 18:nature = Quiet; break;
	case 19:nature = Bashful; break;
	case 20:nature = Rash; break;
	case 21:nature = Calm; break;
	case 22:nature = Gentle; break;
	case 23:nature = Sassy; break;
	case 24:nature = Careful; break;
	case 25:nature = Quirky; break;
	}
	switch (pmlist.ppt)
	{
	case 1:Ppt = Normal; break;
	case 2:Ppt = Fire; break;
	case 3:Ppt = Bug; break;
	case 4:Ppt = Water; break;
	case 5:Ppt = Poison; break;
	case 6:Ppt = Electric; break;
	case 7:Ppt = Flying; break;
	case 8:Ppt = Grass; break;
	case 9:Ppt = Ground; break;
	case 10:Ppt = Ice; break;
	case 11:Ppt = Fighting; break;
	case 12:Ppt = Psychic; break;
	case 13:Ppt = Rock; break;
	case 14:Ppt = Ghost; break;
	case 15:Ppt = Dragon; break;
	case 16:Ppt = Dark; break;
	case 17:Ppt = Steel; break;
	case 18:Ppt = Fairy; break;
	}
	Phy.IndividualValue = pmlist.Phy;
	Int.IndividualValue = pmlist.Int;
	Str.IndividualValue = pmlist.Str;
	Sta.IndividualValue = pmlist.Sta;
	Res.IndividualValue = pmlist.Res;
	Agi.IndividualValue = pmlist.Agi;
	Phy.RacialValue = 78;
	Str.RacialValue = 84;
	Sta.RacialValue = 78;
	Int.RacialValue = 109;
	Res.RacialValue = 85;
	Agi.RacialValue = 100;
	map();
	Attack.ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 12;
	skill_list[1] = 13;
	skill_list[2] = 14;
	skill_list[3] = 15;
	skill_list[4] = 16;
	skill_list[5] = 17;
	skill_list[6] = 18;
	skill_list[7] = 19;
	skill_list[8] = 20;
	skill_list[9] = 21;
	skill_list[10] = 22;
	skill_list[11] = 23;
	skill_list[12] = 24;
	skill_list[13] = 25;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Blastoise::Blastoise()
{
	id = 9;
	name = "Blastoise";
	nicky = "Blastoise";
	Ppt = Water;
	isside = false;
	//妙蛙花种族值
	Phy.RacialValue = 79;
	Str.RacialValue = 83;
	Sta.RacialValue = 100;
	Int.RacialValue = 85;
	Res.RacialValue = 105;
	Agi.RacialValue = 78;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 26;
	skill_list[1] = 27;
	skill_list[2] = 28;
	skill_list[3] = 29;
	skill_list[4] = 30;
	skill_list[5] = 31;
	skill_list[6] = 32;
	skill_list[7] = 33;
	skill_list[8] = 34;
	skill_list[9] = 35;
	skill_list[10] = 36;
	skill_list[11] = 37;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = Attack.pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Blastoise::Blastoise(int level)
{
	id = 9;
	name = "Blastoise";
	nicky = "Blastoise";
	Ppt = Water;
	isside = false;
	grade = level;

	Phy.RacialValue = 79;
	Str.RacialValue = 83;
	Sta.RacialValue = 100;
	Int.RacialValue = 85;
	Res.RacialValue = 105;
	Agi.RacialValue = 78;
	//能力面板值初始化
	map();
	//技能初始化
	Attack.ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 26;
	skill_list[1] = 27;
	skill_list[2] = 28;
	skill_list[3] = 29;
	skill_list[4] = 30;
	skill_list[5] = 31;
	skill_list[6] = 32;
	skill_list[7] = 33;
	skill_list[8] = 34;
	skill_list[9] = 35;
	skill_list[10] = 36;
	skill_list[11] = 37;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	int count = 0;
	for (int i = 11; i >= 0 && count<4; i--)
	{
		if (skills[skill_list[i]].levelreq < grade)
		{
			skill_bar[count] = i;
			remainedpp[count] = skills[skill_list[i]].pp;
			count++;
		}
	}
}
Blastoise::Blastoise(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Blastoise";
	nicky = pmlist.nicky;
	switch (pmlist.nature)
	{
	case 1:nature = Hardy; break;
	case 2:nature = Lonely; break;
	case 3:nature = Brave; break;
	case 4:nature = Adamant; break;
	case 5:nature = Naughty; break;
	case 6:nature = Bold; break;
	case 7:nature = Docile; break;
	case 8:nature = Relaxed; break;
	case 9:nature = Impish; break;
	case 10:nature = Lax; break;
	case 11:nature = Timid; break;
	case 12:nature = Hasty; break;
	case 13:nature = Serious; break;
	case 14:nature = Jolly; break;
	case 15:nature = Naive; break;
	case 16:nature = Modest; break;
	case 17:nature = Mild; break;
	case 18:nature = Quiet; break;
	case 19:nature = Bashful; break;
	case 20:nature = Rash; break;
	case 21:nature = Calm; break;
	case 22:nature = Gentle; break;
	case 23:nature = Sassy; break;
	case 24:nature = Careful; break;
	case 25:nature = Quirky; break;
	}
	switch (pmlist.ppt)
	{
	case 1:Ppt = Normal; break;
	case 2:Ppt = Fire; break;
	case 3:Ppt = Bug; break;
	case 4:Ppt = Water; break;
	case 5:Ppt = Poison; break;
	case 6:Ppt = Electric; break;
	case 7:Ppt = Flying; break;
	case 8:Ppt = Grass; break;
	case 9:Ppt = Ground; break;
	case 10:Ppt = Ice; break;
	case 11:Ppt = Fighting; break;
	case 12:Ppt = Psychic; break;
	case 13:Ppt = Rock; break;
	case 14:Ppt = Ghost; break;
	case 15:Ppt = Dragon; break;
	case 16:Ppt = Dark; break;
	case 17:Ppt = Steel; break;
	case 18:Ppt = Fairy; break;
	}
	Phy.IndividualValue = pmlist.Phy;
	Int.IndividualValue = pmlist.Int;
	Str.IndividualValue = pmlist.Str;
	Sta.IndividualValue = pmlist.Sta;
	Res.IndividualValue = pmlist.Res;
	Agi.IndividualValue = pmlist.Agi;
	Phy.RacialValue = 79;
	Str.RacialValue = 83;
	Sta.RacialValue = 100;
	Int.RacialValue = 85;
	Res.RacialValue = 105;
	Agi.RacialValue = 78;
	map();
	Attack.ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 26;
	skill_list[1] = 27;
	skill_list[2] = 28;
	skill_list[3] = 29;
	skill_list[4] = 30;
	skill_list[5] = 31;
	skill_list[6] = 32;
	skill_list[7] = 33;
	skill_list[8] = 34;
	skill_list[9] = 35;
	skill_list[10] = 36;
	skill_list[11] = 37;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}