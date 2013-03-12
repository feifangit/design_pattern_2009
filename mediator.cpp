#include "stdafx.h"
#include "mediator.h"

void egMediator()
{
	C5i5j a;
	HouseBuyer feifan(&a);
	HouseSeller guyongmei(&a);
	a.buyer = &feifan;
	a.seller = &guyongmei;

	guyongmei.put_msg("首付给我45w");
	feifan.put_msg("钱已经打到你账上了");

}