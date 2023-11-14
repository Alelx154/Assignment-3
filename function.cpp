#include <stack>
#include <string>
#include <iostream>
#include "header.h"
using namespace std;

//Constants for open, closed, and operators
const string OPEN = "([{";
const string CLOSE = ")]}";
const string OPPERATOR = "+-*/";
string space = " ";
//Tells program if a character is an open bracket
bool is_open(char ch) {
	return OPEN.find(ch) != string::npos;
}
//Tells program if a character is a closed brakcet
bool is_close(char c) {
	return CLOSE.find(c) != string::npos && !is_operator(c);
}

bool is_close_parenth(char c) {
	return (c == ')' || c == '}' || c == ']');
}
//Function to check if an expression is balanced
bool is_balanced(const string& expression) {
	stack<char> s;
	bool balanced = true;
	string::const_iterator iter = expression.begin();
	//While balanced equals true and iterator is not at the end of the expression
	//Trigger loop
	while (balanced && (iter != expression.end())) {
		//Sets next_ch to the current index position of the expression
		char next_ch = *iter;
		//If current index character of the expression is an open bracket, trigger if statement
		if (is_open(next_ch)) {
			//Pushes character to the stack
			s.push(next_ch);
		}
		//if character is closed bracket, trigger if statement
		else if (is_close(next_ch)) {
			//If stack is empty
			if (s.empty()) {
				//Set balanced to false
				balanced = false;
			}
			else {
				//Set top character equal to the top of the stack
				char top_ch = s.top();
				//Pop top of stack
				s.pop(); 
				balanced = OPEN.find(top_ch) == CLOSE.find(next_ch);
			}
		}
		//Increases iterator to check the next index
		++iter;
	}
	//Once we're at the end of the expression or balance = false, return value of balanced and if the stack
	//is empty or not
	return balanced && s.empty();
}

bool is_operator(char c) {
	return OPPERATOR.find(c) != string::npos;
}
//Tells program if a character is higher on the pemdas order. Used in the infix to post fix function
int get_precedence(char c) {
	if (c == '*' || c == '/' || c == '%') {
		return 2;
	}
	if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}
//Function to convert from infix form to postfix form
string infixToPostfix(const string& expression) {
	string postfix;
	stack<char> operators;
	//For loop to go through all characters in the string
	for (char c : expression) {
		//If c is a num, adds to the postfix string
		if (isalnum(c)) {
			postfix += c;
		}
		//Checks if c is an oeprator
		else if (is_operator(c)) {
			//If so, checks if while loop gets activated
			while (!operators.empty() && get_precedence(operators.top()) >= get_precedence(c)) {
				postfix += operators.top();
				operators.pop();
			}
			//Pushes c to operator stack
			operators.push(c);
		}
		//If c is an open bracket, pushes it to operator stack
		else if (is_open(c)) {
			operators.push(c);
		}
		//If c is a closed bracket, triggers else if
		else if (is_close_parenth(c)) {
			//If operators stack isnt empty and the top character in the stack is not an open bracket, then
			//activate while loop
			while (!operators.empty() && !is_open(operators.top())) {
				//adds the top operator to the postfix string
				postfix += operators.top();
				//pops the top stack member
				operators.pop();
			}
			//pops the top stack member
			operators.pop();
		}
	}
	//Once all characters have been gone through, the rest of the stack gets pushed to the
	//postfix string
	while (!operators.empty()) {
		postfix += operators.top();
		operators.pop();
	}
	//returns the postfix string
	return postfix;
}
//Pushes elements to queue
void MyQueue::enqueue(int element) {
	elements.push(element);
}
//If queue is empty, tells user that, if not, pops the front element and returns it
int MyQueue::dequeue() {
	if (isEmpty()) {
		cout << "Queue is empty. Cannot dequeue element.\n";
		return -1;
	}
	//sets front element variable to the current element in the queue
	int frontElement = elements.front();
	//Removes it
	elements.pop();
	//Returns removed element
	return frontElement;
}
//If queue is empty, tells user that. If not, returns the front element in the queue
int MyQueue::front() const {
	if (isEmpty()) {
		cout << "Queue is empty. No front element.\n";
		return -1;
	}
	//If not empty, return front element in the queue
	return elements.front();
}
//Tells the user if the queue is empty or not using a bool
bool MyQueue::isEmpty() const {
	return elements.empty();
}
//Tells user the size of the queue
size_t MyQueue::size() const {
	return elements.size();
}