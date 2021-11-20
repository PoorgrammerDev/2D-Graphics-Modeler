#ifndef VECTOR_H
#define VECTOR_H

//vector.h - class specification
// a vector which approximates the stl vector

/**
 * @file vector.h
 * @author Thomas Tran
 * @date 11/19/2021
 */

#include <ostream>
#include <exception> 

const int VECTOR_DEFAULT_CAPACITY = 5;

//Class declaration copied from 2D_Graphics_Modeler_Class_Project.pdf on Canvas, with minor adjustments and additions
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

	using iterator = T*;
	using const_iterator = const T*;
	iterator begin(); // points to first element
	const_iterator begin() const;
	iterator end(); // points to one beyond the last element
	const_iterator end() const;
	iterator insert(iterator p, const T& v);// insert a new element v before p
	iterator erase(iterator p); // remove element pointed to by p

	//Added methods
	void print(std::ostream& out) const;
};

//Added method - overloaded extraction operator for easy printing
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec);

//================================
// CONSTRUCTORS AND DESTRUCTOR
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

//================================
// "NORMAL" METHODS
//================================

template<typename T>
T& vector<T>::operator[] (int n) {
	if (n < 0 || n >= size()) {
		throw std::out_of_range("Vector random access out of bounds!");
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
	int iterLength = ((newsize < space) ? newsize : space); //minimum(newsize, space)

	//move all elements into new array
	for (int i = 0; i < iterLength; ++i) {
		newElem[i] = std::move(this->elem[i]);
	}

	delete[] this->elem;
	this->size_v = ((newsize < this->size_v) ? newsize : this->size_v); //minimum(newsize, size_v)
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

//According to cplusplus.com, the std::vector implementation has this function behave as follows:
//If n is greater than the current vector capacity, the function causes the container to reallocate its storage increasing its capacity to n (or greater)
//Source: https://www.cplusplus.com/reference/vector/vector/reserve/
template<typename T>
void vector<T>::reserve(int newalloc) {
	if (newalloc > this->space) {
		resize(newalloc);
	}
}

//================================
// ITERATOR METHODS
//================================

template <typename T>
using iterator = T*;

template <typename T>
using const_iterator = const T*;


template <typename T>
// points to first element
iterator<T> vector<T>::begin() {
	return &elem[0];	
}

template <typename T>
// points to first element
const_iterator<T> vector<T>::begin() const {
	return &elem[0];
}


template <typename T>
// points to one beyond the last element
iterator<T> vector<T>::end() {
	return &elem[size_v];
}
 
template <typename T>
// points to one beyond the last element
const_iterator<T> vector<T>::end() const {
	return &elem[size_v];
}

template <typename T>
// insert a new element v before p
iterator<T> vector<T>::insert(iterator p, const T& v) {
	iterator trailingIter;
	int offset;

	//Ensure p is in this vector
	if (p < begin() || p > end()) {
		throw std::out_of_range("Iterator p is out of bounds!");
	}

	if (size_v + 1 > space) {
		//resizing the array would mean allocating it somewhere else, so p would be invalid.
		//instead, calculate offset from p to start of array, then re-apply it after with updated begin() value
		offset = p - begin(); 

		resize(space * 2); //double the capacity of array if we need more space
		p = begin() + offset;
	}

	//moves all elements from p onward one space forward, starting at end
	for (iterator leadingIter = end() - 1; leadingIter >= p; --leadingIter) {
		trailingIter = leadingIter + 1;
		*trailingIter = std::move(*leadingIter);
	}

	//Insert new element and update size
	*p = v;
	++size_v;

	return p;
}

template <typename T>
// remove element pointed to by p
iterator<T> vector<T>::erase(iterator p) {
	iterator trailingIter;

	//Ensure p is in this vector
	if (p < begin() || p > end()) {
		throw std::out_of_range("Iterator p is out of bounds!");
	}

	//moves all elements from p onward one space backward, starting at p
	for (iterator leadingIter = p + 1; leadingIter < end(); ++leadingIter) {
		trailingIter = leadingIter - 1;
		*trailingIter = std::move(*leadingIter);
	}

	--size_v;

	return p;
}

//================================
// ADDED METHODS
//================================

//Added print method for easy debugging and output
template <typename T>
void vector<T>::print(std::ostream& out) const {
	out << "[";
	for (int i = 0; i < size_v; ++i) {
		out << elem[i];
		
		if (i != size_v - 1) {
			out << ",";
		}
	}
	out << "]\n";
}

//Output stream extraction operator overload for printing
template <typename T>
std::ostream& operator<<(std::ostream& out, const vector<T>& vec) {
	vec.print(out);
	return out;
}


#endif
