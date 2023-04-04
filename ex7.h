#pragma once
#include <iostream>
#include <set>

void Example()
{
	// set : 원소의 중복을 허용하지 않는다

	std::set<int> s1;
	s1.insert(1);
	s1.insert(1);
	s1.insert(1);
	s1.insert(2);
	s1.insert(3);

	std::set<int>::iterator itr;
	for (itr = s1.begin(); itr != s1.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';

	// insert는 반환값을 가진다.
	if (s1.insert(1).second == false)
	{
		std::cout << "원소가 이미 존재\n";
	}

	// 정렬 기준을 바꿀 수도 있다
	std::set<int, std::greater<int>> s2;
	s2.insert(10);
	s2.insert(20);
	s2.insert(30);
	s2.insert(40);
	for (auto itr = s2.begin(); itr != s2.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';

	// find : 원소를 찾을 경우 해당 위치의 iterator를 반환, 못찾으면 iterator의 end 위치를 반환
	auto s2_itr = s2.find(30);
	if (s2_itr != s2.end())
	{
		std::cout << *s2_itr << '\n';
	}

	// lower_bound() : 원소가 시작하는 위치의 반복자
	// upper_bound() : 원소가 끝나는 위치의 반복자 (원소의 다음을 가리키는 반복자)
	// equal_range() : 시작과 끝 부분의 반복자를 pair로 반환

	int v = 30;
	auto lower_itr = s2.lower_bound(v);
	auto upper_itr = s2.upper_bound(v);
	auto equal_itr = s2.equal_range(v);

	std::cout << "*lower_itr : " << *lower_itr << '\n';
	std::cout << "*upper_itr : " << *upper_itr << '\n';
	std::cout << "*equal_itr : " << *equal_itr.first << "," << *equal_itr.second << '\n';

}