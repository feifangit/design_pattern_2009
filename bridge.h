#pragma once

//����ʹ�þۺ�,�����Ǽ̳�
//�ϳ�/�ۺϸ���ԭ��(CARP): ����ʹ�úϳ�/�ۺ�,������Ҫʹ����̳�

//worker ���Ա�, jobҲ���Ա�.
//job�����ø�worker

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
	void set_job(IJob* pJob) //��job������Ϊһ����Ա,��Ϊ worker has job, 
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