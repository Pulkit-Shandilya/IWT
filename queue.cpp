#include <iostream>

struct queue {
    int data[100];
    int front;
    int rear;
    int size;



public:
    queue() : front(0), rear(-1), size(0) {}

    int PopElement() {
        if (size == 0) {
            std::cout << "Queue is empty" << std::endl;
            return -1;
        }
        int poppedValue = data[front];
        rear = (rear + 1) % 100; // circular code . . .uses the modulus to cicle back to the start
        size--;                   
        return poppedValue;
    }
    
    void insert(int value) {
        if (size == 100) {
            std::cout << "Queue is full" << std::endl;
            return;
        }
        rear = (rear + 1) % 100;
        data[rear] = value;
        size++;
    }
};

int main(int argc, char const *argv[])
{
    queue q;
    
    q.insert(10);
    q.insert(20);
    q.insert(30);

    std::cout << "Popped: " << q.PopElement() << std::endl; // Should print 10
    std::cout << "Popped: " << q.PopElement() << std::endl; // Should print 20
    std::cout << "Current size: " << q.size << std::endl;   // Should print 1

    return 0;
}