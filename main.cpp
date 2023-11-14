#include <stack>
#include <string>
#include <iostream>
#include "header.h"
using namespace std;

int main() {
    //Variables to use with 
    string expression;
    MyQueue myQueue;
    int numToEnter;
    bool breakOut = true;
    bool breakOut2 = true;
    string answer;
    string answer2;
    int toBeRemoved;
    cout << "Enter an expression" << endl;
    //While loop to enter and check for a balanced expression
    //Also gives postfix expression
    while (getline(cin, expression) && (expression != "")) {
        cout << expression;
        if (is_balanced(expression)) {
            cout << " is balanced" << endl;
            string postfixExpression = infixToPostfix(expression);
            cout << "Postfix expression: " << postfixExpression << endl;
            break;
        }
        else {
            cout << " is not balanced" << endl;
        }
        cout << "Enter another expression" << endl;
    }
    //While loop to enter variables into the queue
    //Type "N" to break out of it
    while (breakOut == true) {
        cout << "would you like to add an element? (Y/N)" << endl;
        cin >> answer;
        if (answer == "N") {
            breakOut = false;
            break;
        }
        else{
            cout << "Enter a number to insert into the queue" << endl;
            cin >> numToEnter;
            myQueue.enqueue(numToEnter);
        }

    }
    //While loop to remove elements from the queue
    while(breakOut2 == true) {
        cout << "Would you like to remove the front element? (Y/N)" << endl;
        cin >> answer2;
        if (answer2 == "N") {
            breakOut2 = false;
            break;
        }
        else {
            cout << "Dequeued element: " << myQueue.dequeue() << endl;
        }
    }
    //Shows the front element of the queue
    cout << "Front element: " << myQueue.front() << endl;
    //Checks if the queue is empty
    cout << "Is the queue empty? " << (myQueue.isEmpty() ? "Yes" : "No") << endl;
    //Checks the number of elemement in the queue
    cout << "Number of elements in the queue: " << myQueue.size() << endl;
}   