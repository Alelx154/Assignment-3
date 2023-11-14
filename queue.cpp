#include "queue.h"
#include <stdexcept>

template <typename T>
Queue<T>::Queue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node* newNode = new Node(item);
    if (isEmpty()) {
        frontPtr = rearPtr = newNode;
    }
    else {
        rearPtr->next = newNode;
        rearPtr = newNode;
    }
    size++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }

    T frontItem = frontPtr->data;
    Node* temp = frontPtr;
    frontPtr = frontPtr->next;
    delete temp;

    size--;
    return frontItem;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty");
    }
    return frontPtr->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return size == 0;
}

template <typename T>
size_t Queue<T>::getSize() const {
    return size;
}