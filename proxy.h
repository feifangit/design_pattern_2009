#pragma once

//代理模式

struct ICommonActoin
{
	virtual void connect() = 0;
	virtual void send(const string & data) = 0;
};

struct CUser : public ICommonActoin
{
	string m_targetname;
	void connect()
	{
		cout << "user request connect to " << m_targetname.c_str() << endl;
	}
	void send(const string& data)
	{
		cout << "user send data" << "\t" << data.c_str() <<endl;
	}
};

struct CProxy : public ICommonActoin //在代理处可以做一些限制
{
private:
	int m_connectCount;
	CUser m_user;
public:
	CProxy(const string& targetname) : m_connectCount(0) 
	{
		m_user.m_targetname = targetname;
		cout << "[PROXY]connection to " << targetname.c_str() << "start." << endl;
	}
	void connect()
	{
		if (m_connectCount >= 2)
			cout << "[PROXY]too many user connected. refuse your request" << endl;
		else
		{
			m_user.connect();
			cout << "[PROXY]connecting" << endl;		
			m_connectCount++;
		}
	}
	void send(const string& data)
	{
		string verified_data = data;
		verified_data += "(NO VIRUS! checked by proxy.)";
		m_user.send(verified_data);
	}

};

void egProxy();