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
ListNode* ReverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev; //reversing 
        prev = curr;
        curr = next;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
        return true;

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next != NULL) {
            slow = slow ->next;
            fast = fast->next->next;
        }
        ListNode* secondhalf = ReverseList(slow->next);

        ListNode* p1 = head;
        ListNode* p2 = secondhalf;

        while(p2 != NULL) {
            if(p1->val != p2->val) return false;
            p1 = p1->next;
            p2=p2->next;
        }
        return true;
    }
};