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
};

class LinkedList
{
private:
	Node* begin;
	Node* end;

	class Node
	{
	public:
		value_t value;
		Node* prev;
		Node* next;

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
	};

public:
	LinkedList() : begin(nullptr), end(nullptr)
	{
	}

	void push_front(value_t val)
	{
		if (begin == nullptr)
		{
			end = begin = new Node(val);
			return;
		}
		begin = begin->insert_before_this(val);
	}

	void push_back(value_t val)
	{
		if (end == nullptr)
		{
			end = begin = new Node(val);
			return;
		}
		end = end->insert_after_this(val);
	}
};

int main()
{
	return 0;
}
