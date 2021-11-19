#ifndef VECTOR_H
#define VECTOR_H

//vector.h - class specification
// a vector which approximates the stl vector

#include <exception> 

const int VECTOR_DEFAULT_CAPACITY = 5;

template<class T>
class vector {
private:
	int size_v; // the size
	T* elem; // a pointer to the elements
	int space; // size+free_space

public:
	vector(); // default constructor
	explicit vector(int s); // alternate constructor
	vector(const vector&); // copy constructor
	vector& operator=(const vector&); // copy assignment
	vector(const vector&&); // move constructor
	vector& operator=(const vector&&); // move assignment
	~vector(); // destructor

	T& operator[] (int n); // access: return reference
	//const T& operator[] (int n); // access: return reference //FIXME: duplicate of previous line (?)
	int size() const; // the current size
	int capacity() const; // current available space
	void resize(int newsize); // grow
	void push_back(T val); // add element
	void reserve(int newalloc); // get more space

	//TODO: I don't understand what this is saying, is anyone else familiar with this syntax? - Thomas
	using iterator = T*;
	using const_iterator = const T*;
	iterator begin(); // points to first element
	const_iterator begin() const;
	iterator end(); // points to one beyond the last element
	const_iterator end() const;
	iterator insert(iterator p, const T& v);// insert a new element v before p
	iterator erase(iterator p); // remove element pointed to by p
};

//================================
// METHOD IMPLEMENTATIONS
//================================

//Default constructor
template<typename T>
vector<T>::vector() : size_v(0), elem(new T[VECTOR_DEFAULT_CAPACITY]), space(VECTOR_DEFAULT_CAPACITY) {
}

//Constructor with size
template<typename T>
vector<T>::vector(int s) : size_v(0), elem(new T[s]), space(s) {
}

//Copy Constructor
template<typename T>
vector<T>::vector(const vector<T>& obj) : size_v(obj.size_v), space(obj.space) {
	//Allocates new elem internal array with same capacity and copies all elements contained within active size over
	this->elem = new T[obj.space];
	for (int i = 0; i < obj.size_v; ++i) {
		this->elem[i] = obj.elem[i];
	}
}

//Copy assignment operator
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>& obj) {
	delete[] this->elem;

	this->size_v = obj.size_v;
	this->space = obj.space;

	//Allocates new elem internal array with same capacity and copies all elements contained within active size over
	this->elem = new T[obj.space];
	for (int i = 0; i < obj.size_v; ++i) {
		this->elem[i] = obj.elem[i];
	}
	return *this;
}

//Move constructor
template<typename T>
vector<T>::vector(const vector<T>&& moveObj) : size_v(moveObj.size_v), elem(moveObj.elem), space(moveObj.space) {
	moveObj.elem = nullptr;
}

//Move assignment operator
template<typename T>
vector<T>& vector<T>::operator=(const vector<T>&& moveObj) {
	delete[] this->elem;

	this->size_v = moveObj.size_v;
	this->space = moveObj.space;
	this->elem = moveObj.elem;

	moveObj.elem = nullptr;
	return *this;
}

//Destructor
template<typename T>
vector<T>::~vector<T>() {
	delete[] elem;
}

//======================

template<typename T>
T& vector<T>::operator[] (int n) {
	if (n < 0 || n >= size()) {
		throw 0;//TODO: add out of bounds exception
	}

	return elem[n];
}

/* FIXME: See comment above (in class declaration)
template<typename T>
const T& vector<T>::operator[] (int n) {
	
}
*/

template<typename T>
int vector<T>::size() const {
	return size_v;
}

template<typename T>
int vector<T>::capacity() const {
	return space;
}

template<typename T>
void vector<T>::resize(int newsize) {
	T* newElem = new T[newsize];
	int iterLength = ((newsize > space) ? newsize : space); //This is to ensure that we don't overstep bounds in case user is shrinking array

	//copy all elements into new array
	for (int i = 0; i < iterLength; ++i) {
		newElem[i] = this->elem[i];
	}

	delete[] elem;
	this->size_v = ((newsize < this->size_v) ? newsize : this->size_v); //TODO: see if this is needed
	this->elem = newElem;
	this->space = newsize;

}

template<typename T>
void vector<T>::push_back(T val) {
	if (size_v + 1 > space) {
		resize(space * 2); //double the capacity of array if we need more space
	}

	elem[size_v] = val;
	++size_v;
}

template<typename T>
void vector<T>::reserve(int newalloc) {
	//TODO: Unimplemented method stub
}
 


/*
using iterator = T*;
using const_iterator = const T*;
iterator begin() {
	//TODO: Unimplemented method stub
}
 
const_iterator begin() const {
	//TODO: Unimplemented method stub
}

iterator end() {
	//TODO: Unimplemented method stub
}
 
const_iterator end() const {
	//TODO: Unimplemented method stub
}

iterator insert(iterator p, const T& v) {
	//TODO: Unimplemented method stub
}

iterator erase(iterator p) {
	//TODO: Unimplemented method stub
}
*/
 


#endif
