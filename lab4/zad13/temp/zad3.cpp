

//рассказать про reinterpret_cast - где его можно использовать



#pragma once

#include <stdexcept> //std::out_of_range
#include <iostream>
#include <initializer_list> // для std::initializer_list
#include <memory>
#include <algorithm>
#include <iterator>
#include "MyPair.h"


template <typename T>
class iterator
{
	//конструкторы
public:
	iterator() : ptr(nullptr) {}
	iterator(T* p) : ptr(p) {}
	iterator(const T& other) : ptr(other.ptr) {}

	//булевое сравнение итераторов
	friend bool operator !=(iterator const& a, iterator const& b)
	{
		return a.ptr != b.ptr;
	}
	friend bool operator == (iterator const& a, iterator const& b)
	{
		return a.ptr == b.ptr;
	}
	friend bool operator > (iterator const& a, iterator const& b)
	{
		return a.ptr > b.ptr;
	}
	friend bool operator < (iterator const& a, iterator const& b)
	{
		return a.ptr < b.ptr;
	}
	friend bool operator >= (iterator const& a, iterator const& b)
	{
		return a.ptr >= b.ptr;
	}
	friend bool operator <= (iterator const& a, iterator const& b)
	{
		return a.ptr <= b.ptr;
	}

	//обращение к элементам итератора
	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	//операторы инкремента и декремента
	iterator operator++(int) {
		iterator<T> temp = *this;
		++(*this);
		return temp;
	}
	iterator operator--(int) {
		iterator<T> temp = *this;
		--(*this);
		return temp;
	}
	iterator& operator++() {
		ptr++;
		return *this;
	}
	iterator& operator--() {
		ptr--;
		return *this;
	}
	iterator operator+ (int number) {
		iterator<T> temp = *this;
		temp.ptr += number;
		return temp;
	}
	iterator operator- (int number) {
		iterator<T> temp = *this;
		temp.ptr -= number;
		return temp;
	}
	iterator& operator+= (int number) {
		ptr += number;
		return *this;
	}
	iterator& operator-= (int number) {
		ptr -= number;
		return *this;
	}



	//итератор минус итератор
	friend int operator-(const iterator& first, const iterator& second) {
		return first.ptr - second.ptr;
	}

private:
	T* ptr;
};


template <typename T>
class MyVector
{
private:

	T* arr;

	//память выделенная под вектор
	size_t capacity;

	//количество эллементов в векторе
	size_t size;

public:

	MyVector() : capacity(1), size(0) {
		arr = reinterpret_cast<T*>(new char[sizeof(T)]);

		new(arr) T();

	}

	//для  инициалицазии фигурных скобочек
	MyVector(std::initializer_list<T> list) {
		capacity = 1;
		size = 0;
		arr = reinterpret_cast<T*>(new char[sizeof(T)]);

		for (auto element : list) {
			push_back(element);//!
		}
	}

	MyVector(size_t count) : capacity(count), size(count) {
		arr = reinterpret_cast<T*>(new char[count * sizeof(T)]);

		for (int i = 0; i < capacity; i++)
			new (arr + i) T();
	}

	MyVector(const MyVector& other) : capacity(other.capacity), size(other.size) {
		arr = reinterpret_cast<T*>(new char[capacity * sizeof(T)]);

		for (size_t i = 0; i < size; i++)
			new (arr + i) T(other.arr[i]);

	}

	~MyVector() {
		for (int i = 0; i < size; i++)
			(arr + i)->~T();

		delete[] reinterpret_cast<char*> (arr);


	}


	
	void assign(size_t count, const T& value) {
		clear();

		for (int i = 0; i < count; i++)
			push_back(value);
	}

	template< class InputIt>
	void assign(InputIt first, InputIt last) {
		clear();

		for (; first != last; first++)
			push_back(*first);

	}

	void assign(std::initializer_list<T> ilist) {
		clear();

		for (auto element : ilist)
			push_back(element);
	}

	iterator<T> erase(iterator<T> pos) {
		/*if (pos == end()) {
			pop_back();
			return end();
		}*/

		//что возвращаем
		iterator<T> toRerturn = pos;
		//сдвигаем на элемент в право, т.к. 
		//возвращаем след. за удаляемым
		toRerturn++;

		iterator<T> temp = pos;
		temp++;
		while (temp != end())
		{
			*pos = *temp;
			pos++;
			temp++;
		}

		pop_back();
		return toRerturn;
	}

