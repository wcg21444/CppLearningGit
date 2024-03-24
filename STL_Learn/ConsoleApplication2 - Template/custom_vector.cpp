/*
#include "custom_vector.h"




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
	for (int i = 0 ; i<capacity;i++)
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
	for (auto adress = list.begin();adress != list.end();adress++)
	{
		if(i<list.size())
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
	if(i<capacity)
	{
		return *(arr + i);	//arr []  这里的[] 不会被重载
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
//先填再增

	T* arr_tmp = new T[vector<T>::capacity + ext_capacity];	

	for (int i = 0; i < vector<T>::capacity + ext_capacity; i++)
	{
		if(i < vector<T>::capacity)
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
//先减再填
	capacity--;		

	int* arr_tmp = new T[capacity];

	for (int i = 0,j = 0; i < capacity; i++,j++)
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
void vector<T>::clear()
{
	for (int i = 0; i < capacity; ++i)
	{
		arr[i] = 0;

	}
}
*/