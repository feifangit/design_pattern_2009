#pragma once

class IOperationInt //INT操作
{
protected:
	int m_iPara1, m_iPara2;
public:
	void set_para1(int _para1)	{ m_iPara1 = _para1;	}
	void set_para2(int _para2)	{ m_iPara2 = _para2;	}
	virtual int get_result() = 0;
};
struct COpAddInt : public IOperationInt //加法操作
{
	int get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSubInt : public IOperationInt //减法操作
{
	int get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//-----------------------------------------------------------

class IOperationFloat //FLOAT操作
{	
protected:
	float m_iPara1, m_iPara2;
public:
	void set_para1(float _para1)	{ m_iPara1 = _para1;	}
	void set_para2(float _para2)	{ m_iPara2 = _para2;	}
	virtual float get_result() = 0;
};
struct COpAddFloat : public IOperationFloat //加法操作
{
	float get_result() { cout << "add "; return m_iPara1 + m_iPara2;}
};

struct COpSubFloat : public IOperationFloat //减法操作
{
	float get_result() { cout << "sub "; return m_iPara1 - m_iPara2;}
};

//-----------------------------------------------------------工厂
struct IOpFactory //计算器工厂
{
	virtual IOperationInt* create_op_int() = 0; //int计算器
	virtual IOperationFloat* create_op_float() = 0; //float计算器
};
struct CAddFactory : public IOpFactory //这里将add和sub操作视为两个并列的产品.
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
