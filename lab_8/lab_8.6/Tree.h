#pragma once
#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
void enter(istream& in, T& data) {
	while (true) {
		in >> data;

		if (in.fail()) {
			in.clear();
			in.ignore(INT_MAX, '\n');

			cout << "An incorrect value. Please try again:" << endl;

			continue;
		}
		else {
			break;
		}
	}
}

template <class T>
class Tree {
private:
	template <class T>
	class Node {
	public:
		T data;
		Node<T>* left;
		Node<T>* right;

		Node(T data = T(), Node<T>* left = nullptr, Node<T>* right = nullptr) {
			this->data = data;
			this->left = left;
			this->right = right;
		}
	};

	int size;
	Node<T>* head;

	Node<T>* find_push(Node<T>* top, T data);
	Node<T>* search_key(Node<T>* top, T data);
	void copy_tree(const Node<T>* top);
	void deleteTree(Node<T>* top);
	void outL(Node<T>* top);
	void outR(Node<T>* top);

	int findLeaves_Node(Node<T>* top);

public:
	Tree();
	Tree(int size, T data);
	Tree(const Tree<T>& tree);

	~Tree();

	Tree& operator=(const Tree& tree) {
		if (&tree != this) {
			clear();
			copy_tree(tree.head);
		}

		return *this;
	}

	void input(int n);
	void push(T data);
	Node<T>* search_data(T data);
	bool isLeaf(Node<T>* top);
	void removeAt(T data);
	void clear();
	void output_left();
	void output_right();
	int getSize() const;

	int findLeaves();
};

template <class T>
Tree<T>::Tree() {
	this->size = 0;
	this->head = nullptr;
}

template <class T>
Tree<T>::Tree(int size, T data) {
	this->size = 0;
	this->head = nullptr;

	for (int i = 0; i < size; ++i) {
		push(data);
	}
}

template <class T>
Tree<T>::Tree(const Tree<T>& tree) {
	size = 0;
	head = nullptr;
	copy_tree(tree.head);
}

template <class T>
Tree<T>::~Tree() {
	clear();
}

template <class T>
void Tree<T>::input(int n) {
	for (int i = 0; i < n; ++i) {
		T data;
		enter(cin, data);
		push(data);
	}
}

template <class T>
Tree<T>::Node<T>* Tree<T>::find_push(Tree<T>::Node<T>* top, T data) {
	if (!top) {
		return nullptr;
	}

	Node<T>* element = nullptr;
	if (data < top->data) {
		element = find_push(top->left, data);
	}
	else {
		element = find_push(top->right, data);
	}

	return element ? element : top;
}

template <class T>
void Tree<T>::push(T data) {
	if (!size) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* element = find_push(head, data);

		if (data < element->data) {
			element->left = new Node<T>(data);
		}
		else {
			element->right = new Node<T>(data);
		}
	}

	size++;
}

template <class T>
void Tree<T>::copy_tree(const Node<T>* top) {
	if (top) {
		push(top->data);
		copy_tree(top->left);
		copy_tree(top->right);
	}
}

template <class T>
Tree<T>::Node<T>* Tree<T>::search_key(Node<T>* top, T data) {
	if (top) {
		if (top->data == data) {
			return top;
		}
		if (top->data > data) {
			return search_key(top->left, data);
		}
		else {
			return search_key(top->right, data);
		}
	}
	else {
		return nullptr;
	}
}

template <class T>
Tree<T>::Node<T>* Tree<T>::search_data(T data) {
	if (head) {
		if (head->data == data) {
			return head;
		}
		if (head->data > data) {
			return search_key(head->left, data);
		}
		else {
			return search_key(head->right, data);
		}
	}
	else {
		return nullptr;
	}
}

template <class T>
bool Tree<T>::isLeaf(Node<T>* top) {
	return !(top->left || top->right);
}

template <class T>
void Tree<T>::removeAt(T data) {
	if (head->data == data) {
		cerr << "Error. Deleting the root element" << endl;
		exit(404);
	}

	Node<T>* current = head;
	bool leftTree = false;
	while (true) {
		if (current->left && current->left->data == data) {
			leftTree = true;
			break;
		}
		if (current->right && current->right->data == data) {
			break;
		}
		if (current->data > data) {
			if (!current->left) {
				cerr << "The specified element wasn't found" << endl;
				exit(404);
			}
			current = current->left;
		}
		else {
			if (!current->right) {
				cerr << "The specified element wasn't found" << endl;
				exit(404);
			}
			current = current->right;
		}
	}

	if (leftTree) {
		if (!isLeaf(current->left)) {
			cerr << "Error. Deleting a branch" << endl;
			exit(404);
		}
		delete current->left;
		current->left = nullptr;
		size--;
	}
	else {
		if (!isLeaf(current->right)) {
			cerr << "Error. Deleting a branch" << endl;
			exit(404);
		}
		delete current->right;
		current->right = nullptr;
		size--;
	}
}

template <class T>
void Tree<T>::deleteTree(Node<T>* top) {
	if (top) {
		deleteTree(top->left);
		deleteTree(top->right);
		delete top;
		top = nullptr;
	}
}

template <class T>
void Tree<T>::clear() {
	if (head) {
		deleteTree(head->left);
		deleteTree(head->right);
		delete head;
		head = nullptr;
		size = 0;
	}
}

template <class T>
void Tree<T>::outL(Node<T>* top) {
	if (top) {
		outL(top->left);
		cout << top->data << " ";
		outL(top->right);
	}
}

template <class T>
void Tree<T>::output_left() {
	if (head) {
		outL(head->left);
		cout << head->data << " ";
		outL(head->right);
	}
	cout << endl;
}

template <class T>
void Tree<T>::outR(Node<T>* top) {
	if (top) {
		outR(top->right);
		cout << top->data << " ";
		outR(top->left);
	}
}

template <class T>
void Tree<T>::output_right() {
	if (head) {
		outR(head->right);
		cout << head->data << " ";
		outR(head->left);
	}
	cout << endl;
}

template <class T>
int Tree<T>::getSize() const {
	return this->size;
}

template <class T>
int Tree<T>::findLeaves_Node(Node<T>* top) {
	if (!top) {
		return 0;
	}
	else {
		int l = findLeaves_Node(top->left);
		int r = findLeaves_Node(top->right);

		if (l == 0 && r == 0) {
			return 1;
		}
		else {
			return l + r;
		}
	}
}

template <class T>
int Tree<T>::findLeaves() {
	if (!head) {
		return 0;
	}
	else {
		int l = findLeaves_Node(head->left);
		int r = findLeaves_Node(head->right);

		if (l == 0 && r == 0) {
			return 1;
		}
		else {
			return l + r;
		}
	}
}