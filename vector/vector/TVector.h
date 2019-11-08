#pragma once

#include "pch.h"
#include <iostream>

template<class T>
class TVector
{
public:
	// constructor
	TVector();
	TVector(const TVector&);
	// destructor
	~TVector();

	// functions
	T& at(int pos);
	void push_back(int value);
	void pop_back();
	int size();
	void resize(int size);
	void clear();

private:
	// variables
	// pointer to dynamic array
	T* m_data;
	// size of vector
	int m_capacity;
	// amount of stored ellements
	int m_stored;
};


// constructor
template<class T>
TVector<T>::TVector()
	: m_data(nullptr)
	, m_capacity(0)
{
}

// copy constructor
template<class T>
TVector<T>::TVector(const TVector& x)
{
	m_capacity = x.m_capacity;
	m_stored = x.m_stored;
	if (m_stored > 0)
	{
		m_data = new T[m_stored];
		if (m_capacity > 0) std::copy(x.m_data, x.m_data + x.count, m_data);
	}
	else m_data = nullptr;
}

// destructor
template<class T>
TVector<T>::~TVector()
{
}

template<class T>
void TVector<T>::push_back(int value)
{
	// temporary array for new element
	T* tmp = new T[++m_capacity];

	if (m_capacity == 1)
	{
		tmp[0] = value;
	}
	else
	{
		// overwrite old values to new array
		std::copy(m_data, m_data + m_capacity-1, tmp);

		// write new value to its position
		tmp[m_capacity - 1] = value;
	}

	// ellocate m_data the value of tmp
	m_data = tmp;
}

template<class T>
T& TVector<T>::at(int pos)
{
	//std::unique_ptr<T&> uniquedata(new T(m_data[pos]));
	// error if invalid position
	/*
	if (pos < 0 || pos > m_capacity - 1)
	{
		return ;
	}
	*/

	//else
	//{
		// reference to searched position
		//T& ref_m_data = m_data[pos];
		return uniquedata;
	//}

	// return the positions value
	//return m_data[pos];
	//return std::unique_ptr<T> uniquedata(m_data[pos]);
}

template<class T>
void TVector<T>::pop_back()
{
	// temporary array to delete the last element
	T* tmp = new T[--m_capacity];

	std::copy(m_data, m_data + m_capacity, tmp);

	// ellocate m_data the value of tmp
	m_data = tmp;
}

template<class T>
int TVector<T>::size()
{
	return m_capacity;
}

template<class T>
void TVector<T>::resize(int size)
{
	if (size != m_capacity)
	{
		// temporary array
		T* tmp = new T[size];

		for (int i = 0; i < size; ++i)
		{
			if (m_capacity < i)
			{
				tmp[i] = 0;
			}
			else
			{
				tmp[i] = m_data[i];
			}
		}

		m_capacity = size;

		// ellocate m_data the value of tmp
		m_data = tmp;
	}
	else
	{
		// error message
		std::cerr << "Size allready used!" << std::endl;
	}
}

template<class T>
void TVector<T>::clear()
{
	delete[] m_data; // auf nullptr pruefen
	m_capacity = 0;
}