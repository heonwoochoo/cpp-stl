// 함수 포인터를 이용한 콜백 메커니즘 구현
#pragma once
#include <iostream>

// Server
// 배열의 모든 원소에 반복적인 작업을 수행하게 추상화됨(구체적인 작업은 모름)
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
	std::cout << "정수 : " << n << '\n';
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