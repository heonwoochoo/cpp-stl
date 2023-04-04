#pragma once
#include <iostream>
#include <set>

void Example()
{
	// set : ������ �ߺ��� ������� �ʴ´�

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

	// insert�� ��ȯ���� ������.
	if (s1.insert(1).second == false)
	{
		std::cout << "���Ұ� �̹� ����\n";
	}

	// ���� ������ �ٲ� ���� �ִ�
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

	// find : ���Ҹ� ã�� ��� �ش� ��ġ�� iterator�� ��ȯ, ��ã���� iterator�� end ��ġ�� ��ȯ
	auto s2_itr = s2.find(30);
	if (s2_itr != s2.end())
	{
		std::cout << *s2_itr << '\n';
	}

	// lower_bound() : ���Ұ� �����ϴ� ��ġ�� �ݺ���
	// upper_bound() : ���Ұ� ������ ��ġ�� �ݺ��� (������ ������ ����Ű�� �ݺ���)
	// equal_range() : ���۰� �� �κ��� �ݺ��ڸ� pair�� ��ȯ

	int v = 30;
	auto lower_itr = s2.lower_bound(v);
	auto upper_itr = s2.upper_bound(v);
	auto equal_itr = s2.equal_range(v);

	std::cout << "*lower_itr : " << *lower_itr << '\n';
	std::cout << "*upper_itr : " << *upper_itr << '\n';
	std::cout << "*equal_itr : " << *equal_itr.first << "," << *equal_itr.second << '\n';

}