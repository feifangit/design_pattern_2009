#include "stdafx.h"
#include "prototype.h"



void egPrototype()
{
	CHomework goodstudent;
	goodstudent.set_name("feifan");
	goodstudent.do_homework();
	goodstudent.answer();

	//sunpu���ҵ���ҵ,���Ұ�ѡ�����һ���Ĵ𰸸ĳ���D
	CHomework* pBadStudent = (CHomework*)goodstudent.clone();
	pBadStudent->set_name("sunpu");
	pBadStudent->m_choice[0] = 'D';
	pBadStudent->answer();

}