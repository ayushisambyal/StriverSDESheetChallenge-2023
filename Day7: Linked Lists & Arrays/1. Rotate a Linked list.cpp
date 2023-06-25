Node *rotate(Node *head, int k) {
     //edge cases
     if( !head || !head->next || k==0) return head;

     // 1. find len
     Node *cur = head;
     int len = 1;

     while(cur->next && ++len) cur = cur->next;

     // 2. go to last node
     cur->next = head;
     k %= len;
     k = len - k;

     while(k--) cur = cur->next;

     // 3. label head & point last node to NULL
     head = cur->next;
     cur->next = NULL;
     return head;
}
