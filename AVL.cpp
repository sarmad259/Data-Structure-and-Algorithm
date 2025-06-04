
class AVL {
public:
    class Node {
    public:
        int info;
        Node *left;
        Node *right;
        int height;

        Node(int info) {
            this->info = info;
            left = nullptr;
            right = nullptr;
            height = 1; // Initialize height to 1 for leaf nodes
        }
    };

    int height(Node *m) {
        if (m == nullptr)
            return 0; // Return 0 for a null node
        return m->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    Node *rightRotate(Node *root) {
        Node *child = root->left;
        Node *subChild = child->right;

        // Perform rotation
        child->right = root;
        root->left = subChild;

        // Update height
        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node *leftRotate(Node *root) {
        Node *child = root->right;
        Node *subChild = child->left;

        // Perform rotation
        child->left = root;
        root->right = subChild;

        // Update height
        root->height = max(height(root->left), height(root->right)) + 1;
        child->height = max(height(child->left), height(child->right)) + 1;

        return child;
    }

    Node *insert(Node *n, int value) {
        /* Normal BST Task */
        if (n == nullptr) {
            return new Node(value);
        }
        if (value < n->info) {
            n->left = insert(n->left, value);
        } else if (value > n->info) {
            n->right = insert(n->right, value);
        } else
            return n;
        n->height = 1 + max(height(n->left), height(n->right));
        /* Checking The Level or Balance of the Tree */
        int bal = getBalance(n);
        if (bal > 1 && value < n->left->info) /* Here LL Case */
            return rightRotate(n); /* LL=R, RR=L, LR=RL, RL=LR */
        else if (bal < -1 && value > n->right->info)
            return leftRotate(n); /* RR Case */
        else if (bal > 1 && value > n->left->info) {
            n->left = leftRotate(n->left); /* Here Left Right Case */
            return rightRotate(n);
        } else if (bal < -1 && value < n->right->info) {
            n->right = rightRotate(n->right); /* Here Right Left Case */
            return leftRotate(n);
        }
        return n;
    }

    Node *minval(Node *n) {
        Node *current = n;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    Node *deleteNode(Node *n, int value) {
        if (n == nullptr) {
            return n;
        }
        if (value < n->info) {
            n->left = deleteNode(n->left, value);
        } else if (value > n->info) {
            n->right = deleteNode(n->right, value);
        } else {
            if (n->left == nullptr || n->right == nullptr) {
                Node *temp = (n->left) ? n->left : n->right;
                if (temp == nullptr) {
                    temp = n;
                    n = nullptr;
                } else {
                    *n = *temp;
                    delete temp;
                }
            } else {
                Node *temp = minval(n->right);
                n->info = temp->info;
                n->right = deleteNode(n->right, temp->info);
            }
        }
        if (n == nullptr) {
            return n;
        }
        n->height = 1 + max(height(n->left), height(n->right));
        int bal = getBalance(n);
        if (bal > 1 && getBalance(n->left) >= 0) {
            return rightRotate(n); // LL case
        } else if (bal > 1 && getBalance(n->left) < 0) {
            n->left = leftRotate(n->left);
            return rightRotate(n); // LR case
        } else if (bal < -1 && getBalance(n->right) <= 0) {
            return leftRotate(n); // RR case
        } else if (bal < -1 && getBalance(n->right) > 0) {
            n->right = rightRotate(n->right);
            return leftRotate(n); // RL case
        }
        return n;
    }

    int getBalance(Node *level) {
        if (level == nullptr)
            return 0;
        return height(level->left) - height(level->right);
    }


    AVL() : root(nullptr) {}

    
};
