Node *findIntersection(Node *h1, Node *h2) {
  if (h1 == NULL || h2 == NULL)
    return NULL;

  Node *d1 = h1, *d2 = h2;
  while (d1 != d2){
      d1 = d1 == NULL? h2 : d1->next;
      d2 = d2 == NULL? h1 : d2->next;
  }
  return d1;
}
