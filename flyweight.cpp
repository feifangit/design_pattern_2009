#include "stdafx.h"
#include "flyweight.h"

void egFlyWeight()
{
	CFlyWeightFactory fac;
	cout << fac.m_compentsIndex.size() << endl;
	cout << "our work begin" << endl;

	fac.get_flyweight("button");//�Ѿ��е�
	
	fac.get_flyweight("progressbar"); //û�е�
	fac.get_flyweight("progressbar"); //��������
	fac.get_flyweight("image");
	cout << fac.m_compentsIndex.size() << endl;


	cout << "usage 2" << endl;
	CInt n(10);
	cout << n.get_value() << endl;
	n.set_value(8); //ʡȥ�˲�������Ĺ���
	cout << n.get_value() << endl;
	

}