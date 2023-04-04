#pragma once
#include <iostream>
#include <list>
void Example()
{
	
	std::list<int> lt1;
	std::list<int> lt2;

	lt1.push_back(10);
	lt1.push_back(20);
	lt1.push_back(30);
	lt1.push_back(40);
	lt1.push_back(50);

	lt2.push_back(20);
	lt2.push_back(35);
	lt2.push_back(40);

	// merge() 는 반드시 리스트가 정렬되어있어야한다.
	lt1.merge(lt2);
	for (auto itr = lt1.begin(); itr != lt1.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';


	std::list<int> lt3;
	std::list<int> lt4;

	lt3.push_back(30);
	lt3.push_back(20);
	lt3.push_back(10);

	lt4.push_back(60);
	lt4.push_back(40);
	
	// 오름차순이 아닐 시 반드시 조건자를 지정해줘야한다
	lt3.merge(lt4, std::greater<int>());
	for (auto itr = lt3.begin(); itr != lt3.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';
}