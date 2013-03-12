#include "stdafx.h"
#include "visitor.h"

void egVisitor()
{
	CMan feifan;
	CWoman girl;
	cout << "when man in restroom" << endl;
	feifan.do_things(new CXuxu());
	cout << "when woman in restroom" << endl;
	girl.do_things(new CXuxu());

	cout << "when man get angry" << endl;
	feifan.do_things(new CAngry());
	cout << "when woman get angry" << endl;
	girl.do_things(new CAngry());

}