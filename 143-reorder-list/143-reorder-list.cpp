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
    void reorderList(ListNode* head) {
        ListNode* pointer1 = head;
        ListNode* pointer2 = head->next;
        while(pointer1){
            //printlist(head);
            //printf("\n");
            ListNode* temp = pointer1->next;
            if(!pointer2){
                return;
            }
            
            ListNode* endNode = findEnd(pointer2);
            if(!endNode){
                return;
            }
            pointer1->next = endNode;
            endNode->next = temp;
            pointer1=temp;
            pointer2=temp->next;
        }
        
    }
    void printlist(ListNode* head){
        if(!head){
            return;
        }
        printf("%d -> ",head->val);
        printlist(head->next);
    }
    
    ListNode* findEnd(ListNode* head){
        if(!head->next){
            return nullptr;
        }
        while(head->next->next){
            head = head->next;
            
        }
        ListNode* temp = head->next;
        head->next = nullptr;
        return temp;
    }
};