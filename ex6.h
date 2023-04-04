#pragma once
#include <iostream>
#include <vector>
#include <list>
void Example()
{
	std::vector<int> v(5);
	v[0] = 10;
	v[1] = 20;
	v[2] = 30;
	v[3] = 40;
	v[4] = 50;

	for (std::vector<int>::size_type i = 0; i < v.size(); ++i)
	{
		std::cout << v[i] << " ";
	}
	std::cout << '\n';
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	v.resize(10);
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	// resize를 통한 size 축소 시 capacity는 줄어들지 않는다
	v.resize(5);
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	v.clear();
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	// 사이즈 축소 시 컨테이너는 비었지만 메모리는 계속 같은 크기로 남아있기에 비효율적
	// swap을 통해 임시 객체와 바꾸면 해결 가능
	std::vector<int>().swap(v);
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	// [] 연산자와 at() 함수의 차이
	std::vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	//v2.at(3);	// 범위 검사, out_of_range 예외발생
	//v2[3]		// 범위 검사 안함, 메모리 접근 오류 발생

	// 역방향 iterator 순회
	auto iter = v2.begin();
	auto riter = v2.rbegin();

	for (; iter != v2.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	std::cout << '\n';

	for (; riter != v2.rend(); ++riter)
	{
		std::cout << *riter << " ";
	}
	std::cout << '\n';
	
	// 삽입
	std::vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	
	std::vector<int>::iterator itr = v3.begin();

	v3.insert(itr, 3, 100);
	// 메모리가 재할당되기 때문에 iterator를 다시 설정해줘야한다.
	for (itr = v3.begin(); itr != v3.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';

	// list
	// remove(), splice(), unique() 제공

	// remove
	std::list<int> lt;
	lt.push_back(10);
	lt.push_back(20);
	lt.push_back(30);
	lt.push_back(40);

	std::list<int>::iterator litr;
	for (litr = lt.begin(); litr != lt.end(); ++litr)
	{
		std::cout << *litr << " ";
	}
	std::cout << '\n';

	lt.remove(20);
	for (litr = lt.begin(); litr != lt.end(); ++litr)
	{
		std::cout << *litr << " ";
	}
	std::cout << '\n';

	// splice
	std::list<int> lt2;
	lt2.push_back(10);
	std::list<int>::iterator litr2 = lt2.begin();
	litr = lt.begin();
	lt2.splice(litr2, lt, lt.begin(), lt.end());	// litr2가 가리키는 곳에 lt의 litr 에서부터 모든 원소를 잘라붙임
	for (litr2 = lt2.begin(); litr2 != lt2.end(); ++litr2)
	{
		std::cout << *litr2 << " ";
	}
	std::cout << '\n';


}