Node *merge2lists(Node *a, Node *b){
	Node *temp = new Node(0);
	Node *res = temp;

	while(a != NULL && b != NULL){
		
		if(a->data <  b->data){
			temp->child = a;
			temp = temp->child;
			a = a->child;
		} 
		else{
			temp->child = b;
			temp = temp->child;
			b = b->child;
		}
    }
	
	if(a) temp->child = a;
	else temp->child = b;

	return res -> child;
}

Node* flattenLinkedList(Node* root) 
{
	if(root == NULL || root->next == NULL) return root;

	root->next = flattenLinkedList(root->next);
	root = merge2lists(root, root->next);
	return root;
}
