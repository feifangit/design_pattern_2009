#include "stdafx.h"
#include "abstractFactory.h"

void egAbstractFactory()
{
	IOpFactory* pCalcFac = new CAddFactory();
	//IOpFactory* pCalcFac = new CSubFactory(); //���Ժ���һ����ʱ�л�
	IOperationInt* pOpInt = pCalcFac->create_op_int();
	pOpInt->set_para1(10);
	pOpInt->set_para2(3);
	cout << pOpInt->get_result() << endl;


}