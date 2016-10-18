struct BST_Node {
    BST_Node *l,*r;
    int value;
    BST_Node() {
        l=NULL;
        r=NULL;
    }
};

struct BST {
    BST_Node *root;
    void Insert(BST_Node *&p,int val) {
        if(p==NULL) {
            p = new BST_Node;
            p->value=val;
        } else if(p->value>=val) {
            Insert(p->l,val);
        } else
            Insert(p->r,val);
    }
    int find_DeleteMin(BST_Node *&p) {
        if(!p->l) {
            BST_Node *tmp = p;
            int val = p->value;
            p=p->r;
            delete tmp;
            return val;
        } else
            return find_DeleteMin(p->l);
    }
    void Delete(BST_Node *&p,int val) {
        if(!p)
            return;
        if(p->value==val) {
            if(p->l&&p->r) {
                p->value=find_DeleteMin(p->r);
            } else {
                BST_Node *tmp = p;
                if(p->l)
                    p=p->l;
                else
                    p=p->r;
                delete tmp;
            }
        }
        if(val < p->value)
            Delete(p->l,val);
        else
            Delete(p->r,val);
    }
    BST_Node *Find(BST_Node *p,int val) {
        if(!p)
            return NULL;
        if(p->value==val)
            return p;
        else if(p->value>val)
            return Find(p->l,val);
        else
            return Find(p->r,val);
    }
    void midordervisit(BST_Node *p) {
        if(p) {
            midordervisit(p->l);
            printf("%d\n",p->value);
            midordervisit(p->r);
        }
    }
};
