#pragma once

//ԭ��ģʽ
//��һ�������ٴ�������һ���ɶ��ƵĶ���,���Ҳ���Ҫ֪���κδ�����ϸ��.
//�ؼ�����Clone()����

struct ICloneable //
{
	virtual ICloneable* clone() = 0;
};

//����ʵ����һ������ҵ�Ĺ���,ԭ����CHomework
//����Ϊ�˲�����ʦ�����Լ��ǳ�Ϯ����ҵ,������Ҫ�������м����� :)

struct CHomework : public ICloneable
{
	vector<char> m_choice;
	char* m_student_name;
	CHomework() : m_student_name(NULL) {}
	void set_name(char* name)
	{
		if (m_student_name != NULL)
		{
			delete[] m_student_name;
			m_student_name = NULL;
		}
		if (name != NULL)
		{
			m_student_name = new char[strlen(name) + 1];
			::memset(m_student_name, 0, strlen(name) + 1);
			strcpy(m_student_name, name);
		}
	}
	void do_homework()
	{
		m_choice.push_back('C');
		m_choice.push_back('A');
		m_choice.push_back('D');
	}
	~CHomework()
	{
		if (m_student_name != NULL)
		{
			delete[] m_student_name;
			m_student_name = NULL;
		}
	}
	void answer()
	{
		if (m_student_name != NULL)
			cout << m_student_name << endl;
		else
			cout << "noname" << endl;
		for (int i = 0; i < m_choice.size(); i++)
			cout << m_choice[i] << endl;
	}	
	ICloneable* clone()
	{
		CHomework* other = new CHomework();
		other->m_choice = m_choice;
		if (m_student_name != NULL)
		{
			other->m_student_name = new char [strlen(m_student_name) + 1]; //ע�����������
			::memset(other->m_student_name, 0, strlen(m_student_name) + 1);
			strcpy(other->m_student_name, m_student_name);
		}
		return (ICloneable*)other;
	}

};


void egPrototype();