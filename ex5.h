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

	// vec�� ���� ���� �ݺ����̴�
	std::cout << itr[0] << '\n';
	std::cout << itr[1] << '\n';
	std::cout << itr[2] << '\n';
	
	itr = std::find(vec.begin(), vec.end(), 80);
	if (itr != vec.end())
		std::cout << *itr << '\n';

	// find�� ���ڰ��� �Լ� ��ü�� ������ ����
	std::sort(vec.begin(), vec.end(), std::greater<int>());
	itr = vec.begin();
	for (; itr != vec.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';


	// ������ �ݺ���
	std::reverse_iterator<std::vector<int>::iterator> riter(vec.end());
	std::reverse_iterator<std::vector<int>::iterator> end_riter(vec.begin());

	for (; riter != end_riter; ++riter)
	{
		std::cout << *riter << " ";
	}
}