#include "stdafx.h"
#include "abstractFactory.h"

void egAbstractFactory()
{
	IOpFactory* pCalcFac = new CAddFactory();
	//IOpFactory* pCalcFac = new CSubFactory(); //可以和上一句随时切换
	IOperationInt* pOpInt = pCalcFac->create_op_int();
	pOpInt->set_para1(10);
	pOpInt->set_para2(3);
	cout << pOpInt->get_result() << endl;


}