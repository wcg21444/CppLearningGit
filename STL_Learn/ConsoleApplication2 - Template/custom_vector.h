#pragma once

#include <iostream>
#include <concepts>

template<typename T>
class vector		// capacity variable arr of int
{
private:
	T* arr;
	int capacity;			
public:
	vector();

	~vector();
	//vector(vector& v);

	vector(int capacity);	//capacity is the number of data that the vector stores

	vector(std::initializer_list<T> list);


	T& operator[] (int i);	// overloadding []

	void extend(int ext_capacity);	//extend the vector by capacity filling with 0

	void append(T val);	//extend the vector in the end by 1 to add val(value) to the vector

	void push_out(int index);	//push out specified element of the vector by index

	void cut(int cut_capacity);

	inline T& end()		//return the end of vector
	{
		return arr[capacity - 1];
	}

	inline int get_capacity()
	{
		return capacity;
	}

	void clear();

public:
	template<typename T>
	class iterator
	{

	};

};

/// <summary>
/// ��ģ���Ա�����������嶼�ŵ�ͷ�ļ���
/// </summary>
/// <typeparam name="T"></typeparam>

template<typename T>
vector<T>::vector()
	:capacity(1)
{
	arr = new T[1];

}
template<typename T>
vector<T>::~vector()
{
	delete[] arr;

}
template<typename T>
vector<T>::vector(int capacity)
	:capacity(capacity)
{
	arr = new T[capacity];
	for (int i = 0; i < capacity; i++)
	{
		arr[i] = 0;
	}

}
template<typename T>
vector<T>::vector(std::initializer_list<T> list)
{

	arr = new T[list.size()];
	capacity = list.size();

	int i = 0;
	for (auto adress = list.begin(); adress != list.end(); adress++)
	{
		if (i < list.size())
		{
			arr[i] = *adress;
			i++;
		}
		else
		{
			break;
		}
	}
}
template<typename T>
T& vector<T>::operator[](int i)
{
	if (i < capacity)
	{
		return *(arr + i);	//arr []  �����[] ���ᱻ����
	}

	else
	{
		printf("out of range");
		return *(arr);;
	}
}
template<typename T>
void vector<T>::extend(int ext_capacity)
{
	//��������

	T* arr_tmp = new T[vector<T>::capacity + ext_capacity];

	for (int i = 0; i < vector<T>::capacity + ext_capacity; i++)
	{
		if (i < vector<T>::capacity)
		{
			arr_tmp[i] = arr[i];
		}
		else
		{
			arr_tmp[i] = 0;
		}
	}

	delete[] arr;

	arr = arr_tmp;

	vector<T>::capacity += ext_capacity;
}
template<typename T>
void vector<T>::append(T val)
{
	extend(1);
	arr[capacity - 1] = val;
}
template<typename T>
void vector<T>::push_out(int index)
{
	//�ȼ�����
	capacity--;

	T* arr_tmp = new T[capacity];

	for (int i = 0, j = 0; i < capacity; i++, j++)
	{
		if (i == index)
		{
			j++;
		}

		arr_tmp[i] = arr[j];

	}

	delete[] arr;

	arr = arr_tmp;



}
template<typename T>
void vector<T>::cut(int cut_capacity)		//�ж�һ������
{
	if(cut_capacity<capacity)
	{
		T* tmp_arr = new T[capacity - cut_capacity];

		for (int i = 0; i < capacity - cut_capacity; i++)
		{
			tmp_arr[i] = arr[i];
		}
		delete[] arr;

		arr = tmp_arr;

		capacity -= cut_capacity;
	}
	else if (cut_capacity >= capacity)		//cut >= ԭ����, vector ��Ϊnullptr
	{
		delete[] arr;
		arr = nullptr;
		capacity = 0;
	}
}
template<typename T>
void vector<T>::clear()
{
	for (int i = 0; i < capacity; ++i)
	{
		arr[i] = 0;

	}
}
