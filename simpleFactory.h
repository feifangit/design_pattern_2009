#pragma  once

//////////////////////////////////////////////////////////////////////////////////////
class COperation //操作
{
protected:
	int m_iPara1, m_iPara2;
public:
	void set_para1(int _para1)	{ m_iPara1 = _para1;	}
	void set_para2(int _para2)	{ m_iPara2 = _para2;	}
	virtual int get_result() = 0;
};

struct COpAdd : public COperation //加法操作
{
	int get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSub : public COperation //减法操作
{
	int get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////
class COpFactory
{
public:
	COperation* get_op(const string& type)
	{
		if (type == string("OP_ADD"))
			return new COpAdd();
		else if (type == string("OP_SUB"))
			return new COpSub();
		return NULL;
	}
	
};



void egSimpleFactory();