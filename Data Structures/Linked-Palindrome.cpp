#include <iostream>
#include <vector>


struct node {
    int value;
    struct node* next;

    public:
        node(int val) : value(val), next(nullptr) {}
        node(int val, struct node* n) : value(val), next(n) {}

        int next_value() {
            if (next != nullptr) {
                return next->value;
            }
            return 0; // or some default value
        }
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
        void Insert_right_of_element(struct node **head, int val, int pos){
            struct node* new_node = new node(val);
            if (*head == nullptr) {
                *head = new_node;
            } else {
                struct node* current = *head;
                for (int i = 0; i < pos - 1 && current != nullptr; i++){
                    current = current->next;
                }
                if (current != nullptr){
                    new_node->next = current->next;
                    current->next = new_node;
                }
            }
        }
        void Insert_left_of_Element(struct node **head, int val, int pos){
            if (pos == 0){
                Insert_Start(head, val);
            } else{
                Insert_right_of_element(head, val, pos - 1);
            }
        }

        // Deleting
        void Delete_First_Element(struct node **head){
            if (*head != nullptr){
                struct node* temp = *head;
                *head = (*head)->next;
                delete temp;
            }
        }
        void Delete_last_Element(struct node **head){
            if (*head == nullptr){
                return;
            }
            if ((*head)->next == nullptr){
                delete *head;
                *head = nullptr;
                return;
            }
            struct node* current = *head;
            while (current->next->next != nullptr){
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }           
        void Delete_Selected_Element(struct node **head, int pos){
            if (*head == nullptr){
                return;
            }
            if (pos == 0){
                Delete_First_Element(head);
                return;
            }
            struct node* current = *head;
            for (int i = 0; i < pos - 1 && current != nullptr; i++){
                current = current->next;
            }
            if (current != nullptr && current->next != nullptr){
                struct node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }
};

void enter_values(node** head) {
    int val;
    while (true){
        std::cout << "Enter a value (0 to stop): ";
        std::cin >> val;
        if (val == 0) {
            break;
        }

        node* new_node = new node(val);
        if (*head == nullptr){
            *head = new_node;
        } else {
            node* current = *head;
            while (current->next != nullptr){
                current = current->next;
            }
            current->next = new_node;
        }
    }
}

bool check_palindrome(struct node *head){
    if(head == nullptr){
        return true;
    }
    int count, i;
    std::vector<int> values;
    struct node* current = head;

    while (current->next != nullptr){
        values.push_back(current->value);
        current = current->next;
        count++;
    } 
    values.push_back(current->value);
    
    int len=values.size();
    for(i=0; i<len/2; i++) {
        if(values[i] != values[len-1-i]){
            return false;
        }
    }
    return true;
}   

bool check_palindrome_fast(struct node *head){
    if(head == nullptr){
        return true;
    }
    struct node* slow = head;
    struct node* fast = head;
    std::vector<int> values;

    while(fast != nullptr && fast->next != nullptr){
        values.push_back(slow->value);
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast != nullptr){
        slow = slow->next;
    }

    for(int i = values.size() - 1; i >= 0; i--){
        if(values[i] != slow->value){
            return false;
        }
        slow = slow->next;
    }

    return true;
}

void main(){
    node* head = nullptr;
    enter_values(&head);
}

