#pragma once

//中介者模式
//用一个中介对象来封装一系列的对象交互, 使得各对象不需要显示的相互引用.
//使其耦合松散, 可以独立的改变他们之间的交互

//中介需要知道双方的所有信息
//注意不要把松散的对象的复杂性 变成 中介的复杂性

struct HouseDeal;
struct IHouseMediator
{
	virtual void notify(const string& msg, HouseDeal* msgTarget) = 0;
};


//发生房屋交易的双方
struct  HouseDeal
{
protected:
	IHouseMediator* m_mediator;
public:
	HouseDeal(IHouseMediator* mediator) : m_mediator(mediator) {}
};
//买家
struct HouseBuyer : public HouseDeal
{
	HouseBuyer(IHouseMediator* mediator) : HouseDeal(mediator) {}
	void put_msg(const string& msg)
	{
		m_mediator->notify(msg, this);
	}
	void get_msg(const string& msg)
	{
		cout << "[buyer recv] " << msg.c_str() << endl;
	}
};
//卖家 
struct HouseSeller : public HouseDeal
{
	HouseSeller(IHouseMediator* mediator) : HouseDeal(mediator) {}
	void put_msg(const string& msg)
	{
		m_mediator->notify(msg, this);
	}
	void get_msg(const string& msg)
	{
		cout << "[seller recv] " << msg.c_str() << endl;
	}
};

//具体的中介机构 
class  C5i5j : public IHouseMediator
{
public:
	HouseBuyer* buyer;
	HouseSeller* seller;

	
	void notify(const string& msg, HouseDeal* msgTarget)
	{
		if (msgTarget == buyer)
			seller->get_msg(msg);
		else if (msgTarget == seller)
			buyer->get_msg(msg);
	}
};

void egMediator();