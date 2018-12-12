#include "pokemons.h"

Bulbasaur::Bulbasaur()
{
	id = 1;
	name = "Bulbasaur";
	nicky = "Bulbasaur";
	Ppt = Grass;
	isside = false;

	Phy.RacialValue = 45;
	Str.RacialValue = 49;
	Sta.RacialValue = 49;
	Int.RacialValue = 65;
	Res.RacialValue = 65;
	Agi.RacialValue = 45;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Bulbasaur::Bulbasaur(int level)
{
	id = 1;
	name = "Bulbasaur";
	nicky = "Bulbasaur";
	Ppt = Grass;
	isside = false;
	grade = level;
	Phy.RacialValue = 45;
	Str.RacialValue = 49;
	Sta.RacialValue = 49;
	Int.RacialValue = 65;
	Res.RacialValue = 65;
	Agi.RacialValue = 45;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Bulbasaur::Bulbasaur(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Bulbasaur";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 45;
	Str.RacialValue = 49;
	Sta.RacialValue = 49;
	Int.RacialValue = 65;
	Res.RacialValue = 65;
	Agi.RacialValue = 45;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Ivysaur::Ivysaur()
{
	id = 2;
	name = "Ivysaur";
	nicky = "Ivysaur";
	Ppt = Grass;
	isside = false;

	Phy.RacialValue = 60;
	Str.RacialValue = 62;
	Sta.RacialValue = 63;
	Int.RacialValue = 80;
	Res.RacialValue = 80;
	Agi.RacialValue = 60;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Ivysaur::Ivysaur(int level)
{
	id = 2;
	name = "Ivysaur";
	nicky = "Ivysaur";
	Ppt = Grass;
	isside = false;
	grade = level;
	Phy.RacialValue = 60;
	Str.RacialValue = 62;
	Sta.RacialValue = 63;
	Int.RacialValue = 80;
	Res.RacialValue = 80;
	Agi.RacialValue = 60;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Ivysaur::Ivysaur(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Ivysaur";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 60;
	Str.RacialValue = 62;
	Sta.RacialValue = 63;
	Int.RacialValue = 80;
	Res.RacialValue = 80;
	Agi.RacialValue = 60;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

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
	for (int i = 1; i <= 12; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Venusaur::Venusaur(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Venusaur";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 131;
	skill_list[2] = 1;
	skill_list[3] = 2;
	skill_list[4] = 3;
	skill_list[5] = 4;
	skill_list[6] = 5;
	skill_list[7] = 6;
	skill_list[8] = 7;
	skill_list[9] = 8;
	skill_list[10] = 9;
	skill_list[11] = 10;
	skill_list[12] = 11;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Charmander::Charmander()
{
	id = 4;
	name = "Charmander";
	nicky = "Charmander";
	Ppt = Fire;
	isside = false;

	Phy.RacialValue = 39;
	Str.RacialValue = 52;
	Sta.RacialValue = 43;
	Int.RacialValue = 60;
	Res.RacialValue = 50;
	Agi.RacialValue = 65;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Charmander::Charmander(int level)
{
	id = 4;
	name = "Charmander";
	nicky = "Charmander";
	Ppt = Fire;
	isside = false;
	grade = level;
	Phy.RacialValue = 39;
	Str.RacialValue = 52;
	Sta.RacialValue = 43;
	Int.RacialValue = 60;
	Res.RacialValue = 50;
	Agi.RacialValue = 65;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Charmander::Charmander(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Charmander";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 39;
	Str.RacialValue = 52;
	Sta.RacialValue = 43;
	Int.RacialValue = 60;
	Res.RacialValue = 50;
	Agi.RacialValue = 65;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Charmeleon::Charmeleon()
{
	id = 5;
	name = "Charmeleon";
	nicky = "Charmeleon";
	Ppt = Fire;
	isside = false;

	Phy.RacialValue = 58;
	Str.RacialValue = 64;
	Sta.RacialValue = 58;
	Int.RacialValue = 80;
	Res.RacialValue = 65;
	Agi.RacialValue = 80;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Charmeleon::Charmeleon(int level)
{
	id = 5;
	name = "Charmeleon";
	nicky = "Charmeleon";
	Ppt = Fire;
	isside = false;
	grade = level;
	Phy.RacialValue = 58;
	Str.RacialValue = 64;
	Sta.RacialValue = 58;
	Int.RacialValue = 80;
	Res.RacialValue = 65;
	Agi.RacialValue = 80;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Charmeleon::Charmeleon(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Charmeleon";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 58;
	Str.RacialValue = 64;
	Sta.RacialValue = 58;
	Int.RacialValue = 80;
	Res.RacialValue = 65;
	Agi.RacialValue = 80;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Charizard::Charizard(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Charizard";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 12;
	skill_list[2] = 13;
	skill_list[3] = 14;
	skill_list[4] = 15;
	skill_list[5] = 16;
	skill_list[6] = 17;
	skill_list[7] = 18;
	skill_list[8] = 19;
	skill_list[9] = 20;
	skill_list[10] = 21;
	skill_list[11] = 22;
	skill_list[12] = 23;
	skill_list[13] = 24;
	skill_list[14] = 25;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Squirtle::Squirtle()
{
	id = 7;
	name = "Squirtle";
	nicky = "Squirtle";
	Ppt = Water;
	isside = false;

	Phy.RacialValue = 44;
	Str.RacialValue = 48;
	Sta.RacialValue = 65;
	Int.RacialValue = 50;
	Res.RacialValue = 64;
	Agi.RacialValue = 43;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Squirtle::Squirtle(int level)
{
	id = 7;
	name = "Squirtle";
	nicky = "Squirtle";
	Ppt = Water;
	isside = false;
	grade = level;
	Phy.RacialValue = 44;
	Str.RacialValue = 48;
	Sta.RacialValue = 65;
	Int.RacialValue = 50;
	Res.RacialValue = 64;
	Agi.RacialValue = 43;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Squirtle::Squirtle(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Squirtle";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 44;
	Str.RacialValue = 48;
	Sta.RacialValue = 65;
	Int.RacialValue = 50;
	Res.RacialValue = 64;
	Agi.RacialValue = 43;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Wartortle::Wartortle()
{
	id = 8;
	name = "Wartortle";
	nicky = "Wartortle";
	Ppt = Water;
	isside = false;

	Phy.RacialValue = 59;
	Str.RacialValue = 63;
	Sta.RacialValue = 80;
	Int.RacialValue = 65;
	Res.RacialValue = 80;
	Agi.RacialValue = 58;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Wartortle::Wartortle(int level)
{
	id = 8;
	name = "Wartortle";
	nicky = "Wartortle";
	Ppt = Water;
	isside = false;
	grade = level;
	Phy.RacialValue = 59;
	Str.RacialValue = 63;
	Sta.RacialValue = 80;
	Int.RacialValue = 65;
	Res.RacialValue = 80;
	Agi.RacialValue = 58;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Wartortle::Wartortle(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Wartortle";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 59;
	Str.RacialValue = 63;
	Sta.RacialValue = 80;
	Int.RacialValue = 65;
	Res.RacialValue = 80;
	Agi.RacialValue = 58;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
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
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

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
	for (int i = 1; i <= 12; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Blastoise::Blastoise(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Blastoise";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 26;
	skill_list[2] = 27;
	skill_list[3] = 28;
	skill_list[4] = 29;
	skill_list[5] = 30;
	skill_list[6] = 31;
	skill_list[7] = 32;
	skill_list[8] = 33;
	skill_list[9] = 34;
	skill_list[10] = 35;
	skill_list[11] = 36;
	skill_list[12] = 37;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Pidgey::Pidgey()
{
	id = 10;
	name = "Pidgey";
	nicky = "Pidgey";
	Ppt = Flying;
	isside = false;

	Phy.RacialValue = 40;
	Str.RacialValue = 45;
	Sta.RacialValue = 40;
	Int.RacialValue = 55;
	Res.RacialValue = 35;
	Agi.RacialValue = 86;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Pidgey::Pidgey(int level)
{
	id = 10;
	name = "Pidgey";
	nicky = "Pidgey";
	Ppt = Flying;
	isside = false;
	grade = level;
	Phy.RacialValue = 40;
	Str.RacialValue = 45;
	Sta.RacialValue = 40;
	Int.RacialValue = 55;
	Res.RacialValue = 35;
	Agi.RacialValue = 86;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Pidgey::Pidgey(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Pidgey";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 40;
	Str.RacialValue = 45;
	Sta.RacialValue = 40;
	Int.RacialValue = 55;
	Res.RacialValue = 35;
	Agi.RacialValue = 86;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Pidgeotto::Pidgeotto()
{
	id = 11;
	name = "Pidgeotto";
	nicky = "Pidgeotto";
	Ppt = Flying;
	isside = false;

	Phy.RacialValue = 63;
	Str.RacialValue = 60;
	Sta.RacialValue = 55;
	Int.RacialValue = 70;
	Res.RacialValue = 50;
	Agi.RacialValue = 105;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Pidgeotto::Pidgeotto(int level)
{
	id = 11;
	name = "Pidgeotto";
	nicky = "Pidgeotto";
	Ppt = Flying;
	isside = false;
	grade = level;
	Phy.RacialValue = 63;
	Str.RacialValue = 60;
	Sta.RacialValue = 55;
	Int.RacialValue = 70;
	Res.RacialValue = 50;
	Agi.RacialValue = 105;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Pidgeotto::Pidgeotto(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Pidgeotto";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 63;
	Str.RacialValue = 60;
	Sta.RacialValue = 55;
	Int.RacialValue = 70;
	Res.RacialValue = 50;
	Agi.RacialValue = 105;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Pidgeot::Pidgeot()
{
	id = 12;
	name = "Pidgeot";
	nicky = "Pidgeot";
	Ppt = Flying;
	isside = false;

	Phy.RacialValue = 80;
	Str.RacialValue = 83;
	Sta.RacialValue = 75;
	Int.RacialValue = 70;
	Res.RacialValue = 70;
	Agi.RacialValue = 130;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Pidgeot::Pidgeot(int level)
{
	id = 12;
	name = "Pidgeot";
	nicky = "Pidgeot";
	Ppt = Flying;
	isside = false;
	grade = level;
	Phy.RacialValue = 80;
	Str.RacialValue = 83;
	Sta.RacialValue = 75;
	Int.RacialValue = 70;
	Res.RacialValue = 70;
	Agi.RacialValue = 130;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Pidgeot::Pidgeot(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Pidgeot";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Str.RacialValue = 83;
	Sta.RacialValue = 75;
	Int.RacialValue = 70;
	Res.RacialValue = 70;
	Agi.RacialValue = 130;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 38;
	skill_list[2] = 39;
	skill_list[3] = 40;
	skill_list[4] = 41;
	skill_list[5] = 42;
	skill_list[6] = 43;
	skill_list[7] = 44;
	skill_list[8] = 47;
	skill_list[9] = 45;
	skill_list[10] = 50;
	skill_list[11] = 46;
	skill_list[12] = 48;
	skill_list[13] = 49;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Pikachu::Pikachu()
{
	id = 13;
	name = "Pikachu";
	nicky = "Pikachu";
	Ppt = Electric;
	isside = false;

	Phy.RacialValue = 70;
	Str.RacialValue = 110;
	Sta.RacialValue = 80;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 180;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Pikachu::Pikachu(int level)
{
	id = 13;
	name = "Pikachu";
	nicky = "Pikachu";
	Ppt = Electric;
	isside = false;

	Phy.RacialValue = 70;
	Str.RacialValue = 110;
	Sta.RacialValue = 80;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 180;
	
	grade = level;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Pikachu::Pikachu(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Pikachu";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 70;
	Str.RacialValue = 110;
	Sta.RacialValue = 80;
	Int.RacialValue = 100;
	Res.RacialValue = 100;
	Agi.RacialValue = 180;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Raichu::Raichu()
{
	id = 14;
	name = "Raichu";
	nicky = "Raichu";
	Ppt = Electric;
	isside = false;

	Phy.RacialValue = 80;
	Str.RacialValue = 120;
	Sta.RacialValue = 90;
	Int.RacialValue = 120;
	Res.RacialValue = 110;
	Agi.RacialValue = 220;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Raichu::Raichu(int level)
{
	id = 14;
	name = "Raichu";
	nicky = "Raichu";
	Ppt = Electric;
	isside = false;
	grade = level;
	Phy.RacialValue = 80;
	Str.RacialValue = 120;
	Sta.RacialValue = 90;
	Int.RacialValue = 120;
	Res.RacialValue = 110;
	Agi.RacialValue = 220;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Raichu::Raichu(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Raichu";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Str.RacialValue = 120;
	Sta.RacialValue = 90;
	Int.RacialValue = 120;
	Res.RacialValue = 110;
	Agi.RacialValue = 220;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 52;
	skill_list[3] = 53;
	skill_list[4] = 54;
	skill_list[5] = 55;
	skill_list[6] = 56;
	skill_list[7] = 60;
	skill_list[8] = 57;
	skill_list[9] = 58;
	skill_list[10] = 99;
	skill_list[11] = 100;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Clefairy::Clefairy()
{
	id = 15;
	name = "Clefairy";
	nicky = "Clefairy";
	Ppt = Fairy;
	isside = false;

	Phy.RacialValue = 130;
	Str.RacialValue = 50;
	Sta.RacialValue = 63;
	Int.RacialValue = 65;
	Res.RacialValue = 90;
	Agi.RacialValue = 100;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;        
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Clefairy::Clefairy(int level)
{
	id = 15;
	name = "Clefairy";
	nicky = "Clefairy";
	Ppt = Fairy;
	isside = false;
	grade = level;
	Phy.RacialValue = 130;
	Str.RacialValue = 50;
	Sta.RacialValue = 63;
	Int.RacialValue = 65;
	Res.RacialValue = 90;
	Agi.RacialValue = 100;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Clefairy::Clefairy(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Clefairy";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 130;
	Str.RacialValue = 50;
	Sta.RacialValue = 63;
	Int.RacialValue = 65;
	Res.RacialValue = 90;
	Agi.RacialValue = 100;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
Clefable::Clefable()
{
	id = 16;
	name = "Clefable";
	nicky = "Clefable";
	Ppt = Fairy;
	isside = false;

	Phy.RacialValue = 130;
	Str.RacialValue = 70;
	Sta.RacialValue = 73;
	Int.RacialValue = 95;
	Res.RacialValue = 90;
	Agi.RacialValue = 60;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

	skill_bar[0] = 0;
	skill_bar[1] = -1;
	skill_bar[2] = -1;
	skill_bar[3] = -1;

	remainedpp[0] = skills[0].pp;
	remainedpp[1] = 0;
	remainedpp[2] = 0;
	remainedpp[3] = 0;
}
Clefable::Clefable(int level)
{
	id = 16;
	name = "Clefable";
	nicky = "Clefable";
	Ppt = Fairy;
	isside = false;
	grade = level;
	Phy.RacialValue = 130;
	Str.RacialValue = 70;
	Sta.RacialValue = 73;
	Int.RacialValue = 95;
	Res.RacialValue = 90;
	Agi.RacialValue = 60;
	//能力面板值初始化
	map();
	//技能初始化
	skills[0].ppt = Ppt;
	al_have_skills = 0;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

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
	for (int i = 1; i <= 14; i++)
	{
		if (skills[skill_list[i]].levelreq < grade)
			al_have_skills++;
	}
}
Clefable::Clefable(PMList pmlist)
{
	id = pmlist.id;
	onlyid = pmlist.onlyid;
	name = "Clefable";
	nicky = pmlist.nicky;
	grade = pmlist.grade;
	Exp = pmlist.exp;
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
	Phy.RacialValue = 130;
	Str.RacialValue = 70;
	Sta.RacialValue = 73;
	Int.RacialValue = 95;
	Res.RacialValue = 90;
	Agi.RacialValue = 60;
	map();
	skills[0].ppt = Ppt;
	al_have_skills = pmlist.skills;
	skill_list[0] = 0;
	skill_list[1] = 51;
	skill_list[2] = 38;
	skill_list[3] = 52;
	skill_list[4] = 60;
	skill_list[5] = 109;
	skill_list[6] = 104;
	skill_list[7] = 83;
	skill_list[8] = 80;
	skill_list[9] = 82;
	skill_list[10] = 127;
	skill_list[11] = 88;
	skill_list[12] = 105;

	skill_bar[0] = pmlist.skillbar[0];
	skill_bar[1] = pmlist.skillbar[1];
	skill_bar[2] = pmlist.skillbar[2];
	skill_bar[3] = pmlist.skillbar[3];

	remainedpp[0] = skills[skill_list[skill_bar[0]]].pp;
	remainedpp[1] = skills[skill_list[skill_bar[1]]].pp;
	remainedpp[2] = skills[skill_list[skill_bar[2]]].pp;
	remainedpp[3] = skills[skill_list[skill_bar[3]]].pp;
}