	iterator<T> erase(iterator<T> first, iterator<T> last) {
		iterator<T> toReturn = nullptr;

		if (last != end()) {
			toReturn = last + 1;
		}


		//производим замену элементов
		while (last != end())
		{
			*first = *last;
			first++;
			last++;
		}

		//производим удаление лишних элементов
		while (first != end())
		{
			pop_back();
		}

		if (toReturn != nullptr)
			return toReturn;
		else return end();


	}

	T& back() {
		return arr[size - 1];
	}

	T* data() {
		return arr;
	}

	void clear() {
		while (size != 0)
			pop_back();
	}

	size_t get_capacity() const
	{
		return capacity;
	}

	size_t get_size() const
	{
		return size;
	}

	void reserve(size_t n)
	{
		//T* newarr = new T[n] плоха тем,что конструктора по умолчанию может не быть и
		//мы создаем n объектов типа T, а потом их переприсваиваем
		//при вызове reserv мы не хотим создавать объекты, а лишь зарезервировать 
		//память под них


		//наивная реализация
		/*
			if (n <= capacity)
			{
				return;
			}
			T* newarr = new T[n];
			for (size_t i = 0; i < size; i++)
			newarr[i] = arr[i];
			delete[]arr;
			arr = newarr;
			cap = n;
		*/
		if (n <= capacity)
		{
			return;
		}

		//написав следующую строку мы для newarr выделили 
		//сырую последовательность битов и сказали обращаться с ней
		//как с указателем на T
		T* newarr = reinterpret_cast<T*>(new char[n * sizeof(T)]);
		//reinterpret_cast <new_type> (expression) это прямое указание компилятору
		//обращаться с некоторой последовательностью битов, являющихся 
		//результатом выражения (expression), так будто это объект типа T*
		size_t i = 0;

		//реализация безопасности от исключений
		//если будет выброшен exception при вызове конструктора копирования -
		//подтираем все что успели занести и vector остается неизменным
		try {
			for (; i < size; i++) {
				//newarr[i] = arr[i] недопустимо в данной ситуации, т.к. через 
				//reinterpret_cast была создана сырая последовательность битов в котором
				//newarr не создан
				new (newarr + i) T(arr[i]); //placement new
				//!	 воткунуть сюда std::cout << newarr + i
				//!  чтобы глянуть какой адрес будет возвращаться
				//использовав данну конструкцию мы по адресу (newarr + i)
				// создали объект T от параметров arr[i]
				//можно сказать, что это явный вызов конструктора по
				//данному адресу
			}
		}
		catch (...) {
			for (size_t j = 0; j < i; ++j) {
				(newarr + i)->~T();
			}
			delete[] reinterpret_cast<char*>(newarr);
			throw;
		}

		/*for (size_t i = size; i < n; i++)
			new (newarr + i) T();*/

		//если написать delete[]arr
		//то будет вызван деструктор от элементов, для которых
		//не был вызван конструктор
		for (size_t i = 0; i < size; i++) {
			(arr + i)->~T();
		}

		//такая запись необходима, чтобы деструкторы не вызывались второй раз 
		delete[] reinterpret_cast<char*>(arr);
		arr = newarr;
		capacity = n;
	}

	void resize(size_t n, const T& value = T())
	{
		if (n > capacity) reserve(n);
		size_t i = size;
		try {
			for (; i < n; ++i) {
				new (arr + i) T(value);
			}
		}
		catch (...) {
			for (size_t j = size; j < i; j++) {
				(arr + i)->~T();
			}

			delete[] reinterpret_cast<char*>(arr);
			throw;
		}

		size = n;
	}

	void push_back(const T& value)
	{
		if (capacity == size)
		{
			reserve(2 * size);
		}

		//в обработке этого исключения я не уверен
		try {
			new(arr + size) T(value);
			++size;
		}
		catch (...)
		{
			throw;
		}

	}

	T& front() {
		return arr[0];
	}

	bool empty() {
		return size == 0;
	}

	void pop_back() {
		--size;
		(arr + size)->~T();
	}

