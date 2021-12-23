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
	Queue();// ����������� �� ���������
	Queue(const Queue& other);// ����������� �����������
	Queue(Queue&& other);// ����������� �����������
	~Queue();// ����������
	Queue<T>& operator=(const Queue& other); // �������� ������������
	Queue<T>& operator=(Queue&& other); // �������� �����������
	friend ostream& operator<<<T> (ostream& out, const Queue& queue); // ���������� ��������� � �����
	bool IsEmpty(); // ���������, �������� �� Queue ������.
	void PushQueue(T item, int priority);// ��������� ������� � Queue �������� �����������.
	void PopQueue(); //������� ������ ������� �� Queue �������� �����������.



private:
	T* _data;
	int* _priority;
	int _size;

};


