#include "stdafx.h"
#include "singleton.h"

class COnly //为什么不能放到头文件里面,奇怪
{
protected:
	COnly(){}
	virtual ~COnly(){}
	static COnly* pInstance;
public:
	static COnly* get_instance();

};

COnly* COnly::pInstance = NULL;

COnly* COnly::get_instance()
{
	if (pInstance == NULL)
		pInstance = new COnly();
	return pInstance;
}


void egSingleton()
{
	//COnly a; //不能调用构造
	cout << hex << COnly::get_instance() << endl;
	cout << hex << COnly::get_instance() << endl;
	cout << hex << COnly::get_instance() << endl;
}