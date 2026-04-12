/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create dummy node to handle edge cases (like deleting head)
    struct ListNode dummy;
    dummy.next = head;

    struct ListNode *fast = &dummy;
    struct ListNode *slow = &dummy;

    // Move fast pointer n+1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete the nth node
    struct ListNode* temp = slow->next;
    slow->next = temp->next;

    free(temp);  // optional (depends on platform)

    return dummy.next;
}
