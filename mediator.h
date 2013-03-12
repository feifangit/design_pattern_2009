#pragma once

//�н���ģʽ
//��һ���н��������װһϵ�еĶ��󽻻�, ʹ�ø�������Ҫ��ʾ���໥����.
//ʹ�������ɢ, ���Զ����ĸı�����֮��Ľ���

//�н���Ҫ֪��˫����������Ϣ
//ע�ⲻҪ����ɢ�Ķ���ĸ����� ��� �н�ĸ�����

struct HouseDeal;
struct IHouseMediator
{
	virtual void notify(const string& msg, HouseDeal* msgTarget) = 0;
};


//�������ݽ��׵�˫��
struct  HouseDeal
{
protected:
	IHouseMediator* m_mediator;
public:
	HouseDeal(IHouseMediator* mediator) : m_mediator(mediator) {}
};
//���
struct HouseBuyer : public HouseDeal
{
	HouseBuyer(IHouseMediator* mediator) : HouseDeal(mediator) {}
	void put_msg(const string& msg)
	{
		m_mediator->notify(msg, this);
	}
	void get_msg(const string& msg)
	{
		cout << "[buyer recv] " << msg.c_str() << endl;
	}
};
//���� 
struct HouseSeller : public HouseDeal
{
	HouseSeller(IHouseMediator* mediator) : HouseDeal(mediator) {}
	void put_msg(const string& msg)
	{
		m_mediator->notify(msg, this);
	}
	void get_msg(const string& msg)
	{
		cout << "[seller recv] " << msg.c_str() << endl;
	}
};

//������н���� 
class  C5i5j : public IHouseMediator
{
public:
	HouseBuyer* buyer;
	HouseSeller* seller;

	
	void notify(const string& msg, HouseDeal* msgTarget)
	{
		if (msgTarget == buyer)
			seller->get_msg(msg);
		else if (msgTarget == seller)
			buyer->get_msg(msg);
	}
};

void egMediator();