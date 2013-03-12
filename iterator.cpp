#include "stdafx.h"
#include "iterator.h"


void egIterator()
{
	CRArray<20> myArray;
	myArray.from_begin();
	while(!myArray.isDone() )
	{
		cout << myArray.next() << endl;
	};
}