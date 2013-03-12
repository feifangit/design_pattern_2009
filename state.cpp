#include "stdafx.h"
#include "state.h"


//---------------------------------------------
CCaller::CCaller(IState* init_state)
{
	m_curState = init_state;
}
void CCaller::request(int x)
{
	m_curState->handle(this, x);
}

void CStateA::handle(CCaller* caller, int x)
{
	cout << "state A" << "\t+" << x <<endl;
	caller->m_curState = new CStateB(); //状态改变了, 其行为也会改变
}
void CStateB::handle(CCaller* caller, int x)
{
	cout << "state B" << "\t-" <<  x << endl;
	caller->m_curState = new CStateA();
}

void egState()
{
	CStateA init_state;
	CCaller caller(&init_state);
	caller.request(99);
	caller.request(88);

}