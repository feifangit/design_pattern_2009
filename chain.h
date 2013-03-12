#pragma once

//ְ����ģʽ

//���еĴ���������ͳһ����ӿ� �� ������һ���Ľ��
//, �ɵ���������������.
//���ְ�����ĵ�һ����Ԫ������, ���´�����һ����Ԫ.ֱ�����˴���
//��Ҫע�����һ���Ĵ���,Ҳ����֮ǰ���õĴ���Ԫ��û�д���ʱ,����Ƿ�������,������ʾʲô
//ְ�����еĴ���Ԫ��˳������˴��������Ȩ

struct IProcUnit
{
protected:
	IProcUnit* m_next_handler;
public :
	IProcUnit(): m_next_handler(NULL){}
	virtual bool try_handle(int i) = 0; //����false��Ϊ�õ�Ԫ������
	void  handle(int i)
	{
		if (false == try_handle(i)) //��Ҫ��һ��Ԫ����
		{
			if (m_next_handler) //���û����һ����ɶ������
				m_next_handler->handle(i);
			else
				cout << "fail in handle:" << i << endl;
		}
	}
	void set_next_handle(IProcUnit* procUnit)
	{
		m_next_handler = procUnit;
	}
};

struct C1_100ProcUnit : public IProcUnit
{
	bool try_handle(int i)
	{
		if (i < 100 && i > 0)
		{
			cout << "1-100" << endl;
			return true;
		}
		else
			return false;
	}
};

struct C100_1000ProcUnit : public IProcUnit
{
	bool try_handle(int i)
	{
		if (i >= 100 && i < 1000)
		{
			cout << "100-1000" << endl;
			return true;
		}
		else
			return false;
	}
};

void egChain();
