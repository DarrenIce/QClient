#include "pokemon.h"
#pragma execution_character_set("utf-8")

#include<stdlib.h>

Pokemon::Pokemon()
{
	grade = 0;
	Exp = 0;
	getNature();
	//个体值在0~31随机，基础点数置零
	Str.BaseStats = 0;
	Str.IndividualValue = r.get(0,31);
	Int.BaseStats = 0;
	Int.IndividualValue = r.get(0, 31);
	Phy.BaseStats = 0;
	Phy.IndividualValue = r.get(0, 31);
	Sta.BaseStats = 0;
	Sta.IndividualValue = r.get(0, 31);
	Res.BaseStats = 0;
	Res.IndividualValue = r.get(0, 31);
	Agi.BaseStats = 0;
	Agi.IndividualValue = r.get(0, 31);
	//除血量外基础能力均为2，命中回避为3，上一个等级面板值置零
	Atk.LastLevelValue = 0;
	Atk.ActuallLevel = 2;
	Atk.BaseLevel = 2;
	Sat.LastLevelValue = 0;
	Sat.ActuallLevel = 2;
	Sat.BaseLevel = 2;
	Def.LastLevelValue = 0;
	Def.ActuallLevel = 2;
	Def.BaseLevel = 2;
	Sdf.LastLevelValue = 0;
	Sdf.ActuallLevel = 2;
	Sdf.BaseLevel = 2;
	Spe.LastLevelValue = 0;
	Spe.ActuallLevel = 2;
	Spe.BaseLevel = 2;
	CthBL = 1;
	AccBL = 3;
	AccAL = 3;
	EvaBL = 3;
	EvaAl = 3;

	Attack.name = "普通攻击";
	Attack.levelreq = 1;
	Attack.learn = true;
	Attack.able = true;
	Attack.kind = Physical;
	Attack.power = 30;
	Attack.accuracy = 100;
	Attack.pp = 1000;
	Attack.ae = Nu;
	isside = false;

	{
		//000-叫声---03
		{
			skills[0].name = "叫声";
			skills[0].levelreq = 3;
			skills[0].ppt = Normal;
			skills[0].kind = Change;
			skills[0].power = 0;
			skills[0].accuracy = 100;
			skills[0].pp = 40;
			skills[0].residual = skills[0].pp;
			skills[0].ae = AtkDn;
			skills[0].pb = 0;
		}
		//001-寄生种子---07
		{
			skills[1].name = "寄生种子";
			skills[1].levelreq = 7;
			skills[1].ppt = Grass;
			skills[1].kind = Change;
			skills[1].power = 0;
			skills[1].accuracy = 90;
			skills[1].pp = 10;
			skills[1].residual = skills[1].pp;
			skills[1].ae = leech;
			skills[1].pb = 0;
		}
		//002-藤鞭---09
		{
			skills[2].name = "藤鞭";
			skills[2].levelreq = 9;
			skills[2].ppt = Grass;
			skills[2].kind = Physical;
			skills[2].power = 45;
			skills[2].accuracy = 100;
			skills[2].pp = 25;
			skills[2].residual = skills[2].pp;
			skills[2].ae = Nu;
			skills[2].pb = 0;
		}
		//003-毒粉---13
		{
			skills[3].name = "毒粉";
			skills[3].levelreq = 13;
			skills[3].ppt = Poison;
			skills[3].kind = Change;
			skills[3].power = 0;
			skills[3].accuracy = 75;
			skills[3].pp = 35;
			skills[3].residual = skills[3].pp;
			skills[3].ae = poison;
			skills[3].pb = 0;
		}
		//004-催眠粉---13
		{
			skills[4].name = "催眠粉";
			skills[4].levelreq = 13;
			skills[4].ppt = Grass;
			skills[4].kind = Change;
			skills[4].power = 0;
			skills[4].accuracy = 75;
			skills[4].pp = 15;
			skills[4].residual = skills[4].pp;
			skills[4].ae = sleep;
			skills[4].pb = 0;
		}
		//005-飞叶快刀---17
		{
			skills[5].name = "飞叶快刀";
			skills[5].levelreq = 17;
			skills[5].ppt = Grass;
			skills[5].kind = Physical;
			skills[5].power = 55;
			skills[5].accuracy = 95;
			skills[5].pp = 25;
			skills[5].residual = skills[5].pp;
			skills[5].ae = CthUp;
			skills[5].pb = 10;
		}
		//006-舍身冲撞---25
		{
			skills[6].name = "舍身冲撞";
			skills[6].levelreq = 25;
			skills[6].ppt = Normal;
			skills[6].kind = Physical;
			skills[6].power = 120;
			skills[6].accuracy = 100;
			skills[6].pp = 15;
			skills[6].residual = skills[6].pp;
			skills[6].ae = reflect;
			skills[6].pb = 0;
		}
		//007-光合作用---33
		{
			skills[7].name = "光合作用";
			skills[7].levelreq = 33;
			skills[7].ppt = Grass;
			skills[7].kind = Change;
			skills[7].power = 0;
			skills[7].accuracy = 0;
			skills[7].pp = 5;
			skills[7].residual = skills[7].pp;
			skills[7].ae = heal;
			skills[7].pb = 0;
		}
		//008-种子炸弹---37
		{
			skills[8].name = "种子炸弹";
			skills[8].levelreq = 37;
			skills[8].ppt = Grass;
			skills[8].kind = Physical;
			skills[8].power = 80;
			skills[8].accuracy = 100;
			skills[8].pp = 15;
			skills[8].residual = skills[8].pp;
			skills[8].ae = Nu;
			skills[8].pb = 0;
		}
		//009-日光束---44
		{
			skills[9].name = "日光束";
			skills[9].levelreq = 44;
			skills[9].ppt = Grass;
			skills[9].kind = Special;
			skills[9].power = 120;
			skills[9].accuracy = 100;
			skills[9].pp = 10;
			skills[9].residual = skills[9].pp;
			skills[9].ae = Nu;
			skills[9].pb = 0;
		}
		//010-超级吸取---40
		{
			skills[10].name = "终极吸取";
			skills[10].levelreq = 40;
			skills[10].ppt = Grass;
			skills[10].kind = Special;
			skills[10].power = 40;
			skills[10].accuracy = 100;
			skills[10].pp = 15;
			skills[10].residual = skills[10].pp;
			skills[10].ae = drain;
			skills[10].pb = 0;
		}
		//011-成长---21
		{
			skills[11].name = "成长";
			skills[11].levelreq = 21;
			skills[11].ppt = Normal;
			skills[11].kind = Change;
			skills[11].power = 0;
			skills[11].accuracy = 0;
			skills[11].pp = 40;
			skills[11].residual = skills[11].pp;
			skills[11].ae = AtkUp;
			skills[11].pb = 0;
		}
		//012-火花---09
		{
			skills[12].name = "火花";
			skills[12].levelreq = 9;
			skills[12].ppt = Fire;
			skills[12].kind = Special;
			skills[12].power = 40;
			skills[12].accuracy = 100;
			skills[12].pp = 30;
			skills[12].residual = skills[12].pp;
			skills[12].ae = burn;
			skills[12].pb = 10;
		}
		//013-瞪眼---15
		{
			skills[13].name = "瞪眼";
			skills[13].levelreq = 15;
			skills[13].ppt = Normal;
			skills[13].kind = Change;
			skills[13].power = 0;
			skills[13].accuracy = 100;
			skills[13].pp = 35;
			skills[13].residual = skills[13].pp;
			skills[13].ae = DefDn;
			skills[13].pb = 0;
		}
		//014-愤怒---22
		{
			skills[14].name = "愤怒";
			skills[14].levelreq = 22;
			skills[14].ppt = Normal;
			skills[14].kind = Physical;
			skills[14].power = 20;
			skills[14].accuracy = 100;
			skills[14].pp = 30;
			skills[14].residual = skills[14].pp;
			skills[14].ae = AtkUp;
			skills[14].pb = 0;
		}
		//015-劈开---30
		{
			skills[15].name = "劈开";
			skills[15].levelreq = 30;
			skills[15].ppt = Normal;
			skills[15].kind = Physical;
			skills[15].power = 70;
			skills[15].accuracy = 100;
			skills[15].pp = 25;
			skills[15].residual = skills[15].pp;
			skills[15].ae = CthUp;
			skills[15].pb = 10;
		}
		//016-喷射火焰---38
		{
			skills[16].name = "喷射火焰";
			skills[16].levelreq = 38;
			skills[16].ppt = Fire;
			skills[16].kind = Special;
			skills[16].power = 90;
			skills[16].accuracy = 100;
			skills[16].pp = 15;
			skills[16].residual = skills[16].pp;
			skills[16].ae = burn;
			skills[16].pb = 10;
		}
		//017-火焰漩涡---46
		{
			skills[17].name = "火焰漩涡";
			skills[17].levelreq = 46;
			skills[17].ppt = Fire;
			skills[17].kind = Special;
			skills[17].power = 35;
			skills[17].accuracy = 85;
			skills[17].pp = 15;
			skills[17].residual = skills[17].pp;
			skills[17].ae = burn;
			skills[17].pb = 0;
		}
		//018-烟幕---10
		{
			skills[18].name = "烟幕";
			skills[18].levelreq = 10;
			skills[18].ppt = Normal;
			skills[18].kind = Change;
			skills[18].power = 0;
			skills[18].accuracy = 100;
			skills[18].pp = 25;
			skills[18].residual = skills[18].pp;
			skills[18].ae = AccDn;
			skills[18].pb = 0;
		}
		//019-龙之怒---19
		{
			skills[19].name = "龙之怒";
			skills[19].levelreq = 19;
			skills[19].ppt = Dragon;
			skills[19].kind = Special;
			skills[19].power = 40;
			skills[19].accuracy = 100;
			skills[19].pp = 10;
			skills[19].residual = skills[19].pp;
			skills[19].ae = Nu;
			skills[19].pb = 0;
		}
		//020-火之牙---26
		{
			skills[20].name = "火之牙";
			skills[20].levelreq = 26;
			skills[20].ppt = Fire;
			skills[20].kind = Physical;
			skills[20].power = 65;
			skills[20].accuracy = 95;
			skills[20].pp = 15;
			skills[20].residual = skills[20].pp;
			skills[20].ae = burn;
			skills[20].pb = 10;
		}
		//021-龙爪---42
		{
			skills[21].name = "龙爪";
			skills[21].levelreq = 42;
			skills[21].ppt = Dragon;
			skills[21].kind = Physical;
			skills[21].power = 80;
			skills[21].accuracy = 100;
			skills[21].pp = 20;
			skills[21].residual = skills[21].pp;
			skills[21].ae = Nu;
			skills[21].pb = 0;
		}
		//022-阴影爪---44
		{
			skills[22].name = "阴影爪";
			skills[22].levelreq = 44;
			skills[22].ppt = Ghost;
			skills[22].kind = Physical;
			skills[22].power = 70;
			skills[22].accuracy = 100;
			skills[22].pp = 15;
			skills[22].residual = skills[22].pp;
			skills[22].ae = CthUp;
			skills[22].pb = 10;
		}
		//023-空气切割---49
		{
			skills[23].name = "空气切割";
			skills[23].levelreq = 49;
			skills[23].ppt = Flying;
			skills[23].kind = Special;
			skills[23].power = 75;
			skills[23].accuracy = 95;
			skills[23].pp = 20;
			skills[23].residual = skills[23].pp;
			skills[23].ae = CthUp;
			skills[23].pb = 10;
		}
		//024-热风---71
		{
			skills[24].name = "热风";
			skills[24].levelreq = 71;
			skills[24].ppt = Fire;
			skills[24].kind = Special;
			skills[24].power = 110;
			skills[24].accuracy = 90;
			skills[24].pp = 10;
			skills[24].residual = skills[24].pp;
			skills[24].ae = burn;
			skills[24].pb = 10;
		}
		//025-闪焰冲锋---77
		{
			skills[25].name = "闪焰冲锋";
			skills[25].levelreq = 77;
			skills[25].ppt = Fire;
			skills[25].kind = Physical;
			skills[25].power = 120;
			skills[25].accuracy = 100;
			skills[25].pp = 10;
			skills[25].residual = skills[25].pp;
			skills[25].ae = reflect;
			skills[25].pb = 0;
		}
		//026-摇尾巴---04
		{
			skills[26].name = "摇尾巴";
			skills[26].levelreq = 4;
			skills[26].ppt = Normal;
			skills[26].kind = Change;
			skills[26].power = 0;
			skills[26].accuracy = 100;
			skills[26].pp = 35;
			skills[26].residual = skills[26].pp;
			skills[26].ae = DefDn;
			skills[26].pb = 0;
		}
		//027-泡沫---07
		{
			skills[27].name = "泡沫";
			skills[27].levelreq = 7;
			skills[27].ppt = Water;
			skills[27].kind = Special;
			skills[27].power = 40;
			skills[27].accuracy = 100;
			skills[27].pp = 40;
			skills[27].residual = skills[27].pp;
			skills[27].ae = SpeDn;
			skills[27].pb = 10;
		}
		//028-水枪---13
		{
			skills[28].name = "水枪";
			skills[28].levelreq = 13;
			skills[28].ppt = Water;
			skills[28].kind = Special;
			skills[28].power = 40;
			skills[28].accuracy = 100;
			skills[28].pp = 40;
			skills[28].residual = skills[28].pp;
			skills[28].ae = Nu;
			skills[28].pb = 0;
		}
		//029-缩壳---10
		{
			skills[29].name = "缩壳";
			skills[29].levelreq = 10;
			skills[29].ppt = Water;
			skills[29].kind = Change;
			skills[29].power = 0;
			skills[29].accuracy = 0;
			skills[29].pp = 40;
			skills[29].residual = skills[29].pp;
			skills[29].ae = DefUp;
			skills[29].pb = 0;
		}
		//030-咬咬---17
		{
			skills[30].name = "咬咬";
			skills[30].levelreq = 17;
			skills[30].ppt = Dark;
			skills[30].kind = Physical;
			skills[30].power = 60;
			skills[30].accuracy = 100;
			skills[30].pp = 25;
			skills[30].residual = skills[30].pp;
			skills[30].ae = flinch;
			skills[30].pb = 30;
		}
		//031-高速旋转---25
		{
			skills[31].name = "高速旋转";
			skills[31].levelreq = 25;
			skills[31].ppt = Normal;
			skills[31].kind = Physical;
			skills[31].power = 20;
			skills[31].accuracy = 100;
			skills[31].pp = 40;
			skills[31].residual = skills[31].pp;
			skills[31].ae = deleech;
			skills[31].pb = 0;
		}
		//032-水之波动---28
		{
			skills[32].name = "水之波动";
			skills[32].levelreq = 28;
			skills[32].ppt = Water;
			skills[32].kind = Special;
			skills[32].power = 60;
			skills[32].accuracy = 100;
			skills[32].pp = 25;
			skills[32].residual = skills[32].pp;
			skills[32].ae = confusion;
			skills[32].pb = 20;
		}
		//033-保护---31
		{
			skills[33].name = "保护";
			skills[33].levelreq = 31;
			skills[33].ppt = Normal;
			skills[33].kind = Change;
			skills[33].power = 0;
			skills[33].accuracy = 0;
			skills[33].pp = 10;
			skills[33].residual = skills[33].pp;
			skills[33].ae = protect;
			skills[33].pb = 0;
		}
		//034-水尾巴---33
		{
			skills[34].name = "水尾巴";
			skills[34].levelreq = 33;
			skills[34].ppt = Water;
			skills[34].kind = Physical;
			skills[34].power = 90;
			skills[34].accuracy = 90;
			skills[34].pp = 10;
			skills[34].residual = skills[34].pp;
			skills[34].ae = Nu;
			skills[34].pb = 0;
		}
		//035-火箭头槌---55
		{
			skills[35].name = "火箭头槌";
			skills[35].levelreq = 55;
			skills[35].ppt = Normal;
			skills[35].kind = Physical;
			skills[35].power = 130;
			skills[35].accuracy = 100;
			skills[35].pp = 10;
			skills[35].residual = skills[35].pp;
			skills[35].ae = DefUp;
			skills[35].pb = 30;
		}
		//036-求雨---37
		{
			skills[36].name = "求雨";
			skills[36].levelreq = 37;
			skills[36].ppt = Water;
			skills[36].kind = Change;
			skills[36].power = 0;
			skills[36].accuracy = 0;
			skills[36].pp = 5;
			skills[36].residual = skills[36].pp;
			skills[36].ae = SatUp;
			skills[36].pb = 0;
		}
		//037-水炮---47
		{
			skills[37].name = "水炮";
			skills[37].levelreq = 47;
			skills[37].ppt = Water;
			skills[37].kind = Special;
			skills[37].power = 110;
			skills[37].accuracy = 80;
			skills[37].pp = 5;
			skills[37].residual = skills[37].pp;
			skills[37].ae = Nu;
			skills[37].pb = 0;
		}
		//038-泼沙---03
		{
			skills[38].name = "泼沙";
			skills[38].levelreq = 3;
			skills[38].ppt = Ground;
			skills[38].kind = Change;
			skills[38].power = 0;
			skills[38].accuracy = 100;
			skills[38].pp = 20;
			skills[38].residual = skills[38].pp;
			skills[38].ae = AccDn;
			skills[38].pb = 0;
		}
		//039-起风---07
		{
			skills[39].name = "起风";
			skills[39].levelreq = 7;
			skills[39].ppt = Flying;
			skills[39].kind = Special;
			skills[39].power = 40;
			skills[39].accuracy = 100;
			skills[39].pp = 35;
			skills[39].residual = skills[39].pp;
			skills[39].ae = Nu;
			skills[39].pb = 0;
		}
		//040-龙卷风---14
		{
			skills[40].name = "龙卷风";
			skills[40].levelreq = 14;
			skills[40].ppt = Dragon;
			skills[40].kind = Special;
			skills[40].power = 40;
			skills[40].accuracy = 100;
			skills[40].pp = 20;
			skills[40].residual = skills[40].pp;
			skills[40].ae = flinch;
			skills[40].pb = 20;
		}
		//041-羽毛舞---19
		{
			skills[41].name = "羽毛舞";
			skills[41].levelreq = 19;
			skills[41].ppt = Flying;
			skills[41].kind = Change;
			skills[41].power = 0;
			skills[41].accuracy = 100;
			skills[41].pp = 20;
			skills[41].residual = skills[41].pp;
			skills[41].ae = AtkDn;
			skills[41].pb = 0;
		}
		//042-高速移动---23
		{
			skills[42].name = "高速移动";
			skills[42].levelreq = 23;
			skills[42].ppt = Psychic;
			skills[42].kind = Change;
			skills[42].power = 0;
			skills[42].accuracy = 0;
			skills[42].pp = 40;
			skills[42].residual = skills[42].pp;
			skills[42].ae = SpeUp;
			skills[42].pb = 0;
		}
		//043-翅膀拍击---27
		{
			skills[43].name = "翅膀拍击";
			skills[43].levelreq = 27;
			skills[43].ppt = Flying;
			skills[43].kind = Physical;
			skills[43].power = 60;
			skills[43].accuracy = 100;
			skills[43].pp = 35;
			skills[43].residual = skills[43].pp;
			skills[43].ae = Nu;
			skills[43].pb = 0;
		}
		//044-羽栖---32
		{
			skills[44].name = "羽栖";
			skills[44].levelreq = 32;
			skills[44].ppt = Flying;
			skills[44].kind = Change;
			skills[44].power = 0;
			skills[44].accuracy = 0;
			skills[44].pp = 10;
			skills[44].residual = skills[44].pp;
			skills[44].ae = heal;
			skills[44].pb = 0;
		}
		//045-空气切割---38
		{
			skills[45].name = "空气切割";
			skills[45].levelreq = 38;
			skills[45].ppt = Flying;
			skills[45].kind = Special;
			skills[45].power = 75;
			skills[45].accuracy = 95;
			skills[45].pp = 15;
			skills[45].residual = skills[45].pp;
			skills[45].ae = flinch;
			skills[45].pb = 30;
		}
		//046-暴风---45
		{
			skills[46].name = "暴风";
			skills[46].levelreq = 45;
			skills[46].ppt = Flying;
			skills[46].kind = Special;
			skills[46].power = 110;
			skills[46].accuracy = 70;
			skills[46].pp = 10;
			skills[46].residual = skills[46].pp;
			skills[46].ae = confusion;
			skills[46].pb = 30;
		}
		//047-燕返---35
		{
			skills[47].name = "燕返";
			skills[47].levelreq = 35;
			skills[47].ppt = Flying;
			skills[47].kind = Physical;
			skills[47].power = 60;
			skills[47].accuracy = 0;
			skills[47].pp = 20;
			skills[47].residual = skills[47].pp;
			skills[47].ae = Nu;
			skills[47].pb = 0;
		}
		//048-勇鸟猛攻---52
		{
			skills[48].name = "勇鸟猛攻";
			skills[48].levelreq = 52;
			skills[48].ppt = Flying;
			skills[48].kind = Physical;
			skills[48].power = 120;
			skills[48].accuracy = 100;
			skills[48].pp = 15;
			skills[48].residual = skills[48].pp;
			skills[48].ae = reflect;
			skills[48].pb = 0;
		}
		//049-神鸟猛击---60
		{
			skills[49].name = "神鸟猛击";
			skills[49].levelreq = 60;
			skills[49].ppt = Flying;
			skills[49].kind = Physical;
			skills[49].power = 140;
			skills[49].accuracy = 90;
			skills[49].pp = 5;
			skills[49].residual = skills[49].pp;
			skills[49].ae = flinch;
			skills[49].pb = 30;
		}
		//050-热风---42
		{
			skills[50].name = "热风";
			skills[50].levelreq = 42;
			skills[50].ppt = Fire;
			skills[50].kind = Special;
			skills[50].power = 95;
			skills[50].accuracy = 90;
			skills[50].pp = 10;
			skills[50].residual = skills[50].pp;
			skills[50].ae = burn;
			skills[50].pb = 10;
		}
		//051-撒娇---03
		{
			skills[51].name = "撒娇";
			skills[51].levelreq = 3;
			skills[51].ppt = Fairy;
			skills[51].kind = Change;
			skills[51].power = 0;
			skills[51].accuracy = 100;
			skills[51].pp = 20;
			skills[51].residual = skills[51].pp;
			skills[51].ae = AtkDnn;
			skills[51].pb = 0;
		}
		//052-天使之吻---05
		{
			skills[52].name = "天使之吻";
			skills[52].levelreq = 5;
			skills[52].ppt = Fairy;
			skills[52].kind = Change;
			skills[52].power = 0;
			skills[52].accuracy = 75;
			skills[52].pp = 10;
			skills[52].residual = skills[52].pp;
			skills[52].ae = confusion;
			skills[52].pb = 0;
		}
		//053-诡计---06
		{
			skills[53].name = "诡计";
			skills[53].levelreq = 6;
			skills[53].ppt = Dark;
			skills[53].kind = Change;
			skills[53].power = 0;
			skills[53].accuracy = 0;
			skills[53].pp = 20;
			skills[53].residual = skills[53].pp;
			skills[53].ae = SatUpp;
			skills[53].pb = 0;
		}
		//054-电击---07
		{
			skills[54].name = "电击";
			skills[54].levelreq = 7;
			skills[54].ppt = Electric;
			skills[54].kind = Physical;
			skills[54].power = 40;
			skills[54].accuracy = 100;
			skills[54].pp = 30;
			skills[54].residual = skills[54].pp;
			skills[54].ae = paralyze;
			skills[54].pb = 10;
		}
		//055-电光一闪---10
		{
			skills[55].name = "电光一闪";
			skills[55].levelreq = 10;
			skills[55].ppt = Normal;
			skills[55].kind = Physical;
			skills[55].power = 40;
			skills[55].accuracy = 100;
			skills[55].pp = 30;
			skills[55].residual = skills[55].pp;
			skills[55].ae = Nu;
			skills[55].pb = 0;
		}
		//056-电球---13  //基础威力与双方速度有关
		{
			skills[56].name = "电球";
			skills[56].levelreq = 13;
			skills[56].ppt = Electric;
			skills[56].kind = Special;
			skills[56].power = 0;
			skills[56].accuracy = 100;
			skills[56].pp = 10;
			skills[56].residual = skills[56].pp;
			skills[56].ae = Nu;
			skills[56].pb = 0;
		}
		//057-电磁波---18
		{
			skills[57].name = "电磁波";
			skills[57].levelreq = 18;
			skills[57].ppt = Electric;
			skills[57].kind = Change;
			skills[57].power = 0;
			skills[57].accuracy = 90;
			skills[57].pp = 20;
			skills[57].residual = skills[57].pp;
			skills[57].ae = paralyze;
			skills[57].pb = 0;
		}
		//058-影子分身---21
		{
			skills[58].name = "影子分身";
			skills[58].levelreq = 21;
			skills[58].ppt = Normal;
			skills[58].kind = Change;
			skills[58].power = 0;
			skills[58].accuracy = 0;
			skills[58].pp = 15;
			skills[58].residual = skills[58].pp;
			skills[58].ae = EvaUp;
			skills[58].pb = 0;
		}
		//059-空手劈---08
		{
			skills[59].name = "空手劈";
			skills[59].levelreq = 8;
			skills[59].ppt = Fighting;
			skills[59].kind = Physical;
			skills[59].power = 50;
			skills[59].accuracy = 100;
			skills[59].pp = 25;
			skills[59].residual = skills[59].pp;
			skills[59].ae = CthUp;
			skills[59].pb = 20;
		}
		//060-连环巴掌---13
		{
			skills[60].name = "连环巴掌";
			skills[60].levelreq = 13;
			skills[60].ppt = Normal;
			skills[60].kind = Physical;
			skills[60].power = 15;
			skills[60].accuracy = 85;
			skills[60].pp = 10;
			skills[60].residual = skills[60].pp;
			skills[60].ae = combo;
			skills[60].pb = 25;
		}
		//061-连续拳---14
		{
			skills[61].name = "连续拳";
			skills[61].levelreq = 14;
			skills[61].ppt = Normal;
			skills[61].kind = Physical;
			skills[61].power = 18;
			skills[61].accuracy = 85;
			skills[61].pp = 15;
			skills[61].residual = skills[61].pp;
			skills[61].ae = combo;
			skills[61].pb = 25;
		}
		//062-百万吨重拳---41
		{
			skills[62].name = "百万吨重拳";
			skills[62].levelreq = 41;
			skills[62].ppt = Normal;
			skills[62].kind = Physical;
			skills[62].power = 80;
			skills[62].accuracy = 85;
			skills[62].pp = 20;
			skills[62].residual = skills[62].pp;
			skills[62].ae = Nu;
			skills[62].pb = 0;
		}
		//063-火焰拳---38
		{
			skills[63].name = "火焰拳";
			skills[63].levelreq = 38;
			skills[63].ppt = Fire;
			skills[63].kind = Physical;
			skills[63].power = 75;
			skills[63].accuracy = 100;
			skills[63].pp = 15;
			skills[63].residual = skills[63].pp;
			skills[63].ae = burn;
			skills[63].pb = 10;
		}
		//064-冰冻拳---38
		{
			skills[64].name = "冰冻拳";
			skills[64].levelreq = 38;
			skills[64].ppt = Ice;
			skills[64].kind = Physical;
			skills[64].power = 75;
			skills[64].accuracy = 100;
			skills[64].pp = 15;
			skills[64].residual = skills[64].pp;
			skills[64].ae = freeze;
			skills[64].pb = 10;
		}
		//065-雷电拳---38	
		{
			skills[65].name = "雷电拳";
			skills[65].levelreq = 38;
			skills[65].ppt = Electric;
			skills[65].kind = Physical;
			skills[65].power = 75;
			skills[65].accuracy = 100;
			skills[65].pp = 15;
			skills[65].residual = skills[65].pp;
			skills[65].ae = paralyze;
			skills[65].pb = 10;
		}
		//066-夹住---10
		{
			skills[66].name = "夹住";
			skills[66].levelreq = 10;
			skills[66].ppt = Normal;
			skills[66].kind = Physical;
			skills[66].power = 55;
			skills[66].accuracy = 100;
			skills[66].pp = 30;
			skills[66].residual = skills[66].pp;
			skills[66].ae = Nu;
			skills[66].pb = 0;
		}
		//067-旋风刀---42
		{
			skills[67].name = "旋风刀";
			skills[67].levelreq = 42;
			skills[67].ppt = Normal;
			skills[67].kind = Special;
			skills[67].power = 80;
			skills[67].accuracy = 100;
			skills[67].pp = 10;
			skills[67].residual = skills[67].pp;
			skills[67].ae = CthUp;
			skills[67].pb = 10;
		}
		//068-剑舞---24
		{
			skills[68].name = "剑舞";
			skills[68].levelreq = 24;
			skills[68].ppt = Normal;
			skills[68].kind = Change;
			skills[68].power = 0;
			skills[68].accuracy = 0;
			skills[68].pp = 20;
			skills[68].residual = skills[68].pp;
			skills[68].ae = AtkUpp;
			skills[68].pb = 0;
		}
		//069-居合斩---17
		{
			skills[69].name = "居合斩";
			skills[69].levelreq = 17;
			skills[69].ppt = Normal;
			skills[69].kind = Physical;
			skills[69].power = 50;
			skills[69].accuracy = 95;
			skills[69].pp = 30;
			skills[69].residual = skills[69].pp;
			skills[69].ae = Nu;
			skills[69].pb = 0;
		}
		//070-飞翔---46
		{
			skills[70].name = "飞翔";
			skills[70].levelreq = 46;
			skills[70].ppt = Flying;
			skills[70].kind = Physical;
			skills[70].power = 90;
			skills[70].accuracy = 95;
			skills[70].pp = 15;
			skills[70].residual = skills[70].pp;
			skills[70].ae = Nu;
			skills[70].pb = 0;
		}
		//071-摔打---38
		{
			skills[71].name = "摔打";
			skills[71].levelreq = 38;
			skills[71].ppt = Normal;
			skills[71].kind = Physical;
			skills[71].power = 80;
			skills[71].accuracy = 75;
			skills[71].pp = 20;
			skills[71].residual = skills[71].pp;
			skills[71].ae = Nu;
			skills[71].pb = 0;
		}
		//072-踩踏---27
		{
			skills[72].name = "踩踏";
			skills[72].levelreq = 27;
			skills[72].ppt = Normal;
			skills[72].kind = Physical;
			skills[72].power = 65;
			skills[72].accuracy = 100;
			skills[72].pp = 20;
			skills[72].residual = skills[72].pp;
			skills[72].ae = flinch;
			skills[72].pb = 30;
		}
		//073-连踢---24
		{
			skills[73].name = "连踢";
			skills[73].levelreq = 24;
			skills[73].ppt = Fighting;
			skills[73].kind = Physical;
			skills[73].power = 30;
			skills[73].accuracy = 100;
			skills[73].pp = 30;
			skills[73].residual = skills[73].pp;
			skills[73].ae = combo;
			skills[73].pb = 25;
		}
		//074-百万吨重踢---57
		{
			skills[74].name = "百万吨重踢";
			skills[74].levelreq = 57;
			skills[74].ppt = Normal;
			skills[74].kind = Physical;
			skills[74].power = 120;
			skills[74].accuracy = 75;
			skills[74].pp = 5;
			skills[74].residual = skills[74].pp;
			skills[74].ae = Nu;
			skills[74].pb = 0;
		}
		//075-飞踢---47
		{
			skills[75].name = "飞踢";
			skills[75].levelreq = 47;
			skills[75].ppt = Fighting;
			skills[75].kind = Physical;
			skills[75].power = 100;
			skills[75].accuracy = 95;
			skills[75].pp = 10;
			skills[75].residual = skills[75].pp;
			skills[75].ae = Nu;
			skills[75].pb = 0;
		}
		//076-回旋踢---27
		{
			skills[76].name = "回旋踢";
			skills[76].levelreq = 27;
			skills[76].ppt = Fighting;
			skills[76].kind = Physical;
			skills[76].power = 60;
			skills[76].accuracy = 85;
			skills[76].pp = 15;
			skills[76].residual = skills[76].pp;
			skills[76].ae = flinch;
			skills[76].pb = 30;
		}
		//077-角撞---30
		{
			skills[77].name = "角撞";
			skills[77].levelreq = 30;
			skills[77].ppt = Normal;
			skills[77].kind = Physical;
			skills[77].power = 65;
			skills[77].accuracy = 100;
			skills[77].pp = 25;
			skills[77].residual = skills[77].pp;
			skills[77].ae = Nu;
			skills[77].pb = 0;
		}
		//078-头槌---34
		{
			skills[78].name = "头槌";
			skills[78].levelreq = 34;
			skills[78].ppt = Normal;
			skills[78].kind = Physical;
			skills[78].power = 70;
			skills[78].accuracy = 100;
			skills[78].pp = 15;
			skills[78].residual = skills[78].pp;
			skills[78].ae = flinch;
			skills[78].pb = 30;
		}
		//079-泰山压顶---42
		{
			skills[79].name = "泰山压顶";
			skills[79].levelreq = 42;
			skills[79].ppt = Normal;
			skills[79].kind = Physical;
			skills[79].power = 85;
			skills[79].accuracy = 100;
			skills[79].pp = 15;
			skills[79].residual = skills[79].pp;
			skills[79].ae = paralyze;
			skills[79].pb = 30;
		}
		//080-乱击---24
		{
			skills[80].name = "乱击";
			skills[80].levelreq = 24;
			skills[80].ppt = Normal;
			skills[80].kind = Physical;
			skills[80].power = 20;
			skills[80].accuracy = 85;
			skills[80].pp = 20;
			skills[80].residual = skills[80].pp;
			skills[80].ae = combo;
			skills[80].pb = 25;
		}
		//081-双针---20  可以中毒
		{
			skills[81].name = "双针";
			skills[81].levelreq = 20;
			skills[81].ppt = Bug;
			skills[81].kind = Physical;
			skills[81].power = 25;
			skills[81].accuracy = 100;
			skills[81].pp = 20;
			skills[81].residual = skills[81].pp;
			skills[81].ae = combo;
			skills[81].pb = 25;
		}
		//082-唱歌---25
		{
			skills[82].name = "唱歌";
			skills[82].levelreq = 25;
			skills[82].ppt = Normal;
			skills[82].kind = Change;
			skills[82].power = 0;
			skills[82].accuracy = 55;
			skills[82].pp = 15;
			skills[82].residual = skills[82].pp;
			skills[82].ae = sleep;
			skills[82].pb = 0;
		}
		//083-超音波---20
		{
			skills[83].name = "超音波";
			skills[83].levelreq = 20;
			skills[83].ppt = Normal;
			skills[83].kind = Change;
			skills[83].power = 0;
			skills[83].accuracy = 55;
			skills[83].pp = 20;
			skills[83].residual = skills[83].pp;
			skills[83].ae = confusion;
			skills[83].pb = 0;
		}
		//084-溶解液---08
		{
			skills[84].name = "溶解液";
			skills[84].levelreq = 8;
			skills[84].ppt = Poison;
			skills[84].kind = Special;
			skills[84].power = 40;
			skills[84].accuracy = 100;
			skills[84].pp = 30;
			skills[84].residual = skills[84].pp;
			skills[84].ae = SdfDn;
			skills[84].pb = 10;
		}
		//085-冲浪---47
		{
			skills[85].name = "冲浪";
			skills[85].levelreq = 47;
			skills[85].ppt = Water;
			skills[85].kind = Special;
			skills[85].power = 90;
			skills[85].accuracy = 100;
			skills[85].pp = 15;
			skills[85].residual = skills[85].pp;
			skills[85].ae = Nu;
			skills[85].pb = 0;
		}
		//086-冰冻光束---47
		{
			skills[86].name = "冰冻光束";
			skills[86].levelreq = 47;
			skills[86].ppt = Ice;
			skills[86].kind = Special;
			skills[86].power = 90;
			skills[86].accuracy = 100;
			skills[86].pp = 10;
			skills[86].residual = skills[86].pp;
			skills[86].ae = freeze;
			skills[86].pb = 10;
		}
		//087-暴风雪---54
		{
			skills[87].name = "暴风雪";
			skills[87].levelreq = 54;
			skills[87].ppt = Ice;
			skills[87].kind = Special;
			skills[87].power = 110;
			skills[87].accuracy = 70;
			skills[87].pp = 5;
			skills[87].residual = skills[87].pp;
			skills[87].ae = freeze;
			skills[87].pb = 10;
		}
		//088-幻象光线---32
		{
			skills[88].name = "幻象光线";
			skills[88].levelreq = 32;
			skills[88].ppt = Psychic;
			skills[88].kind = Special;
			skills[88].power = 65;
			skills[88].accuracy = 100;
			skills[88].pp = 20;
			skills[88].residual = skills[88].pp;
			skills[88].ae = confusion;
			skills[88].pb = 10;
		}
		//089-泡沫光线---32
		{
			skills[89].name = "泡沫光线";
			skills[89].levelreq = 32;
			skills[89].ppt = Water;
			skills[89].kind = Special;
			skills[89].power = 65;
			skills[89].accuracy = 100;
			skills[89].pp = 20;
			skills[89].residual = skills[89].pp;
			skills[89].ae = SpeDn;
			skills[89].pb = 10;
		}
		//090-极光束---32
		{
			skills[90].name = "极光束";
			skills[90].levelreq = 32;
			skills[90].ppt = Ice;
			skills[90].kind = Special;
			skills[90].power = 65;
			skills[90].accuracy = 100;
			skills[90].pp = 20;
			skills[90].residual = skills[90].pp;
			skills[90].ae = AtkDn;
			skills[90].pb = 10;
		}
		//091-破坏光线---72
		{
			skills[91].name = "破坏光线";
			skills[91].levelreq = 72;
			skills[91].ppt = Normal;
			skills[91].kind = Special;
			skills[91].power = 150;
			skills[91].accuracy = 90;
			skills[91].pp = 5;
			skills[91].residual = skills[91].pp;
			skills[91].ae = Nu;
			skills[91].pb = 0;
		}
		//092-啄钻---42
		{
			skills[92].name = "啄钻";
			skills[92].levelreq = 42;
			skills[92].ppt = Flying;
			skills[92].kind = Physical;
			skills[92].power = 80;
			skills[92].accuracy = 100;
			skills[92].pp = 20;
			skills[92].residual = skills[92].pp;
			skills[92].ae = Nu;
			skills[92].pb = 0;
		}
		//093-啄---07
		{
			skills[93].name = "啄";
			skills[93].levelreq = 7;
			skills[93].ppt = Flying;
			skills[93].kind = Physical;
			skills[93].power = 35;
			skills[93].accuracy = 100;
			skills[93].pp = 35;
			skills[93].residual = skills[93].pp;
			skills[93].ae = Nu;
			skills[93].pb = 0;
		}
		//094-地狱翻滚---42
		{
			skills[94].name = "地狱翻滚";
			skills[94].levelreq = 42;
			skills[94].ppt = Fighting;
			skills[94].kind = Physical;
			skills[94].power = 80;
			skills[94].accuracy = 80;
			skills[94].pp = 20;
			skills[94].residual = skills[94].pp;
			skills[94].ae = Nu;
			skills[94].pb = 0;
		}
		//095-地球上投---25  造成和自己等级相同的伤害
		{
			skills[95].name = "地球上投";
			skills[95].levelreq = 25;
			skills[95].ppt = Fighting;
			skills[95].kind = Physical;
			skills[95].power = 0;
			skills[95].accuracy = 100;
			skills[95].pp = 20;
			skills[95].residual = skills[95].pp;
			skills[95].ae = Nu;
			skills[95].pb = 0;
		}
		//096-怪力---42
		{
			skills[96].name = "怪力";
			skills[96].levelreq = 42;
			skills[96].ppt = Normal;
			skills[96].kind = Physical;
			skills[96].power = 80;
			skills[96].accuracy = 100;
			skills[96].pp = 15;
			skills[96].residual = skills[96].pp;
			skills[96].ae = Nu;
			skills[96].pb = 0;
		}
		//097-吸取---20
		{
			skills[97].name = "吸取";
			skills[97].levelreq = 20;
			skills[97].ppt = Grass;
			skills[97].kind = Special;
			skills[97].power = 20;
			skills[97].accuracy = 100;
			skills[97].pp = 25;
			skills[97].residual = skills[97].pp;
			skills[97].ae = drain;
			skills[97].pb = 0;
		}
		//098-日光束---54
		{
			skills[98].name = "日光束";
			skills[98].levelreq = 54;
			skills[98].ppt = Grass;
			skills[98].kind = Special;
			skills[98].power = 120;
			skills[98].accuracy = 100;
			skills[98].pp = 5;
			skills[98].residual = skills[98].pp;
			skills[98].ae = Nu;
			skills[98].pb = 0;
		}
		//099-十万伏特---45
		{
			skills[99].name = "十万伏特";
			skills[99].levelreq = 45;
			skills[99].ppt = Electric;
			skills[99].kind = Special;
			skills[99].power = 90;
			skills[99].accuracy = 100;
			skills[99].pp = 15;
			skills[99].residual = skills[99].pp;
			skills[99].ae = paralyze;
			skills[99].pb = 10;
		}
		//100-打雷---52
		{
			skills[100].name = "打雷";
			skills[100].levelreq = 52;
			skills[100].ppt = Electric;
			skills[100].kind = Special;
			skills[100].power = 110;
			skills[100].accuracy = 70;
			skills[100].pp = 10;
			skills[100].residual = skills[100].pp;
			skills[100].ae = paralyze;
			skills[100].pb = 30;
		}
		//101-落石---17
		{
			skills[101].name = "落石";
			skills[101].levelreq = 17;
			skills[101].ppt = Rock;
			skills[101].kind = Physical;
			skills[101].power = 50;
			skills[101].accuracy = 90;
			skills[101].pp = 15;
			skills[101].residual = skills[101].pp;
			skills[101].ae = Nu;
			skills[101].pb = 0;
		}
		//102-地震---47
		{
			skills[102].name = "地震";
			skills[102].levelreq = 47;
			skills[102].ppt = Ground;
			skills[102].kind = Physical;
			skills[102].power = 100;
			skills[102].accuracy = 100;
			skills[102].pp = 10;
			skills[102].residual = skills[102].pp;
			skills[102].ae = Nu;
			skills[102].pb = 0;
		}
		//103-挖洞---42
		{
			skills[103].name = "挖洞";
			skills[103].levelreq = 42;
			skills[103].ppt = Ground;
			skills[103].kind = Physical;
			skills[103].power = 80;
			skills[103].accuracy = 100;
			skills[103].pp = 10;
			skills[103].residual = skills[103].pp;
			skills[103].ae = Nu;
			skills[103].pb = 0;
		}
		//104-念力---17
		{
			skills[104].name = "念力";
			skills[104].levelreq = 17;
			skills[104].ppt = Psychic;
			skills[104].kind = Special;
			skills[104].power = 50;
			skills[104].accuracy = 100;
			skills[104].pp = 25;
			skills[104].residual = skills[104].pp;
			skills[104].ae = confusion;
			skills[104].pb = 10;
		}
		//105-精神强念---47
		{
			skills[105].name = "精神强念";
			skills[105].levelreq = 47;
			skills[105].ppt = Psychic;
			skills[105].kind = Special;
			skills[105].power = 90;
			skills[105].accuracy = 100;
			skills[105].pp = 10;
			skills[105].residual = skills[105].pp;
			skills[105].ae = SdfDn;
			skills[105].pb = 10;
		}
		//106-黑夜魔影---25 给予和自己等级同等的伤害
		{
			skills[106].name = "黑夜魔影";
			skills[106].levelreq = 25;
			skills[106].ppt = Ghost;
			skills[106].kind = Special;
			skills[106].power = 0;
			skills[106].accuracy = 100;
			skills[106].pp = 15;
			skills[106].residual = skills[106].pp;
			skills[106].ae = Nu;
			skills[106].pb = 0;
		}
		//107-自我再生---37
		{
			skills[107].name = "自我再生";
			skills[107].levelreq = 37;
			skills[107].ppt = Normal;
			skills[107].kind = Change;
			skills[107].power = 0;
			skills[107].accuracy = 0;
			skills[107].pp = 10;
			skills[107].residual = skills[107].pp;
			skills[107].ae = heal;
			skills[107].pb = 0;
		}
		//108-奇异之光---17
		{
			skills[108].name = "奇异之光";
			skills[108].levelreq = 17;
			skills[108].ppt = Ghost;
			skills[108].kind = Change;
			skills[108].power = 0;
			skills[108].accuracy = 100;
			skills[108].pp = 10;
			skills[108].residual = skills[108].pp;
			skills[108].ae = confusion;
			skills[108].pb = 0;
		}
		//109-变圆---15
		{
			skills[109].name = "变圆";
			skills[109].levelreq = 15;
			skills[109].ppt = Normal;
			skills[109].kind = Change;
			skills[109].power = 0;
			skills[109].accuracy = 0;
			skills[109].pp = 40;
			skills[109].residual = skills[109].pp;
			skills[109].ae = DefUp;
			skills[109].pb = 0;
		}
		//110-屏障---27
		{
			skills[110].name = "屏障";
			skills[110].levelreq = 27;
			skills[110].ppt = Psychic;
			skills[110].kind = Change;
			skills[110].power = 0;
			skills[110].accuracy = 0;
			skills[110].pp = 10;
			skills[110].residual = skills[110].pp;
			skills[110].ae = DefUpp;
			skills[110].pb = 0;
		}
		//111-光墙---32
		{
			skills[111].name = "光墙";
			skills[111].levelreq = 32;
			skills[111].ppt = Psychic;
			skills[111].kind = Change;
			skills[111].power = 0;
			skills[111].accuracy = 0;
			skills[111].pp = 30;
			skills[111].residual = skills[111].pp;
			skills[111].ae = SdfUpp;
			skills[111].pb = 0;
		}
		//112-炸蛋---49
		{
			skills[112].name = "炸蛋";
			skills[112].levelreq = 49;
			skills[112].ppt = Normal;
			skills[112].kind = Physical;
			skills[112].power = 100;
			skills[112].accuracy = 75;
			skills[112].pp = 10;
			skills[112].residual = skills[112].pp;
			skills[112].ae = Nu;
			skills[112].pb = 0;
		}
		//113-舌舔--07
		{
			skills[113].name = "舌舔";
			skills[113].levelreq = 7;
			skills[113].ppt = Ghost;
			skills[113].kind = Physical;
			skills[113].power = 30;
			skills[113].accuracy = 11300;
			skills[113].pp = 30;
			skills[113].residual = skills[113].pp;
			skills[113].ae = paralyze;
			skills[113].pb = 30;
		}
		//114-浊雾---14
		{
			skills[114].name = "浊雾";
			skills[114].levelreq = 1144;
			skills[114].ppt = Poison;
			skills[114].kind = Special;
			skills[114].power = 30;
			skills[114].accuracy = 70;
			skills[114].pp = 20;
			skills[114].residual = skills[114].pp;
			skills[114].ae = poison;
			skills[114].pb = 40;
		}
		//115-污泥攻击---30
		{
			skills[115].name = "污泥攻击";
			skills[115].levelreq = 30;
			skills[115].ppt = Poison;
			skills[115].kind = Special;
			skills[115].power = 65;
			skills[115].accuracy = 11500;
			skills[115].pp = 20;
			skills[115].residual = skills[115].pp;
			skills[115].ae = poison;
			skills[115].pb = 30;
		}
		//116-骨棒---27
		{
			skills[116].name = "骨棒";
			skills[116].levelreq = 27;
			skills[116].ppt = Ground;
			skills[116].kind = Physical;
			skills[116].power = 65;
			skills[116].accuracy = 85;
			skills[116].pp = 20;
			skills[116].residual = skills[116].pp;
			skills[116].ae = flinch;
			skills[116].pb = 10;
		}
		//117-大字爆炎---52
		{
			skills[117].name = "大字爆炎";
			skills[117].levelreq = 52;
			skills[117].ppt = Fire;
			skills[117].kind = Special;
			skills[117].power = 110;
			skills[117].accuracy = 85;
			skills[117].pp = 5;
			skills[117].residual = skills[117].pp;
			skills[117].ae = burn;
			skills[117].pb = 10;
		}
		//118-攀瀑---35
		{
			skills[118].name = "攀瀑";
			skills[118].levelreq = 35;
			skills[118].ppt = Water;
			skills[118].kind = Physical;
			skills[118].power = 80;
			skills[118].accuracy = 100;
			skills[118].pp = 15;
			skills[118].residual = skills[118].pp;
			skills[118].ae = flinch;
			skills[118].pb = 20;
		}
		//119-高速星星---24
		{
			skills[119].name = "高速星星";
			skills[119].levelreq = 24;
			skills[119].ppt = Normal;
			skills[119].kind = Special;
			skills[119].power = 60;
			skills[119].accuracy = 0;
			skills[119].pp = 20;
			skills[119].residual = skills[119].pp;
			skills[119].ae = Nu;
			skills[119].pb = 0;
		}
		//120-尖刺加农炮---15
		{
			skills[120].name = "尖刺加农炮";
			skills[120].levelreq = 15;
			skills[120].ppt = Normal;
			skills[120].kind = Physical;
			skills[120].power = 20;
			skills[120].accuracy = 100;
			skills[120].pp = 15;
			skills[120].residual = skills[120].pp;
			skills[120].ae = combo;
			skills[120].pb = 25;
		}
		//121-飞膝踢---62
		{
			skills[121].name = "飞膝踢";
			skills[121].levelreq = 62;
			skills[121].ppt = Fighting;
			skills[121].kind = Physical;
			skills[121].power = 130;
			skills[121].accuracy = 90;
			skills[121].pp = 10;
			skills[121].residual = skills[121].pp;
			skills[121].ae = Nu;
			skills[121].pb = 0;
		}
		//122-食梦---55
		{
			skills[122].name = "食梦";
			skills[122].levelreq = 55;
			skills[122].ppt = Psychic;
			skills[122].kind = Special;
			skills[122].power = 100;
			skills[122].accuracy = 100;
			skills[122].pp = 15;
			skills[122].residual = skills[122].pp;
			skills[122].ae = drain;
			skills[122].pb = 0;
		}
		//123-吸血---47
		{
			skills[123].name = "吸血";
			skills[123].levelreq = 47;
			skills[123].ppt = Bug;
			skills[123].kind = Physical;
			skills[123].power = 80;
			skills[123].accuracy = 100;
			skills[123].pp = 10;
			skills[123].residual = skills[123].pp;
			skills[123].ae = drain;
			skills[123].pb = 0;
		}
		//124-迷昏拳---36
		{
			skills[124].name = "迷昏拳";
			skills[124].levelreq = 36;
			skills[124].ppt = Normal;
			skills[124].kind = Physical;
			skills[124].power = 70;
			skills[124].accuracy = 100;
			skills[124].pp = 10;
			skills[124].residual = skills[124].pp;
			skills[124].ae = confusion;
			skills[124].pb = 20;
		}
		//125-蘑菇孢子---27
		{
			skills[125].name = "蘑菇孢子";
			skills[125].levelreq = 27;
			skills[125].ppt = Grass;
			skills[125].kind = Change;
			skills[125].power = 0;
			skills[125].accuracy = 100;
			skills[125].pp = 15;
			skills[125].residual = skills[125].pp;
			skills[125].ae = sleep;
			skills[125].pb = 0;
		}
		//126-闪光---27
		{
			skills[126].name = "闪光";
			skills[126].levelreq = 27;
			skills[126].ppt = Normal;
			skills[126].kind = Change;
			skills[126].power = 0;
			skills[126].accuracy = 100;
			skills[126].pp = 20;
			skills[126].residual = skills[126].pp;
			skills[126].ae = AccDn;
			skills[126].pb = 0;
		}
		//127-精神波---30  造成使用者等级*（0.5-1.5）的固定伤害
		{
			skills[127].name = "精神波";
			skills[127].levelreq = 30;
			skills[127].ppt = Psychic;
			skills[127].kind = Special;
			skills[127].power = 0;
			skills[127].accuracy = 100;
			skills[127].pp = 15;
			skills[127].residual = skills[127].pp;
			skills[127].ae = Nu;
			skills[127].pb = 0;
		}
		//128-蟹钳锤---47
		{
			skills[128].name = "蟹钳锤";
			skills[128].levelreq = 47;
			skills[128].ppt = Water;
			skills[128].kind = Physical;
			skills[128].power = 100;
			skills[128].accuracy = 90;
			skills[128].pp = 10;
			skills[128].residual = skills[128].pp;
			skills[128].ae = CthUp;
			skills[128].pb = 10;
		}
		//129-骨头镖---39
		{
			skills[129].name = "骨头镖";
			skills[129].levelreq = 39;
			skills[129].ppt = Ground;
			skills[129].kind = Physical;
			skills[129].power = 50;
			skills[129].accuracy = 90;
			skills[129].pp = 10;
			skills[129].residual = skills[129].pp;
			skills[129].ae = combo;
			skills[129].pb = 25;
		}
		//130-岩崩---37
		{
			skills[130].name = "岩崩";
			skills[130].levelreq = 37;
			skills[130].ppt = Rock;
			skills[130].kind = Physical;
			skills[130].power = 75;
			skills[130].accuracy = 90;
			skills[130].pp = 10;
			skills[130].residual = skills[130].pp;
			skills[130].ae = flinch;
			skills[130].pb = 30;
		}
		//131-必杀门牙---40
		{
			skills[131].name = "必杀门牙";
			skills[131].levelreq = 40;
			skills[131].ppt = Normal;
			skills[131].kind = Physical;
			skills[131].power = 80;
			skills[131].accuracy = 90;
			skills[131].pp = 15;
			skills[131].residual = skills[131].pp;
			skills[131].ae = flinch;
			skills[131].pb = 20;
		}
	}
}
void Pokemon::LevelUp()
{
	if (grade < 100)
		grade++;
}
void Pokemon::SaveLastLevelValue()
{
	Hp.LastLevelValue = Hp.InitialValue;
	Atk.LastLevelValue = Atk.InitialValue;
	Sat.LastLevelValue = Sat.InitialValue;
	Def.LastLevelValue = Def.InitialValue;
	Sdf.LastLevelValue = Sdf.InitialValue;
	Spe.LastLevelValue = Spe.InitialValue;
}
void Pokemon::AddExp(int gra)
{
	//每级所需经验为等级的立方
	//打怪获取经验为敌人PM等级的平方*6
	Exp = Exp + gra*gra * 6;
	while (Exp >= (grade*grade*grade))
	{
		Exp = Exp - grade*grade*grade;
		LevelUp();
		SaveLastLevelValue();
		map();
	}
}
void Pokemon::map()
{
	//HP能力值 = （种族值×2＋个体值＋基础点数÷4）×等级÷100＋10＋等级
	//攻击 / 防御 / 速度 / 特攻 / 特防能力值 = （（种族值×2＋个体值＋基础点数÷4）×等级÷100＋5）×性格修正
	Hp.InitialValue  =  (int)(Phy.RacialValue * 2 + Phy.IndividualValue + Phy.BaseStats / 4)*grade / 100 + 10 + grade;
	Atk.InitialValue = (int)((Str.RacialValue * 2 + Str.IndividualValue + Str.BaseStats / 4)*grade / 100 + 10 + grade)*AtkModify();
	Sat.InitialValue = (int)((Int.RacialValue * 2 + Int.IndividualValue + Int.BaseStats / 4)*grade / 100 + 10 + grade)*SatModify();
	Def.InitialValue = (int)((Str.RacialValue * 2 + Str.IndividualValue + Str.BaseStats / 4)*grade / 100 + 10 + grade)*DefModify();
	Sdf.InitialValue = (int)((Str.RacialValue * 2 + Str.IndividualValue + Str.BaseStats / 4)*grade / 100 + 10 + grade)*SdfModify();
	Spe.InitialValue = (int)((Str.RacialValue * 2 + Str.IndividualValue + Str.BaseStats / 4)*grade / 100 + 10 + grade)*SpeModify();
}
double Pokemon::AtkModify()
{
	if (nature == Lonely || nature == Brave || nature == Adamant || nature == Naughty)
		return 1.1;
	else if (nature == Bold || nature == Timid || nature == Modest || nature == Calm)
		return 0.9;
	else
		return 1;
}
double Pokemon::SatModify()
{
	if (nature == Modest || nature == Mild || nature == Quiet || nature == Rash)
		return 1.1;
	else if (nature == Adamant || nature == Impish || nature == Jolly || nature == Careful)
		return 0.9;
	else
		return 1;
}
double Pokemon::DefModify()
{
	if (nature == Bold || nature == Relaxed || nature == Impish || nature == Lax)
		return 1.1;
	else if (nature == Lonely || nature == Hasty || nature == Mild || nature == Gentle)
		return 0.9;
	else
		return 1;
}
double Pokemon::SdfModify()
{
	if (nature == Calm || nature == Gentle || nature == Sassy || nature == Careful)
		return 1.1;
	else if (nature == Naughty || nature == Lax || nature == Naive || nature == Rash)
		return 0.9;
	else
		return 1;
}
double Pokemon::SpeModify()
{
	if (nature == Timid || nature == Hasty || nature == Jolly || nature == Naive)
		return 1.1;
	else if (nature == Brave || nature == Relaxed || nature == Quiet || nature == Sassy)
		return 0.9;
	else
		return 1;
}
void Pokemon::FightInitial()
{
	Hp.FightValue = Hp.InitialValue;
	Atk.FightValue = Atk.InitialValue;
	Sat.FightValue = Sat.InitialValue;
	Def.FightValue = Def.InitialValue;
	Sdf.FightValue = Sdf.InitialValue;
	Spe.FightValue = Spe.InitialValue;
	CthAl = CthBL;
	AccAL = AccBL;
	EvaAl = EvaBL;
	for (int i = 0; i < 10; i++)
	{
		effs[i] = 0;
	}
}
void Pokemon::FightModify()
{
	if (Atk.ActuallLevel > 8)
		Atk.ActuallLevel = 8;
	else if (Atk.BaseLevel > 8)
		Atk.BaseLevel = 8;
	if (Sat.ActuallLevel > 8)
		Sat.ActuallLevel = 8;
	else if (Sat.BaseLevel > 8)
		Sat.BaseLevel = 8;
	if (Def.ActuallLevel > 8)
		Def.ActuallLevel = 8;
	else if (Def.BaseLevel > 8)
		Def.BaseLevel = 8;
	if (Sdf.ActuallLevel > 8)
		Sdf.ActuallLevel = 8;
	else if (Sdf.BaseLevel > 8)
		Sdf.BaseLevel = 8;
	if (Spe.ActuallLevel > 8)
		Spe.ActuallLevel = 8;
	else if (Spe.BaseLevel > 8)
		Spe.BaseLevel = 8;
	Atk.FightValue = Atk.InitialValue*Atk.BaseLevel / Atk.ActuallLevel;
	Sat.FightValue = Sat.InitialValue*Sat.BaseLevel / Sat.ActuallLevel;
	Def.FightValue = Def.InitialValue*Def.BaseLevel / Def.ActuallLevel;
	Sdf.FightValue = Sdf.InitialValue*Sdf.BaseLevel / Sdf.ActuallLevel;
	Spe.FightValue = Spe.InitialValue*Spe.BaseLevel / Spe.ActuallLevel;
}
double Pokemon::PptRestraint(PPT AnoPpt)
{
	switch (Ppt)
	{
	case Normal:
		switch (AnoPpt)
		{
		case Ghost: return 0;
		case Rock:return 0.5;
		case Steel:return 0.5;
		default:return 1;
		}
	case Fire:
		switch (AnoPpt)
		{
		case Fire: return 0.5;
		case Rock:return 0.5;
		case Water:return 0.5;
		case Dragon:return 0.5;
		case Bug:return 2;
		case Grass:return 2;
		case Ice:return 2;
		case Steel:return 2;
		default:return 1;
		}
	case Bug:
		switch (AnoPpt)
		{
		case Ghost: return 0.5;
		case Poison:return 0.5;
		case Flying:return 0.5;
		case Fighting:return 0.5;
		case Fire:return 0.5;
		case Fairy:return 0.5;
		case Steel:return 0.5;
		case Grass:return 2;
		case Psychic:return 2;
		case Dark:return 2;
		default:return 1;
		}
	case Water:
		switch (AnoPpt)
		{
		case Water: return 0.5;
		case Grass:return 0.5;
		case Dragon:return 0.5;
		case Ground:return 2;
		case Fire:return 2;
		case Rock:return 2;
		default:return 1;
		}
	case Poison:
		switch (AnoPpt)
		{
		case Steel: return 0;
		case Rock:return 0.5;
		case Poison:return 0.5;
		case Ground:return 0.5;
		case Ghost:return 0.5;
		case Grass:return 2;
		case Fairy:return 2;
		default:return 1;
		}
	case Electric:
		switch (AnoPpt)
		{
		case Ground: return 0;
		case Electric:return 0.5;
		case Grass:return 0.5;
		case Dragon:return 0.5;
		case Flying:return 2;
		case Water:return 2;
		default:return 1;
		}
	case Flying:
		switch (AnoPpt)
		{
		case Electric: return 0.5;
		case Rock:return 0.5;
		case Steel:return 0.5;
		case Bug:return 2;
		case Fighting:return 2;
		case Grass:return 2;
		default:return 1;
		}
	case Grass:
		switch (AnoPpt)
		{
		case Electric: return 0.5;
		case Poison:return 0.5;
		case Flying:return 0.5;
		case Fire:return 0.5;
		case Grass:return 0.5;
		case Dragon:return 0.5;
		case Steel:return 0.5;
		case Ground:return 2;
		case Water:return 2;
		case Rock:return 2;
		default:return 1;
		}
	case Ground:
		switch (AnoPpt)
		{
		case Flying: return 0;
		case Bug:return 0.5;
		case Grass:return 0.5;
		case Poison:return 2;
		case Fire:return 2;
		case Electric:return 2;
		case Rock:return 2;
		case Steel:return 2;
		default:return 1;
		}
	case Ice:
		switch (AnoPpt)
		{
		case Fire: return 0.5;
		case Water:return 0.5;
		case Ice:return 0.5;
		case Steel:return 0.5;
		case Flying:return 2;
		case Ground:return 2;
		case Grass:return 2;
		case Dragon:return 2;
		default:return 1;
		}
	case Fighting:
		switch (AnoPpt)
		{
		case Ghost: return 0;
		case Bug:return 0.5;
		case Poison:return 0.5;
		case Flying:return 0.5;
		case Psychic:return 0.5;
		case Fairy:return 0.5;
		case Normal:return 2;
		case Rock:return 2;
		case Ice:return 2;
		case Steel:return 2;
		case Dark:return 2;
		default:return 1;
		}
	case Psychic:
		switch (AnoPpt)
		{
		case Dark: return 0;
		case Psychic:return 0.5;
		case Steel:return 0.5;
		case Poison:return 2;
		case Fighting:return 2;
		default:return 1;
		}
	case Rock:
		switch (AnoPpt)
		{
		case Ground: return 0.5;
		case Fighting:return 0.5;
		case Steel:return 0.5;
		case Bug:return 2;
		case Flying:return 2;
		case Fire:return 2;
		case Ice:return 2;
		default:return 1;
		}
	case Ghost:
		switch (AnoPpt)
		{
		case Normal: return 0;
		case Dark:return 0.5;
		case Psychic:return 2;
		case Ghost:return 2;
		default:return 1;
		}
	case Dragon:
		switch (AnoPpt)
		{
		case Fairy: return 0;
		case Steel:return 0.5;
		case Dragon:return 2;
		default:return 1;
		}
	case Dark:
		switch (AnoPpt)
		{
		case Fighting: return 0.5;
		case Dark:return 0.5;
		case Fairy:return 0.5;
		case Psychic:return 2;
		case Ghost:return 2;
		default:return 1;
		}
	case Steel:
		switch (AnoPpt)
		{
		case Water: return 0.5;
		case Fire:return 0.5;
		case Electric:return 0.5;
		case Steel:return 0.5;
		case Ice:return 2;
		case Rock:return 2;
		case Fairy:return 2;
		default:return 1;
		}
	case Fairy:
		switch (AnoPpt)
		{
		case Poison: return 0.5;
		case Fire:return 0.5;
		case Steel:return 0.5;
		case Fighting:return 2;
		case Dragon:return 2;
		case Dark:return 2;
		default:return 1;
		}
	}
}
void Pokemon::getNature()
{
	int C = r.get(1, 25);
	switch (C)
	{
	case 1:	nature = Hardy; break;
	case 2:	nature = Lonely; break;
	case 3:	nature = Brave; break;
	case 4:	nature = Adamant; break;
	case 5:	nature = Naughty; break;
	case 6:	nature = Bold; break;
	case 7:	nature = Docile; break;
	case 8:	nature = Relaxed; break;
	case 9:	nature = Impish; break;
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
}
/*void Pokemon::FirstSave(std::string username, sqlite3 *db)
{
	char sql[512];
	sprintf_s(sql, "INSERT INTO pokemon_table (NAME,PMID,NICKY,GRADE,EXP,NATURE,PROPERTY,STR_IV,INT_IV,PHY_IV,STA_IV,RES_IV,AGI_IV,SKILLS,SKILL_BAR1,SKILL_BAR2,SKILL_BAR3,SKILL_BAR4)\
		VALUES ('%s',%d,'%s',%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,0,0,-1,-1,-1);"
		,username.c_str(),id,nicky.c_str(),grade,Exp,nature, Ppt,
		Str.IndividualValue, Int.IndividualValue, Phy.IndividualValue, Sta.IndividualValue, Res.IndividualValue, Agi.IndividualValue );
	char *zErrMsg = 0;
	int rc = sqlite3_exec(db, sql, NULL, NULL, &zErrMsg);
	if (rc != SQLITE_OK)
	{
		fprintf(stderr, "SQL error:%s\n", zErrMsg);
		sqlite3_free(zErrMsg);
	}
	else
	{
		fprintf(stdout, "Records created successfully\n");
	}
}*/
void Pokemon::Display()
{
	std::cout << "Name: " << name << std::endl
		<< "ID: " << id << std::endl
		<< "Nicky name: " << nicky << std::endl
		<< "Grade: " << grade << std::endl
		<< "Exp: " << Exp << std::endl
		<< "Nature: ";
	switch (nature)
	{
	case 1:std::cout << "Hardy" << std::endl; break;
	case 2:std::cout << "Lonely" << std::endl; break;
	case 3:std::cout << "Brave" << std::endl; break;
	case 4:std::cout << "Adamant" << std::endl; break;
	case 5:std::cout << "Naughty" << std::endl; break;
	case 6:std::cout << "Bold" << std::endl; break;
	case 7:std::cout << "Docile" << std::endl; break;
	case 8:std::cout << "Relaxed" << std::endl; break;
	case 9:std::cout << "Impish" << std::endl; break;
	case 10:std::cout << "Lax" << std::endl; break;
	case 11:std::cout << "Timid" << std::endl; break;
	case 12:std::cout << "Hasty" << std::endl; break;
	case 13:std::cout << "Serious" << std::endl; break;
	case 14:std::cout << "Jolly" << std::endl; break;
	case 15:std::cout << "Naive" << std::endl; break;
	case 16:std::cout << "Modest" << std::endl; break;
	case 17:std::cout << "Mild" << std::endl; break;
	case 18:std::cout << "Quiet" << std::endl; break;
	case 19:std::cout << "Bashful" << std::endl; break;
	case 20:std::cout << "Rash" << std::endl; break;
	case 21:std::cout << "Calm" << std::endl; break;
	case 22:std::cout << "Gentle" << std::endl; break;
	case 23:std::cout << "Sassy" << std::endl; break;
	case 24:std::cout << "Careful" << std::endl; break;
	case 25:std::cout << "Quirky" << std::endl; break;
	}
	std::cout << "Property: ";
	switch (Ppt)
	{
	case 1:std::cout << "Normal\n"; break;
	case 2:std::cout << "Fire\n"; break;
	case 3:std::cout << "Bug\n"; break;
	case 4:std::cout << "Water\n"; break;
	case 5:std::cout << "Poison\n"; break;
	case 6:std::cout << "Electric\n"; break;
	case 7:std::cout << "Flying\n"; break;
	case 8:std::cout << "Grass\n"; break;
	case 9:std::cout << "Ground\n"; break;
	case 10:std::cout << "Ice\n"; break;
	case 11:std::cout << "Fighting\n"; break;
	case 12:std::cout << "Psychic\n"; break;
	case 13:std::cout << "Rock\n"; break;
	case 14:std::cout << "Ghost\n"; break;
	case 15:std::cout << "Dragon\n"; break;
	case 16:std::cout << "Dark\n"; break;
	case 17:std::cout << "Steel\n"; break;
	case 18:std::cout << "Fairy\n"; break;
	}
	std::cout << "Atk: " << Atk.InitialValue << std::endl
		<< "Sat: " << Sat.InitialValue << std::endl
		<< "Hp: " << Hp.InitialValue << std::endl
		<< "Def: " << Def.InitialValue << std::endl
		<< "Sdf: " << Sdf.InitialValue << std::endl
		<< "Spe: " << Spe.InitialValue << std::endl;
}
int Pokemon::Accuracy(Pokemon* pm)
{
	int acc = AccAL - pm->EvaAl;
	if (acc > 6)
		acc = 6;
	else if (acc < -6)
		acc = -6;
	switch (acc)
	{
	case -6:return r.get(0, 100) * 100 / 25;
	case -5:return r.get(0, 100) * 100 / 28;
	case -4:return r.get(0, 100) * 100 / 33;
	case -3:return r.get(0, 100) * 100 / 40;
	case -2:return r.get(0, 100) * 100 / 50;
	case -1:return r.get(0, 100) * 100 / 66;
	case 0:return r.get(0, 100);
	case 1:return r.get(0, 100) * 100 / 150;
	case 2:return r.get(0, 100) * 100 / 200;
	case 3:return r.get(0, 100) * 100 / 250;
	case 4:return r.get(0, 100) * 100 / 300;
	case 5:return r.get(0, 100) * 100 / 350;
	case 6:return r.get(0, 100) * 100 / 400;
	}
}
void Pokemon::Fight(Pokemon* pm)
{
	int power = 0;
	FightModify();
	Move SelectSkill = skills[skill_list[skill_bar[select_skill]]];
	if (effs[1] != 0)
	{
		effs[1]--;
		Hp.FightValue = Hp.FightValue * 7 / 8;
	}
	else if (effs[3] != 0)
	{
		effs[3]--;
		Hp.FightValue = Hp.FightValue * 7 / 8;
	}
	else if (effs[5] != 0)
	{
		effs[5]--;
		pm->Hp.FightValue = pm->Hp.FightValue + (Hp.FightValue / 8);
		Hp.FightValue = Hp.FightValue * 7 / 8;
	}
	else if (effs[2] != 0)
	{
		effs[2]--;
		return;
	}
	else if (effs[4] != 0)
	{
		effs[4]--;
	}
	if (SelectSkill.kind == Physical)
	{
		power = (grade * 2 / 5 + 2)*SelectSkill.power*Atk.FightValue / pm->Def.FightValue / 50 + 2;
	}
	else if (SelectSkill.kind == Special)
	{
		power = (grade * 2 / 5 + 2)*SelectSkill.power*Sat.FightValue / pm->Sdf.FightValue / 50 + 2;
	}
	else
	{
		power = 0;
	}
	power = power*PptRestraint(pm->Ppt);
	if (SelectSkill.ae == combo)
	{
		while (Accuracy(pm) < SelectSkill.accuracy)
		{
			pm->Hp.FightValue -= power;
			if (pm->Hp.FightValue <= 0)
			{
				pm->Hp.FightValue = 0;
				return;
			}
		}
	}
	else
	{
		if (SelectSkill.accuracy == 0)
		{
			pm->Hp.FightValue -= power;
			if (pm->Hp.FightValue <= 0)
			{
				pm->Hp.FightValue = 0;
				return;
			}
		}
		else if (Accuracy(pm) < SelectSkill.accuracy)
		{
			pm->Hp.FightValue -= power;
			if (pm->Hp.FightValue <= 0)
			{
				pm->Hp.FightValue = 0;
				return;
			}
			if (SelectSkill.ae != Nu)
			{
				if (SelectSkill.pb == 0)
				{
					switch (SelectSkill.ae)
					{
					case AtkUp:Atk.ActuallLevel++; break;
					case AtkUpp:Atk.ActuallLevel += 2; break;
					case AtkDn:pm->Atk.ActuallLevel--; break;
					case AtkDnn:pm->Atk.ActuallLevel -= 2; break;
					case SatUp:Sat.ActuallLevel++; break;
					case SatUpp:Sat.ActuallLevel += 2; break;
					case SatDn:pm->Sat.ActuallLevel--; break;
					case SatDnn:pm->Sat.ActuallLevel -= 2; break;
					case DefUp:Def.ActuallLevel++; break;
					case DefUpp:Def.ActuallLevel += 2; break;
					case DefDn:pm->Def.ActuallLevel--; break;
					case DefDnn:pm->Def.ActuallLevel -= 2; break;
					case SdfUp:Sdf.ActuallLevel++; break;
					case SdfUpp:Sdf.ActuallLevel += 2; break;
					case SdfDn:pm->Sdf.ActuallLevel--; break;
					case SdfDnn:pm->Sdf.ActuallLevel -= 2; break;
					case SpeUp:Spe.ActuallLevel++; break;
					case SpeUpp:Spe.ActuallLevel += 2; break;
					case SpeDn:pm->Spe.ActuallLevel--; break;
					case SpeDnn:pm->Spe.ActuallLevel -= 2; break;
					case AccUp:AccAL++; break;
					case AccUpp:AccAL += 2; break;
					case AccDn:pm->AccAL--; break;
					case AccDnn:pm->AccAL -= 2; break;
					case EvaUp:EvaAl++; break;
					case EvaUpp:EvaAl += 2; break;
					case EvaDn:pm->EvaAl--; break;
					case EvaDnn:pm->EvaAl -= 2; break;
					case CthUp:CthAl++; break;
					case CthUpp:CthAl += 2; break;
					case CthDn:pm->CthAl--; break;
					case CthDnn:pm->CthAl -= 2; break;
					case poison:
						pm->effs[1] = 5;
						break;
					case paralyze:
						pm->effs[2] = 2;
						break;
					case burn:
						pm->effs[3] = 5;
						break;
					case freeze:
						pm->effs[4] = 2;
						break;
					case leech:
						pm->effs[5] = 5;
						break;
					}
				}
				else if (Accuracy(pm)<SelectSkill.pb)
				{
					switch (SelectSkill.ae)
					{
					case AtkUp:Atk.ActuallLevel++; break;
					case AtkUpp:Atk.ActuallLevel += 2; break;
					case AtkDn:pm->Atk.ActuallLevel--; break;
					case AtkDnn:pm->Atk.ActuallLevel -= 2; break;
					case SatUp:Sat.ActuallLevel++; break;
					case SatUpp:Sat.ActuallLevel += 2; break;
					case SatDn:pm->Sat.ActuallLevel--; break;
					case SatDnn:pm->Sat.ActuallLevel -= 2; break;
					case DefUp:Def.ActuallLevel++; break;
					case DefUpp:Def.ActuallLevel += 2; break;
					case DefDn:pm->Def.ActuallLevel--; break;
					case DefDnn:pm->Def.ActuallLevel -= 2; break;
					case SdfUp:Sdf.ActuallLevel++; break;
					case SdfUpp:Sdf.ActuallLevel += 2; break;
					case SdfDn:pm->Sdf.ActuallLevel--; break;
					case SdfDnn:pm->Sdf.ActuallLevel -= 2; break;
					case SpeUp:Spe.ActuallLevel++; break;
					case SpeUpp:Spe.ActuallLevel += 2; break;
					case SpeDn:pm->Spe.ActuallLevel--; break;
					case SpeDnn:pm->Spe.ActuallLevel -= 2; break;
					case AccUp:AccAL++; break;
					case AccUpp:AccAL += 2; break;
					case AccDn:pm->AccAL--; break;
					case AccDnn:pm->AccAL -= 2; break;
					case EvaUp:EvaAl++; break;
					case EvaUpp:EvaAl += 2; break;
					case EvaDn:pm->EvaAl--; break;
					case EvaDnn:pm->EvaAl -= 2; break;
					case CthUp:CthAl++; break;
					case CthUpp:CthAl += 2; break;
					case CthDn:pm->CthAl--; break;
					case CthDnn:pm->CthAl -= 2; break;
					case poison:
						pm->effs[1] = 5;
						break;
					case paralyze:
						pm->effs[2] = 2;
						break;
					case burn:
						pm->effs[3] = 5;
						break;
					case freeze:
						pm->effs[4] = 2;
						break;
					case leech:
						pm->effs[5] = 5;
						break;
					}
				}
			}
		}
	}
	//结算自身的effs
	//写一个产生0-100的随机数，与命中率对比，如果命中判断是否击杀，击杀则Hp.FightValue置零
	//没有击杀考虑连击，对连击进行循环，每次攻击后判断是否击杀
	//如果没有击杀则继续判断附加状态，为0必中
	//增减属性的状态直接计算给对方
	//附加属性加到对方的effs中，在对方行动前结算
}
int Pokemon::SpeedMap()
{
	if (Spe.FightValue <= 100)
		return 10;
	else if (Spe.FightValue <= 150)
		return 9;
	else if (Spe.FightValue <= 200)
		return 8;
	else if (Spe.FightValue <= 250)
		return 7;
	else if (Spe.FightValue <= 300)
		return 6;
	else if (Spe.FightValue <= 350)
		return 5;
	else if (Spe.FightValue <= 400)
		return 4;
	else if (Spe.FightValue <= 450)
		return 3;
	else if (Spe.FightValue <= 500)
		return 2;
	else
		return 1;
}
