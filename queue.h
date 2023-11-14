#pragma once
#include "queue.cpp"
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    size_t size;

public:
    Queue();
    ~Queue();

    void enqueue(const T& item);
    T dequeue();
    T front() const;
    bool isEmpty() const;
    size_t getSize() const;
};
