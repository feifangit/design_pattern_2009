#include "stdafx.h"
#include "command.h"

void egCommand()
{
	CWorker worker;  //������������ɸ�worker,�����ܸɵ����黹��һ��, cmd�ͷֱ����õ���ͬ����ͷ��
	CmdCleanHouse a(&worker);
	CmdCleanHouse b(&worker);
	CmdWashCar c(&worker);

	CCaller boss;
	boss.set_cmd(&a);
	boss.set_cmd(&b);
	boss.set_cmd(&c);

	boss.request();


}