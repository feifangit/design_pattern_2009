#include "stdafx.h"
#include "prototype.h"



void egPrototype()
{
	CHomework goodstudent;
	goodstudent.set_name("feifan");
	goodstudent.do_homework();
	goodstudent.answer();

	//sunpu抄我的作业,并且把选择题第一个的答案改成了D
	CHomework* pBadStudent = (CHomework*)goodstudent.clone();
	pBadStudent->set_name("sunpu");
	pBadStudent->m_choice[0] = 'D';
	pBadStudent->answer();

}