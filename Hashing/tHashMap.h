#pragma once
#include "tHashes.h"
template<typename K, typename V>
class tHashMap
{
private:
	V * data; // holds the data
	size_t dataCapacity; // sizes of the above buffers
public:
	V& operator[] (const K& key); // return the object at the given key
	V& operator[] (const K& key) const; // return the object at the given key
	tHashMap& operator= (const tHashMap&rhs); // will set the data at the location
	tHashMap(size_t dataCapacity); // constructer and need the size
	tHashMap(); // sets size to 50
	tHashMap(const tHashMap&rhs); // constructer that copies another hash map
	~tHashMap();
};
template<typename K, typename V>
inline V & tHashMap<K, V>::operator[](const K & key)
{
	return data[tHashes<K>::getInst().hash(key) % dataCapacity];
}
template<typename K, typename V>
inline V & tHashMap<K, V>::operator[](const K & key) const
{
	return data[tHashes::getInst().hash(key) % dataCapacity];
}
template<typename K, typename V>
inline tHashMap<K, V> & tHashMap<K, V>::operator=(const tHashMap & rhs)
{
	if (data != nullptr)
		delete[] data;
	else
	{
		dataCapacity = rhs.dataCapacity;
		data = new V[rhs.dataCapacity];
		for (size_t i = 0; i < rhs.dataCapacity; ++i)
		{
			*data[i] = *rhs[i];
		}
	}
}

template<typename K, typename V>
inline tHashMap<K, V>::tHashMap(size_t dataCapacity)
{
	this->dataCapacity = dataCapacity;
	data = new V[dataCapacity];
}

template<typename K, typename V>
inline tHashMap<K, V>::tHashMap()
{
	data = new V[50];
}

template<typename K, typename V>
inline tHashMap<K, V>::tHashMap(const tHashMap & rhs)
{
	dataCapacity = rhs.dataCapacity;
	data = new V[rhs.dataCapacity];
	for (size_t i = 0; i < rhs.dataCapacity; ++i) 
	{
		*data[i] = *rhs[i];
	}
}

template<typename K, typename V>
inline tHashMap<K, V>::~tHashMap()
{
	delete[] data;
}
