#pragma once
#include <string>
template<typename type>
class tHashes
{
public:
	static tHashes getInst(); // gets a instance
	size_t hash(const type& val);
	tHashes();
	~tHashes();
};

template<typename type>
inline tHashes<type> tHashes<type>::getInst()
{
	static tHashes<type> * instance = new tHashes<type>();
	return  *instance;
}

template<typename type>
inline size_t tHashes<type>::hash(const type & val)
{
	return val * 2654435761 % std::numeric_limits<size_t>::max();
}
template<>
inline size_t tHashes<std::string>::hash(const std::string & val)
{
	size_t hashVal = 0;
	for (size_t i = 0; i < val.length(); ++i)
	{
		hashVal += (val[i] * 2654435761 % std::numeric_limits<size_t>::max() + i >> i);
	}
	return hashVal;
}

template<typename type>
inline tHashes<type>::tHashes()
{
}

template<typename type>
inline tHashes<type>::~tHashes()
{
}
