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
    int getDecimalValue(ListNode* head) {
        string s;
        while(head!=nullptr){
            s+=to_string(head->val);
            head=head->next;
        }
        int num=0;
        int n=s.size()-1;
        for(char c:s){
            int n1=c-'0';
            num+=(n1*(1<<n));
            n--;
        }
        cout<<s;
        return num;
    }
};