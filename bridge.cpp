#include "stdafx.h"
#include "bridge.h"

void egBridge()
{
	IWorker* worker = new CGoodWorker(); //��߿�����bad worker

	IJob* job1 = new CWash(); //��߿�����������job
	worker->set_job(job1);
	worker->start_work();

	delete job1;job1 = NULL;
	delete worker; worker = NULL;

}