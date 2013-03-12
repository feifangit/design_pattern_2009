#include "stdafx.h"
#include "adapter.h"


void egAdapter()
{
	string str = "12";
	IAdapter* adp1 = new CStdStringAdapter(str);
	adp1->add_content("abcde");
	cout << str.c_str() << endl;
	delete adp1;
	adp1 = NULL;

	IAdapter* adp2 = new CStdFileAdapter(string("c:\\adp.txt"));
	adp2->add_content("abcde");
	delete adp2;
	adp2 = NULL;

}