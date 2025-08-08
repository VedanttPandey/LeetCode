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
    ListNode* reverseList(ListNode* head) {
        ListNode* nextt,*prevv=NULL;
        ListNode* curr=head;

        while(curr!=NULL){
            nextt=curr->next;
            curr->next=prevv;
            prevv=curr;
            curr=nextt;
        }
        return prevv;
    }
};