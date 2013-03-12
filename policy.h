#pragma once

//����ģʽ (Strategy)
//�����㷨����,�ֱ��װ����,������֮������໥�滻
//�ص��Ƕ��㷨�ķ�װ

//�����߸��߷�����һ����ʶ(�ַ�������int), Ȼ�����ŷ��صĶ����ĳ�������þ�����
//�����߸�������ʶ��Щ�㷨������,ֻ֪���㷨�ı�ʶ


//�㷨
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

//���Է�����
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