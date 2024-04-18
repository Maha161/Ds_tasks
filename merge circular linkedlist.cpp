    void merge(CircularLinkedListDummyHead* l1, CircularLinkedListDummyHead* l2) {
        Node* cur1 = l1->head->next;
        Node* cur2 = l2->head->next;
        CircularLinkedListDummyHead* l3 = new CircularLinkedListDummyHead(); 
        while (cur1 != l1->head && cur2 != l2->head) {
            if (cur1->data < cur2->data) {  // لو الداتا في اللبست الاول اقل من اللي في الليست التانية
                l3->insertAtPosition(cur1->data, l3->size);  //  هخزن في الليست الجديدة الداتا الاولي
                cur1 = cur1->next;
            }
            else if (cur1->data > cur2->data) { // لو الداتا في اللبست الثانية اقل من اللي في الليست الاولي
                l3->insertAtPosition(cur2->data, l3->size); //  هخزن في الليست الجديدة الداتا الثانية
                cur2 = cur2->next;
            }
            else { // لو الداتا في اللبست الاول بتساوي اللي في الليست التانية
                l3->insertAtPosition(cur1->data, l3->size);  // هخزن عنصر واحد بس منهم
                cur1 = cur1->next;
                cur2 = cur2->next;
            }
        }

        while (cur1 != l1->head) { // هخزن باقي العناصر اللي موجودة في الليست الاولي
            l3->insertAtPosition(cur1->data, l3->size);
            cur1 = cur1->next;
        }

        while (cur2 != l2->head) {  // هخزن باقي العناصر اللي موجودة في الليست  الثانية
            l3->insertAtPosition(cur2->data, l3->size);
            cur2 = cur2->next;
        }
        // هشوف لو في عناصر من اللي ضفتها فالاخر متكرره همسحها
        Node* cur3 = l3->head->next;
        while (cur3 != l3->head) {
            Node* temp = cur3->next;
            if (temp != l3->head && temp->data == cur3->data) {
                l3->DeleteAtPositon(l3->size); 
            }
            cur3 = temp;
        }

        l3->print(); 
    }



