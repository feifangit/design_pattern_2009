#include "stdafx.h"
#include "simpleFactory.h"

void egSimpleFactory()
{
	COpFactory factory;
	COperation* op1 = factory.get_op("OP_ADD");

	op1->set_para1(10);
	op1->set_para2(7);
	cout << op1->get_result() << endl;

	COperation* op2 = factory.get_op("OP_SUB");
	op2->set_para1(10);
	op2->set_para2(7);
	cout << op2->get_result() << endl;

	delete op1;
	delete op2;
}
