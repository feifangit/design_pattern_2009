#include "stdafx.h"
#include "flyweight.h"

void egFlyWeight()
{
	CFlyWeightFactory fac;
	cout << fac.m_compentsIndex.size() << endl;
	cout << "our work begin" << endl;

	fac.get_flyweight("button");//已经有的
	
	fac.get_flyweight("progressbar"); //没有的
	fac.get_flyweight("progressbar"); //现在有了
	fac.get_flyweight("image");
	cout << fac.m_compentsIndex.size() << endl;


	cout << "usage 2" << endl;
	CInt n(10);
	cout << n.get_value() << endl;
	n.set_value(8); //省去了产生对象的过程
	cout << n.get_value() << endl;
	

}