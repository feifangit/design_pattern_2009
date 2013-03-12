#pragma once

//�ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ��,�����ֲ���¶�ڲ���ʾ
//��ʵ ��ʲô�õĽӿں��ж���ʵ��һ��ѭ��������Ҫ
//��Ҫ���� ����洢�����õĵ������Ҫͳһ.


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
class CRArray : public IIterator<int> //�ɱ�����
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