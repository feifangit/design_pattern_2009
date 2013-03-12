#include "stdafx.h"
#include "command.h"

void egCommand()
{
	CWorker worker;  //这里可以有若干个worker,他们能干的事情还不一样, cmd就分别设置到不同的人头上
	CmdCleanHouse a(&worker);
	CmdCleanHouse b(&worker);
	CmdWashCar c(&worker);

	CCaller boss;
	boss.set_cmd(&a);
	boss.set_cmd(&b);
	boss.set_cmd(&c);

	boss.request();


}