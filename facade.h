#pragma once

//外观模式
//用于将子系统(若干类)的多个功能抽样合并使用
//以魔兽争霸为例
//一波流打法发局  和 正常打法开局

//**忽略没有释放的内存, 只是一个例子


struct CFarmer
{
	void create_house()
	{
		cout << "制造房子" << endl;
	}
	void create_barracks()
	{
		cout << "制造兵营" << endl;
	}
	void create_timberjack()
	{
		cout << "制造伐木场" << endl;
	}
};

struct CBase
{
	CFarmer* create_farmer()
	{
		cout << "制造农民" << endl;
		return new CFarmer;
	}
};


struct CNormalFight
{
	void start()
	{
		CBase humanBase;
		CFarmer* farmer1 = humanBase.create_farmer();
		farmer1->create_house();

		CFarmer* farmer2 = humanBase.create_farmer();
		farmer2->create_barracks();
	}
};

struct CRushFight
{
	void start()
	{
		CBase humanBase;
		CFarmer* farmer1 = humanBase.create_farmer();
		farmer1->create_house();

		CFarmer* farmer2 = humanBase.create_farmer();
		farmer2->create_timberjack();
	}
};

void egFacade();
