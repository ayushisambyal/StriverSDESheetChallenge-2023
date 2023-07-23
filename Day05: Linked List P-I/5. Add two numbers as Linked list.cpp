Node *addTwoNumbers(Node *n1, Node *n2)
{
    Node *dummy = new Node();
    Node *temp = dummy;
    int carry = 0;

    while(n1 != NULL || n2 != NULL || carry){
        int sum = 0;
        if(n1 != NULL){
            sum += n1 -> data;
            n1 = n1 -> next;
        }
        if(n2 != NULL){
            sum += n2 -> data;
            n2 = n2 -> next;
        }
        sum += carry;
        carry = sum/10;
        Node *node = new Node(sum%10);
        temp -> next = node;
        temp = temp ->next;
    }
    return dummy -> next;
}
