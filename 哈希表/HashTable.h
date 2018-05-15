//#include<iostream>
//////namespace  kangfagndizhi
//////{
//////	//#pragma once 
//////	//#include<vector>
//////	//#include<iostream>
//////	//using namespace std;
//////	////哈希表的几种构造方法，哈希表也可以叫散列表，方法就是散列函数
//////	////下面的 几种方法 自己去了解，不是很常用
//////	///*折叠法
//////	//随机数法
//////	//数学分析法*/
//////	////方法1：直接定址法hash(key)=key*i+j;适用于局部性的场景
//////	////方法2：除留余数法：即余数是几就往几上面放，不过它存在的一个问题就是哈希冲突或者说哈希碰撞
//////	//
//////	////解决哈希冲突的方法: 闭散列方法开放定址法
//////	////大方向有两种方法:1.线性探测，即往冲突的位置后面再去找位置，找到空位置就放进去
//////	//
//////	//
//////	////一个值会映射到同一个位置，就会产生哈希冲突
//////	////在写hash的时候有一个 要注意的问题就是如果元素将哈希标表填满的话那么会死循环，所以我们在插入的时候要进行扩容，不过这个里扩容不能随便的取扩容，取决于其载菏因子，负载因子=表中元素个数/散列表的长度 
////enum State
////{
////	
////};
////template<class K,class V>
////struct HashNode
////{
////	K _key;
////	V _value;
////	State _state;
////	HashNode(const K& key = K(), const V& value = V())
////		:_key(key)
////		, _value(value)
////	    , _state(EMPTY){}
////};
////template<class K,class V>
////class HashTable
////{
////public:
////	typedef HashNode<K, V> Node;
////public:
////	HashTable()
////		:_size(0){}
////	bool Insert(const K& key, const V& value)
////	{
////		CheckCapacity();
////		if (Find(key))
////			return false;		
////		size_t index = HashFunc(key);
////		while (_tables[index]._state==EXIST)
////		{
////			//如果是二次探测的话则需要改动这里的插入位置
////			index++;
////			 if (index == _tables.size())
////				 {
////					 index = 0;
////				 }
////		}
////			_tables[index]._key = key;
////			_tables[index]._value = value;
////			_tables[index]._state = EXIST;
////			_size++;
////			return true;
////		}
////	Node* Find(const K& key)
////	{
////		size_t index = HashFunc(key);
////		while (_tables[index]._state != EMPTY)
////		{
////     		if (_tables[index]._key == key)
////			{
////				if (_tables[index]._state == EXIST)
////					return &_tables[index];
////				else
////				{
////					return NULL;
////				}
////			}
////			++index;
////			if (index == _tables.size())
////					index = 0;
////		}
////			return NULL;
////	}
////	bool CheckCapacity()
////	{
////		if (_tables.size()==0||_size*10 / _tables.size()*10 >=7)//因为整形除整形的结果还是整形所以我们在 这里这样去优化
////		{
////				//增容resize,reserve
////				/*vector<Node> newtables;
////				newtables.resize(_tables.size() * 2);*///扩容了以后需要重新映射,因为表的容量大了位置也就大了
////			size_t newsize = _tables.size() * 2;
////			if (newsize==0)
////			{
////				newsize = 3;
////			}
////				HashTable<K, V> newht;
////				newht._tables.resize(newsize);
////			for (size_t i = 0; i < _tables.size(); ++i)
////			{
////				if (_tables[i]._state == EXIST)
////				{
////					newht.Insert(_tables[i]._key, _tables[i]._value);
////				}
////			}
////			_tables.swap(newht._tables);
////		}
////			return true;
////	}
////    bool Erase(const K& key)
////	{
////		Node* node = Find(key);
////		if (node)
////		{
////			node->_state = DELETE;
////			--_size;
////		}
////		else
////		{
////			return false;
////		}
////	}
////	size_t HashFunc(const K& key)//防止key是任意类型,因为 string不能取模
////	{
////			return key%_tables.size();
////	}
////protected:
////		vector<Node> _tables;
////		size_t _size;//数据元素不够确定,因为vector的size表示表的数据的大小，而这里的size表示扔进去多少个
////	};
////	void TestHashtable()
////	{
////		int a[] = { 89, 18, 49, 58, 9 };
////		HashTable<int, int> ht;
////		for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
////		{
////			ht.Insert(i, a[i]);
////		}
////	}
////
//	//以上不是所所有的key都支持取模
//#pragma once 
//#include<vector>
//#include<iostream>
//	using namespace std;
//	//哈希表的几种构造方法，哈希表也可以叫散列表，方法就是散列函数
//	//下面的 几种方法 自己去了解，不是很常用
//	/*折叠法
//	随机数法
//	数学分析法*/
//	//方法1：直接定址法hash(key)=key*i+j;适用于局部性的场景
//	//方法2：除留余数法：即余数是几就往几上面放，不过它存在的一个问题就是哈希冲突或者说哈希碰撞
//
//	//解决哈希冲突的方法: 闭散列方法开放定址法
//	//大方向有两种方法:1.线性探测，即往冲突的位置后面再去找位置，找到空位置就放进去
//
//
//	//一个值会映射到同一个位置，就会产生哈希冲突
//	//在写hash的时候有一个 要注意的问题就是如果元素将哈希标表填满的话那么会死循环，所以我们在插入的时候要进行扩容，不过这个里扩容不能随便的取扩容，取决于其载菏因子，负载因子=表中元素个数/散列表的长度 
//	enum State
//	{
//		EXIST,
//		EMPTY,
//		DELETE,
//	};
//	template<class K, class V>
//	struct HashNode
//	{
//		K _key;
//		V _value;
//		State _state;
//		HashNode(const K& key = K(), const V& value = V())
//			:_key(key)
//			, _value(value)
//			, _state(EMPTY){}
//
//	};
//template<class K>
//struct Hash
//{
//	size_t operator()(const K& key)//处理所有的key都可以取模
//	{
//		return key;
//	}
//};
//	template<>
//	struct Hash<string>
//	{
//		size_t operator()(const string& s)
//		{
//			return s[0];
//		}
//	};
//	//struct Hashstring//处理字符串的
//	//{
//	//	size_t operator()(const string& s)
//	//	{
//	//		return s[0];//不过这种方法在这里并不是很好，因为如果首字符相同的话,那么则会产生冲突
//	//
//	//		//所以有专门字符串处理算法取优化
//	//	}
//	//};
//template<class K, class V, class _Hash = Hash<K>>
//class HashTable
//{
//public:
//	typedef HashNode<K, V> Node;
//public:
//	HashTable()
//		:_size(0){}
//  bool Insert(const K& key, const V& value)
// {
//		CheckCapacity();
//		if (Find(key))
//			return false;
//			size_t index = HashFunc(key);
//			while (_tables[index]._state == EXIST)
//			{
//				//如果是二次探测的话则需要改动这里的插入位置
//				index++;
//				if (index == _tables.size())
//				{
//					index = 0;
//				}
//			}
//			_tables[index]._key = key;
//			_tables[index]._value = value;
//			_tables[index]._state = EXIST;
//			_size++;
//			return true;
//		}
//		Node* Find(const K& key)
//		{
//			size_t index = HashFunc(key);
//			while (_tables[index]._state != EMPTY)
//			{
//				if (_tables[index]._key == key)
//				{
//					if (_tables[index]._state == EXIST)
//						return &_tables[index];
//					else
//					{
//						return NULL;
//					}
//				}
//				++index;
//				if (index == _tables.size())
//					index = 0;
//			}
//			return NULL;
//		}
//		bool CheckCapacity()
//		{
//			if (_tables.size() == 0 || _size * 10 / _tables.size() * 10 >= 7)//因为整形除整形的结果还是整形所以我们在 这里这样去优化
//			{
//				//增容resize,reserve
//				/*vector<Node> newtables;
//				newtables.resize(_tables.size() * 2);*///扩容了以后需要重新映射,因为表的容量大了位置也就大了
//				size_t newsize = _tables.size() * 2;
//				if (newsize == 0)
//				{
//					newsize = 3;
//				}
//				HashTable<K, V, _Hash > newht;
//				newht._tables.resize(newsize);
//				for (size_t i = 0; i < _tables.size(); ++i)
//				{
//					if (_tables[i]._state == EXIST)
//					{
//						newht.Insert(_tables[i]._key, _tables[i]._value);
//					}
//				}
//				_tables.swap(newht._tables);
//			}
//			return true;
//		}
//		bool Erase(const K& key)
//		{
//			Node* node = Find(key);
//			if (node)
//			{
//				node->_state = DELETE;
//				--_size;
//			}
//			else
//			{
//				return false;
//			}
//		}
//		size_t HashFunc(const K& key)//防止key是任意类型,因为 string不能取模
//		{
//			_Hash hf;
//			return hf(key) % _tables.size();
//		}
//	protected:
//		/*Node* _tables;
//		size_t _size;
//		size_t _capacity;*/
//		vector<Node> _tables;
//		size_t _size;//数据元素不够确定,因为vector的size表示表的数据的大小，而这里的size表示扔进去多少个
//	};
//	void TestHashtable()
//	{
//		/*int a[] = { 89, 18, 49, 58, 9 };
//		HashTable<int, int> ht;
//		for (size_t i = 0; i < sizeof(a) / sizeof(*a); i++)
//		{
//		ht.Insert(i, a[i]);
//		}*/
//		/*HashTable<string, string,Hashstring> dict;*/
//		HashTable<string, string> dict;
//		dict.Insert("nihao", "李帅");
//	}
//
//	//处理使用仿函数取处理以外还可以用模板特化取处理这个问题
//
//	//以上哈希的冲突使用线性探测解决了，但是还是不是很好，那么就有另外一种方法就是
//
//	//开链法（哈希桶）冲突了即往下面挂，本质是顺序表+链表
//
//	/*搜索框架：
//
//	搜索树 AVL 红黑树(map/set)
//	哈希表(unordered_map/unordered_set)--哈希的扩展（位图、布隆、一致性哈希算法）
//
//	上面这些都是内存的搜索，内查找
//	B树--(扩展)B+树   数据库搜索  硬盘，外查找*/
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////
//哈希桶拉链法
#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

