#include "stdafx.h"
#include "builder.h"


void egBuilder()
{
	cout << "����װ��" << endl;
	fitmentBuilder* expSolution = new CExpensiveFitment;
	CFeiFan me1(expSolution);
	me1.fitment();
	delete expSolution;
	expSolution = NULL;


	cout << "��װ��" << endl;
	fitmentBuilder* chpSolution = new CCheapFitment;
	CFeiFan me2(chpSolution);
	me2.fitment();
	delete chpSolution;
	chpSolution = NULL;
}