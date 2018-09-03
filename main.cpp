#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range
/**
	@file main.cpp File di test di dbuffer
**/	
int main() {
	stack<int> s;
	stack<int> s1(22);
	stack<int> s2(4, 42);
	stack<int> s3(s2);
	// stack<int> s4(s2.begin(), s2.end()); // BAD_ALLOC
	stack<int> s5 = s2;
	// s5.bino(s1.begin(), s1.end());
	s2.clear();
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	s.swap(s3);
	std::cout << s2.size() << std::endl;
	stack<int>::const_iterator a = s2.begin();
	std::cout << *a << std::endl;
	stack<int>::const_iterator b = s2.end();
	std::cout << *b << std::endl;
	for (stack<int>::const_iterator i = s2.begin(); i != s2.end(); ++i){
		stack<int>::const_iterator c = i;
		std::cout << "nel for" << std::endl;
		std::cout << *c << std::endl;
	}
	return 0;
}