	//вставляет value перед pos
	iterator<T> insert(iterator<T> pos, const T& value) {

		int index = pos - begin();

		if (size == capacity) reserve(2 * capacity);

		pos = begin() + index;

		new (arr + size) T();
		T temp = *pos;
		T temp2;
		*pos = value;
		iterator<T> toReturn = pos;

		size++;
		pos++;
		while (pos != end())
		{
			temp2 = *pos;
			*pos = temp;
			pos++;
			temp = temp2;
		}

		return toReturn;
	}

	template <class ... Args>
	iterator<T> emplace(iterator<T> pos, Args&& ... args) {

		T temp(std::forward<Args>(args)...);
		return insert(pos, temp);
	}

	template <class ... Args>
	iterator<T> emplace_back(Args&& ... args) {

		T temp(std::forward<Args>(args)...);
		return insert(end(), temp);
	}

	void swap(MyVector& other) {
		auto temp = arr;
		arr = other.arr;
		other.arr = temp;


		size_t tempCapacity = capacity;
		size_t tempSize = size;
		capacity = other.capacity;
		size = other.size;
		other.capacity = tempCapacity;
		other.size = tempSize;

	}


	T& operator[](size_t i) {
		return arr[i];
	}

	T& at(size_t i) {
		if (i >= size)
			throw std::out_of_range("...");
		return arr[i];
	}
	const T& operator[](size_t i) const {
		return arr[i];
	}


	const T& at(size_t i) const {
		if (i >= size)
			throw std::out_of_range("...");
		return arr[i];
	}

	unsigned long long max_size() {
		//доступное количество памяти 
		long double degree = 8 * sizeof(size_t);

		//почему то для типов размером в единицу дается в два раза меньше 
		//чем 2 в степени разрядность системы
		if (sizeof(T) == 1) {
			unsigned long long a = powl(2, degree) / 2;
			//танцы с бубном ибо -1 не работает
			int b = a % 10;
			a /= 10;
			a *= 10;
			a += b - 1;
			return a;
		}
		else {
			unsigned long long a = powl(2, degree) / sizeof(T);
			//танцы с бубном ибо -1 не работает
			int b = a % 10;
			a /= 10;
			a *= 10;
			a += b - 1;
			return a;
		}


	}

	MyVector& operator=(const MyVector& other) {
		for (size_t i = 0; i < size; i++)
			(arr + i)->~T();

		delete[] reinterpret_cast<char*>(arr);

		capacity = other.capacity;
		size = other.size;
		arr = reinterpret_cast<T*>(new char[capacity * sizeof(T)]);

		for (size_t i = 0; i < size; i++)
			new (arr + i) T(other.arr[i]);

		return *this;
	}


	bool operator==(const MyVector& other)
	{
		if (size != other.size)
			return false;

		iterator<T> s1 = begin();
		iterator<T> s2 = other.begin();

		while (s1 != end())
		{
			if (*s1 != *s2)
				return false;

			s1++;
			s2++;
		}

		return true;
	}

	bool operator!=( MyVector& other)
	{
		return !(*this == other);
	}

	bool operator>( MyVector& other)
	{
		size_t min = (size < other.size) ? size : other.size;

		iterator<T> s1 = begin();
		iterator<T> s2 = other.begin();

		size_t i = 0;

		while (i < min)
		{
			if (*s1 > *s2)
				return true;

			if (*s1 < *s2)
				return false;

			i++;
			s1++;
			s2++;
		}

		if (size > other.size)
			return true;

		return false;
	}

	bool operator<(const MyVector& other)
	{
		return (!(*this > other) && *this != other);
	}

	bool operator>=(const MyVector& other)
	{
		return ((*this > other) || *this == other);
	}

	bool operator<=(const MyVector& other)
	{
		return ((*this < other) || *this == other);
	}

























	iterator<T> begin() {
		return iterator<T>(arr);
	}

	iterator<T> end() {
		return iterator<T>(arr + size);
	}

	//тут я не уверен в правильности реализации
	const iterator<T> cbegin() const {
		return  iterator<T>(arr);
	}

	//тут я не уверен в правильности реализации
	const iterator<T> cend() const {
		return iterator<T>(arr + size);
	}

	iterator<T> rbegin() {
		return iterator<T>(arr + size);
	}

