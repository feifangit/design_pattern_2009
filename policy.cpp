#include "stdafx.h"
#include "policy.h"

void egPolicy()
{
	CDeliver a("add");
	cout << a.get_result(1, 5) << endl;

	CDeliver b("sub");
	cout << b.get_result(9, 6) << endl;

}