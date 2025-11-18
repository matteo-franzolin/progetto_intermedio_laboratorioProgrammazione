#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>

template<typename T>
class MyVector
{
public:
	explicit MyVector<T>(int sz = 0);
	MyVector<T>(std::initializer_list<T> lst);
	MyVector<T>(const MyVector<T>& v); //costr. copia
	MyVector<T>(MyVector<T>&& v); //costr. move
	T& operator[](int index);
	T operator[](int index) const;
	MyVector<T>& operator=(const MyVector<T>& v); //op. copia
	MyVector<T>& operator=(MyVector<T>&& v); //op. move
	int length() const;
	T& at(int index);
	T at(int index) const;
	void push_back(const T& element);
	T pop_back();
	void reserve(int n);
	~MyVector<T>();
	
private:
	static constexpr int INITIAL_SIZE = 100;
	int buffer_size;
	int size;
	T* arr;
	
};
 
#include "../src/MyVector.hpp"
#endif
