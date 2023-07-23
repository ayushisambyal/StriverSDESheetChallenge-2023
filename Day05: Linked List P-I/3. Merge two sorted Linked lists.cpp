Node<int>* sortTwoLists(Node<int>* l1, Node<int>* l2)
{
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;

    // l2 = min(l1, l2)
    if(l1->data > l2->data){
        Node<int> *temp = l1;
        l1 = l2;
        l2 = temp;
    }

    Node<int> *res = l1;
    while(l1 != NULL && l2 != NULL){
        Node<int> *tmp = NULL;
        while(l1 != NULL && l1->data <= l2->data){
            tmp = l1;
            l1 = l1->next;
        }
        tmp->next = l2;

        Node<int> *temp = l1;
        l1 = l2;
        l2 = temp;
    }
    return res;
}
