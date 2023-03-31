// �Լ� ��ü
#pragma once
#include <iostream>
#include <algorithm>

// Client
struct Functor1
{
	void operator()(int n)
	{
		std::cout << n << " ";
	}
};

struct Functor2
{
	void operator()(int n)
	{
		std::cout << n*n << " ";
	}
};

struct Functor3
{
	void operator()(int n)
	{
		std::cout << "���� : " << n << " ";
	}
};

struct Less
{
	bool operator() (int a, int b)
	{
		return a < b;
	}
};

struct Equl
{
	bool operator() (int a, int b)
	{
		return a == b;
	}
};

class Adder
{
public:
	int operator() (int a, int b)
	{
		return a + b;
	}
};

void Example()
{
	int arr[5] = { 10,20,30,40,50 };

	std::for_each(arr, arr + 5, Functor1());
	std::cout << '\n';
	std::for_each(arr, arr + 5, Functor2());
	std::cout << '\n';
	std::for_each(arr, arr + 5, Functor3());
	std::cout << '\n';

	Less l;
	std::cout << l(10, 20) << '\n';						// l ��ü�� �Ϲ��� ȣ��
	std::cout << l(20, 10) << '\n';						// l ��ü�� �Ϲ��� ȣ��
	std::cout << Less()(10, 20) << '\n';				// �ӽ� ��ü�� �Ϲ��� ȣ��
	std::cout << l.operator()(20, 10) << '\n';			// ����� ȣ��
	std::cout << Less().operator()(10, 20) << '\n';		// ����� ȣ��

	Equl cmp;
	std::cout << cmp(10, 20) << '\n';
	std::cout << cmp(20, 20) << '\n';

	Adder add;
	std::cout << "sum = " << add(10, 20) << '\n';
}