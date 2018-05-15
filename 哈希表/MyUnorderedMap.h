//#pragma once
//#include"HashTable.h"
//
//template<class K, class V>
//struct MapKeyOfValue
//{
//	const K operator()(const pair<K, V>& key)
//	{
//		return key.first;
//	}
//};
//
//template<class K, class V,class HashFunc = Hash<K>>
//class MyUnorderedMap
//{
//public:
//	typedef HashTable<K, pair<K, V>, MapKeyOfValue<K, V>, HashFunc> HT;
//	typedef typename HT::Iterator Iterator;
//public:
//	pair<Iterator, bool> Insert(const pair<K,V>& kv)//直接用pair变量代替键值对
//	{
//		return _ht.Insert(kv);
//	}
//	V& operator[](const K& key)
//	{
//		pair<Iterator, bool> ret = _ht.Insert(make_pair(key,V()));
//		return ret.first->second;
//	}
//	Iterator Find(const K& key)
//	{
//		return _ht.Find(key);
//	}
//	Iterator Begin()
//	{
//		return _ht.Begin();
//	}
//	Iterator End()
//	{
//		return _ht.End();
//	}
//private:
//	HT _ht;
//};
//void TestMap()
//{
//	MyUnorderedMap<string,string> s;
//	s.Insert(make_pair("string", "字符串"));
//s.Insert(make_pair("left", "左边"));
//MyUnorderedMap<string,string>::Iterator  it = s.Begin();
//	while (it != s.End())
//	{
//		cout <<it->first<<" "<<it->second<<endl;
//		++it;
//	}
//}