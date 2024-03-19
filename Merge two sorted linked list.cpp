#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node* next) : data(x), next(next) {}
};

class LinkedList {
public:
    Node* mergeTwoLists(Node* l1, Node* l2) {
        if (l1 == nullptr) {
            return l2; // لو الليست الاولي فاضية هرجع الليست التانيه
        }
        else if (l2 == nullptr) {
            return l1; // لو الليست التانية فاضية هرجع الليست الاولي
        }

        Node* Head = new Node(0); // هعمل نود عشان استخدمها في اني اعمل دمج بين التو ليست وهيدي اللي هرجعها في الاخر
        Node* cur = Head; // نود عشان اللف بيها علي التوليست


        while (l1 != nullptr && l2 != nullptr) {
            if (l1->data <= l2->data) {  //لو العنصر  في الليست الاولي اصغر من او يساوي العنصر  في الليست التانية 
                cur->next = l1; // هخزن في الكرانت نيكست العنصر اللي في الليست الاولي
                l1 = l1->next; // هنقل للعنصر اللي بعده 
            }
            else {    //لو العنصر  في الليست التانية اصغر من او يساوي العنصر  في الليست الاولي
                cur->next = l2;   // هخزن في الكرانت نيكست العنصر اللي في الليست الثانية
                l2 = l2->next;   // هنقل للعنصر اللي بعده 
            }
            cur = cur->next;  // هخلي الكرانت بيساوي الكرانت نيكست في كل لفة
        }

        if (l1 == nullptr && l2 != nullptr) {  // لو الليست الاولي خلاص بقت فاضية والتانية لسه فيها عناصر
            cur->next = l2;  // هخزن العناصر اللي باقيه في الكرانت نيكست
        }
        else {// لو الليست التانية خلاص بقت فاضية والاولي لسه فيها عناصر
            cur->next = l1;  // هخزن العناصر اللي باقيه في الكرانت نيكست
        }

        return Head->next; //  هرجع الهيد اللي كنت عامله عشان يمسك المرجيد ليست
    }
};

int main() {
    Node* l1 = new Node(1);
    l1->next = new Node(2);
    l1->next->next = new Node(4);

    Node* l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);
    l2->next->next->next = new Node(4);

    LinkedList list;
    Node* mergedList = list.mergeTwoLists(l1, l2);

    while (mergedList != nullptr) {
        cout << mergedList->data << " ";
        mergedList = mergedList->next;
    }
    cout << endl;
    return 0;
}