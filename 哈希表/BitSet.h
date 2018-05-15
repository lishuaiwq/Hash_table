#pragma once
#include"MyUnorderedSet.h"

class BitSet
{
public:
	BitSet(size_t range)//����λͼ�ܱ�ʾ�ķ�Χ��һ���Ǳ���λ
	{
		//_bits.resize(range/32+1, 0);
		_bits.resize((range>>5)+1, 0);
	}
	void Set(size_t x)//����λͼ��
	{
		size_t num = (x >> 5);
		size_t pos = x % 32;
		_bits[num] |= 1 << pos;
	}
	void ReSet(size_t x)//��λͼ��ɾ��
	{
		size_t num = (x >> 5);
		size_t pos = x % 32;
		_bits[num] &= ~(1 << pos);
	}
	bool Test(size_t x)//�ж��Ƿ���λͼ��
	{
		size_t num = (x >> 5);
		size_t pos = x % 32;
		return  _bits[num] & (1 << pos);
	}
protected:
	vector<size_t> _bits;
}��
void test()
{

	BitSet bs(32);
	bs.Set(110);
	bs.Set(1);
	bs.Set(100000);
	bs.Set(100001);

	cout << bs.Test(110) << endl;

}