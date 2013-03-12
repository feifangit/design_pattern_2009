#include "stdafx.h"
#include "observer.h"

void CSubject::notify()
{
	for (int i = 0; i < reg_users.size(); i++)
	{
		reg_users[i]->update(); //���֪ͨ���Լ�����ע�����
	}
}

void egObserver()
{
	CSubject dog;

	CObserver a("user_1",&dog);//���ù������ҿ���
	CObserver b("user_2", &dog);

	dog.add_rec(&a); //����ͬ����
	dog.add_rec(&b);

	dog.msg = "there's bad guy!~";
	dog.notify();

}