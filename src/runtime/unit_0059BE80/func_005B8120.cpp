/* compiler: ee-gcc2.9-991111 */
/* Remove a node from the doubly linked list whose head is D_00659308; returns the node's former next. */
struct ListNode {
	ListNode *next;
	ListNode *prev;
};

extern "C" ListNode *D_00659308;

extern "C" ListNode *func_005B8120(ListNode *node)
{
	ListNode *next = node->next;
	if (node->prev)
		node->prev->next = next;
	else
		D_00659308 = next;
	if (next)
		next->prev = node->prev;
	node->prev = 0;
	return next;
}
