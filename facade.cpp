#include "stdafx.h"
#include "facade.h"


void egFacade()
{
	cout << "正常打法" << endl;
	CNormalFight fight1;
	fight1.start();

	cout << "一波流打法" << endl;
	CRushFight fight2;
	fight2.start();

}