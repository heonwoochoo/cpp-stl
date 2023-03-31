// �Լ� �����͸� �̿��� �ݹ� ��Ŀ���� ����
#pragma once
#include <iostream>

// Server
// �迭�� ��� ���ҿ� �ݺ����� �۾��� �����ϰ� �߻�ȭ��(��ü���� �۾��� ��)
void For_each(int* begin, int* end, void (*pf)(int))
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

// Client
void Print(int n)
{
	std::cout << n << '\n';
}

void Print2(int n)
{
	std::cout << n*n << '\n';
}

void Print3(int n)
{
	std::cout << "���� : " << n << '\n';
}

void Example()
{
	int arr[5] = { 10, 20, 30, 40, 50 };

	For_each(arr, arr + 5, Print);
	std::cout << '\n';
	For_each(arr, arr + 5, Print2);
	std::cout << '\n';
	For_each(arr, arr + 5, Print3);
	std::cout << '\n';
}