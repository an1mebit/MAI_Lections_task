#include <iostream>


using namespace std;

template<typename T>
class List
{
private:


	template<typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
public:
	List();
	~List();

	void popfront();
	void pushnode(T data);
	void clear();
	int getsize() { return size; }
	void show();

	int size;
	Node<T>* head;
};

template<typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::~List()
{
	clear();
}

template<typename T>
void List<T>::popfront()
{
	Node<T>* temp = head;

	head = head->pNext;
	delete temp;
	size--;
}

template<typename T>
void List<T>::pushnode(T data)
{
	Node<T>* nd = new Node<T>();
	nd->data = data;
	nd->pNext = head;
	head = nd;
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		popfront();
	}
}

template<typename T>
void List<T>::show()
{
	Node<T>* current = head;
	while (current)
	{
		cout << current->data << " ";
		current = current->pNext;
	}
	cout << endl;
}

int main()
{
	List<int> lst;
	cout << "Enter size" << endl;
	int numberCount = 0;
	cin >> numberCount;
	for (int i = 0; i < numberCount; i++)
		lst.pushnode(rand() % 30);
	lst.show();
}
