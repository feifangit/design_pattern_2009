#pragma once

//�۲���ģʽ (���еĹ۲��� ��ʵ�� ������)
//����һ�Զ��������ϵ ����۲��Ŷ���ͬʱ����ͬһ���ź�
//���źŷ�����ʱ��, ��֪ͨ���еĹ۲���


class CObserver;

class CSubject //֪ͨ��
{
protected:
	vector<CObserver*> reg_users; //ע�������Ҫ֪ͨ����
public:
	virtual void add_rec(CObserver* reg_user) //ע��Ҫ֪ͨ����
	{
		reg_users.push_back(reg_user);
	}
	virtual void del_rec(CObserver* reg_user) //ȥ��Ҫ֪ͨ����
	{
		//find reg_rec reg_user
		//reg_users remove
	}
	void notify(); //֪ͨ

	string msg; //֪ͨ����
};

class CObserver //�۲��� ,�ᱻ֪ͨ
{
protected:
	string m_name;
	CSubject* m_dependence;

public:
	CObserver(const string& self_name, CSubject* dependence)
	{
		m_name = self_name;
		m_dependence = dependence;
	}
	virtual void update()
	{
		cout << "[" << m_name.c_str() << "] : " << m_dependence->msg.c_str() << endl;
	}
};




void egObserver();