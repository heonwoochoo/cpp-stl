#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

// 이항 조건 연산자를 위한 함수
bool Pred(int a, int b)
{
	return a > b;
}

bool Pred_Odd(int a)
{
	// a가 홀수면 true
	return a % 2;
}

// for_each를 위한 함수 객체
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

// 원소를 수정하지 않는 알고리즘
void Example()
{
	std::vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(35);

	// adjacent_find() : 구간 내 현재 원소와 다음 원소가 같아지는 첫 원소의 반복자를 반환
	// 찾지 못한다면 구간의 끝 부분을 반환
	auto ad_itr = std::adjacent_find(vec.begin(), vec.end());
	if (ad_itr != vec.end())
	{
		std::cout << *ad_itr << '\n';	// 30
	}

	// 이항 조건 연산자를 넣을 경우 해당 함수에서 true를 반환하는 첫 번째 반복자를 반환한다.
	auto ad_itr2 = std::adjacent_find(vec.begin(), vec.end(), Pred);
	if (ad_itr2 != vec.end())
	{
		std::cout << *ad_itr2 << '\n';
	}

	// count() : 원소의 개수 반환
	int value = 30;
	auto cnt = std::count(vec.begin(), vec.end(), value);
	std::cout << value << "는 " << cnt << "개 입니다.\n";

	// count_if() 단항 조건연산자의 true를 반환하는 원소의 개수를 반환
	std::vector<int> vec2{ 1,2,3,4,5,6 };
	auto cnt_odd = std::count_if(vec2.begin(), vec2.end(), Pred_Odd);
	std::cout << "홀수는 " << cnt_odd << "개 입니다.\n";

	// for_each() 와 함수자를 이용한 다양한 출력패턴 구현
	std::for_each(vec2.begin(), vec2.end(), PrintFunctor());
	std::cout << '\n';
	std::for_each(vec2.begin(), vec2.end(), PrintFunctor(','));
}