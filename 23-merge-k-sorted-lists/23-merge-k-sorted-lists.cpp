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
    
    struct{
        bool operator() (const ListNode* l, const ListNode* r) const { return l->val > r->val; }
    } customLess;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int i = 0;
        while(i < lists.size()){
            if(!lists[i]){
                if (i != lists.size() - 1)
                {
                    lists[i] = std::move(lists.back());
                }
                lists.pop_back();
            }
            else{
                ++i;
            }
        }
//         for(int i = 0;i < lists.size();++i){
//             if(lists[i]){
//                  printf("list %d",lists[i]->val);
//             }
//             else{
//                 printf(" [ ] ");
//             }
           
//         }
        
        priority_queue sortList(lists.begin(), lists.end(), customLess);
        
        ListNode* newList = new ListNode(0);
        ListNode* returnList = newList;
        //printf("size: %ld \n",sortList.size());
        for(int i = 0; i < sortList.size(); sortList.pop()){
            ListNode* node = sortList.top();
            if(!node){
                continue;
            }
            newList->next = node;
            if(node->next){
                sortList.push(node->next);
            }
            newList = newList->next;
        }
        return returnList->next;
    }
};