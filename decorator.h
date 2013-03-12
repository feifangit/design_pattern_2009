#pragma once

//装饰模式Decorator
//动态的给一个对象增加一些额外的职责, 比生成子类更加的灵活
//其实是将所需要的功能按照正确的顺序串联起来进行控制

struct IDsp //没有规矩 不成方圆
{
	virtual void show_power() = 0; //显示战斗力
};

struct CHuman : public IDsp //原有的类,需要给这个类增加额外的职责(穿上装备)
{
	void show_power()
	{
		cout << "裸身,战斗力0" << endl;		
	}
};

struct IWare : public IDsp //抽象装备
{
	IDsp* m_org_lvl; //原有的装备
	void ware_something_on(IDsp* org_lvl) //设置原有的装备基础
	{
		m_org_lvl = org_lvl;
	}
	virtual void show_power()
	{
		if (m_org_lvl != NULL)
			m_org_lvl->show_power();
	}
};

struct CHujia : public IWare
{
	virtual void show_power()
	{
		m_org_lvl->show_power(); //显示穿上之前的力量
		cout << "战斗力 +10" << endl;
	}
};
struct CWeapon : public IWare
{
	void try_weapon()
	{
		cout << "试枪" << endl;
	}
	virtual void show_power()
	{
		m_org_lvl->show_power();
		cout << "战斗力 + 40" << endl;
	}
};


void egDecorator();