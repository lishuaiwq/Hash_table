#pragma once
#include"BitSet.h"
template<class K>
struct HashFunc1
{
	size_t BKDRHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
	size_t operator()(const string& key)
	{
		return BKDRHash(key.c_str());
	}
};
template<class K>
struct HashFunc2
{
	size_t SDBMHash(const char *str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 65599 + ch;
		}
		return hash;
	}
	size_t operator()(const string& key)
	{
		return SDBMHash(key.c_str());
	}
};
template<class K>
struct HashFunc3
{
	size_t RSHash(const char *str)
	{
		register size_t hash = 0;
		size_t magic = 63689;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * magic + ch;
			magic *= 378551;
		}
		return hash;
	}
	size_t operator()(const string& key)
	{
		return RSHash(key.c_str());
	}
};
//哈希映射次数K=位数/数据个数*0.7（ln2）---->总位数=K/数据个数
template<class K=string,
 class HashFunc1=HashFunc1<K>,
 class HashFunc2=HashFunc2<K>,
 class HashFunc3=HashFunc3<K>>
class BloomFilter
{
protected:
	BitSet _bs;
	size_t _rang;//范围
public:
	BloomFilter(size_t num)//数据个数
		:_bs(num * 5)
		, _rang(num * 5){}
	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key);//转换为整形的方式
		size_t hash2 = HashFunc2()(key);
		size_t hash3 = HashFunc3()(key);

		_bs.Set(hash1%_rang);
		_bs.Set(hash2%_rang);
		_bs.Set(hash3%_rang);
	}
	//void Reset(const K& key)
	bool Test(const K& key)
	{
		size_t hash1 = HashFunc1()(key);//转换为整形的方式.哈希函数
		if (_bs.Test(hash1%_rang) == false)
			return false;
		size_t hash2 = HashFunc2()(key);
		if (_bs.Test(hash2%_rang) == false)
			return false;
		size_t hash3 = HashFunc3()(key);
		if (_bs.Test(hash3%_rang) == false)
			return false;

		return true;//不准确的，存在误判
	}
};
void TestBloomFilter()
{
	BloomFilter<> bf(10);
	bf.Set("sort");
	bf.Set("bloom");
	bf.Set("filter");
	bf.Set("bloomfilter");

	cout << bf.Test("sort");
	cout << bf.Test("bloom");

	cout << bf.Test("sort1");
}