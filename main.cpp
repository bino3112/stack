#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range
/**
	@file main.cpp File di test di dbuffer
**/	
int main() {
	stack<int> s;
	stack<int> s1(22);
	stack<int> s2(22, 42);
	stack<int> s3(s2);
	stack<int> s4 = s2;
	s.clear();
	s.pop();
	s.push(22);
	s.size();
	s.swap(s2);
	s2.begin();
	s.end();
	for (stack<int>::const_iterator i = s2.begin(); i != s2.end(); ++i){
		std::cout << "bino" << std::endl;
	}
	return 0;
}
