#pragma once

//״̬ģʽ
//���� �ض�״̬��ص���Ϊ�ֲ���, ���ҽ���ͬ״̬����Ϊ�ָ��
//��һ���������Ϊȡ��������״̬,����������������ʱ�����״̬�ı�������Ϊʱ,�Ϳ��Կ���ʹ��״̬ģʽ

//��ְ��������
//����: ״̬ģʽ��״̬��дʱ ��֪���¼���
//�� ְ����ģʽ �ǵ����ߵ��õ�,ÿ�����ڵ㶼�����ε�,�����ڵ����ߵĴ�������������

struct IState;

struct CCaller
{
	IState* m_curState;
	CCaller(IState* init_state);
	void request(int x); //��������, ����state��switch״̬
};
//��״̬��ص���Ϊ
struct IState
{
	virtual void handle(CCaller* caller, int x) = 0;
};
struct CStateA : public IState
{
	void handle(CCaller* caller, int x);//���ֵ������"+"

};
struct CStateB : public IState
{
	void handle(CCaller* caller, int x); //���ֵ������ "-"
};





void egState();