#pragma once

//命令模式
//把请求一个操作的对象 和 知道如何执行一个操作的对象分隔开
//把请求封装成一个对象,使你可以用不同的请求对客户进行参数化, 对请求排队或者记录请求日志, 以及支持可撤销的操作
//分离 行为请求者 和 行为实现者
//可以容易的设计一个命令队列
//


//行为实现者
struct CWorker
{
	void clean_house()
	{
		cout << "clean house" << endl;
	}
	void wash_car()
	{
		cout << "wash car" << endl;
	}
};

//命令(mid levl)
struct ICmd
{
protected:
	CWorker* m_worker;
public:
	ICmd(CWorker* worker)
	{
		m_worker = worker;
	}
	virtual bool execute() = 0;
};

//具体的命令
struct CmdCleanHouse : public ICmd
{
	CmdCleanHouse(CWorker* worker) : ICmd(worker) {}
	bool execute()
	{
		m_worker->clean_house();
		return true;
	}
};
struct CmdWashCar : public ICmd
{
	CmdWashCar(CWorker* worker) : ICmd(worker) {}
	bool execute()
	{
		m_worker->wash_car();
		return true;
	}
};

//请求者
//请求者只和命令打交道,不和worker打交道
class CCaller
{
	vector<ICmd*> cmdList;
public:
	void set_cmd(ICmd* cmd)
	{
		cmdList.push_back(cmd);
	}
	void cancel_cmd(ICmd* cmd)
	{
		//...
	}
	void request()
	{
		for (size_t i = 0; i < cmdList.size(); i++)
		{
			if (true == cmdList[i]->execute())
			{
				//cmdList.del(xxxxcmd);
			}			
		}
	}
};

void egCommand();