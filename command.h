#pragma once

//����ģʽ
//������һ�������Ķ��� �� ֪�����ִ��һ�������Ķ���ָ���
//�������װ��һ������,ʹ������ò�ͬ������Կͻ����в�����, �������Ŷӻ��߼�¼������־, �Լ�֧�ֿɳ����Ĳ���
//���� ��Ϊ������ �� ��Ϊʵ����
//�������׵����һ���������
//


//��Ϊʵ����
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

//����(mid levl)
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

//���������
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

//������
//������ֻ������򽻵�,����worker�򽻵�
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