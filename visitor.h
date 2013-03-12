#pragma once

//访问者模式

//表示一个作用于 某个对象结构中的各元素 的操作.
//可以在  不改变各元素的类  的前提下  定义作用域这些元素的新操作
//适用于元素种类稳定的系统

//特点: 操作类的借口中需要对元素种类分别提供接口 -> 所以要求元素的种类稳定

//其中用到了双分派的技术
//元素 从入参得到 操作对象
//然后将自己(this)传给操作对象 ,操作对象能操作到元素


struct CMan;
struct CWoman;

//男人和女人是稳定的分类
struct IAction
{
	virtual void getManAction(CMan* man) = 0; //操作man对象 实现动作
	virtual void getWomanAction(CWoman* woman) = 0;
};

//元素: 稳定的分类 
struct IHuman
{
	string x;
	virtual void do_things(IAction* action) = 0;
};
struct CMan : public IHuman
{
	CMan()  {x = "xiaodidi";}
	void do_things(IAction* action) //做 某个动作 
	{
		action->getManAction(this);
	}
};
struct CWoman : public IHuman
{
	CWoman()  {x = "????";}
	void do_things(IAction* action)
	{
		action->getWomanAction(this);
	}
};

//多样化的动作 (针对元素做再多的动作都不怕)
struct CXuxu : public IAction
{
	void getManAction(CMan* man)
	{
		cout << "man use " << man->x.c_str() << " to xuxu" << endl;
	}
	void getWomanAction(CWoman* woman)
	{
		cout << "woman use " << woman->x.c_str() << " to xuxu" << endl;
	}
};
struct CAngry : public IAction
{
	void getManAction(CMan* man)
	{
		cout << "fight!~ 3 2 1" << endl;
	}
	void getWomanAction(CWoman* woman)
	{
		cout << "keep slience" << endl;
	}
};

void egVisitor();