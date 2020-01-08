#pragma once

#include <cassert>
#include <iostream>
template <typename type>
class tVector
{
private:
	const static size_t GROWTH_FACTOR = 2;
	type *arr; // pointer to underlying array
	size_t arrSize; // stores numbers of elements currently used
	size_t arrCapacity; // stores the capacity of the underlying array
public:
	// Variables

	//Functions
	type *data(); // returns a pointer to the underlying array
	void reserve(size_t newCapacity); // resizes the vector to at least this many elements
	void push_back(const type &value); // adds an element to the end of the vector
	void pop_back(); // drops the last element of the vector
	type &at(size_t index); // returns the element at the given element
	size_t size() const; // returns the element at the given elements
	size_t size_capacity() const; // returns the maxium number of elements we can store
	bool empty() const;   // Returns true if the vector contains no elements.
	void resize(size_t);  // Resizes the vector to contain the given number of elements.
	void shrink_to_fit(); // Resizes the vector's capacity to match its size.
	void clear();         // Empties the vector (all elements are destroyed in this process)
	// Operators
	tVector& operator=(const tVector &vec);   // copies the contents of the provided vector into this vector
	type& operator[] (size_t index); // returns the object at the given index
	// Constructers and Destructer
	tVector(const tVector &vec);              // copy constructs a vector from another
	tVector(); // intializes the vectors default values
	~tVector(); // destroys the underlying array
};

template<typename type>
inline type * tVector<type>::data()
{
	return arr;
}

template<typename type>
inline void tVector<type>::reserve(size_t newCapacity)
{
	if(newCapacity >= arrSize)
	{
		arrCapacity = newCapacity;
		type *nArr = new type[newCapacity];
		for(size_t i = 0; i < arrSize; ++i)
		{
			nArr[i] = arr[i];
		}
		delete[] arr;
		arr = nArr;
	}
}

template<typename type>
inline void tVector<type>::push_back(const type & value)
{
	if(arrSize >= arrCapacity)
	{
		//increase array capacity here
		if(arrSize != 0)
			reserve(arrSize*GROWTH_FACTOR);
		else
			reserve(1);
	}
	arr[arrSize] = value;
	arrSize++;
}

template<typename type>
inline void tVector<type>::pop_back()
{
	if(arrSize > 0)
	{
		arr[arrSize-1].~type();
		arrSize--;
	}
}

template<typename type>
inline type & tVector<type>::at(size_t index)
{
	assert(index < arrSize && index >= 0);
	return arr[index];
}

template<typename type>
inline size_t tVector<type>::size() const
{
	return arrSize;
}

template<typename type>
inline size_t tVector<type>::size_capacity() const
{
	return arrCapacity;
}

template<typename type>
inline bool tVector<type>::empty() const
{
	if (arrSize <= 0)
		return true;
	else
		return false;
}

template<typename type>
inline void tVector<type>::resize(size_t value)
{
	if(value > 0)
	{
		type *nArr = new type[value];
		if(value <= arrSize)
		{
			for (size_t i = 0; i < value; ++i)
			{
				nArr[i] = arr[i];
			}
			arrSize = value;
		}else
		{
			for (size_t i = 0; i < arrSize; ++i)
			{
				nArr[i] = arr[i];
			}
		}
		arrCapacity = value;
		delete[] arr;
		arr = nArr;
	}
}

template<typename type>
inline void tVector<type>::shrink_to_fit()
{
	if(arrSize > 0)
	{
		arrCapacity = arrSize;
		type *nArr = new type[arrSize];
		for(size_t i = 0; i < arrSize; ++i)
		{
			nArr[i] = arr[i];
		}
		delete[] arr;
		arr = nArr;
	}
}

template<typename type>
inline void tVector<type>::clear()
{
	if(arrSize > 0)
	{
		for (size_t i = 0; i < arrSize; ++i )
		{
			arr[i].~type();
		}
		arrSize = 0;
	}
}


template<typename type>
inline tVector<type> & tVector<type>::operator=(const tVector & vec)
{
	arr = new type[vec.size_capacity()];
	for (size_t i = 0; i < vec.size(); ++i)
	{
		arr[i] = vec.arr[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;
}

template<typename type>
inline type & tVector<type>::operator[](size_t index)
{
	return arr[index];
}

template<typename type>
inline tVector<type>::tVector(const tVector & vec)
{
	arr = new type[vec.size_capacity()];
	for (size_t i = 0; i < vec.size(); ++i)
	{
		arr[i] = vec.arr[i];
	}
	arrCapacity = vec.arrCapacity;
	arrSize = vec.arrSize;
}

template<typename type>
inline tVector<type>::tVector()
{
	arr = new type[10];
}

template<typename type>
inline tVector<type>::~tVector()
{
}
