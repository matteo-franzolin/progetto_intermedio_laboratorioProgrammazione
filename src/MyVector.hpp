#ifndef MYVECTOR_HPP
#define MYVECTOR_HPP
#include "../include/MyVector.h"

//costruttori
template<typename T>
MyVector<T>::MyVector(int sz)
	:buffer_size{(sz < INITIAL_SIZE) ? INITIAL_SIZE : sz + INITIAL_SIZE},size{sz},arr{new T[buffer_size]}
{
	if(size < 0) 
	{ throw std::invalid_argument("non si può avere dimensione negativa"); }
	for(int i = 0; i < sz; i++)
	{
		arr[i] = T{};
	}
}
//costruttore initializer list
template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> lst)
	:size{lst.size()},buffer_size{(lst.size() < INITIAL_SIZE)? INITIAL_SIZE : lst.size()+INITIAL_SIZE},arr{new T[buffer_size]}
{
	std::copy(lst.begin(), lst.end(), arr);
}
//costruttore di copia
template<typename T>
MyVector<T>::MyVector(const MyVector<T>& v)
	:size{v.size},buffer_size{v.buffer_size},arr{new T[buffer_size]}
{
	std::copy(v.arr, v.arr+v.size, arr);
}
//costruttore move
template<typename T>
MyVector<T>::MyVector(MyVector<T>&& v)
	:size{v.size},buffer_size{v.buffer_size},arr{new T[buffer_size]}
{
	arr = v.arr;
	v.size = 0;
	v.arr = nullptr;
}
//distruttore
template<typename T>
MyVector<T>::~MyVector()
{
	delete[] arr;
}
template<typename T>
T& MyVector<T>::operator[](int index)
{
	return arr[index];
}
template<typename T>
T MyVector<T>::operator[](int index) const
{
	return arr[index];
}
//operatore di copia
template<typename T>
MyVector<T>& MyVector<T>::operator=(const MyVector<T>& v)
{
	size = v.size;
	T* temp = nullptr;
	if(v.size < INITIAL_SIZE)
	{
		temp = new T[INITIAL_SIZE];
	}
	else 
	{
		temp = new T[v.buffer_size];
	}
	std::copy(v.arr, v.arr+v.size, temp);
	delete[] arr;
	arr = temp;
	return *this;
}
//operatore move
template<typename T>
MyVector<T>& MyVector<T>::operator=(MyVector<T>&& v)
{
	size = v.size;
	v.size = 0;
	delete[] arr;
	arr = v.arr;
	v.arr = nullptr;
	return *this;
}
template<typename T>
int MyVector<T>::length() const
{
	return size;
}
template<typename T>
T& MyVector<T>::at(int index)
{
	if(index >= 0 && index < size)
	{ return arr[index]; }
	else
	{ throw std::out_of_range("indice non valido");}
}
template<typename T>
T MyVector<T>::at(int index) const
{
	if(index >= 0 && index < size)
	{ return arr[index]; }
	else
	{ throw std::out_of_range("indice non valido");}
}
template<typename T>
void MyVector<T>::push_back(const T& element)
{
	if(size >= buffer_size)
	{
		buffer_size += INITIAL_SIZE;
		T* temp = new T[buffer_size];
		for(int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
	arr[size] = element;
	size++;
}
template<typename T>
T MyVector<T>::pop_back()
{
	size--;
	return arr[size];
}
template<typename T>
void MyVector<T>::reserve(int n)
{
	if(n > buffer_size)
	{
		buffer_size = n;
		T* temp = new T[buffer_size];
		for(int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		arr = temp;
	}
}
#endif