template<class V>
struct HashNode
{
	V _v;//set->   map->kv
	HashNode<V>* _next;
	HashNode(const V& v)
		:_v(v)
		, _next(NULL){}
};
template<class K>
struct Hash
{
	size_t operator()(const K& key)
	{
		return key;
	}
};
template<>
struct Hash<string>
{
	size_t operator()(const string& s)
	{
		return s[0];
	}
};
template<class K, class V, class  KeyofValue, class _HashFunc>
class HashTable;
//迭代器
template<class K, class V, class KeyofValue, class _HashFunc>
struct _HashTableIterator
{
private:
	typedef _HashTableIterator<K, V, KeyofValue, _HashFunc> Self;
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KeyofValue, _HashFunc> HT;
	Node* _node;
	HT* _ht;
public:
	//在这里不需要--，即可以是单向迭代器
	_HashTableIterator(Node* node, HT* ht)
		:_node(node)
		, _ht(ht){}
	V& operator*()
	{
		return _node->_v;//如果是map的话,那么返回的是pair
	}
	V* operator->()
	{
		return &(operator*());
	}
	Self operator++()
	{
		if (_node->_next)
		{
			_node = _node->_next;
		}
		else
		{
			KeyofValue kov;
           size_t index = _ht->HashFunc(kov(_node->_v),_ht->_tables.size());
			++index;
			while (index < _ht->_tables.size())
			{
				if (_ht->_tables[index] != NULL)
				{
					_node = _ht->_tables[index];
					break;
				}
				else
				{
					++index;
				}
			}
			if (index == _ht->_tables.size())
			{
				_node = NULL;
			}
		}
		return *this;
	}
	Self operator++(int)//后置++
	{
		Self tmp(*this);
		++*this;
		return tmp;
	}
	bool operator==(const Self& s) const
	{
		return _node == s._node;
	}
	bool operator!=(const Self& s) const
	{
		return _node != s._node;
	}
};

