#include "stdafx.h"
#include "decorator.h"

void egDecorator()
{
	CHuman feifan; //��
	CHujia shenjia; //����
	CWeapon ak47; //����

	shenjia.ware_something_on(&feifan); //�����״���feifan����
	ak47.ware_something_on(&shenjia); //�������������ڻ�������

	ak47.show_power(); //������չʾ

}