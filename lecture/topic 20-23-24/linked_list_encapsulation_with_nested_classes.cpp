#include <iostream>
#include <iterator>

class List
{
private:
	struct Node
	{
		int data;
		Node* prev;
		Node* next;

		Node(const int& value) : data(value), prev(nullptr), next(nullptr)
		{
		}
	};

	Node* head;
	Node* tail;
	size_t sz;

public:
	// Конструктори и деструктор
	List() : head(nullptr), tail(nullptr), sz(0)
	{
	}

	~List()
	{
		clear();
	}

	List(const List& other) : head(nullptr), tail(nullptr), sz(0)
	{
		for (auto it = other.begin(); it != other.end(); ++it)
		{
			push_back(*it);
		}
	}

	List& operator=(const List& other)
	{
		if (this != &other)
		{
			clear();
			for (auto it = other.begin(); it != other.end(); ++it)
			{
				push_back(*it);
			}
		}
		return *this;
	}

	// Клас за итератор
	class iterator
	{
	private:
		Node* node;
		friend class List;

	public:
		using iterator_category = std::bidirectional_iterator_tag;
		using difference_type = ptrdiff_t;
		using value_type = int;
		using pointer = int*;
		using reference = int&;

		iterator(Node* n) : node(n)
		{
		}

		reference operator*() const
		{
			return node->data;
		}
		pointer operator->()
		{
			return &(node->data);
		}

		// Префиксно инкрементиране
		iterator& operator++()
		{
			node = node->next;
			return *this;
		}

		// Постфиксно инкрементиране
		iterator operator++(int)
		{
			iterator temp = *this;
			node = node->next;
			return temp;
		}

		// Префиксно декрементиране
		iterator& operator--()
		{
			node = node->prev;
			return *this;
		}

		// Постфиксно декрементиране
		iterator operator--(int)
		{
			iterator temp = *this;
			node = node->prev;
			return temp;
		}

		bool operator==(const iterator& other) const
		{
			return node == other.node;
		}
		bool operator!=(const iterator& other) const
		{
			return node != other.node;
		}
	};

	// Методи
	iterator begin() const
	{
		return iterator(head);
	}
	iterator end() const
	{
		return iterator(nullptr);
	}

	bool empty() const
	{
		return sz == 0;
	}

	size_t size() const
	{
		return sz;
	}

	void clear()
	{
		Node* current = head;
		while (current)
		{
			Node* tmp = current;
			current = current->next;
			delete tmp;
		}
		head = tail = nullptr;
		sz = 0;
	}

	void push_back(const int& value)
	{
		Node* new_node = new Node(value);
		new_node->prev = tail;
		if (tail)
		{
			tail->next = new_node;
		}
		else
		{ // Празен списък
			head = new_node;
		}
		tail = new_node;
		++sz;
	}

	void push_front(const int& value)
	{
		Node* new_node = new Node(value);
		new_node->next = head;
		if (head)
		{
			head->prev = new_node;
		}
		else
		{ // Празен списък
			tail = new_node;
		}
		head = new_node;
		++sz;
	}

	void pop_back()
	{
		if (tail)
		{
			Node* tmp = tail;
			tail = tail->prev;
			if (tail)
			{
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
			}
			delete tmp;
			--sz;
		}
	}

	void pop_front()
	{
		if (head)
		{
			Node* tmp = head;
			head = head->next;
			if (head)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}
			delete tmp;
			--sz;
		}
	}

	iterator insert(iterator pos, const int& value)
	{
		if (pos == begin())
		{
			push_front(value);
			return begin();
		}
		else if (pos == end())
		{
			push_back(value);
			return iterator(tail);
		}
		else
		{
			Node* next_node = pos.node;
			Node* prev_node = next_node->prev;
			Node* new_node = new Node(value);
			new_node->prev = prev_node;
			new_node->next = next_node;
			prev_node->next = new_node;
			next_node->prev = new_node;
			++sz;
			return iterator(new_node);
		}
	}

	iterator erase(iterator pos)
	{
		if (pos == end())
		{
			return end();
		}
		Node* node_to_delete = pos.node;
		Node* prev_node = node_to_delete->prev;
		Node* next_node = node_to_delete->next;

		if (prev_node)
		{
			prev_node->next = next_node;
		}
		else
		{ // Изтриване на началото
			head = next_node;
		}

		if (next_node)
		{
			next_node->prev = prev_node;
		}
		else
		{ // Изтриване на края
			tail = prev_node;
		}

		delete node_to_delete;
		--sz;
		return iterator(next_node);
	}
};

int main()
{
	List lst;
	lst.push_back(10);
	lst.push_front(20);
	lst.push_back(30);

	for (auto it = lst.begin(); it != lst.end(); ++it)
	{
		std::cout << *it << " ";
	}
	// Изход: 20 10 30

	return 0;
}
