#include "HW05_02_queue.h"

template<typename T>
Queue<T>::Queue(): _data(nullptr), _priority(nullptr), _size(0)
{
	cout << "Constructor Queue:\t" << this << endl;

}

template<typename T>
Queue<T>::Queue(const Queue& other)
{
	this->_siza = other._size;
	_data = new T[this->_siza];
	_data = new int[this->_siza];
	for (size_t i = 0; i < this->_size; i++)
	{
		_data[i] = other._data[i];
		this->_priority[i] = other._priority[i];

		cout << "Copy constructor:\t" << this << endl;
	}
}

template<typename T>
Queue<T>::Queue(Queue&& other)
{
	this->_data = other._data;
	this->_priority = other._priority;
	this->_size = other._size;
	other._data = nullptr; // Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._priority = nullptr;
	other._size = 0;

	cout << "Constructor movement:\t" << this << endl;
}

template<typename T>
Queue<T>::~Queue()
{
	if (_data != nullptr)
	{
		cout << "Destructor:\t _data " << this << endl;
		delete[] _data;
	}
	if (_priority != nullptr)
	{
		cout << "Destructor:\t _priority " << this << endl;
		delete[] _priority;
	}
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this == &other)	return *this;
	_size = other._size;
	_data = new T[_size];
	_priority = new int[this->_siza];

	for (size_t i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
		_priority[i] = other._priority[i];

	}
	cout << "Copy operator=:\t" << this << endl;
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue&& other)
{
	cout << "Operator assignment:\t" << this << endl;
	delete[] _data;
	delete[] _priority;
	_data = other._data;
	_priority = other._priority;
	_size = other._size;
	other._data = nullptr; // Присвоить указателю nullpter что бы деструктор лишний раз не срабатывал
	other._capacity = nullptr;
	other._size = 0;
	return *this;
}
template<typename T>
bool Queue<T>::IsEmpty()
{
	if (this->_data == nullptr)
		return true;
	return false;
}
template<typename T>
void Queue<T>::PushQueue(T item, int priority)
{
	if (!IsEmpty())
	{
		T* tempItem = new T[_size];
		int* tempPr = new int[_size];
		for (size_t i = 0; i < _size; i++)
		{
			tempItem[i] = _data[i];
			tempPr[i] = this->_priority[i];
		
		}
		delete[] _data;
		delete[] _priority;
		_data = new T[++_size];
		_priority = new int[_size];
		for (size_t i = 0, z = 0,j=0; z < _size; i++,z++)
		{
			if ((priority > tempPr[i]) &&( j == 0))
			{
				_data[i] = item;
				this->_priority[i] = priority;
				z++; 
				j++;
				if(z==_size) continue;
			}
			this->_data[z] = tempItem[i];
			this->_priority[z] = tempPr[i];
		}
		delete[] tempItem;
		delete[] tempPr;
	}
	else
	{
		_data = new T[++_size];
		_priority = new int[_size];
		_data[0] = item;
		_priority[0] = priority;
	}

}
template<typename T>
void Queue<T>::PopQueue()
{
	//if (!IsEmpty())
	//{
	//	T* temp = new T[--_size];
	//	for (size_t i = 0; i < _size-1 ; i++)
	//		temp[i] = _data[i+1];
	//	delete[] _data;
	//	_data = new T[_size];
	//	for (size_t i = 0; i < _size; i++)
	//		_data[i] = temp[i];
	//	delete[] temp;
	//}
	//if (_size == 0)
	//	_data = nullptr;

}
template<typename T>
ostream& operator<<(ostream& out, const Queue<T>& queue)
{
	//out << "Priority:\t" << queue._priority << endl;
	for (size_t i = 0; i < queue._size; i++)
	{
		out << queue._data[i] << "\t"<< "Priority:\t" << queue._priority[i] << endl;
	}
	return out;
}
