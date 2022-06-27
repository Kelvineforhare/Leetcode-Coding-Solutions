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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list;
        if(list1 && !list2){
            return list1;
        }
        else if(!list1 && list2){
            return list2;
        }
        else if (!list1 && !list2)
        {
            return nullptr;
        }
        ListNode* returnPointer;
        if(list1->val == list2->val  ){
            returnPointer = list1;
            ListNode* temp = list1->next;
            ListNode* temp2 = list2->next;
            list = list1;
            list->next= list2;
            list = list2;
            list1 = temp;
            list2 = temp2;
        }
        else if(list1->val > list2->val){
            returnPointer = list2;
            list = list2;
            list2 = list2->next;
        }
        else{
            returnPointer = list1;
            list = list1;
            list1 = list1->next;
        }
        while(list1 && list2){
            //cout << list->val;
            if(list1->val == list2->val  ){
                ListNode* temp = list1->next;
                ListNode* temp2 = list2->next;
                list->next = list1;
                list = list1;
                list->next= list2;
                list = list2;
                list1 = temp;
                list2 = temp2;
            }
            else if (list1->val < list2->val)
            {
                ListNode* temp = list1->next;
                list->next = list1;
                list = list1;
                list1 = temp;
                
            }
            else if(!list2->next){
                //cout << list2->val;
                ListNode* temp = list2->next;
                list->next = list2;
                list = list2;
                list2 = temp;
            }
            else{
                cout << list2->val;
                list->next = list2;
                list = list2;
                list2 = list2->next;
            }
        }
        if(list1)
        {
            list->next = list1;
        }
        else if(list2)
        {
            list->next = list2;
        }
        return returnPointer;
        
    }
};