	iterator<T> rend() {
		return iterator<T>(arr);
	}

	//тут я не уверен в правильности реализации
	const iterator<T> crbegin() const {
		return iterator<T>(arr + size);
	}

	//тут я не уверен в правильности реализации
	const iterator<T> crend() const {
		return iterator<T>(arr);
	}

};

typedef MyVector<int> vi;

int B = 1;
const int fm = (1 << B) - 1;

void norm(MyVector<int>& c) {
	for (int i = 0; i < c.get_size() - 1; ++i) {
		c[i + 1] += c[i] >> B;
		c[i] &= fm;
	}
}

void trim(vi& c, int x) {
	c.resize(x / B + 1);
	c[x / B] &= (1 << (x % B)) - 1;
}

vi add(const vi& a, const vi& b, int k) {
	vi c(std::max(a.get_size(), b.get_size()) + 1);
	for (int i = 0; i < c.get_size(); ++i) {
		if (i < a.get_size()) c[i] += a[i];
		if (i < b.get_size()) c[i] += b[i];
	}
	norm(c);
	trim(c, k);
	return c;
}

int get_bit(const vi& v, int b) {
	return (v[b / B] >> (b % B)) & 1;
}

MyVector<int> mul(const vi& a, int x, int k)
{
	MyVector<int> b = a;
	b.push_back(0);
	for (int i = 0; i < b.get_size(); ++i) b[i] *= x;
	norm(b);
	trim(b, k);
	return b;
}

template <typename T>
void Reverse(iterator<T> start, iterator<T> end)
{
	MyVector<T> tmp;
	iterator<T> buf = end;

	while (start != end)
	{
		end--;

		tmp.push_back(*end);
	}

	int i = 0;

	while (start != buf)
	{
		*start = tmp[i];

		i++;
		start++;
	}
}


template <typename T>
void Qsort(iterator<T> start, iterator<T> end)
{
	iterator<T> i = start;
	iterator<T> j = end;

	T temp;

	iterator<T> C;

	iterator<T> ts = start;
	iterator<T> te = end;

	while (1)
	{
		if (te >= ts)
		{
			C = ts;
			break;
		}

		ts++;
		te--;
	}

	while (i <= j)
	{
		while (*i < *C) i++;
		while (*j > *C) j--;

		if (i <= j)
		{
			if (*i > *j)
			{
				temp = *i;
				*i = *j;
				*j = temp;
			}

			i++; j--;
		}
	};

	if (start < j) Qsort(start, j);
	if (i < end) Qsort(i, end);
}
void gen(MyVector<int> n, const MyVector<MyVector<int>>& p, int k, int i, MyVector<Pair<int, MyVector<int>> >& v) {
	if (i == k) {
		n.resize(k + 1);
		if (get_bit(n, k)) v.push_back(make_Pair(k, n));
		return;
	}
	if (get_bit(n, i)) return;
	gen(n, p, k, i + 1, v);
	if (i) gen(add(n, p[i], k + 1), p, k, i + 1, v);
}

void print(const vi& v, int k) {
	for (int i = k; i >= 0; --i) std::cerr << get_bit(v, i);
	std::cerr << '\n';
}

int main() {
	int n; std::cin >> n;
	if (n == 1) {
		std::cout << "1\n";
		return 0;
	}
	--n;

	MyVector<Pair<int, MyVector<int>> > v;
	for (int k = 1; n / 2 >= v.get_size(); ++k) {
		MyVector<int> vekt(k / B + 1);
		vekt[k / B] = 1 << (k % B);
		MyVector<MyVector<int>> p(k + 1);
		p[0].push_back(1);
		trim(p[0], k + 1);
		for (int i = 0; i < k; ++i) p[i + 1] = mul(p[i], 10, k + 1);
		gen(vekt, p, k, 0, v);
	}
	for (int i = 0; i < v.get_size(); ++i) Reverse(v[i].second.begin(), v[i].second.end());
	Qsort(v.begin(), v.end());
	MyVector<int> w = v[--n / 2].second;
	Reverse(w.begin(), w.end());
	if (n & 1) w[0] ^= 1;
	for (int k = v[n / 2].first + 1 - 1; k >= 0; --k) std::cout << get_bit(w, k);
	std::cout << '\n';
	return 0;
}