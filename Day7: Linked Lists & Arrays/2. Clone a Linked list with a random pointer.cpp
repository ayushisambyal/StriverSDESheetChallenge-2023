LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // 1- create deep copy nodes
    LinkedListNode<int> *itr = head;
    LinkedListNode<int> *front = head;

    while(itr != NULL){
        front = itr->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(itr->data);
        itr->next = copy;
        copy->next = front;
        itr = front;
    }
    
    // 2- random pointers 
    itr = head;
    while(itr != NULL){
        if(itr->random != NULL){
            itr->next->random = itr->random->next;
        }
        else{
            itr->next->random = NULL;
        }
        itr = itr->next->next;
    }
    
    // 3- sggregate both the lls and return deep copy's head
    itr = head; 
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    LinkedListNode<int> *copy = dummy;

    while(itr != NULL){
        front = itr->next->next;
        copy->next = itr->next;
        itr->next = front;
        copy = copy->next;
        itr = itr->next;
    }
    return dummy->next;
}
 
