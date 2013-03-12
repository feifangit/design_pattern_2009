#include "stdafx.h"
#include "bridge.h"

void egBridge()
{
	IWorker* worker = new CGoodWorker(); //这边可以是bad worker

	IJob* job1 = new CWash(); //这边可以是其他的job
	worker->set_job(job1);
	worker->start_work();

	delete job1;job1 = NULL;
	delete worker; worker = NULL;

}