LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    LinkedListNode<int> *dummy = NULL;

    while(head != NULL){
        LinkedListNode<int> *next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}
