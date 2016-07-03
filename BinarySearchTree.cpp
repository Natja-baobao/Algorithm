#include <iostream>
using namespace std;
#include <vector>

class BinarySearchTree {
    private:
        struct tree_node {
            int data;
            tree_node* left;
            tree_node* right;
        };
        tree_node* root;
    public:
        BinarySearchTree() {
            root = NULL;
        }
        bool isEmpty() {
            return root == NULL;
        }
        void print_inorder();
        void inorder(tree_node*);
        void print_preorder();
        void preorder(tree_node*);
        void print_postorder();
        void postorder(tree_node*);
        void insert(int);
        void remove(int);
};

//smaller elements go left, larger elements go right
void BinarySearchTree::insert(int d) {
    //get ready for an insert-node
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = d;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
    
    //if this is a new tree
    if(isEmpty())
        root = t;
    else {
        //all insertions are as leaf nodes
        tree_node* curr;
        curr = root;
        //find the node's parent
        while(curr) {
            parent = curr;
            if(t->data > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
        if(t->data < parent->data)
            parent->left = t;
        else
            parent->right = t;
        //cout<<" "<<t->data<<" "<<endl;
    }
}

void BinarySearchTree::remove(int d) {
    //locate the element
    bool found = false;
    if(isEmpty()) {
        cout<<"this tree is empty!"<<endl;
        return;
    }
    tree_node* curr;
    tree_node* parent;
    curr = root;
    while(curr != NULL) {
        if(curr->data == d) {
            found = true;
            break;
        }
        else {
            parent = curr;
            if(d > curr->data)
                curr = curr->right;
            else
                curr = curr->left;
        }
    }
    if(!found) {
            cout<<"data not found!"<<endl;
            return;
    }
    
    //1. node with a single child
    if((curr->left == NULL && curr->right != NULL) || (curr->left != NULL && curr->right == NULL)) {
        if(curr->left == NULL && curr->right != NULL) {
            if(curr == parent->right) {
                    parent->right = curr->right;
                    delete curr;
            }
            else {
                parent->left = curr->right;
                delete curr;
            }
        }
        else {
            if(curr == parent->left) {
                parent->left = curr->left;
                delete curr;
            }
            else {
                parent->right = curr->left;
                delete curr;
            }
        }
        return;
    }
    //leaf node
    if(curr->left == NULL && curr->right == NULL) {
        if(curr == parent->left)
            parent->left = NULL;
        else
            parent->right = NULL;
        delete curr;
        return;
    }
    //node with 2 children
    if(curr->left != NULL && curr->right != NULL) {
        tree_node* chkr;
        chkr = curr->right;
        if(chkr->left == NULL && chkr->right == NULL) {
            curr = chkr;
            delete chkr;
            curr->right = NULL;
        }
        else {
            if(curr->right->left != NULL) {
                tree_node* lcurr;
                tree_node* lcurrp;
                lcurrp = curr->right;
                lcurr = curr->right->left;
                while(lcurr->left != NULL) {
                    lcurrp = lcurr;
                    lcurr = lcurr->left;
                }
                curr->data = lcurr->data;
                delete lcurr;
                lcurrp->left = NULL;
            }
            else {
                tree_node* tmp;
                tmp = curr->right;
                curr->data = tmp->data;
                curr->right = tmp->right;
                delete tmp;
            }
        }
        return;
    }  
}

void BinarySearchTree::print_inorder() {
    inorder(root);
}

void BinarySearchTree::inorder(tree_node* p) {
    if(p != NULL) {
        if(p->left)
            inorder(p->left);
        cout<<" "<<p->data<<" ";
        if(p->right)
            inorder(p->right);
    }
    else
        return;             
}

void BinarySearchTree::print_preorder() {
    preorder(root);
}

void BinarySearchTree::preorder(tree_node* p) {
    if(p != NULL) {
        cout<<" "<<p->data<<" ";
        if(p->left)
            preorder(p->left);
        if(p->right)
            preorder(p->right);
    }
    else
        return;             
}

void BinarySearchTree::print_postorder() {
    postorder(root);
}

void BinarySearchTree::postorder(tree_node* p) {
    if(p != NULL) {
        if(p->left)
            postorder(p->left);
        if(p->right)
            postorder(p->right);
        cout<<" "<<p->data<<" ";
    }
    else
        return;             
}

int main()
{
    int myints[] = {5, 4, 7, 9, 3, 1, 2, 11, 8, 10, 12};
    vector<int> ini;
    ini.assign(myints, myints+11); 
    BinarySearchTree Tree;
    for(int i = 0; i<ini.size(); ++i)
        Tree.insert(ini[i]);
    cout<<"preorder:"<<endl;
    Tree.print_preorder();
    cout<<endl;
    Tree.remove(4);
    cout<<"inorder:"<<endl;
    Tree.print_inorder();
    cout<<endl;
    Tree.remove(9);
    cout<<"postorder:"<<endl;
    Tree.print_postorder();
    
    return 0;
}
