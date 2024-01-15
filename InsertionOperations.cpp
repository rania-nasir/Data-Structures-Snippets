// Insert Operations
#include<iostream>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int data) {
		this->data = data;
		next = nullptr;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() {
		head = nullptr;
	}

	void insertAtStart(int data) {
		Node* temp = new Node(data);

		if (head == nullptr) {
			temp->next = nullptr;
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void insertAtEnd(int data) {
		Node* newNode = new Node(data);
		newNode->next = nullptr;

		if (head == NULL) {
			head = newNode;
			return;
		}

		Node* temp = head;
		while (temp->next != nullptr) {
			temp = temp->next;
		}
		temp->next = newNode;
	}

	void insertInMiddle(int data) {
		Node* newNode = new Node(data);
		newNode->next = nullptr;

		if (head == nullptr) {
			head = newNode;
			return;
		}

		int len = 0;
		Node* temp = head;
		while (temp != nullptr) {
			len++;
			temp = temp->next;
		}
		int mid = len / 2;

		temp = head;
		for (int i = 1; i < mid; i++) {
			temp = temp->next;
		}
		newNode->next = temp->next;
		temp->next = newNode;

	}

	void print() {
		Node* node = head;
		while (node != NULL) {
			cout << node->data << " -> ";
			node = node->next;
		}
		cout << "NULL\n";
	}
};

int main() {

	LinkedList l;
	cout << "Currently the Linked List is empty!";
	int e = 1;

	while (e != 0) {

		int s;
		cout << "Insertion Operations are:\n";
		cout << "\n1. Insert At the Start";
		cout << "\n2. Insert At the End";
		cout << "\n3. Insert In the Middle";

		cout << "\nSelect Insertion Operations ? ";
		cin >> s;

		int n;
		cout << "\nHow many number of operations you want to add ? ";
		cin >> n;

		int value;

		for (int i = 0; i < n; i++) {
			cout << "Enter Value = ";
			cin >> value;

			if (s == 1) {
				l.insertAtStart(value);
				l.print();
			}
			else if (s == 2) {
				l.insertAtEnd(value);
				l.print();
			}
			else if (s == 3) {
				l.insertInMiddle(value);
				l.print();
			}
			else { cout << "\nInvalid Input"; }
		}

		cout << "\nWanna exit ? 0 for yes : ";
		cin >> e;
	}

	cout << "\nTerminating...." << endl;

	return 0;
}