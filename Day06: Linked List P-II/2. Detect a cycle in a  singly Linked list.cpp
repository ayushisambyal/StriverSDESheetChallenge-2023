bool detectCycle(Node *head)
{
	if(head == NULL || head->next == NULL) return false;
    Node *fast = head;
    Node *slow = head;

    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
        if(fast == slow) return true;
    }
    return false;
}
