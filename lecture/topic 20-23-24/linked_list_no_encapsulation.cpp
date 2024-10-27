#include <iostream>

using value_t = int;

class Node
{
private:
	value_t value;
	Node* prev;
	Node* next;

public:
	Node(value_t val, Node* prev = nullptr, Node* next = nullptr) : value(val), prev(prev), next(next)
	{
	}

	Node* insert_before_this(value_t val)
	{
		Node* old_prev = prev;
		prev = new Node(val, old_prev, this);
		old_prev->next = prev;
		return prev;
	}

	Node* insert_after_this(value_t val)
	{
		Node* old_next = next;
		next = new Node(val, this, old_next);
		old_next->prev = next;
		return next;
	}

	operator value_t&()
	{
		return value;
	}
};

class LinkedList
{
private:
	Node* _begin;
	Node* _end;

public:
	LinkedList() : _begin(nullptr), _end(nullptr)
	{
	}

	void push_front(value_t val)
	{
		if (_begin == nullptr)
		{
			_end = _begin = new Node(val);
			return;
		}
		_begin = _begin->insert_before_this(val);
	}

	void push_back(value_t val)
	{
		if (_end == nullptr)
		{
			_end = _begin = new Node(val);
			return;
		}
		_end = _end->insert_after_this(val);
	}

	Node* begin()
	{
		return _begin;
	}
	Node* end()
	{
		return _end;
	}
};

int main()
{
	return 0;
}
