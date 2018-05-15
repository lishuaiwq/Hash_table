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
//��ϣӳ�����K=λ��/���ݸ���*0.7��ln2��---->��λ��=K/���ݸ���
template<class K=string,
 class HashFunc1=HashFunc1<K>,
 class HashFunc2=HashFunc2<K>,
 class HashFunc3=HashFunc3<K>>
class BloomFilter
{
protected:
	BitSet _bs;
	size_t _rang;//��Χ
public:
	BloomFilter(size_t num)//���ݸ���
		:_bs(num * 5)
		, _rang(num * 5){}
	void Set(const K& key)
	{
		size_t hash1 = HashFunc1()(key);//ת��Ϊ���εķ�ʽ
		size_t hash2 = HashFunc2()(key);
		size_t hash3 = HashFunc3()(key);

		_bs.Set(hash1%_rang);
		_bs.Set(hash2%_rang);
		_bs.Set(hash3%_rang);
	}
	//void Reset(const K& key)
	bool Test(const K& key)
	{
		size_t hash1 = HashFunc1()(key);//ת��Ϊ���εķ�ʽ.��ϣ����
		if (_bs.Test(hash1%_rang) == false)
			return false;
		size_t hash2 = HashFunc2()(key);
		if (_bs.Test(hash2%_rang) == false)
			return false;
		size_t hash3 = HashFunc3()(key);
		if (_bs.Test(hash3%_rang) == false)
			return false;

		return true;//��׼ȷ�ģ���������
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