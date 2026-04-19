/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode smallHead = {0, NULL};
    struct ListNode largeHead = {0, NULL};
    

    struct ListNode* small = &smallHead;
    struct ListNode* large = &largeHead;

    while (head != NULL) {
        if (head->val < x) {
            small->next = head;
            small = small->next;
        } else {
            large->next = head;
            large = large->next;
        }
        head = head->next;
    }
    small->next = largeHead.next;
    
    large->next = NULL;

    return smallHead.next;
}
