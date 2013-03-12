#pragma once

//策略模式 (Strategy)
//定义算法家族,分别封装起来,让它们之间可以相互替换
//重点是对算法的封装

//调用者告诉分配器一个标识(字符串或者int), 然后拿着返回的对象的某个方法用就是了
//调用者根本不认识那些算法的类名,只知道算法的标识


//算法
struct  IAgl
{
	int para1, para2;
	void set_para(int p1, int p2)
	{
		para1 = p1;
		para2 = p2;
	}
	virtual int get_result() = 0;
};

struct CAdd : public IAgl
{
	int get_result()
	{
		return (para1 + para2);
	}
};
struct CSub : public IAgl
{
	int get_result()
	{
		return (para1 - para2);
	}
};

//策略分配器
class CDeliver
{
	IAgl * m_op;
public:
	CDeliver(const string& policyName)
	{
		m_op = NULL;
		if (policyName == "add")
		{
			m_op = new CAdd();
		}
		else if (policyName == "sub")
		{
			m_op = new CSub();
		}
	}
	~CDeliver()
	{
		if (NULL != m_op)
		{
			delete m_op;
			m_op = NULL;
		}
	}
	int get_result(int a, int b)
	{
		m_op->set_para(a, b);
		return m_op->get_result();
	}

};

void egPolicy();