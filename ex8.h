#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// ���� ���� �����ڸ� ���� �Լ�
bool Pred(int a, int b)
{
	return a > b;
}

bool Pred_Odd(int a)
{
	// a�� Ȧ���� true
	return a % 2;
}

// for_each�� ���� �Լ� ��ü
class PrintFunctor
{
	char fmt;

public:
	explicit PrintFunctor(char c = ' ') : fmt(c) {}

	void operator() (int n)
	{
		std::cout << n << fmt;
	}
};

// ���Ҹ� �������� �ʴ� �˰���
void Example()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(35);

	// adjacent_find() : ���� �� ���� ���ҿ� ���� ���Ұ� �������� ù ������ �ݺ��ڸ� ��ȯ
	// ã�� ���Ѵٸ� ������ �� �κ��� ��ȯ
	auto ad_itr = std::adjacent_find(vec.begin(), vec.end());
	if (ad_itr != vec.end())
	{
		std::cout << *ad_itr << '\n';	// 30
	}

	// ���� ���� �����ڸ� ���� ��� �ش� �Լ����� true�� ��ȯ�ϴ� ù ��° �ݺ��ڸ� ��ȯ�Ѵ�.
	auto ad_itr2 = std::adjacent_find(vec.begin(), vec.end(), Pred);
	if (ad_itr2 != vec.end())
	{
		std::cout << *ad_itr2 << '\n';
	}

	// count() : ������ ���� ��ȯ
	int value = 30;
	auto cnt = std::count(vec.begin(), vec.end(), value);
	std::cout << value << "�� " << cnt << "�� �Դϴ�.\n";

	// count_if() ���� ���ǿ������� true�� ��ȯ�ϴ� ������ ������ ��ȯ
	std::vector<int> vec2{ 1,2,3,4,5,6 };
	auto cnt_odd = std::count_if(vec2.begin(), vec2.end(), Pred_Odd);
	std::cout << "Ȧ���� " << cnt_odd << "�� �Դϴ�.\n";

	// for_each() �� �Լ��ڸ� �̿��� �پ��� ������� ����
	std::for_each(vec2.begin(), vec2.end(), PrintFunctor());
	std::cout << '\n';
	std::for_each(vec2.begin(), vec2.end(), PrintFunctor(','));
}