#pragma once

//提供一种方法顺序访问一个聚合对象中各个元素,但是又不暴露内部标示
//其实 用什么用的接口和判断来实现一个循环都不重要
//重要的是 多个存储容器用的迭代借口要统一.


//
template <typename T>
class IIterator
{
public:
	int m_curIndex;
	void from_begin()
	{
			m_curIndex = 0;
	}
	virtual T next() = 0;
	virtual bool isDone() = 0;
};


template<int array_size>
class CRArray : public IIterator<int> //可被迭代
{
private:
	int m_array[array_size];
public:
	CRArray()
	{
		::ZeroMemory(m_array, array_size* sizeof(int));
	}

	int next()
	{
		return m_array[m_curIndex++];
	}
	bool isDone()
	{
		if (m_curIndex < (array_size - 1))
			return false;
		return true;
	}
};


void egIterator();