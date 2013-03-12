#include "stdafx.h"
#include "observer.h"

void CSubject::notify()
{
	for (int i = 0; i < reg_users.size(); i++)
	{
		reg_users[i]->update(); //逐个通知在自己这里注册的人
	}
}

void egObserver()
{
	CSubject dog;

	CObserver a("user_1",&dog);//想让狗狗帮我看门
	CObserver b("user_2", &dog);

	dog.add_rec(&a); //狗狗同意了
	dog.add_rec(&b);

	dog.msg = "there's bad guy!~";
	dog.notify();

}