	void halve(DoublyLinkedList* l1) {
		DoublyLinkedList* l2 = new DoublyLinkedList();
		DoublyLinkedList* l3 = new DoublyLinkedList();
		Node* cur1 = l1->head;
		Node* cur2 = l1->head->next;

		while (cur2 != nullptr && cur2->next != nullptr) {
			cur1 = cur1->next;
			cur2 = cur2->next->next;
		}
		// بعد ما اللوب تخلص هيكون كرانت1 واقف عند نص الليست او قريب منها وكرانت 2 هيكون عند اخر عنصر في الليست
		//  هخلي الليست التانية تشاور علي اول جزء والليست التالتة تشاور علي الجزء التاني من الليست
		l2->head = l1->head; 
		l1->head = nullptr;
		l3->head = cur1->next;
		cur1->next = nullptr;

		l2->Print();
		l3->Print();
	}

