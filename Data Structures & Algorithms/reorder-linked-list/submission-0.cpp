/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:

    ListNode* reo(ListNode* head, ListNode* curr){
        if(curr == NULL) return head;
        
        head = reo(head,curr->next);

        if(head == NULL) return NULL;

        ListNode* temp = NULL;
        if(head == curr || head->next == curr){
            curr->next = NULL;
        }else{
            temp = head->next;
            head->next = curr;
            curr->next = temp;
        }
        return temp;
    }

    void reorderList(ListNode* head) {
        reo(head,head->next);
    }
};
