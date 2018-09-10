#ifndef STACK_H
#define STACK_H

#include <ostream> // std::ostream
#include <iostream>
#include <cassert>
#include <algorithm>
#include <stdexcept>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t
#include <stdexcept>

/**
@file stack.h 
@brief Dichiarazione della classe stac
**/

/**
@brief Array dinamico di interi

Classe che rappresenta un array dinamico di interi. La dimensione puo' essere scelta in fase di
costruzione.
*/
template <typename T>
class stack {
public:
	typedef unsigned int size_type; ///< Definzione del tipo corrispondente a size

	typedef T value_type;

	class const_iterator;

	/**
		@brief Costruttore di default (METODO FONDAMENTALE)

		Costruttore di default per istanziare uno stack vuoto. E' l'unico costruttore
		che puo' essere usato per create un array di stack!
	*/
	stack() : _size(0), _stack(0), _capacity(0) { // initialization list
		#ifndef NDEBUG
		std::cout << "stack::stack()" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un stack con una data dimensione.
		@param size Dimensione del stack da istanziare 
	*/
	explicit stack(const size_type capacity) : _size(0), _stack(0), _capacity(0) {
		_stack = new T[capacity];
		_size = 0;
		_capacity = capacity;

		#ifndef NDEBUG
		std::cout << "stack::stack(size_type)" << std::endl;
		#endif
	}

	/**
		@brief Costruttore secondario

		Costruttore secondario. Permette di istanziare un stack con una data dimensione
		e di inizializzare le celle dell'array con il valore dato

		@param capacity Dimensione del stack da istanziare
		@param value Valore da usare per inizizalizzare le celle dell'array
	*/
	stack(const size_type capacity, const T &value) : _size(0), _stack(0), _capacity(0) {
		_stack = new T[capacity];
		_size = capacity;
		_capacity = capacity;

		try {
			for(size_type i = 0; i < _size; ++i)
				_stack[i] = value;
		}
		catch(...) {
			delete[] _stack;
			_size = 0;
			_stack = 0;
			_capacity= 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "stack::stack(size_type, T&)" << std::endl;
		#endif
	}

	/**
		@brief Copy constructor (METODO FONDAMENTALE)

		Costruttore di copia. Permette di istanziare un stack con i valori
		presi da un altro stack.
		@param other stack da usare per creare quello corrente
	*/
	stack(const stack &other) : _size(0), _stack(0), _capacity(0) {
		_stack = new T[other._capacity];
		_size = other._size;
		_capacity = other._capacity;

		try {
			for(size_type i = 0; i < _size; ++i)
				_stack[i] = other._stack[i];
		}
		catch(...) {
			delete[] _stack;
			_size = 0;
			_stack = 0;
			_capacity = 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "stack::stack(const stack&)" << std::endl;
		#endif
	}

	/**
		@brief Costruttore che prende una coppia di iteratori: uno che punta all’inizio
		di una sequenza di elementi e uno che punta alla fine della sequenza.

		@param begin iteratore che punta alla cima dello stack
		@param end iteratore che unta alla cella di memoria dopo l'ultimo elemento dello stack
	*/
	stack(const_iterator begin, const_iterator end) : _size(0), 
													  _stack(0), 
													  _capacity(0){
		_capacity = begin - end;
		_stack = new T[_capacity];
		_size = _capacity;
		
		try {
			int a = 0;
			for(const_iterator i = begin; i != end; ++i){
				_stack[a] = *i;
				++a;
			}
		}
		catch(...) {
			delete[] _stack;
			_size = 0;
			_stack = 0;
			_capacity = 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "stack::stack(const const_iterator, const const_iterator)" << std::endl;
		#endif
	}

	/**
		@brief Operatore di assegnamento (METODO FONDAMENTALE)

		Operatore di assegnamento. Permette la copia tra stack.
		@param other stack sorgente
		@return Riferimento a this
	*/
	stack &operator=(const stack &other) {
		if (this != &other) {
			// Proviamo a copiare i nuovi dati in un stack di appoggio
			// Se la copia fallisce, viene lanciata una eccezione e l'esecuzione
			// torna al chiamante (non la stiamo gestendo)  
			stack tmp(other);

			// Se la copia riesce, scambiamo i dati di this 
			// con quelli dello stack di appoggio
			this->swap(tmp);

			// All'uscita dell'if, tmp viene automaticamente distrutto e quindi vengono 
			//  rimossi i vecchi dati di this che ora si trovano dentro tmp!
		}

		#ifndef NDEBUG
		std::cout << "stack::operator=(const stack&)" << std::endl;
		#endif

		return *this;
	}

	/**
		@brief Distruttore (METODO FONDAMENTALE)

		Distruttore. Rimuove la memoria allocata da stack.
	*/
	~stack() {
		delete[] _stack;
		_stack = 0;
		_size = 0;
		_capacity = 0;

		#ifndef NDEBUG
		std::cout << "stack::~stack()" << std::endl;
		#endif
	}

	/**
		@brief Riempimeto dello stack tramite iteratori begin, end

		Riempe lo stack tramite iteratori begin, end
		@param L'iteratore che punta all'inizio
		@param L'iteratore che punta alla fine
	*/

	void fill(const const_iterator begin, const const_iterator end){
		if (_stack != 0)
			this->clear();
		stack tmp(begin, end);
		this->swap(tmp);
	}
	/**
		@brief Rimozione dell'elemento in cima allo stack

		Rimuove l'elemento in cima allo stack
		@return l'elemento in cima allo stack
	*/

	T pop(){
		if(_size > 0){
			T popped = _stack[_size-1];
			_stack[_size-1] = T(); // azzeramento locazione di memoria
			_size = _size-1;
			return popped;
		}
		else
			throw std::out_of_range("ok");
	}

	/**
		@brief Aggiunta di un elemento in cima allo stack

		Aggiunge l'elemento in cima allo stack
		@param L'elemento in cima allo stack
	*/
	void push(const T &value){
		if(_size == _capacity){
			if(_capacity != 0){
				stack tmp(*this, _capacity*2);
				tmp._stack[_size] = value;
				tmp._size++;
				this->swap(tmp);
			}
			else{
				stack tmp(*this, 1);
				tmp._stack[_size] = value;
				tmp._size++;
				this->swap(tmp);
			}
		}
		else{
			_stack[_size] = value;
			_size++;
		}
	}
	
	/**
		@brief Svuotamento dello stack

		Svuota lo stack
	*/
	void clear() {
		for (size_type i = _size; i > 0; --i)
			this->pop();
	}

	/**
		@brief Dimensione dell'array dinamico

		Ritorna la dimensione dell'array dinamico.
		@return La dimensione dell'array dinamico
	*/
	size_type capacity() const {
		return _capacity;
	}

	/**
		@brief Numero elementi dell'array

		Ritorna il numero di elementi contenuti nell'array
		@return Il numero di elementi contenuti nell'array
	*/
	size_type size() const {
		return _size;
	}

	template<typename P>
	void removeif(const P predicato) {
		stack tmp(_size);
		for(size_type i = _size; i > 0; --i){
			T popped = this->pop();
			if(!predicato(popped)){
				tmp.push(popped);
			}
		}
		this->fill(tmp.begin(), tmp.end());
	}

	/**
		@brief Scambia il contenuto di due stack

		Scambia il contenuto di due stack.
		@param other stack con il quale scambiare i dati 
	*/
	void swap(stack &other) {
		std::swap(other._stack, this->_stack);
		std::swap(other._size, this->_size);
		std::swap(other._capacity, this-> _capacity);
	}
	
	class const_iterator {
		const T *ptr;

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

		const_iterator() : ptr(0) {
		}
		
		const_iterator(const const_iterator &other)
			: ptr(other.ptr) {
		}

		const_iterator& operator=(const const_iterator &other) {
			ptr = other.ptr;
			return *this;
		}

		~const_iterator() {
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
			return *ptr;
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			return ptr;
		}

		// Operatore di iterazione post-incremento
		// (diminuisco perchè scorro _stack dalla fine all'inizio)
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			--ptr;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		// (diminuisco perchè scorro _stack dalla fine all'inizio)
		const_iterator& operator++() {
			--ptr;
			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return ptr == other.ptr;
		}

		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return ptr != other.ptr;
		}

		difference_type operator-(const const_iterator &other){
			return ptr - other.ptr;
		}

	private:
		friend class stack;

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T *p) : ptr(p) {
			}
		}; // classe const_iterator
		
		// Ritorna l'iteratore all'inizio della sequenza dati
		// (punta all'ultimo elemento perche l'inizio della pila è la fine di _stack)
		const_iterator begin() const {
			return const_iterator(_stack+_size-1);
		}
		
		// Ritorna l'iteratore alla fine della sequenza dati
		// (punta al primo elemento perchè la fine della pila è l'inzio di _stack)
		const_iterator end() const {
			return const_iterator(_stack-1);
		}

private:

	size_type _size; ///< Numero di elementi
	T *_stack; ///< Puntatore all'array di elementi
	size_type _capacity; ///< Dimensione dell'array

	/**
		@brief Costruttore privato utilizzato dalla funzione fill che 
		è come il copy constructor ma a cui passo una capacity differente
		
		@param other stack da usare per creare quello corrente
		@param capacity da usare invece di other._capacity
	*/
	stack(const stack &other, size_type capacity) : _size(0), 
													 _stack(0), 
													 _capacity(0) {
		_stack = new T[capacity];
		_size = other._size;
		_capacity = capacity;

		try {
			for(size_type i = 0; i < _size; ++i)
				_stack[i] = other._stack[i];
		}
		catch(...) {
			delete[] _stack;
			_size = 0;
			_stack = 0;
			_capacity = 0;
			throw;
		}

		#ifndef NDEBUG
		std::cout << "stack::stack(const stack&, size_type)" << std::endl;
		#endif
	}

}; // stack

#endif