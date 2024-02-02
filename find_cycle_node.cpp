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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast;
        ListNode *slow;
        fast = slow = head;
        if(!head || !head->next){
            return NULL;
        }

        bool found = false;
        slow = slow->next;
        fast = fast->next->next;
        while(fast && fast->next){
            if(slow == fast){break;}
            fast = fast->next->next;
            slow = slow->next;
        }

        if(slow == fast){
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
        return NULL;
    }
};