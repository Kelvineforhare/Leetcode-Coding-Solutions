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
    bool hasCycle(ListNode *head) {
        set<ListNode*> visit;
        while(head){
            auto insert = visit.insert(head);
            if(!insert.second){
                return true;
            }
            head = head->next;
        }
        return false;
    }
};