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
    bool isPalindrome(ListNode* head) {
        ListNode* ans = nullptr;  
        ListNode* curr = head;

        while (curr != nullptr) {
            ListNode* newNode = new ListNode(curr->val);
            newNode->next = ans;
            ans = newNode;

            curr = curr->next;
        }

        ListNode* p1 = head;
        ListNode* p2 = ans;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val != p2->val) return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }
};
