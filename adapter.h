#pragma once

class IAdapter //ÊÊÅäÆ÷½Ó¿Ú
{
public:
	virtual void add_content(char*) = 0;
};

class CStdStringAdapter : public IAdapter
{
	string& m_str;
public:
	CStdStringAdapter(string& str) : m_str(str)
	{
		//m_str = str;
	}
	void add_content(char* content)
	{
		m_str += content;
	}
};

class CStdFileAdapter : public IAdapter
{
	ofstream m_file;
public:
	CStdFileAdapter(string & filename)
	{
		m_file.open(filename.c_str());
	}
	~CStdFileAdapter()
	{
		m_file.close();
	}
	void add_content(char* content)
	{
		m_file.write(content, strlen(content));
	}

};

void egAdapter();