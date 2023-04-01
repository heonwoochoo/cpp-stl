#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

void Example()
{
	std::vector<int> vec;
	vec.emplace_back(10);
	vec.emplace_back(20);
	vec.emplace_back(30);
	vec.emplace_back(40);
	vec.emplace_back(50);

	std::vector<int>::iterator itr = vec.begin();

	// vec는 임의 접근 반복자이다
	std::cout << itr[0] << '\n';
	std::cout << itr[1] << '\n';
	std::cout << itr[2] << '\n';
	
	itr = std::find(vec.begin(), vec.end(), 80);
	if (itr != vec.end())
		std::cout << *itr << '\n';

	// find의 인자값에 함수 객체를 적용한 버전
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	itr = vec.begin();
	for (; itr != vec.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';


	// 역방향 반복자
	std::reverse_iterator<std::vector<int>::iterator> riter(vec.end());
	std::reverse_iterator<std::vector<int>::iterator> end_riter(vec.begin());

	for (; riter != end_riter; ++riter)
	{
		std::cout << *riter << " ";
	}
}