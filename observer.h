#pragma once

//观察者模式 (其中的观察者 其实是 监听者)
//用于一对多的依赖关系 多个观察着对象同时监听同一个信号
//当信号发生的时候, 会通知所有的观察者


class CObserver;

class CSubject //通知者
{
protected:
	vector<CObserver*> reg_users; //注册过的需要通知的人
public:
	virtual void add_rec(CObserver* reg_user) //注册要通知的人
	{
		reg_users.push_back(reg_user);
	}
	virtual void del_rec(CObserver* reg_user) //去掉要通知的人
	{
		//find reg_rec reg_user
		//reg_users remove
	}
	void notify(); //通知

	string msg; //通知内容
};

class CObserver //观察者 ,会被通知
{
protected:
	string m_name;
	CSubject* m_dependence;

public:
	CObserver(const string& self_name, CSubject* dependence)
	{
		m_name = self_name;
		m_dependence = dependence;
	}
	virtual void update()
	{
		cout << "[" << m_name.c_str() << "] : " << m_dependence->msg.c_str() << endl;
	}
};




void egObserver();