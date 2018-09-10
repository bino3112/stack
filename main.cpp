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
	cpu() : _clock(0), _core_count(0) {}

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
	os << "cpu(";
	os << procio._clock << ", ";
	os << procio._core_count;
	os << ")";
	return os;
}

void test_metodi_tipi_primitivi(){
	std::cout << std::endl << "-----TEST STACK CON TIPI PRIMITIVI-----" << std::endl;
	stack<int> s1;
	stack<int> s2(5);
	stack<int> s3(4, 42);
	std::cout << "STACK DI 4 ELEMENTI TUTTI 42" << std::endl;
	for (stack<int>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<int> s4 = s3;
	std::cout << "STACK DI 4 ELEMENTI TUTTI 42 UTILIZZANDO operator=" << std::endl;
	for (stack<int>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<int> s5(s4);
	std::cout << "STACK DI 4 ELEMENTI TUTTI 42 UTILIZZANDO copy constructor" << std::endl;
	for (stack<int>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	s3.clear();
	s3.push(1);
	s3.push(2);
	s3.push(3);
	s3.push(4);
	stack<int> s6(s3.begin(), s3.end());
	std::cout << "STACK DI ELEMENTI int UTILIZZANDO COSTRUTTORE CON ITERATORI" << std::endl;
	for (stack<int>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI int dopo la pop" << std::endl;
	for (stack<int>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s2.clear();
	s2.push(10);
	s2.push(11);
	s2.push(12);
	s6.push(22);
	s6.fill(s2.begin(), s2.end());
	std::cout << "STACK DI ELEMENTI int UTILIZZANDO METODO fill" << std::endl;
	for (stack<int>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI int dopo la pop" << std::endl;
	for (stack<int>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<int> s7;
	s7.push(1);
	s7.push(2);
	s7.push(3);
	s7.push(4);
	s7.push(5);
	std::cout << "capacità massima stack s7 = " << s7.capacity() << std::endl;
	std::cout << "numero di elementi nello stack s7 = " << s7.size() << std::endl;
	std::cout << "STACK DI ELEMENTI int prima del removeif(equal<int>(5))" << std::endl;
	for (stack<int>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(equal<int>(5));
	std::cout << "STACK DI ELEMENTI int dopo il removeif(equal<int>(5))" << std::endl;
	for (stack<int>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "STACK DI ELEMENTI int prima del removeif(less_than<int>(3))" << std::endl;
	for (stack<int>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(less_than<int>(3));
	std::cout << "STACK DI ELEMENTI int dopo il removeif(less_than<int>(3))" << std::endl;
	for (stack<int>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<int> s8(2, 22);
	std::cout << "TEST pop() su stack svuotato" << std::endl;
	for (int i = s8.size(); i >= 0; --i)	{	
		std::cout << s8.pop() << std::endl;
	}
}

void test_metodi_standard_library(){
	std::cout << std::endl << "-----TEST STACK CON TIPI DELLA STANDARD LIBRARY-----" << std::endl;
	stack<std::string> s1;
	stack<std::string> s2(5);
	stack<std::string> s3(4, "ciao");
	std::cout << "STACK DI 4 ELEMENTI TUTTI \"ciao\"" << std::endl;
	for (stack<std::string>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<std::string> s4 = s3;
	std::cout << "STACK DI 4 ELEMENTI TUTTI \"ciao\" UTILIZZANDO operator=" << std::endl;
	for (stack<std::string>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<std::string> s5(s4);
	std::cout << "STACK DI 4 ELEMENTI TUTTI \"ciao\" UTILIZZANDO copy constructor" << std::endl;
	for (stack<std::string>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	s3.clear();
	s3.push("Ferrari");
	s3.push("Porshce");
	s3.push("Lamborghini");
	s3.push("Toyota");
	stack<std::string> s6(s3.begin(), s3.end());
	std::cout << "STACK DI ELEMENTI std::string UTILIZZANDO COSTRUTTORE CON ITERATORI" << std::endl;
	for (stack<std::string>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI std::string dopo la pop" << std::endl;
	for (stack<std::string>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s2.clear();
	s2.push("BOXER");
	s2.push("V6");
	s2.push("V12");
	s6.push("ELETTRICO");
	s6.fill(s2.begin(), s2.end());
	std::cout << "STACK DI ELEMENTI std::string UTILIZZANDO METODO fill" << std::endl;
	for (stack<std::string>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI std::string dopo la pop" << std::endl;
	for (stack<std::string>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<std::string> s7;
	s7.push("GT86");
	s7.push("F40");
	s7.push("458 Italia");
	std::cout << "capacità massima stack s7 = " << s7.capacity() << std::endl;
	std::cout << "numero di elementi nello stack s7 = " << s7.size() << std::endl;
	std::cout << "STACK DI ELEMENTI std::string prima del removeif(equal<std::string>(\"F40\"))" << std::endl;
	for (stack<std::string>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(equal<std::string>("F40"));
	std::cout << "STACK DI ELEMENTI std::string dopo il removeif(equal<std::string>(\"F40\"))" << std::endl;
	for (stack<std::string>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "STACK DI ELEMENTI std::string prima del removeif(less_than<std::string>(\"488 GTB\"))" << std::endl;
	for (stack<std::string>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(less_than<std::string>("CIAO5"));
	std::cout << "STACK DI ELEMENTI std::string dopo il removeif(less_than<std::string>(\"488 GTB\"))" << std::endl;
	for (stack<std::string>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<std::string> s8(2, "prova");
	std::cout << "TEST pop() su stack svuotato" << std::endl;
	for (int i = s8.size(); i >= 0; --i)	{	
		std::cout << s8.pop() << std::endl;
	}
}

void test_metodi_tipi_generici(){
	std::cout << std::endl << "-----TEST STACK CON TIPI GENERICI-----" << std::endl;
	stack<cpu> s1;
	stack<cpu> s2(5);
	stack<cpu> s3(4, cpu(4.4, 6));
	std::cout << "STACK DI 4 ELEMENTI TUTTI cpu(4.4, 6)" << std::endl;
	for (stack<cpu>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<cpu> s4 = s3;
	std::cout << "STACK DI 4 ELEMENTI TUTTI cpu(4.4, 6) UTILIZZANDO operator=" << std::endl;
	for (stack<cpu>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<cpu> s5(s4);
	std::cout << "STACK DI 4 ELEMENTI TUTTI cpu(4.4, 6) UTILIZZANDO copy constructor" << std::endl;
	for (stack<cpu>::const_iterator i = s3.begin(); i != s3.end(); ++i){
		std::cout << *i << std::endl;
	}
	s3.clear();
	s3.push(cpu(0.5, 2));
	s3.push(cpu(2, 1));
	s3.push(cpu(3.5, 6));
	s3.push(cpu(4.8, 4));
	stack<cpu> s6(s3.begin(), s3.end());
	std::cout << "STACK DI ELEMENTI cpu UTILIZZANDO COSTRUTTORE CON ITERATORI" << std::endl;
	for (stack<cpu>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI cpu dopo la pop" << std::endl;
	for (stack<cpu>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s2.clear();
	s2.push(cpu(2.4, 1));
	s2.push(cpu(2, 6));
	s2.push(cpu(4.8, 4));
	s6.push(cpu(1, 1));
	s6.fill(s2.begin(), s2.end());
	std::cout << "STACK DI ELEMENTI cpu UTILIZZANDO METODO fill" << std::endl;
	for (stack<cpu>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	s6.pop();
	std::cout << "STACK DI ELEMENTI cpu dopo la pop" << std::endl;
	for (stack<cpu>::const_iterator i = s6.begin(); i != s6.end(); ++i){
		std::cout << *i << std::endl;
	}
	stack<cpu> s7;
	s7.push(cpu(1.5, 1));
	s7.push(cpu(2.3, 2));
	s7.push(cpu(3, 4));
	s7.push(cpu(2.5, 8));
	s7.push(cpu(1.8, 6));
	s7.push(cpu(4.4, 4));
	s7.push(cpu(1.5, 1));
	s7.push(cpu(2.8, 4));
	s7.push(cpu(3.5, 6));
	std::cout << "capacità massima stack s7 = " << s7.capacity() << std::endl;
	std::cout << "numero di elementi nello stack s7 = " << s7.size() << std::endl;
	std::cout << "STACK DI ELEMENTI cpu prima del removeif(equal<cpu>(cpu(1.5, 1)))" << std::endl;
	for (stack<cpu>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(equal<cpu>(cpu(1.5, 1)));
	std::cout << "STACK DI ELEMENTI cpu dopo il removeif(equal<cpu>(cpu(1.5, 1)))" << std::endl;
	for (stack<cpu>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "STACK DI ELEMENTI cpu prima del removeif(less_than<cpu>(cpu(4.1, 4)))" << std::endl;
	for (stack<cpu>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	s7.removeif(less_than<cpu>(cpu(4.1, 4)));
	std::cout << "STACK DI ELEMENTI cpu dopo il removeif(less_than<cpu>(cpu(4.1, 4)))" << std::endl;
	for (stack<cpu>::const_iterator i = s7.begin(); i != s7.end(); ++i){
		std::cout << *i << std::endl;
	}
	std::cout << "TEST pop() su stack svuotato" << std::endl;
	stack<cpu> s8(2, cpu(1,1));
	for (int i = s8.size(); i >= 0; --i)	{	
		std::cout << s8.pop() << std::endl;
	}
}


int main() {
	test_metodi_tipi_primitivi();
	test_metodi_standard_library();
	test_metodi_tipi_generici();

	return 0;
}
