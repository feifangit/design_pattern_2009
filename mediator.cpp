#include "stdafx.h"
#include "mediator.h"

void egMediator()
{
	C5i5j a;
	HouseBuyer feifan(&a);
	HouseSeller guyongmei(&a);
	a.buyer = &feifan;
	a.seller = &guyongmei;

	guyongmei.put_msg("�׸�����45w");
	feifan.put_msg("Ǯ�Ѿ�����������");

}