#pragma once

//尽量使用聚合,而不是继承
//合成/聚合复用原则(CARP): 尽量使用合成/聚合,尽量不要使用类继承

//worker 可以变, job也可以变.
//job被设置给worker

struct IJob
{
	virtual void work() = 0;
};
struct CWash : public IJob
{
	void work()
	{
		cout << "wash" << endl;
	}
};
struct CClean : public IJob
{
	void work()
	{
		cout << "clean" << endl;
	}
};


class IWorker
{
protected:
	IJob* m_pJob;
public:
	void set_job(IJob* pJob) //将job仅仅作为一个成员,因为 worker has job, 
	{
		m_pJob = pJob;
	}
	virtual void start_work() = 0;
};

class CGoodWorker : public IWorker
{
public:
	void start_work()
	{
		m_pJob->work();
	}
};
class CBadWorker : public IWorker
{
public:
	void start_work()
	{
		::Sleep(10000);
		m_pJob->work();
	}
};

void egBridge();