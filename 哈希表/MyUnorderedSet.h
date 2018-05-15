#pragma once
#include"HashTable.h"
template<class K>
struct SetKeyOfValue
{
	const K operator()(const K& key)
	{
		return key;
	}
};
template<class K,class HashFunc = Hash<K>>
class MyUnorderedSet
{

	typedef HashTable<K, K, SetKeyOfValue<K>,HashFunc> HT;
public:
	typedef typename HT::Iterator Iterator;
public:
	pair<Iterator, bool> Insert(const K& key)
	{
		return _ht.Insert(key);
	}
	Iterator Find(const K& key)
	{
		return _ht.Find(key);
	}
	Iterator Begin()
	{
		return _ht.Begin();
	}
	Iterator End()
	{
		return _ht.End();
	}
private:
	HT _ht;
};

void TestSet()
{
	MyUnorderedSet<string> s;
	s.Insert("nihao");
	s.Insert("left");
	MyUnorderedSet<string>::Iterator  it = s.Begin();
	while (it != s.End())
	{
		cout << *it <<endl;
		++it;
	}
}