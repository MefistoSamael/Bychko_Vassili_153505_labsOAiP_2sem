#include <iostream>

template <typename T>
class Deque
{
public:
	class Iteratork;
private:
	const size_t k = 4;
	std::pair<T*, size_t*>* array;
	std::pair<size_t, size_t> Head, Tail;
	size_t array_size;
	size_t J;
public:
	Deque() : Head(0, 0),
		Tail(0, 0)
	{
		array_size = 1;
		array = new std::pair<T*, size_t*>[array_size];
		array[0].first = reinterpret_cast<T*>(new char[k * sizeof(T)]);
		array[0].second = new size_t(0);
	}


	~Deque()
	{
		for (Iteratork it = begin(); it != end(); ++it)
			(*it).~T();

		for (size_t i = 0; i < array_size; i++)
		{
			//чистим подмассивы
			delete[] reinterpret_cast<char*>(array[i].first);
			//чистим счетчики
			delete array[i].second;
		}
		delete[]array;
	}

	size_t get_size()
	{
		int i = 0;
		for (Iteratork it = begin(); it != end(); ++it, i++);

		return i;
	}

	bool is_empty()
	{
		return (Head == Tail);
	}

	void pop_back() {
		if (is_empty()) return;


		Iteratork it = end();
		--it;
		(*it).~T();

		//если хвост в начале дека
		if (Tail.first == 0 && Tail.second == 0)
		{
			Tail.first = array_size - 1;
			Tail.second = 3;
		}
		//если хвост в начале подмассива
		else if (Tail.second == 0)
		{
			Tail.first--;
			Tail.second = 3;
		}
		else
		{
			Tail.second--;
		}
	}

	void push_back(T value)
	{
		new (array[Tail.first].first + Tail.second) T(value);

		Tail.second++;
		if (Tail.second >= k)
		{
			Tail.first++;
			Tail.second = 0;

			if (Tail.first >= array_size)
			{
				Tail.first = 0;
			}
			if (Head.first == Tail.first)
			{
				resize(Head);
				Head.first = 0;
				Tail.first = J;
				array_size *= 2;
			}
		}
	}

	void pop_front()
	{
		if (is_empty()) return;


		Iteratork it = begin();
		(*it).~T();


		//если голова в конце дека
		if (Head.first == array_size - 1 && Head.second == 3)
		{
			Head.first = 0;
			Head.second = 0;
		}
		//если голова в конце подмассива
		else if (Head.second == 3)
		{
			Head.first++;
			Head.second = 0;
		}
		else
		{
			Head.second++;
		}
	}

	void push_front(T value)
	{
		std::pair<size_t, size_t> oldHead(Head);
		if (Head.second == 0)
		{
			Head.second = 3;
			if (Head.first == 0)
			{
				Head.first = array_size - 1;
			}
			else
			{
				Head.first--;
			}

			if (Head.first == Tail.first && Head.second >= Tail.second)
			{
				resize(oldHead);
				Tail.first = array_size - 1;
				array_size *= 2;
				Head.first = array_size - 1;
			}
		}
		else
		{
			Head.second--;
		}

		new (array[Head.first].first + Head.second) T(value);
	}

	void resize(std::pair<size_t, size_t> Head)
	{
		std::pair<T*, size_t*>* newarr = new std::pair<T*, size_t*>[array_size * 2];// это тоже страшно

		size_t j = 0;

		for (size_t i = Head.first; i < array_size; i++, j++)
		{
			newarr[j] = array[i];
			*newarr[j].second = j;
		}

		J = j;

		for (size_t i = 0; i < Head.first; i++, j++)
		{
			newarr[j] = array[i];
			*newarr[j].second = j;
		}

		for (size_t i = j; i < 2*array_size; i++)
		{
			newarr[i].first = reinterpret_cast<T*>(new char[k * sizeof(T)]);
			newarr[i].second = new size_t(i);
		}

		delete[]array;
		array = newarr;
	}

	void clear()
	{
		while (!is_empty())
			pop_back();
	}

	Iteratork begin()
	{
		Iteratork temp(&array, array[Head.first].second, Head.second, array_size);
		return temp;
	}

	Iteratork end()
	{
		Iteratork temp(&array, array[Tail.first].second, Tail.second, array_size);
		return temp;
	}

	T& PrintTail()
	{
		if (Tail.second == 0) return array[Tail.first - 1].first[3];
		return array[Tail.first].first[Tail.second - 1];
	}

	T& PrintHead()
	{
		return array[Head.first].first[Head.second];
	}

	class Iteratork
	{
		std::pair<T*, size_t*>** ptr_array;
		size_t* row;
		size_t column;
		size_t* size_arr;
		T* object;

	public:
		Iteratork()
		{
			ptr_array = nullptr;
			row = nullptr;
			column = 0;
			object = nullptr;
			size_arr = nullptr;
		}

		Iteratork(std::pair<T*, size_t*>** arr, size_t* row, size_t column, size_t& size)
		{
			ptr_array = arr;
			this->row = row;
			this->column = column;
			size_arr = &size;
			object = &((*ptr_array)[*this->row].first[this->column]); //страшно
		}

		Iteratork(const Iteratork& other)
		{
			*this = other;
		}

		Iteratork(Iteratork&& other) noexcept
		{
			*this = other;
		}

		bool operator ==(const Iteratork& other) const noexcept
		{
			return this->object == other.object;
		}

		bool operator !=(const Iteratork& other) const noexcept
		{
			return !(this->object == other.object);
		}

		Iteratork& operator =(Iteratork& other)
		{
			this->ptr_array = other.ptr_array;
			this->row = other.row;
			this->column = other.column;
			this->object = other.object;
			this->size_arr = other.size_arr;
			return *this;
		}

		Iteratork& operator++()
		{
			if (column == 3)
			{
				column = 0;
				if (*row == *size_arr - 1)
				{
					row = (*ptr_array)[0].second;
				}
				else
				{
					row = (*ptr_array)[*row + 1].second;
				}
				object = &((*ptr_array)[*this->row].first[this->column]);
			}
			else
			{
				column++;
				object++;
			}
			return *this;
		}

		Iteratork& operator--()
		{
			if (column == 0)
			{
				column = 3;

				if (*row == 0)
				{
					row = (*ptr_array)[*size_arr - 1].second;
				}
				else
				{
					row = (*ptr_array)[*row - 1].second;
				}
				object = &((*ptr_array)[*this->row].first[this->column]);
			}
			else
			{
				column--;
				object--;
			}

			return *this;
		}

		T& operator*() const noexcept { return *object; }

		T* operator->() const noexcept { return object; }
	};
};

