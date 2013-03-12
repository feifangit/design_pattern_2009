#pragma once

//组合模式
//倒树状的标示 部分-整体 关系
//使得对 单个对象 和 组合对象 的使用 具有统一性


struct INode
{
protected:
	string m_nodeName;
public:
	virtual void add(INode* child) = 0;
	virtual void display() = 0;

};

struct CFile : public INode
{
	CFile(const string& name)
	{
		m_nodeName = name;

	}
	void add(INode* child)
	{
		cout << "error operation" << endl; //can not put  file/folder under a file object
	}
	void display()
	{
		cout << "[file] " <<m_nodeName.c_str() << endl;
	}


};

struct CFolder : public INode
{
private:
	vector<INode*> m_children;
public:
	CFolder(const string& name)
	{
		m_nodeName = name;
		m_nodeName += "/";
	}
	void add(INode* child)
	{
		m_children.push_back(child);
	}
	void display()
	{
		cout << "[folder] " << m_nodeName.c_str() << endl;
		for (size_t i = 0; i < m_children.size(); i++)
		{
			m_children[i]->display();
		}
	}
};

void egComposite();