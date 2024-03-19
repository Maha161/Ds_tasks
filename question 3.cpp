#include<iostream>
#include<stack>
using namespace std;
struct Node {
public:
	int data;
	Node* next;
};
class LinkedList {
private:
	Node* head, * last;
	int count;
public:
	LinkedList() {
		head = last = nullptr;
		count = 0;
	}
	bool is_empty() {
		if (count == 0 || head == nullptr) {
			return true;
		}
		return false;
	}
	void insertAtPosition(int position, int data) {
		if (position < 0) {
			cout << " position is invalid" << endl;
			return;
		}
		Node* newNode = new Node;
		newNode->data = data;
		if (position == 0) { // insert in position zero
			if (count == 0) { // if linked_list is empty 
				head = last = newNode;
				newNode->next = nullptr;
			}
			else  { // if linked_list has 1 node
				newNode->next = head;
				head = newNode;
			}
		}
		else if (position == count) {  // inert after last node
			last->next = newNode;
			newNode->next = nullptr;
			last = newNode;
		}
		else {
			Node* curr = head;
			for (int i = 0; i < position - 1; i++) {
				curr = curr->next;
			}
			newNode->next = curr->next;
			curr->next = newNode;
		}
		count++;
	}
	void remove(int data) {
		if (is_empty()) {
			cout << "linked list is empty" << endl;
			return;
		}
		Node* cur, * prev;
		if (head->data == data) { // remove first element
			cur = head;
			head = head->next;
			delete cur;
			if (count == 0) {
				last = nullptr;
			}
		}
		else {
			cur = head->next;
			prev = head;
			while (cur != nullptr && cur->data != data) {
				prev = cur;
				cur = cur->next;
			}
			if (cur == nullptr) {
				cout << "not found\n";
			}
			else {
				prev->next = cur->next;
				if (last == cur) {
					last = prev;
				}
				delete cur;
			}
			count--;
		}
	}
	void print() {
		Node* cur = head;
		for (int i = 0; cur != nullptr; i++) {
			cout << cur->data << " ";
			cur = cur->next;
		}
		cout << endl;
	}
};
int main() {
	LinkedList l1;
	l1.insertAtPosition(0, 35);
	l1.insertAtPosition(1, 45);
	l1.insertAtPosition(2, 65);
	l1.insertAtPosition(3, 75);
	l1.print();
	l1.insertAtPosition(0, 25);
	l1.insertAtPosition(3, 55);
	l1.remove(25);
	l1.remove(75);
	l1.print();
	return 0;
}