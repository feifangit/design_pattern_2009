#pragma once

//状态模式
//将与 特定状态相关的行为局部化, 并且将不同状态的行为分割开来
//当一个对象的行为取决于它的状态,并且它必须在运行时候根绝状态改变它的行为时,就可以考虑使用状态模式

//和职责链很像
//区别: 状态模式在状态编写时 就知道下家了
//而 职责链模式 是调用者调用的,每个链节点都是自治的,可以在调用者的代码中任意的组合

struct IState;

struct CCaller
{
	IState* m_curState;
	CCaller(IState* init_state);
	void request(int x); //发出请求, 进入state的switch状态
};
//和状态相关的行为
struct IState
{
	virtual void handle(CCaller* caller, int x) = 0;
};
struct CStateA : public IState
{
	void handle(CCaller* caller, int x);//表现的是输出"+"

};
struct CStateB : public IState
{
	void handle(CCaller* caller, int x); //表现的是输出 "-"
};





void egState();