/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL)
            return head;
        
        ListNode * ptr = head -> next;
        ListNode * pre = head;
        
        while (ptr != NULL) {
            pre -> next = ptr -> next;
            ptr -> next = head;
            head = ptr;
            ptr = pre -> next;
        }
        
        return head;
    }
};
