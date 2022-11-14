#include <iostream>

template <typename T>
class BinarySearchTree
{
    struct Node
    {
        int key;
        T val;
        Node *l;
        Node *r;
        Node() {
            l = nullptr;
            r = nullptr;
        }
    };

    Node* root;

    Node* getMaxNode(Node* cur) {
        if (!cur) {
            return nullptr;
        }
        while(cur->r) {
            cur = cur->r;
        } 
        // if there is no right node, this is maximum node
        return cur;
    }

    Node* getMinNode(Node* cur) {
        if(!cur) {
            return nullptr;
        }
        while(cur->l) {
            cur = cur->l;
        }
        // if there is no left node, this is minimum node
        return cur;
    }

    void deleteNode(Node* cur) {
        if (cur == nullptr)
            return;

        Node* maxNode = getMaxNode(cur->l);
        if (maxNode) {
            cur->key = maxNode->key;
            cur->val = maxNode->val;
            deleteNode(maxNode);
        } else {
            Node* minNode = getMinNode(cur->r);
            if (minNode) {
                cur->key = minNode->key;
                cur->val = minNode->val;
                deleteNode(minNode);              
            } else {
                // just remove cur;
            }
        }
    }

public:
    void add(int k, T v) {
        if (root == nullptr) {
            root = new Node(k, v);
            return;
        }

        Node* cur = root;
        while (curr) {
            if (key > cur->key) {
                cur = cur->r;
            } else if (key < cur->key) {
                cur = cur->l;
            } else {
                cur->key = k; // update
                return;
            }
        }
        cur = new Node(k, v);
    }

    bool delete(int key) {
        root = delete(root, key);
    }

    Node* delete(Node* node, int key) {
        if (node == nullptr)
            return nullptr;

        if (node->key > key) {
            // find left
            node->left = delete(node->left, key);
        } else if (node->key < key) {
            // find right
            node->right = delete(node->right, key);
        } else {
            // found, delete this node, but take care of children
            if (node->right == nullptr) {
                Node* max = deleteMax(node->left);
                node->key = max->key;
                node->val = max->val;
                delete max;
                return node;
            } else if (node->left == nullptr) {
                Node* min = deleteMin(node->right);
                node->key = max->key;
                node->val = max->val;
                delete min;
                return node;
            } else {
                delete node;
                return nullptr;
            }

        }
    }

    bool search(int key, T& value) {

    }
}