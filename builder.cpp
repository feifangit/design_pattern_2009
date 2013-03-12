#include "stdafx.h"
#include "builder.h"


void egBuilder()
{
	cout << "豪华装修" << endl;
	fitmentBuilder* expSolution = new CExpensiveFitment;
	CFeiFan me1(expSolution);
	me1.fitment();
	delete expSolution;
	expSolution = NULL;


	cout << "简单装修" << endl;
	fitmentBuilder* chpSolution = new CCheapFitment;
	CFeiFan me2(chpSolution);
	me2.fitment();
	delete chpSolution;
	chpSolution = NULL;
}