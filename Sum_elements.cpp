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
	int sum = 0;
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
	void insertAtPosition(int postition, int data) {
		if (postition < 0) {
			cout << " position is invalid" << endl;
			return;
		}

		Node* temp = head;

		Node* t = new Node;

		t->data = data;

		if (postition == 0) {
			// add node at the first 

			t->next = head;
			head = t;
		}

		else {

			for (int i = 0; i < postition - 1 && temp; i++) {
				temp = temp->next;
			}

			if (temp != nullptr) {
				t->next = temp->next;

				temp->next = t;
			}

			else {
				cout << "position greater than the number of elements";
				delete t;
				return;
			}
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
	Node* return_head() {
		return head; // function to return head -> used in calling sum_linked_elements function
	}
	/*فانكشن بترجع مجموع عناصر اللينكد ليست باستخدام الريكيرجن بتستقبل تو برامترز اول واحد ه, النوود اللي همشي بيها خلال اللينكد ليست وتاني
	 واحد وفاريبل  بخزن فيه مجموع العناصر وببعته باي ريفؤينس عشان التعديل يتم ع نفس الفاريبل*/
	int sum_linkedList_elements(Node* p, int& sum) {
		if (p != nullptr) {
			sum += p->data;  // بخزن في الفاريبل الداتا بتاع كل عنصر
			sum_linkedList_elements(p->next, sum); // بنادي الفانكشن للعنير اللي بعده
		}
		return sum;
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
	Node* t = nullptr;
	int sum = 0;
	l1.insertAtPosition(0, 5);
	l1.insertAtPosition(1, 4);
	l1.insertAtPosition(2, 3);
	l1.insertAtPosition(3, 2);
	l1.print();
	cout << l1.sum_linkedList_elements(l1.return_head(), sum) << endl;
}