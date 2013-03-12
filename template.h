#pragma once

class CS60Phone
{
public:
	virtual bool check_model(const string& at_response) = 0; //所有的手机这一步都不一样
	string send_recv_data(const string& data)
	{
		cout << "... send ... recv ... " << endl;
		return "UNKNOW";
	}
	virtual void sync()
	{
		string model = send_recv_data("AT+GMM");
		if (true == check_model(model))
		{
			cout << "start sync" << endl;
			cout << "end sync" << endl;
		}
		else
			cout << "model not matched" << endl;
	}
};

class CN95Phone : public CS60Phone
{
	virtual bool check_model(const  string& at_respone)
	{
		cout << "checking phone ? n95" << endl;
		if (at_respone  == "NOKIA N95")
			return true;
		return false;
	}
};

class CE65Phone : public CS60Phone
{
	virtual bool check_model(const  string& at_respone)
	{
		cout << "checking phone ? E65" << endl;
		if (at_respone  == "NOKIA E65")
			return true;
		return false;
	}
};

void egTemplte();