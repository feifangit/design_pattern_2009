#include "stdafx.h"
#include "singleton.h"

class COnly //Ϊʲô���ܷŵ�ͷ�ļ�����,���
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
	//COnly a; //���ܵ��ù���
	cout << hex << COnly::get_instance() << endl;
	cout << hex << COnly::get_instance() << endl;
	cout << hex << COnly::get_instance() << endl;
}