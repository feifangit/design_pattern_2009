#pragma once

//建造者模式
//优点 : 使得建造代码和表示代码分离
//

struct fitmentBuilder //装修方案
{
	virtual void buy_tv() = 0; //买电视
	virtual void buy_ac() = 0; //买空调
	virtual void buy_floor() = 0; //买地板
};

struct  CFeiFan
{
	fitmentBuilder* m_fitmentBuilder;
	CFeiFan(fitmentBuilder* builder) //必须接受一种装修方案
	{
		m_fitmentBuilder = builder;
	}
	void fitment() //装修
	{
		m_fitmentBuilder->buy_tv();
		m_fitmentBuilder->buy_ac();
		m_fitmentBuilder->buy_floor();
	}
};

struct CExpensiveFitment : public fitmentBuilder
{
	void buy_tv(){cout << "SONY 60寸液晶电视" << endl;}
	void buy_floor(){cout << "圣象实木地板" << endl;}
	void buy_ac(){cout << "中央空调解决方案" << endl;}
};

struct CCheapFitment : public fitmentBuilder
{
	void buy_tv(){cout << "熊猫 21寸普通电视" << endl;}
	void buy_floor(){cout << "不知名地板" << endl;}
	void buy_ac(){cout << "窗式空调" << endl;}
};

void egBuilder();