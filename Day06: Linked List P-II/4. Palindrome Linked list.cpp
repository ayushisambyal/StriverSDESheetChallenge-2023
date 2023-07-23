LinkedListNode<int> *reverseLL(LinkedListNode<int> *head){
    LinkedListNode<int> *dummy = NULL, *next = NULL;
    while(head){
        next = head->next;
        head->next = dummy;
        dummy = head;
        head = next;
    }
    return dummy;
}


bool isPalindrome(LinkedListNode<int> *head) {
    if(head == NULL || head->next == NULL) return true;

    LinkedListNode<int> *slow = head, *fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseLL(slow->next);
    slow = slow->next;

    while(slow != NULL){
        if(head->data != slow->data) return false;
        head = head->next;
        slow = slow->next;
    }
    return true;
}
