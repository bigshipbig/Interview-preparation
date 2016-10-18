"this is Single Linked List Sort"

struct Node{
    int key;
    Node* next;
    Node(int k, Node* n):key(k),next(n){};
};

Node* GetPartition(Node* begin, Node* end){
    int key = begin->key;
    Node* p = begin;
    Node* q = begin->next;
    while(q != end){
        if(q->key < key){
            p = p->next;
            swap(p->key,q->key);
        }
        q = q->next;
    }
    swap(p->key,begin->key);
    return p;
}

void quick_sort(Node* begin, Node* end){
    if(begin != end){
        Node* partion = GetPartition(begin, end);
        quick_sort(begin, partion);
        quick_sort(partion->next, end);
    }
}
