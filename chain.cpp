#include "stdafx.h"
#include "chain.h"

void egChain()
{
	C1_100ProcUnit a;
	C100_1000ProcUnit b;
	a.set_next_handle(&b); //1_100优先处理

	a.handle(10);
	a.handle(999);
	a.handle(-1);

}