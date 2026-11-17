#include <iostream>
using namespace std;

struct CircularQueue {
    private:
        int* arr;
        int front;
        int rear;
        int capacity;

    public:
        // Constructor
        CircularQueue(int size) {
            capacity = size;
            arr = new int[capacity];
            front = -1;
            rear = -1;
        }

        // Destructor
        ~CircularQueue() {
            delete[] arr;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return (front == -1);
        }

        // Check if the queue is full
        bool isFull() {
            return ((rear + 1) % capacity == front);
        }

        // Insert (Enqueue) an element
        void insert(int value) {
            if (isFull()) {
                cout << "Queue Overflow! Cannot insert " << value << endl;
                return;
            }
            
            // If inserting the first element
            if (isEmpty()) {
                front = 0;
                rear = 0;
            } else {
                // Wrap rear around to 0 if it reaches the end
                rear = (rear + 1) % capacity;
            }
            
            arr[rear] = value;
            cout << "Inserted: " << value << endl;
        }

        // Deletion (Dequeue) an element
        void deletion() {
            if (isEmpty()) {
                cout << "Queue Underflow! Queue is empty." << endl;
                return;
            }
            
            cout << "Deleted: " << arr[front] << endl;

            // If only one element was left, reset the queue
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                // Wrap front around to 0 if it reaches the end
                front = (front + 1) % capacity;
            }
        }

        // Display all elements in the circular queue
        void display() {
            if (isEmpty()) {
                cout << "Queue is empty." << endl;
                return;
            }
            
            cout << "Queue elements: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear) break;
                i = (i + 1) % capacity;
            }
            cout << endl;
        }
};

int main() {
    CircularQueue cq(3); // Capacity of 3

    cq.insert(10);
    cq.insert(20);
    cq.insert(30);
    cq.insert(40); // Triggers isFull()

    cq.display();

    cq.deletion(); // Removes 10, freeing index 0
    cq.deletion(); // Removes 20, freeing index 1
    
    // Insert new elements into the freed spaces at the front
    cq.insert(40); 
    cq.insert(50); 

    cq.display(); // Prints: 30 40 50

    return 0;
}
