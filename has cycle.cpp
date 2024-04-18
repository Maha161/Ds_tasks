	bool hasCycle(Node* head) {

		if (head == nullptr || head->next == nullptr) {
			return false; // مفيش  سايكل لو الليست فاضية او فيها عنصر واحد
		}

		Node* cur1 = head;
		Node* cur2 = head->next;

		while (cur2 != nullptr && cur2->next != nullptr) {
			if (cur1 == cur2) { // لما احنا الاتنين بنشاور علي نفس الحاجه 
				return true;
			}
			cur1 = cur1->next; 
			cur2 = cur2->next->next; 
		}
		return false; 
	}
	