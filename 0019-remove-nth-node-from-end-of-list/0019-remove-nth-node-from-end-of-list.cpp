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
int getSize(ListNode* head){
    int cnt=0;
    while(head!=nullptr){
        head=head->next;
        cnt++;
    }
    return cnt;
}
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=getSize(head);
        // cout<<size;

        if(size==1 && n==1){
            return nullptr;
        }
        if(n==size){
            head=head->next;
            return head;
        }

        ListNode* temp=head;

        for(int i=1;i<(size-n);++i){
            temp=temp->next;
        }
        // ListNode* toDelete=temp;
        // temp->val=temp->next->val;
        temp->next=temp->next->next;
        // delete toDelete;
        return head;
        /*
            1 2 3 4 5 6 7
            size=7
            n=2
            size-n=5

            so lesst than size will be 4
            1 2 3 4 5 6 7 
            0 1 2 3 4 5 6
        */
    }
};