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
//if head -> next == nullptr head == 1

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //(remove(head,n,nullptr) == 0)?nullptr:head;
        remove(head,n,nullptr);
        return head;
           
    }
    
    int remove(ListNode* & head, int n,ListNode* previous) {
        if(head->next != nullptr){
            int nth = 1 + remove(head->next,n,head);
            printf("val: %d n: %d\n",head->val,nth);
            if(nth == n){
                if(previous){
                    previous->next = previous->next->next;
                }
                else{
                    printf("head: %d head->next: %d\n",head->val,head->next->val);
                    head = head->next;
                }
                
            }
            return nth;
        }
        if(n == 1){
            if(previous){
                previous->next = nullptr;
            }
            else{
                head = nullptr;
            }
        }
        return 1;
    }
};