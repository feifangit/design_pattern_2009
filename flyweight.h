#pragma once


//享元模式
//运用共享技术 有效支持 大量 小颗粒 对象
// 用法1 返回已经有的对象 ,避免实例化很多对象.  (公用一个对象)
	//为了找到目前是否有符合自己需求的实例  使用索引(map)
// 用法2 可以通过外部参数的方式来个性化这个对象 ,以达到自己的目的 (用完 改头换面 再给别人用)


struct IFlyWeight
{
	virtual void operation() = 0;
};
struct CSharedCompent : IFlyWeight //可以被公用的
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
// struct CUnsharedCompent : IFlyWeight //不会被公用的
// {
// 	void operation()
// 	{
// 		cout << "un-shared compent :"<<endl;
// 	}
// };
struct CFlyWeightFactory
{
	map<string, IFlyWeight*> m_compentsIndex;
	CFlyWeightFactory() //pre-work机制
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


//用法2
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