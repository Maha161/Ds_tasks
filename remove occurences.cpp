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
	void remove_occurrences(int data) {
		/*فانكشن بتحذف التكرار للعنصر اللي انا باعته بتستقبل برامتر واحد بس وهو العنصر اللي عايز احذفه كل ما الاقيه في اللينكد ليست*/
		Node* cur = head; //هعمل نود اخليها واقفه عند الهيد
		while (cur != nullptr) { // طول ما ال كرانت مش بتساوي زيرو هكمل
			if (cur->data == data) { //لو الداتا بتاع النود اللي واقف عندها ال كرانت دلوقتي بتساوي العنصر اللي بعته هدخل في الكوندشن
				Node* nextNode = cur->next; // هعمل نود جديدة هخزن فيها ال كرانت نيكست
				remove(data); // هحذف العنصر ده من اللينكد ليست
				cur = nextNode; // هخلي الكرانت دلوقتي واقف عن النوود الجديدة اللي هي واقفه عند العنصر اللي بعد العنصر اللي حذفته
			}
			else {
				cur = cur->next; // لو مدخلناش في الكوندشن اللي فوق هخلي ال كرانت بيساوي ال كرانت نيكست يعني دلوقتي ال كرانت واقف عند العنصر اللي بعده وهبدا اشوف الداتا بتاعته
			}
		}
		print();
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
	l1.insertAtPosition(0, 4);
	l1.insertAtPosition(1, 1);
	l1.insertAtPosition(2, 2);
	l1.insertAtPosition(3, 3);
	l1.insertAtPosition(4, 1);
	l1.insertAtPosition(5, 4);
	l1.insertAtPosition(6, 4);
	l1.insertAtPosition(7, 5);
	l1.insertAtPosition(8, 4);
	l1.remove_occurrences(4);
	return 0;
}