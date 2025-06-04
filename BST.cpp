    #include <iostream>
    using namespace std;

    class Tree {
    public:
        int data;
        Tree* left;
        Tree* right;

        Tree(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    class BST {
    private:
        Tree* root;

    public:
        BST() : root(nullptr) {}

        bool check_empty() {
            return root == nullptr;
        }

        Tree* insert(Tree* root, int data) {
            if (root == nullptr) {
                return new Tree(data);
            }
            if (data > root->data) {
                root->right = insert(root->right, data);
            } else if (data < root->data) {
                root->left = insert(root->left, data);
            }
            return root;
        }

        Tree* remove(Tree* root, int data) {
            if (root == nullptr) {
                return root;
            }
            if (data > root->data) {
                root->right = remove(root->right, data);
            } else if (data < root->data) {
                root->left = remove(root->left, data);
            } else {
                if (root->left == nullptr) {
                    Tree* temp = root->right;
                    delete root;
                    return temp;
                } else if (root->right == nullptr) {
                    Tree* temp = root->left;
                    delete root;
                    return temp;
                }
                Tree* temp = minValueNode(root->right);
                root->data = temp->data;
                root->right = remove(root->right, temp->data);
            }
            return root;
        }

        Tree* minValueNode(Tree* node) {
            while (node->left != nullptr) {
                node = node->left;
            }
            return node;
        }
       int Pre(Tree* root) {
    if (root == nullptr) {
        return -1; // or any other default value to indicate an empty tree
    }
    cout << root->data << " ";
    Pre(root->left);
    Pre(root->right);
    return root->data;
}

        void inOrder(Tree* root) {
            if (root == nullptr) {
                return;
            }
            inOrder(root->left);
            cout << root->data << " ";
            inOrder(root->right);
        }



        Tree* search(Tree* root, int key) {
            if (root == nullptr) {
                cout << "Tree is empty" << endl;
                return nullptr;
            }

            if (root->data == key) {
                cout << "Value is Found: " << root->data << endl;
                return root;
            }

            if (key < root->data) {
                return search(root->left, key);
            }

            return search(root->right, key);
        }
        void destroyTree(Tree* node) {
            if (node) {
                destroyTree(node->left);
                destroyTree(node->right);
                delete node;
            }
        }
    };

    int main() {
        BST bst;
        Tree* root = nullptr; 

        root = bst.insert(root, 50);
        root = bst.insert(root, 30);
        root = bst.insert(root, 70);
        root = bst.insert(root, 20);
        root = bst.insert(root, 50);
        root = bst.insert(root, 60);
        root = bst.insert(root, 80);

        cout << "Is BST empty? " << (bst.check_empty() ? "Yes" : "No") << endl;

        bst.search(root, 40);
         cout<<"hi";
        cout << "Pre-order traversal: ";
    cout<<bst.Pre(root);
    cout << endl;
        cout << "In-order traversal: ";
        bst.inOrder(root);
        cout << endl;

        root = bst.remove(root, 30);
        cout << "In-order traversal after removing 30: ";
        bst.inOrder(root);
        cout << endl;

        // Destroy the tree
        bst.destroyTree(root); // Ensure this is the last operation on 'root'

        return 0;
    }


