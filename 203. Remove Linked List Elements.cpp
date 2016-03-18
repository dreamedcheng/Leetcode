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
    ListNode* removeElements(ListNode* head, int val) {
        if (head == NULL)
            return head;
        
        ListNode * pre = head;
        ListNode * cur = head;
        
        while (cur != NULL) {
            if (cur -> val == val) {
                if (pre == cur) {
                    head = cur -> next;
                    delete(pre);
                    cur = head;
                    pre = head;
                }
                else {
                    pre -> next = cur -> next;
                    delete(cur);
                    cur = pre -> next;
                }
            }
            else {
                pre = cur;
                cur = cur -> next; 
            }
            
        }
        
        return head;
    }
};
