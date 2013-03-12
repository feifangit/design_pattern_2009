#pragma once


//��Ԫģʽ
//���ù����� ��Ч֧�� ���� С���� ����
// �÷�1 �����Ѿ��еĶ��� ,����ʵ�����ܶ����.  (����һ������)
	//Ϊ���ҵ�Ŀǰ�Ƿ��з����Լ������ʵ��  ʹ������(map)
// �÷�2 ����ͨ���ⲿ�����ķ�ʽ�����Ի�������� ,�Դﵽ�Լ���Ŀ�� (���� ��ͷ���� �ٸ�������)


struct IFlyWeight
{
	virtual void operation() = 0;
};
struct CSharedCompent : IFlyWeight //���Ա����õ�
{
	string m_name;
	CSharedCompent(const string& name)
	{
		m_name = name;
		cout << "create " << name.c_str() << endl;
	}
	void operation()
	{
		cout << "shared compent :" << m_name.c_str() << endl;
	}
};
// struct CUnsharedCompent : IFlyWeight //���ᱻ���õ�
// {
// 	void operation()
// 	{
// 		cout << "un-shared compent :"<<endl;
// 	}
// };
struct CFlyWeightFactory
{
	map<string, IFlyWeight*> m_compentsIndex;
	CFlyWeightFactory() //pre-work����
	{
		m_compentsIndex["button"] =  new CSharedCompent("button");
		m_compentsIndex["image"] =  new CSharedCompent("image");
		m_compentsIndex["text"] =  new CSharedCompent("text");
	}
	~CFlyWeightFactory()
	{
		map<string, IFlyWeight*>::iterator it ;
		for (it = m_compentsIndex.begin(); it != m_compentsIndex.end(); it++)
		{
			delete it->second;
			it->second = NULL;
		}
		m_compentsIndex.clear();
	}
	IFlyWeight* get_flyweight(const string& typeName)
	{
		map<string, IFlyWeight*>::iterator it = m_compentsIndex.find(typeName);
		if (it != m_compentsIndex.end())
		{
			return it->second;
		}
		else
		{
			IFlyWeight* pNewOne = new CSharedCompent(typeName);
			m_compentsIndex[typeName] = pNewOne;
			return pNewOne;
		}
	}

};


//�÷�2
class CInt
{
	int i;
public:
	CInt(int x) : i(x){}
	void set_value(int x)
	{
		i = x;
	}
	int get_value()
	{
		return i;
	}	
};
void egFlyWeight();