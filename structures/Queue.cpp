#include <iostream>
using namespace std;

struct Queue {
    int* arr;
    int front;
    int rear;
    int capacity;

    public:
        // Constructor to initialize queue
        Queue(int size) {
            capacity = size;
            arr = new int[capacity];
            front = -1;
            rear = -1;
        }

        // Destructor to free memory
        ~Queue() {
            delete[] arr;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return (front == -1 || front > rear);
        }

        // Check if the queue is full
        bool isFull() {
            return (rear == capacity - 1);
        }

        // Insert (Enqueue) an element at the rear
        void insert(int value) {
            if (isFull()) {
                cout << "Queue Overflow! Cannot insert " << value << endl;
                return;
            }
            if (front == -1) {
                front = 0; // Set front to 0 when inserting the first element
            }
            arr[++rear] = value;
            cout << "Inserted: " << value << endl;
        }

        // Deletion (Dequeue) an element from the front
        void deletion() {
            if (isEmpty()) {
                cout << "Queue Underflow! Queue is empty." << endl;
                return;
            }
            cout << "Deleted: " << arr[front++] << endl;

            // Reset pointers if the last element was just deleted
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }

        // View the front element without removing it
        int peek() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return -1;
            }
            return arr[front];
        }

        // Display all elements currently in the queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            cout << "Queue elements: ";
            for (int i = front; i <= rear; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q(3); // Create a queue of capacity 3

    q.insert(10);
    q.insert(20);
    q.insert(30);
    q.insert(40); // Triggers isFull()

    q.display();

    q.deletion();
    q.deletion();
    q.display();

    q.deletion();
    q.deletion(); // Triggers isEmpty()

    return 0;
}
