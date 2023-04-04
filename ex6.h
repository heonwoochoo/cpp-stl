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

	// resize�� ���� size ��� �� capacity�� �پ���� �ʴ´�
	v.resize(5);
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	v.clear();
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	// ������ ��� �� �����̳ʴ� ������� �޸𸮴� ��� ���� ũ��� �����ֱ⿡ ��ȿ����
	// swap�� ���� �ӽ� ��ü�� �ٲٸ� �ذ� ����
	std::vector<int>().swap(v);
	std::cout << "size: " << v.size() << " capacity: " << v.capacity() << '\n';

	// [] �����ڿ� at() �Լ��� ����
	std::vector<int> v2;
	v2.push_back(10);
	v2.push_back(20);
	v2.push_back(30);
	//v2.at(3);	// ���� �˻�, out_of_range ���ܹ߻�
	//v2[3]		// ���� �˻� ����, �޸� ���� ���� �߻�

	// ������ iterator ��ȸ
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
	
	// ����
	std::vector<int> v3;
	v3.push_back(10);
	v3.push_back(20);
	v3.push_back(30);
	
	std::vector<int>::iterator itr = v3.begin();

	v3.insert(itr, 3, 100);
	// �޸𸮰� ���Ҵ�Ǳ� ������ iterator�� �ٽ� ����������Ѵ�.
	for (itr = v3.begin(); itr != v3.end(); ++itr)
	{
		std::cout << *itr << " ";
	}
	std::cout << '\n';

	// list
	// remove(), splice(), unique() ����

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
	lt2.splice(litr2, lt, lt.begin(), lt.end());	// litr2�� ����Ű�� ���� lt�� litr �������� ��� ���Ҹ� �߶����
	for (litr2 = lt2.begin(); litr2 != lt2.end(); ++litr2)
	{
		std::cout << *litr2 << " ";
	}
	std::cout << '\n';


}