template<class K, class V, class KeyofValue, class _HashFunc = Hash<K>>
class HashTable
{
public:
	typedef HashNode<V> Node;
	friend struct  _HashTableIterator<K, V, KeyofValue, _HashFunc>;
public:
	typedef _HashTableIterator<K, V, KeyofValue, _HashFunc> Iterator;
	Iterator Begin()
	{
		for (size_t i = 0; i < _tables.size(); ++i)
		{
			if (_tables[i])
			{
				return Iterator(_tables[i], this);
			}
		}
		return End();
	}
	Iterator End()
	{
		return Iterator(NULL, this);
	}
	HashTable()
		:_size(0){}
	pair<Iterator, bool> Insert(const V& v)
	{
		CheckCapacity();

		KeyofValue kov;
		size_t index = HashFunc(kov(v), _tables.size());//用来防止是pair
		Node* cur = _tables[index];
		while (cur)
		{
			if (kov(cur->_v) == kov(v))//不能插入重复的元素
			{
				return make_pair(Iterator(cur, this), false);
			}
			cur = cur->_next;
		}

		Node* node = new Node(v);

		//头插
		node->_next = _tables[index];
		_tables[index] = node;
		++_size;
		return make_pair(Iterator(node, this), true);
	}
	size_t HashFunc(const K& key, size_t size)
	{
		_HashFunc _kov;
		return _kov(key) % size;
	}
	size_t GetNextPreimeNum(size_t num)//素数表
	{
		const int _PrimeSize = 28;
		static const unsigned long _PrimeList[_PrimeSize] =
		{
			53ul, 97ul, 193ul, 389ul, 769ul,
			1543ul, 3079ul, 6151ul, 12289ul, 24593ul,
			49157ul, 98317ul, 196613ul, 393241ul, 786433ul,
			1572869ul, 3145739ul, 6291469ul, 12582917ul, 25165843ul,
			50331653ul, 100663319ul, 201326611ul, 402653189ul, 805306457ul,
			1610612741ul, 3221225473ul, 4294967291ul
		};
		for (size_t i = 0; i < _PrimeSize; ++i)
		{
			if (_PrimeList[i]>num)
			{
				return _PrimeList[i];
			}
		}
		return _PrimeList[_PrimeSize - 1];
	}
	void CheckCapacity()//扩容
	{
		if (_tables.size() == 0)
		{
			_tables.resize(GetNextPreimeNum(1), NULL);//除了给空间还可以给值
		}
		else  if (_size == _tables.size())//负载因子到了要进行增容
		{
			size_t newsize = GetNextPreimeNum(_tables.size());
			if (newsize == _tables.size())
				return;
			vector<Node*> newtables;
			newtables.resize(newsize, NULL);
			KeyofValue kov;
			for (size_t i = 0; i < _tables.size(); ++i)
			{
				Node* cur = _tables[i];
				while (cur)
				{
					size_t index = HashFunc(kov(cur->_v), newsize);//计算新位置
					Node* next = cur->_next;
					//头插到桶中去
					cur->_next = newtables[index];
					newtables[index] = cur;
					cur = next;
				}
				_tables[i] = NULL;
			}
			swap(_tables, newtables);
			//为什么开放地址法不能这么做呢?
			//可以这么做，但是太过于复杂
		}
	}
	Node* Find(const K& key)
	{
		size_t index = HashFunc(key, _tables.size());
		Node* cur = _tables[index];
		KeyofValue kov;
		while (cur)
		{
			if (keykov(cur->_v) == key)
			{
				//return cur;
				return Iterator(cur, this)
			}
			cur = cur->_next;
		}
		//return NULL;
		return Iterator(NULL, this);
	}
	bool Remove(const K& key)//删除元素
	{
		KeyofValue kov;
		size_t index = HashFunc(key);
		Node* cur = _tables[index];
		if (cur == NULL)
			return false;
		if (kov(cur->_v) == key)
		{
			_tables[index] = cur->_next;
			delete cur;
			return true;
		}
		else
		{
			Node* prev = cur;
			cur = cur->_next;
			while (cur)
			{
				if (kov(cur->_v) == key)
				{
					prev->_next = cur->_next;
					delete cur;
					return true;
				}
				prev = cur;
				cur = cur->_next;
			}
			return false;
		}
	}
private:
	vector<Node*> _tables;
	size_t _size;
};
//void TestHashTable()
//{
//HashTable<int, int,SetKeyOfValue<int>> hs;
//	hs.Insert(4);
	//hs.Insert(14);
	//hs.Insert(24);
	//hs.Insert(33);
	//hs.Insert(55);
	//hs.Insert(55);
	//hs.Insert(5);
	//hs.Insert(19);
	//HashTable<int, int, SetKeyOfValue<int>>::Iterator it = hs.Begin();
	//while (it != hs.End())
	//{
	//	cout << *it << " " << endl;
	//	++it;
	//}
	/*HashTable<string, string, SetKeyOfValue<string>> hs;
	hs.Insert("wangqiam");
	hs.Insert("lishuai");
	hs.Insert("love");
	hs.Insert("forever");
	hs.Insert("haha");
	HashTable<string, string, SetKeyOfValue<string>>::Iterator it = hs.Begin();
	while (it != hs.End())
	{
		cout << *it << " " << endl;
		++it;
	}*/
//}
//
////哈希攻击
//
////给40亿个不重复的无符号整形，没排过序。给一个无符号的整数，如何判断一哥数是否在这40亿个中，【腾讯】

//下面来讲一下 位图