#pragma once
#include <iostream>
#include <ostream>
#include <climits>
#include <string>
#include <sstream>
using namespace std;

template<typename T>
class Queue
{
public:
	Queue();// Конструктор по умолчанию
	Queue(const Queue& other);// Конструктор копирования
	Queue(Queue&& other);// Конструктор перемещения
	~Queue();// Деструктор
	Queue<T>& operator=(const Queue& other); // Оператор присваивания
	Queue<T>& operator=(Queue&& other); // Оператор перемещения
	friend ostream& operator<<<T> (ostream& out, const Queue& queue); // Перегрузка оператора в поток
	bool IsEmpty(); // Проверяет, является ли Queue пустым.
	void PushQueue(T item, int priority);// Добавляет элемент в Queue согласно приоритетам.
	void PopQueue(); //Удоляем первый элемент из Queue согласно приоритетам.



private:
	T* _data;
	int* _priority;
	int _size;

};


