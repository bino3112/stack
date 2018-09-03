#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range
/**
	@file main.cpp File di test di dbuffer
**/	
int main() {
	stack<int> s;
	stack<int> s1(22);
	stack<int> s2(3, 42);
	stack<int> s3(s2);
	std::cout << s3.size() << std::endl;
	for (unsigned int i = s3.size(); i > 0; --i)
	{
		std::cout << "STACK s3" << std::endl;
		std::cout << s3.pop() << std::endl;
	}
	// stack<int> s4(s2.begin(), s2.end()); // BAD_ALLOC
	stack<int> s5 = s2;
		for (unsigned int i = s5.size(); i > 0; --i)
	{
		std::cout << "STACK s5" << std::endl;
		std::cout << s5.pop() << std::endl;
	}
	// s5.bino(s1.begin(), s1.end());
	// s.clear();
	// s2.pop();
	// s2.push(22);
	// s2.size();
	// s.swap(s2);
	// s2.begin();
	// s2.end();
	for (stack<int>::const_iterator i = s2.begin(); i != s2.end(); ++i){
		std::cout << "bino" << std::endl;
	}
	return 0;
}
