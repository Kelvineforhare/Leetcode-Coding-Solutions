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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        tuple<int,ListNode*,int> sortList;
        for(int i = 0; i < lists.size();++i){
            if(lists[i]){
                sortList = {lists[i]->val,lists[i],i};
                break;
            }
        }
        for(int i = 0; i < lists.size();++i){
            if(lists[i]){
                if(get<0>(sortList) > lists[i]->val){
                    sortList = {lists[i]->val,lists[i],i};
                }
                
            }
        }
        if(get<1>(sortList) == nullptr){
            return nullptr;
        }
        //sort(sortList.begin(),sortList.end());
        lists[get<2>(sortList)] = get<1>(sortList)->next;
        // for(int i = 0; i < lists.size();++i){
        //     if(lists[i]){
        //         printf("%d , ",lists[i]->val);
        //     }
        // }
        // printf("\n");
        get<1>(sortList)->next = mergeKLists(lists);            
       
        return get<1>(sortList);
    }
};