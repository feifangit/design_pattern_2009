#include "stdafx.h"
#include "factory.h"

void egFactory()
{
	IOpFactory* opFactory = new CAddFactory(); // ***
	IOperation* op1 = opFactory->create_op();
	op1->set_para1(10);
	op1->set_para2(8);
	cout << op1->get_result() << endl;

	opFactory = new CSubFactory(); // 创建的工厂不一样
	IOperation* op2 = opFactory->create_op();
	op2->set_para1(10);
	op2->set_para2(8);
	cout << op2->get_result() << endl;


}