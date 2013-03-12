#pragma once;

class IOperation //����
{
protected:
	int m_iPara1, m_iPara2;
public:
	void set_para1(int _para1)	{ m_iPara1 = _para1;	}
	void set_para2(int _para2)	{ m_iPara2 = _para2;	}
	virtual int get_result() = 0;
};
struct COpAdd : public IOperation //�ӷ�����
{
	int get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSub : public IOperation //��������
{
	int get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//////////////////////////////////////////////////////////////////////
struct IOpFactory 
{
	virtual IOperation* create_op() = 0; //�ͼ򵥹���������:�����ڹ������ж�
};

struct CAddFactory : public IOpFactory
{
	IOperation* create_op()
	{
		return new COpAdd();
	}
};

struct CSubFactory : public IOpFactory
{
	IOperation* create_op()
	{
		return new COpSub();
	}
};

/////////////////////////////////////////////////////////////////////////
void egFactory();