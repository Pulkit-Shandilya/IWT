#include <iostream>


struct node {
    int value;
    struct node* next;

    public:
        node(int val) : value(val), next(nullptr) {}

        void Insert_Start(struct node **head, int val) {
            struct node* new_node = new node(val);
            new_node->next = *head; 
            *head = new_node;
        }
        void Insert_End(struct node **head, int val) {
            struct node* new_node = new node(val);
            if (*head == nullptr) {
                *head = new_node;
            } else {
                struct node* current = *head;
                while (current->next != nullptr) {
                    current = current->next;
                }
                current->next = new_node;
            }
        }
        void Insert_right_of_element(struct node **head, int val, int pos) {
            struct node* new_node = new node(val);
            if (*head == nullptr) {
                *head = new_node;
            } else {
                struct node* current = *head;
                for (int i = 0; i < pos - 1 && current != nullptr; i++) {
                    current = current->next;
                }
                if (current != nullptr) {
                    new_node->next = current->next;
                    current->next = new_node;
                }
            }
        }
        void Insert_left_of_Element(struct node **head, int val, int pos) {
            if (pos == 0) {
                Insert_Start(head, val);
            } else {
                Insert_right_of_element(head, val, pos - 1);
            }
        }
        // Deleting

        void Delete_First_Element(struct node **head){
            if (*head != nullptr) {
                struct node* temp = *head;
                *head = (*head)->next;
                delete temp;
            }
        }
        void Delete_last_Element(struct node **head){
            if (*head == nullptr) {
                return;
            }
            if ((*head)->next == nullptr) {
                delete *head;
                *head = nullptr;
                return;
            }
            struct node* current = *head;
            while (current->next->next != nullptr) {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }           
        void Delete_Selected_Element(struct node **head, int pos) {
            if (*head == nullptr) {
                return;
            }
            if (pos == 0) {
                Delete_First_Element(head);
                return;
            }
            struct node* current = *head;
            for (int i = 0; i < pos - 1 && current != nullptr; i++) {
                current = current->next;
            }
            if (current != nullptr && current->next != nullptr) {
                struct node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
};
