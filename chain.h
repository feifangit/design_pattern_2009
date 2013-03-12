#pragma once

//职责链模式

//所有的处理方法共享统一处理接口 和 设置下一环的借口
//, 由调用者来串联它们.
//如果职责链的第一个单元不处理, 则下传给下一个单元.直到有人处理
//需要注意最后一环的处理,也就是之前设置的处理单元都没有处理时,最后是放弃操作,还是提示什么
//职责链中的处理单元的顺序代表了处理的优先权

struct IProcUnit
{
protected:
	IProcUnit* m_next_handler;
public :
	IProcUnit(): m_next_handler(NULL){}
	virtual bool try_handle(int i) = 0; //返回false意为该单元不处理
	void  handle(int i)
	{
		if (false == try_handle(i)) //需要下一单元处理
		{
			if (m_next_handler) //如果没有下一环就啥都不干
				m_next_handler->handle(i);
			else
				cout << "fail in handle:" << i << endl;
		}
	}
	void set_next_handle(IProcUnit* procUnit)
	{
		m_next_handler = procUnit;
	}
};

struct C1_100ProcUnit : public IProcUnit
{
	bool try_handle(int i)
	{
		if (i < 100 && i > 0)
		{
			cout << "1-100" << endl;
			return true;
		}
		else
			return false;
	}
};

struct C100_1000ProcUnit : public IProcUnit
{
	bool try_handle(int i)
	{
		if (i >= 100 && i < 1000)
		{
			cout << "100-1000" << endl;
			return true;
		}
		else
			return false;
	}
};

void egChain();
