#include <iostream>
#include <cstdlib>

typedef struct BSTNode {
    int value;
    int index;
    struct BSTNode *left;
    struct BSTNode *right;
} BSTNode;

typedef struct BST {
    int currentIndex;
    BSTNode *root;
} BST;

BSTNode* createNode(int value, int index) {
    BSTNode *newNode = (BSTNode*)malloc(sizeof(BSTNode));
    newNode->value = value;
    newNode->index = index;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

BST* createTree() {
    BST *tree = (BST*)malloc(sizeof(BST));
    tree->currentIndex = 1;
    tree->root = NULL;
    return tree;
}


BSTNode* search(BSTNode *node, int value) {
    if (node == NULL) {
        return NULL;
    }

    if (value == node->value) {
        return node;
    }

    if (value < node->value) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

BSTNode* insert(BST *tree, BSTNode *node, int value, int index) {
    if (node == NULL) {
        BSTNode *newNode = createNode(value, tree->currentIndex);
        tree->currentIndex++;
        return newNode;
    }

    if (value < node->value) {
        node->left = insert(tree, node->left, value, node->index+1);
    } 
    else if (value > node->value) {
        node->index++;
        node->right = insert(tree, node->right, value, node->index-1);
    }

    return node;
}

int main() {
    int a;
    std::cin >> a;

    BST *tree = createTree();

    for (int i = 0; i < a; i++) {
        int opr, value;
        std::cin >> opr >> value;

        if (opr == 1) {
            tree->root = insert(tree, tree->root, value);
        } 
        else {
            BSTNode *result = search(tree->root, value);

            if (result == NULL) {
                std::cout << "Data tidak ada" << '\n';
            } 
            else {
                std::cout << result->index << '\n';
            }
        }
    }

    return 0;
}