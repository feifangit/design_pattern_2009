#include "stdafx.h"
#include "decorator.h"

void egDecorator()
{
	CHuman feifan; //人
	CHujia shenjia; //护甲
	CWeapon ak47; //武器

	shenjia.ware_something_on(&feifan); //将护甲穿在feifan身上
	ak47.ware_something_on(&shenjia); //将武器继续穿在护甲外面

	ak47.show_power(); //最外层的展示

}