#include "stdafx.h"
#include "composite.h"

void egComposite()
{
	INode* folder1 = new CFolder("lv1 folder0");
	INode* file1 = new CFile("lv2 file1");
	INode* file2 = new CFile("lv2 file2");
	INode* folder2 = new CFolder("lv2 folder1");
	INode* file3 = new CFile("lv3 file1");

	folder1->add(file1);
	folder1->add(file2);
	folder1->add(folder2);
	folder2->add(file3);

	cout  <<  "look down from folder 0:" << endl ;
	folder1->display();

	cout  << endl<< "look down from folder 1" << endl;
	folder2->display();

	cout  << endl<< "look down form file 2" << endl;
	file2->display();

	delete folder1; folder1 = NULL;
	delete folder2; folder2 = NULL;
	delete file1; file1 = NULL;
	delete file2; file2 = NULL;
	delete file3; file3 = NULL;
}