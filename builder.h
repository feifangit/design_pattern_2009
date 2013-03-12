#pragma once

//������ģʽ
//�ŵ� : ʹ�ý������ͱ�ʾ�������
//

struct fitmentBuilder //װ�޷���
{
	virtual void buy_tv() = 0; //�����
	virtual void buy_ac() = 0; //��յ�
	virtual void buy_floor() = 0; //��ذ�
};

struct  CFeiFan
{
	fitmentBuilder* m_fitmentBuilder;
	CFeiFan(fitmentBuilder* builder) //�������һ��װ�޷���
	{
		m_fitmentBuilder = builder;
	}
	void fitment() //װ��
	{
		m_fitmentBuilder->buy_tv();
		m_fitmentBuilder->buy_ac();
		m_fitmentBuilder->buy_floor();
	}
};

struct CExpensiveFitment : public fitmentBuilder
{
	void buy_tv(){cout << "SONY 60��Һ������" << endl;}
	void buy_floor(){cout << "ʥ��ʵľ�ذ�" << endl;}
	void buy_ac(){cout << "����յ��������" << endl;}
};

struct CCheapFitment : public fitmentBuilder
{
	void buy_tv(){cout << "��è 21����ͨ����" << endl;}
	void buy_floor(){cout << "��֪���ذ�" << endl;}
	void buy_ac(){cout << "��ʽ�յ�" << endl;}
};

void egBuilder();