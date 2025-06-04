#include <iostream>
#include <string>

using namespace std;

// Tree structure for displaying the tree
struct Tree {
    Tree* prev;
    string str;

    Tree(Tree* prev, string str) {
        this->prev = prev;
        this->str = str;
    }

    void showTrees(Tree* p) {
        if (p == NULL)
            return;

        showTrees(p->prev);

        cout << p->str;
    }
};

// Node structure for the binary tree
class node {
public:
    int info;
    node* left;
    node* right;

    node(int val) {
        info = val;
        left = NULL;
        right = NULL;
    }

    // Search for a value in the tree and return the node if found
    node* searchValue(int value) {
        if (info == value)
            return this;

        node* result = NULL;
        if (left)
            result = left->searchValue(value);
        if (result)
            return result;
        if (right)
            result = right->searchValue(value);
        return result;
    }

    int getLevel(node* n) {
        return getNodeLevel(this, n, 0);
    }
int getNodeLevel(node* ptr, node* n, int level) {
    if (ptr == NULL)
        return 0;
    if (ptr == n)
        return level;

    int l = getNodeLevel(ptr->left, n, level + 1);
    int r = getNodeLevel(ptr->right, n, level + 1);

    if (l == 0)
        return r;
    else if (r == 0)
        return l;
    else
        return 0;
}

};

node* parent(node* curr, node* p, node* par) {
    if (curr == NULL)
        return NULL;

    if (curr == p) {
        return par;
    } else {
        node* t = NULL;
        t = parent(curr->left, p, curr);
        if (t != NULL)
            return t;
        else {
            t = parent(curr->right, p, curr);
            return t;
        }
    }
}

node* sibling(node* root, node* p) {
    node* par = parent(root, p, root);

    if (par->left == p)
        return par->right;
    else
        return par->left;
}

void deleteTree(node* leaf) {
    if (leaf != NULL) {
        deleteTree(leaf->left);
        deleteTree(leaf->right);
        delete leaf;
    }
}

void checkDuplicates(node** n, int val) {
    if (*n == NULL) {
        *n = new node(val);
        return;
    }

    if (val > (*n)->info) {
        if ((*n)->right != NULL)
            checkDuplicates(&(*n)->right, val);
        else {
            (*n)->right = new node(val);
            return;
        }
    } else if (val < (*n)->info) {
        if ((*n)->left != NULL)
            checkDuplicates(&(*n)->left, val);
        else {
            (*n)->left = new node(val);
            return;
        }
    } else if (val == (*n)->info) {
        cout << val << " is repeated..." << endl;
    }
}


int maxDepth(node* n) {
    if (n == NULL)
        return -1;
    else {
        int lDepth = maxDepth(n->left);
        int rDepth = maxDepth(n->right);

        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}

void preOrder(node* n) {
    if (n == NULL)
        return;

    cout << n->info << "\t";
    preOrder(n->left);
    preOrder(n->right);
}

void inOrder(node* n) {
    if (n == NULL)
        return;

    inOrder(n->left);
    cout << n->info << "\t";
    inOrder(n->right);
}

void postOrder(node* n) {
    if (n == NULL)
        return;

    postOrder(n->left);
    postOrder(n->right);
    cout << n->info << "\t";
}

void printTree(node* root, Tree* prev, bool isRight) {
    if (root == NULL)
        return;

    string prev_str = "    ";
    Tree* treeNode = new Tree(prev, prev_str);

    printTree(root->right, treeNode, true);

    if (!prev)
        treeNode->str = "---";
    else if (isRight) {
        treeNode->str = ".---";
        prev_str = "   |";
    } else {
        treeNode->str = "`---";
        prev->str = prev_str;
    }

    treeNode->showTrees(treeNode);
    cout << root->info << endl;

    if (prev)
        prev->str = prev_str;
    treeNode->str = "   |";

    printTree(root->left, treeNode, false);
}

node* searchValue(node* current, int value) {
    if (current == NULL)
        return NULL;

    if (current->info == value)
        return current;
    else {
        node* leftResult = searchValue(current->left, value);
        if (leftResult)
            return leftResult;
        return searchValue(current->right, value);
    }
}

void insertLeft(node* parent, int value) {
    if (parent->left == NULL) {
        parent->left = new node(value);
        cout << "The Value " << value << " is inserted on the left " << parent->info << endl;
    } else {
        cout << "Left child is not empty. Do you want to overwrite (Y/N)? ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            parent->left->info = value;
            cout << "The Value " << value << " is inserted on the left " << parent->info << endl;
        } else {
            cout << "No changes made." << endl;
        }
    }
}

