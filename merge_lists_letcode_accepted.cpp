class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr) {
            return l2; 
        }
        else if (l2 == nullptr) {
            return l1;
        }
  
        ListNode* Head = new ListNode(0);
        ListNode* cur = Head;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 == nullptr) {
            cur->next = l2;
        }
        else {
            cur->next = l1;
        }

        return Head->next;
    }
};