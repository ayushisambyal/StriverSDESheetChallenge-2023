Node *firstNode(Node *head)
{
    Node *fast = head, *slow = head, *entry = head;
    if(head->next == NULL || head->next->next == NULL) return NULL;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            while(slow != entry){
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return NULL;
}
