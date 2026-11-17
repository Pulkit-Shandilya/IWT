#include <iostream>

struct node {
    int value;
    struct node* left;
    struct node* right;


    public:
        node(int val) : value(val), left(nullptr), right(nullptr) {}

        void insertNode(struct node** root, int val) {
            if (*root == nullptr) {
                *root = new node(val);
            } else {
                if (val < (*root)->value) {
                    insertNode(&((*root)->left), val);
                } else {
                    insertNode(&((*root)->right), val);
                }
            }
        }

        void InorderBST(struct node* root) {
            if (root != nullptr) {
                InorderBST(root->left);
                std::cout << root->value << " ";
                InorderBST(root->right);
            }
        }

        void InorderBST(struct node* root, int result[], int index) {
            if (root != nullptr) {
                InorderBST(root->left, result, index);
                result[index++] = root->value;
                InorderBST(root->right, result, index);
            }
        }

        void Searching(struct node* root, int target){
            if (root == nullptr) {
                std::cout << "Element not found";
                return;
            }
            else{
                if (root->value == target) {
                    std::cout << "Element found";
                }
                else if (target < root->value) {
                    Searching(root->left, target);
                }
                else {
                    Searching(root->right, target);
                }
            }
        }


        int* BSTSorted(int *arr[]) {
            int result[200];
            struct node* head = nullptr;
            for (int i = 0; i < 200; i++) {
                insertNode(&head, *arr[i]);
            }
            InorderBST(head , result, 0);
            return result;
        }

    };