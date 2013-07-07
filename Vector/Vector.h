#ifndef VECTOR_H_
#define VECTOR_H_ value

#include <iostream>
#include "IndexOutofBounds.h"
using namespace std;

template <class T>
class Vector {
public:

	inline Vector() : m_nSize(0), m_pElements(NULL) {cout << "Vector created." << endl;};
	// create an empty vector

	inline Vector(int size) : m_nSize(size) {
	m_pElements = new T[size];
	cout << "Vector with size " << m_nSize << " created." << endl;};
	// create a vector of size elements

	Vector(const Vector& r);// copy ctor
	virtual ~Vector(){
		// delete [] m_pElements;
		// m_nSize = 0;
		cout << "~Vector" << endl;
	};

	inline T& operator[](int index) throw(IndexOutofBounds) {
		if (index < 0 || index >= m_nSize)
			throw IndexOutofBounds ("WARNING! [] out of range");
		return m_pElements[index];
	};
	// throw(IndexOutofBounds);
	// return the specified element, throws exception when index <0 or >=m_nSize

	inline int size() {
		return m_nSize;
	}	
	// return the size of the vector

	inline int inflate(int addSize){
		int newSize = m_nSize + addSize;
		int oldBytes = m_nSize * sizeof(T);
		int newBytes = newSize * sizeof(T);
		T * temp = new T[newBytes];
		for (int i = 0; i < oldBytes; ++i)
		{
			temp[i] = m_pElements[i];
		}
		delete [] m_pElements;
		m_pElements = temp;
		m_nSize = newSize;
		cout << "inflated" << endl;
		return m_nSize;
	};
	// expand the storage to m_nSize+addSize, return the new size

private:
	T *m_pElements;
	int m_nSize;
};

#endif