#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range

template<typename T>
struct equal {
	bool operator()(const T &a, const T &b) const{
		return a == b;
	}
};

template<typename T>
struct less_than {
	bool operator()(const T &a, const T &b) const{
		return a < b;
	}
}

struct bino {
	int no;
	int yes;

	bool operator==(const bino &b) {}

	bool operator<(const bino &b) {}
}

/**
	@file main.cpp File di test di dbuffer
**/	
int main() {
	// stack<int> s;
	// stack<int> s1(22);
	stack<int> s2(4, 42);
	// stack<int> s3(s2);
	// stack<int> s5 = s2;
	// s5.bino(s1.begin(), s1.end());
	s2.clear();
	s2.push(1);
	s2.push(2);
	s2.push(3);
	s2.push(4);
	// s.swap(s3);
	stack<int> s4(s2.begin(), s2.end());
	// std::cout << s2.size() << std::endl;
	// stack<int>::const_iterator a = s2.begin();
	// std::cout << *a << std::endl;
	// stack<int>::const_iterator b = s2.end();
	// std::cout << *b << std::endl;

	stack<bino> s1000(10, { a: 1, yes: "ok" });

	int a = 1;

	bino b = { a: 1, yes: "no" };

	s4.removeif(equal<bino>(), 2);

	for (stack<int>::const_iterator i = s4.begin(); i != s4.end(); ++i){
		std::cout << "nel for" << std::endl;
		std::cout << *i << std::endl;
	}

	return 0;
}
