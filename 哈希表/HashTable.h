//#include<iostream>
//////namespace  kangfagndizhi
//////{
//////	//#pragma once 
//////	//#include<vector>
//////	//#include<iostream>
//////	//using namespace std;
//////	////��ϣ��ļ��ֹ��췽������ϣ��Ҳ���Խ�ɢ�б���������ɢ�к���
//////	////����� ���ַ��� �Լ�ȥ�˽⣬���Ǻܳ���
//////	///*�۵���
//////	//�������
//////	//��ѧ������*/
//////	////����1��ֱ�Ӷ�ַ��hash(key)=key*i+j;�����ھֲ��Եĳ���
//////	////����2���������������������Ǽ�����������ţ����������ڵ�һ��������ǹ�ϣ��ͻ����˵��ϣ��ײ
//////	//
//////	////�����ϣ��ͻ�ķ���: ��ɢ�з������Ŷ�ַ��
//////	////���������ַ���:1.����̽�⣬������ͻ��λ�ú�����ȥ��λ�ã��ҵ���λ�þͷŽ�ȥ
//////	//
//////	//
//////	////һ��ֵ��ӳ�䵽ͬһ��λ�ã��ͻ������ϣ��ͻ
//////	////��дhash��ʱ����һ�� Ҫע�������������Ԫ�ؽ���ϣ��������Ļ���ô����ѭ�������������ڲ����ʱ��Ҫ�������ݣ�������������ݲ�������ȡ���ݣ�ȡ�������غ����ӣ���������=����Ԫ�ظ���/ɢ�б�ĳ��� 
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
////			//����Ƕ���̽��Ļ�����Ҫ�Ķ�����Ĳ���λ��
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
////		if (_tables.size()==0||_size*10 / _tables.size()*10 >=7)//��Ϊ���γ����εĽ�������������������� ��������ȥ�Ż�
////		{
////				//����resize,reserve
////				/*vector<Node> newtables;
////				newtables.resize(_tables.size() * 2);*///�������Ժ���Ҫ����ӳ��,��Ϊ�����������λ��Ҳ�ʹ���
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
////	size_t HashFunc(const K& key)//��ֹkey����������,��Ϊ string����ȡģ
////	{
////			return key%_tables.size();
////	}
////protected:
////		vector<Node> _tables;
////		size_t _size;//����Ԫ�ز���ȷ��,��Ϊvector��size��ʾ������ݵĴ�С���������size��ʾ�ӽ�ȥ���ٸ�
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
//	//���ϲ��������е�key��֧��ȡģ
//#pragma once 
//#include<vector>
//#include<iostream>
//	using namespace std;
//	//��ϣ��ļ��ֹ��췽������ϣ��Ҳ���Խ�ɢ�б���������ɢ�к���
//	//����� ���ַ��� �Լ�ȥ�˽⣬���Ǻܳ���
//	/*�۵���
//	�������
//	��ѧ������*/
//	//����1��ֱ�Ӷ�ַ��hash(key)=key*i+j;�����ھֲ��Եĳ���
//	//����2���������������������Ǽ�����������ţ����������ڵ�һ��������ǹ�ϣ��ͻ����˵��ϣ��ײ
//
//	//�����ϣ��ͻ�ķ���: ��ɢ�з������Ŷ�ַ��
//	//���������ַ���:1.����̽�⣬������ͻ��λ�ú�����ȥ��λ�ã��ҵ���λ�þͷŽ�ȥ
//
//
//	//һ��ֵ��ӳ�䵽ͬһ��λ�ã��ͻ������ϣ��ͻ
//	//��дhash��ʱ����һ�� Ҫע�������������Ԫ�ؽ���ϣ��������Ļ���ô����ѭ�������������ڲ����ʱ��Ҫ�������ݣ�������������ݲ�������ȡ���ݣ�ȡ�������غ����ӣ���������=����Ԫ�ظ���/ɢ�б�ĳ��� 
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
//	size_t operator()(const K& key)//�������е�key������ȡģ
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
//	//struct Hashstring//�����ַ�����
//	//{
//	//	size_t operator()(const string& s)
//	//	{
//	//		return s[0];//�������ַ��������ﲢ���Ǻܺã���Ϊ������ַ���ͬ�Ļ�,��ô��������ͻ
//	//
//	//		//������ר���ַ��������㷨ȡ�Ż�
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
//				//����Ƕ���̽��Ļ�����Ҫ�Ķ�����Ĳ���λ��
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
//			if (_tables.size() == 0 || _size * 10 / _tables.size() * 10 >= 7)//��Ϊ���γ����εĽ�������������������� ��������ȥ�Ż�
//			{
//				//����resize,reserve
//				/*vector<Node> newtables;
//				newtables.resize(_tables.size() * 2);*///�������Ժ���Ҫ����ӳ��,��Ϊ�����������λ��Ҳ�ʹ���
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
//		size_t HashFunc(const K& key)//��ֹkey����������,��Ϊ string����ȡģ
//		{
//			_Hash hf;
//			return hf(key) % _tables.size();
//		}
//	protected:
//		/*Node* _tables;
//		size_t _size;
//		size_t _capacity;*/
//		vector<Node> _tables;
//		size_t _size;//����Ԫ�ز���ȷ��,��Ϊvector��size��ʾ������ݵĴ�С���������size��ʾ�ӽ�ȥ���ٸ�
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
//		dict.Insert("nihao", "��˧");
//	}
//
//	//����ʹ�÷º���ȡ�������⻹������ģ���ػ�ȡ�����������
//
//	//���Ϲ�ϣ�ĳ�ͻʹ������̽�����ˣ����ǻ��ǲ��Ǻܺã���ô��������һ�ַ�������
//
//	//����������ϣͰ����ͻ�˼�������ң�������˳���+����
//
//	/*������ܣ�
//
//	������ AVL �����(map/set)
//	��ϣ��(unordered_map/unordered_set)--��ϣ����չ��λͼ����¡��һ���Թ�ϣ�㷨��
//
//	������Щ�����ڴ���������ڲ���
//	B��--(��չ)B+��   ���ݿ�����  Ӳ�̣������*/
//}
//
//////////////////////////////////////////////////////////////////////////////////////////////
//��ϣͰ������
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
//������
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
	//�����ﲻ��Ҫ--���������ǵ��������
	_HashTableIterator(Node* node, HT* ht)
		:_node(node)
		, _ht(ht){}
	V& operator*()
	{
		return _node->_v;//�����map�Ļ�,��ô���ص���pair
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
	Self operator++(int)//����++
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
		size_t index = HashFunc(kov(v), _tables.size());//������ֹ��pair
		Node* cur = _tables[index];
		while (cur)
		{
			if (kov(cur->_v) == kov(v))//���ܲ����ظ���Ԫ��
			{
				return make_pair(Iterator(cur, this), false);
			}
			cur = cur->_next;
		}

		Node* node = new Node(v);

		//ͷ��
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
	size_t GetNextPreimeNum(size_t num)//������
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
	void CheckCapacity()//����
	{
		if (_tables.size() == 0)
		{
			_tables.resize(GetNextPreimeNum(1), NULL);//���˸��ռ仹���Ը�ֵ
		}
		else  if (_size == _tables.size())//�������ӵ���Ҫ��������
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
					size_t index = HashFunc(kov(cur->_v), newsize);//������λ��
					Node* next = cur->_next;
					//ͷ�嵽Ͱ��ȥ
					cur->_next = newtables[index];
					newtables[index] = cur;
					cur = next;
				}
				_tables[i] = NULL;
			}
			swap(_tables, newtables);
			//Ϊʲô���ŵ�ַ��������ô����?
			//������ô��������̫���ڸ���
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
	bool Remove(const K& key)//ɾ��Ԫ��
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
////��ϣ����
//
////��40�ڸ����ظ����޷������Σ�û�Ź��򡣸�һ���޷��ŵ�����������ж�һ�����Ƿ�����40�ڸ��У�����Ѷ��

//��������һ�� λͼ