void insertRight(node* parent, int value) {
    if (parent->right == NULL) {
        parent->right = new node(value);
        cout << "The Value " << value << " inserted on the right of " << parent->info << endl;
    } else {
        cout << "Right child is not empty. Do you want to overwrite (Y/N)? ";
        char choice;
        cin >> choice;
        if (choice == 'Y' || choice == 'y') {
            parent->right->info = value;
            cout << "The Value " << value << " overwritten on the right of " << parent->info << endl;
        } else {
            cout << "No changes made." << endl;
        }
    }
}
int getLevel(node *ptr, node* n,int level) 
{
    if (ptr == NULL)
        return 0;
    if (ptr == n)
        return level;

    int l = getLevel(ptr->left, n, level+1); 
    int r = getLevel(ptr->right, n, level+1);

    if(l == 0)
        return r;
    else if(r == 0)
        return l;
    else
        return 0;
    // return l | r;
    // return getLevel(ptr->left, val, level+1) | 
            // getLevel(ptr->right, val, level+1);
}

int main() {
    int value;
    node* root = new node(5);

   

    while (true) {
        cout << "1. Add Primary nodes" << endl;
        cout << "2. Search and Insert" << endl;
        cout << "3. Check Max Depth" << endl;
        cout << "4. In Order" << endl;
        cout << "5. Pre Order" << endl;
        cout << "6. Post Order" << endl;
        cout << "7. Exit" << endl;
        cout << "8. Search Value" << endl;
        cout << "9. Get Level" << endl;
        cout << "Enter your choice: ";
        int option;
        cin >> option;

        if (option == 1) {
            cout << "1. For Left" << endl;
            cout << "2. For Right" << endl;
            cout << "Enter your choice: ";
            int choice;
            cin >> choice;
            if (choice == 1) {
                cout << "Enter the Value: ";
                cin >> value;
                insertLeft(root, value);
            } else if (choice == 2) {
                cout << "Enter the Value: ";
                cin >> value;
                insertRight(root, value);
            } else {
                cout << "Invalid choice!" << endl;
            }
        } else if (option == 2) {
            cout << "Enter the value for search and then edit or replace" << endl;
            int searchValue1;
            cin >> searchValue1;
            node* got = searchValue(root, searchValue1);
            if (got) {
                cout << "Found " << searchValue1 << " in the tree. Now press 1 for left and 2 for right: ";
                int choice;
                cin >> choice;
                cout << "Enter the value to insert: ";
                int Req_Value;
                cin >> Req_Value;
                if (choice == 1) {
                    insertLeft(got, Req_Value);
                } else if (choice == 2) {
                    insertRight(got, Req_Value);
                } else {
                    cout << "Invalid choice!" << endl;
                }
            } else {
                cout << searchValue1 << " not found in the tree." << endl;
            }
        } else if (option == 3) {
            int Height = maxDepth(root);
            cout << "Depth of the tree: " << Height << endl;
        } else if (option == 4) {
            cout << "In-Order Traversal: ";
            inOrder(root);
            cout << endl;
        } else if (option == 5) {
            cout << "Pre-Order Traversal: ";
            preOrder(root);
            cout << endl;
        } else if (option == 6) {
            cout << "Post-Order Traversal: ";
            postOrder(root);
            cout << endl;
        } else if (option == 7) {
            break;
        } 
        else if (option == 8) {
            int searched;
            cout<<"Enter the Value"<<endl;
            cin>>searched;  
        node* get = searchValue(root, searched);
        if(get) 
        {
            cout<<"Requried Value Found "<<endl;
        }
        else{
            cout<<"Not Found"<<endl;
        }
        }
       else if (option == 9) {
        int Value1 ;
        cin >> Value1;
        node* got = searchValue(root, Value1);

        if (got) {
            int level = root->getLevel(got);
            cout << "Level of node with value " << searchValue << " is " << level << endl;
        } else {
            cout << "Node with value " << searchValue << " not found in the tree." << endl;
        }
    }
    }
    printTree(root, NULL, false);
    deleteTree(root);

    return 0;
}
