#pragma once

//���ģʽ
//���ڽ���ϵͳ(������)�Ķ�����ܳ����ϲ�ʹ��
//��ħ������Ϊ��
//һ�����򷨷���  �� �����򷨿���

//**����û���ͷŵ��ڴ�, ֻ��һ������


struct CFarmer
{
	void create_house()
	{
		cout << "���췿��" << endl;
	}
	void create_barracks()
	{
		cout << "�����Ӫ" << endl;
	}
	void create_timberjack()
	{
		cout << "���췥ľ��" << endl;
	}
};

struct CBase
{
	CFarmer* create_farmer()
	{
		cout << "����ũ��" << endl;
		return new CFarmer;
	}
};


struct CNormalFight
{
	void start()
	{
		CBase humanBase;
		CFarmer* farmer1 = humanBase.create_farmer();
		farmer1->create_house();

		CFarmer* farmer2 = humanBase.create_farmer();
		farmer2->create_barracks();
	}
};

struct CRushFight
{
	void start()
	{
		CBase humanBase;
		CFarmer* farmer1 = humanBase.create_farmer();
		farmer1->create_house();

		CFarmer* farmer2 = humanBase.create_farmer();
		farmer2->create_timberjack();
	}
};

void egFacade();
