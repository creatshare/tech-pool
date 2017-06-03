/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//把下一个结点的值赋给当前结点,然后删除下一个结点来达成删除结点的操作
void deleteNode(struct ListNode* node) {
    struct ListNode* p = node->next;
    node ->val =p->val;
    node ->next = p->next;
    free(p);
}
