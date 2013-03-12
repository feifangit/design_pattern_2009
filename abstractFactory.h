#pragma once

class IOperationInt //INT����
{
protected:
	int m_iPara1, m_iPara2;
public:
	void set_para1(int _para1)	{ m_iPara1 = _para1;	}
	void set_para2(int _para2)	{ m_iPara2 = _para2;	}
	virtual int get_result() = 0;
};
struct COpAddInt : public IOperationInt //�ӷ�����
{
	int get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSubInt : public IOperationInt //��������
{
	int get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//-----------------------------------------------------------

class IOperationFloat //FLOAT����
{	
protected:
	float m_iPara1, m_iPara2;
public:
	void set_para1(float _para1)	{ m_iPara1 = _para1;	}
	void set_para2(float _para2)	{ m_iPara2 = _para2;	}
	virtual float get_result() = 0;
};
struct COpAddFloat : public IOperationFloat //�ӷ�����
{
	float get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSubFloat : public IOperationFloat //��������
{
	float get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//-----------------------------------------------------------����
struct IOpFactory //����������
{
	virtual IOperationInt* create_op_int() = 0; //int������
	virtual IOperationFloat* create_op_float() = 0; //float������
};
struct CAddFactory : public IOpFactory //���ｫadd��sub������Ϊ�������еĲ�Ʒ.
{
	IOperationInt* create_op_int()
	{
		return new COpAddInt();
	}
	IOperationFloat* create_op_float()
	{
		return new COpAddFloat();
	}
};
struct CSubFactory : public IOpFactory
{
	IOperationInt* create_op_int()
	{
		return new COpSubInt();
	}
	IOperationFloat* create_op_float()
	{
		return new COpSubFloat();
	}
};

void egAbstractFactory();
