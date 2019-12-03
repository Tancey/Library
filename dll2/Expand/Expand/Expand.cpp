// MathClient.cpp : Client app for MathLibrary DLL.
// #include "pch.h" Uncomment for Visual Studio 2017 and earlier
#include <iostream>
#include "windows.h"
//using namespace std;
int main()
{
	HMODULE hDLL = LoadLibrary(L"E:/Visual Studio IDE/Code/离散数学/MathLibrary/Debug/MathLibrary.dll");
	if (hDLL == NULL) {
		std::cout << "获取动态链接库失败";
		return 0;
	}
	typedef void(*PINIT)(const unsigned long long a, const unsigned long long b);
	PINIT fibonacci_init = (PINIT)GetProcAddress(hDLL, "fibonacci_init");
	typedef bool(*PINIT_1)();
	PINIT_1 fibonacci_next = (PINIT_1)GetProcAddress(hDLL, "fibonacci_next");
	typedef unsigned(*PINIT_2)();
	PINIT_2 fibonacci_index = (PINIT_2)GetProcAddress(hDLL, "fibonacci_index");
	typedef unsigned long long(*PINIT_3)();
	PINIT_3 fibonacci_current = (PINIT_3)GetProcAddress(hDLL, "fibonacci_current");

	// Initialize a Fibonacci relation sequence.
	if (fibonacci_init!=NULL)
	    fibonacci_init(1, 1);
	// Write out the sequence values until overflow.
	do {
		std::cout << fibonacci_index() << ": "
			<< fibonacci_current() << std::endl;
	} while (fibonacci_next());
	// Report count of values written before overflow.
	std::cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << std::endl;
	FreeLibrary(hDLL);
}