//Reverse the linked list

#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;

	LinkedList() {
		head = NULL;
	}
	void push(int data) {
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
	void reverselist() {

		cout << "\nREVERSED LINKED LIST:\n";

		Node* current = head;
		Node* prev = NULL;
		Node* next = NULL;

		while (current != NULL) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
		}
		head = prev;
	}
	void print() {
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " -> ";
			temp = temp->next;
		}
		cout << "NULL" << endl;
	}
};

int main() {

	LinkedList l;

	l.push(54);
	l.push(67);
	l.push(23);
	l.push(45);
	l.push(25);

	cout << "\nLINKED LIST:\n";
	l.print();

	l.reverselist();

	l.print();

	return 0;
}