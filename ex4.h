#pragma once
#include <iostream>
#include <string>
template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

class Point
{
public:
	explicit Point(int x = 0, int y = 0): m_x(x), m_y(y) {}
	void Print() const { std::cout << m_x << " , " << m_y << std::endl; }

private:
	int m_x;
	int m_y;

};

template<typename T>
void Print(T a)
{
	std::cout << a << std::endl;
}

// 함수 템플릿 특수화
template<>
void Print(Point a)
{
	std::cout << "Print 특수화 버전: ";
	a.Print();
}


template<typename T>
class Array
{
public:
	explicit Array(int cap = 100) : buf(0), size(0), capacity(cap)
	{
		buf = new T[capacity];
	}
	~Array() { delete[] buf; }

private:
	T* buf;
	int size;
	int capacity;

public:
	void Add(T data)
	{
		buf[size++] = data;
	}

	T operator[] (int idx) const
	{
		return buf[idx];
	}

	int GetSize() const
	{
		return size;
	}
};

template<typename T>
class ObjectInfo
{
	T data;
	
public:
	ObjectInfo(const T& d) : data(d) {}

	void Print()
	{
		std::cout << "타입 : " << typeid(data).name() << '\n';
		std::cout << "크기 : " << sizeof(data) << '\n';
		std::cout << "값 : " << data << '\n';
		std::cout << '\n';
	}
};

template<>
class ObjectInfo<std::string>
{
	std::string data;

public:
	ObjectInfo(const std::string& d) : data(d) {}

	void Print()
	{
		std::cout << "타입 : std::string" << '\n';
		std::cout << "크기 : " << sizeof(data) << '\n';
		std::cout << "값 : " << data << '\n';
		std::cout << "문자열 길이 : " << data.size() << '\n';

		std::cout << '\n';
	}
};

template<typename IterT, typename Func>
void For_each(IterT begin, IterT end, Func pf)
{
	while (begin != end)
	{
		pf(*begin++);
	}
}

template<typename T>
struct PrintFunctor
{
	std::string sep;	// 출력 구분자 정보

	explicit PrintFunctor(const std::string& s = " "): sep(s){}

	void operator() (T data) const
	{
		std::cout << data << sep;
	}
};

template<typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
	Pair(const T1& ft, const T2& sd): first(ft), second(sd)
	{}
};

void Example()
{
	//int n1 = 10;
	//int n2 = 20;
	//Swap(n1, n2);
	//std::cout << n1 << " " << n2 << '\n';

	//int n = 10;
	//double d = 2.5;
	//Point pt(2, 3);

	//Print(n);
	//Print(d);
	//Print(pt);

	//Array<int> iarr;
	//iarr.Add(10);
	//iarr.Add(20);
	//iarr.Add(30);
	//for (int i = 0; i < iarr.GetSize(); ++i)
	//{
	//	std::cout << iarr[i] << " ";
	//}
	//std::cout << '\n';

	//Array<double> darr;
	//darr.Add(10.1);
	//darr.Add(20.2);
	//darr.Add(30.3);
	//for (int i = 0; i < darr.GetSize(); ++i)
	//{
	//	std::cout << darr[i] << " ";
	//}
	//std::cout << '\n';

	//Array<std::string> sarr;
	//sarr.Add("Choo");
	//sarr.Add("Heon");
	//sarr.Add("Woo");
	//for (int i = 0; i < sarr.GetSize(); ++i)
	//{
	//	std::cout << sarr[i] << " ";
	//}
	//std::cout << '\n';

	//ObjectInfo<int> d1(10);
	//d1.Print();

	//ObjectInfo<double> d2(20.3);
	//d2.Print();

	//ObjectInfo<std::string> s1("heonwoo");
	//s1.Print();

	//int arr[5] = { 10, 20, 30, 40, 50 };
	//For_each(arr, arr + 5, PrintFunctor<int>());
	//std::cout << '\n';

	//std::string sarr[3] = { "abc", "ABCED", "Hello" };
	//For_each(sarr, sarr + 3, PrintFunctor<std::string>("\n"));
	//std::cout << '\n';

	Pair<int, int> p1(10, 20);
	std::cout << p1.first << " , " << p1.second << '\n';

	Pair<int, std::string> p2(10, "choo");
	std::cout << p2.first << " , " << p2.second << '\n';
}