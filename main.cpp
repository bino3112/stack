#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range

template<typename T>
struct equal {
	explicit equal(const T &parameter) : _parameter(parameter) {}

	bool operator()(const T &a) const{
		return a == _parameter;
	}

private: 
	equal() {}

	const T _parameter;
};

template<typename T>
struct less_than {
	explicit less_than(const T &parameter) : _parameter(parameter) {}

	bool operator()(const T &a) const{
		return a < _parameter;
	}

private:
	less_than() {}

	const T _parameter;
};

struct cpu {
	cpu() {}

	cpu(const double clock, const int core_count) : _clock(clock), _core_count(core_count) {}

	bool operator==(const cpu &b) const{
		return _clock == b._clock && _core_count == b._core_count;
	}

	bool operator<(const cpu &b) const{
		return (_clock*_core_count) < (b._clock*b._core_count);
	}
private:
	

	friend std::ostream& operator<<(std::ostream &os, const cpu &procio);
	double _clock;
	int _core_count;
};

std::ostream& operator<<(std::ostream &os, const cpu &procio) {
	os << procio._clock << ", ";
	os << procio._core_count;
	return os;
}

int main() {
	// stack<int> s;
	// stack<int> s1(22);
	stack<int> s2(4, 42);
	// stack<int> s3(s2);
	// stack<int> s5 = s2;
	// s5.fill(s1.begin(), s1.end());
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

	cpu b(4.40, 8);
	cpu a(3.50, 6);

	stack<cpu> s1000(10, cpu(0.5, 2));
	s1000.push(a);

	s1000.removeif(less_than<cpu>(cpu(0.6, 2)));

	for (stack<cpu>::const_iterator i = s1000.begin(); i != s1000.end(); ++i){
		std::cout << "nel for" << std::endl;
		std::cout << *i << std::endl;
	}

	return 0;
}
