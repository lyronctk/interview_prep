#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;


struct BTNode {
    int value;
    BTNode *left, *right;

    BTNode(int val) : 
        value(val), left(nullptr), right(nullptr) {}
};


class BinarySearchTree {

    public: 

        BinarySearchTree() : root(nullptr) {}


        void insert(int val) {
            root = recursiveInsert(root, val);
        }


        void inOrder() {
            recursiveInOrder(root);
            printf("\n");
        }


        void deleteNode(int val) {
            root = recursiveDelete(root, val);
        }


    private:

        BTNode *root;


        BTNode* recursiveInsert(BTNode *current, int val) {
            if(current == nullptr) {
                return new BTNode(val);
            }

            if(val > current->value) {
                current->right = recursiveInsert(current->right, val);
            }
            else if(val < current->value) {
                current->left = recursiveInsert(current->left, val);
            }
            return current;
        }


        void recursiveInOrder(BTNode *current) {
            if(current != nullptr) {
                recursiveInOrder(current->left);
                printf("%d ", current->value);
                recursiveInOrder(current->right);
            }
        }


        BTNode* recursiveDelete(BTNode *current, int val) {
            if(current == nullptr) {
                return current;
            }

            if(val > current->value) {
                current->right = recursiveDelete(current->right, val);
            }
            else if(val < current->value) {
                current->left = recursiveDelete(current->left, val);
            }
            else {
                if(current->left == nullptr) {
                    BTNode *temp = current->right;
                    delete current;
                    return temp;
                }
                else if(current->right == nullptr) {
                    BTNode *temp = current->left;
                    delete current;
                    return temp;
                }

                BTNode *minNode = findMinNode(current->right);
                current->value = minNode->value;
                current->right = recursiveDelete(current->right, 
                    minNode->value);
            }
            return current;
        }


        BTNode* findMinNode(BTNode *current) {
            if(current->left == nullptr) {
                return current;
            }
            return findMinNode(current->left);
        }
};


int main() {

    BinarySearchTree BST;
    BST.insert(50);
    BST.insert(30);
    BST.insert(20);
    BST.insert(40);
    BST.insert(70);
    BST.insert(60);
    BST.insert(80);
  
    printf("Inorder traversal of the given tree: "); 
    BST.inOrder(); 
  
    printf("\nDELETE 20\n"); 
    BST.deleteNode(20);
    printf("Inorder traversal of the modified tree: "); 
    BST.inOrder(); 
  
    printf("\nDELETE 30\n"); 
    BST.deleteNode(30);
    printf("Inorder traversal of the modified tree: "); 
    BST.inOrder(); 
  
    printf("\nDELETE 50\n"); 
    BST.deleteNode(50);
    printf("Inorder traversal of the modified tree: "); 
    BST.inOrder(); 
  
}

