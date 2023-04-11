#include <iostream>
using namespace std;

class Queue {
private:
    int queue[100];
    int front, rear, capacity;

public:
    Queue() {
        front = rear = -1;
        capacity = 100;
    }

    void push(int value) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }

        if (isempty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        queue[rear] = value;
    }

    int pop() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int value = queue[front];

        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }

        return value;
    }

    int size() {
        if (isempty()) {
            return 0;
        }

        if (front <= rear) {
            return rear - front + 1;
        }
        else {
            return capacity - front + rear + 1;
        }
    }

    void reverse() {
        int start = front;
        int end = rear;

        while (start < end) {
            int temp = queue[start];
            queue[start] = queue[end];
            queue[end] = temp;
            start = (start + 1) % capacity;
            end = (end - 1 + capacity) % capacity;
        }
    }

    int find(int value) {
        if (isempty()) {
            return -1;
        }

        int i = front;

        while (i != rear) {
            if (queue[i] == value) {
                return value;
            }

            i = (i + 1) % capacity;
        }

        if (queue[rear] == value) {
            return value;
        }

        return -1;
    }

    bool isfull() {
        return (rear + 1) % capacity == front;
    }

    bool isempty() {
        return front == -1;
    }
};


int main()
{
    Queue my_queue;
    my_queue.push(10);
    my_queue.push(20);
    my_queue.push(30);
    my_queue.push(40);
    my_queue.push(50);
    cout << my_queue.pop() << endl;
    cout << my_queue.pop() << endl; 
    cout << my_queue.pop() << endl; 
    cout << my_queue.pop() << endl;
    cout << my_queue.pop() << endl; 

   
    cout << my_queue.size() << endl; 
    cout << my_queue.isempty() << endl; 

  
    for (int i = 0; i < 100; i++) {
        my_queue.push(i);
    }
    cout << my_queue.isfull() << endl;
    my_queue.push(200); 

    my_queue.reverse();
    cout << my_queue.pop() << endl;
    cout << my_queue.pop() << endl;
    cout << my_queue.pop() << endl; 

 
    cout << my_queue.find(50) << endl; 
    cout << my_queue.find(99) << endl; 

    Queue q;
    for (int i = 0; i < 100; i++) {
        q.push(i);
    }
    cout << q.isfull() << endl; 
    q.pop();
    cout << q.isfull() << endl; 
    cout << q.isempty() << endl; 
    for (int i = 0; i < 99; i++) {
        q.pop();
    }
    cout << q.isempty() << endl;
    q.pop();
    cout << q.isempty() << endl; 
    return 0;
}
