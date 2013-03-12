#pragma once

//װ��ģʽDecorator
//��̬�ĸ�һ����������һЩ�����ְ��, ������������ӵ����
//��ʵ�ǽ�����Ҫ�Ĺ��ܰ�����ȷ��˳�����������п���

struct IDsp //û�й�� ���ɷ�Բ
{
	virtual void show_power() = 0; //��ʾս����
};

struct CHuman : public IDsp //ԭ�е���,��Ҫ����������Ӷ����ְ��(����װ��)
{
	void show_power()
	{
		cout << "����,ս����0" << endl;		
	}
};

struct IWare : public IDsp //����װ��
{
	IDsp* m_org_lvl; //ԭ�е�װ��
	void ware_something_on(IDsp* org_lvl) //����ԭ�е�װ������
	{
		m_org_lvl = org_lvl;
	}
	virtual void show_power()
	{
		if (m_org_lvl != NULL)
			m_org_lvl->show_power();
	}
};

struct CHujia : public IWare
{
	virtual void show_power()
	{
		m_org_lvl->show_power(); //��ʾ����֮ǰ������
		cout << "ս���� +10" << endl;
	}
};
struct CWeapon : public IWare
{
	void try_weapon()
	{
		cout << "��ǹ" << endl;
	}
	virtual void show_power()
	{
		m_org_lvl->show_power();
		cout << "ս���� + 40" << endl;
	}
};


void egDecorator();