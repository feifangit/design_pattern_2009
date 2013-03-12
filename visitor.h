#pragma once

//������ģʽ

//��ʾһ�������� ĳ������ṹ�еĸ�Ԫ�� �Ĳ���.
//������  ���ı��Ԫ�ص���  ��ǰ����  ������������ЩԪ�ص��²���
//������Ԫ�������ȶ���ϵͳ

//�ص�: ������Ľ������Ҫ��Ԫ������ֱ��ṩ�ӿ� -> ����Ҫ��Ԫ�ص������ȶ�

//�����õ���˫���ɵļ���
//Ԫ�� ����εõ� ��������
//Ȼ���Լ�(this)������������ ,���������ܲ�����Ԫ��


struct CMan;
struct CWoman;

//���˺�Ů�����ȶ��ķ���
struct IAction
{
	virtual void getManAction(CMan* man) = 0; //����man���� ʵ�ֶ���
	virtual void getWomanAction(CWoman* woman) = 0;
};

//Ԫ��: �ȶ��ķ��� 
struct IHuman
{
	string x;
	virtual void do_things(IAction* action) = 0;
};
struct CMan : public IHuman
{
	CMan()  {x = "xiaodidi";}
	void do_things(IAction* action) //�� ĳ������ 
	{
		action->getManAction(this);
	}
};
struct CWoman : public IHuman
{
	CWoman()  {x = "????";}
	void do_things(IAction* action)
	{
		action->getWomanAction(this);
	}
};

//�������Ķ��� (���Ԫ�����ٶ�Ķ���������)
struct CXuxu : public IAction
{
	void getManAction(CMan* man)
	{
		cout << "man use " << man->x.c_str() << " to xuxu" << endl;
	}
	void getWomanAction(CWoman* woman)
	{
		cout << "woman use " << woman->x.c_str() << " to xuxu" << endl;
	}
};
struct CAngry : public IAction
{
	void getManAction(CMan* man)
	{
		cout << "fight!~ 3 2 1" << endl;
	}
	void getWomanAction(CWoman* woman)
	{
		cout << "keep slience" << endl;
	}
};

void egVisitor();