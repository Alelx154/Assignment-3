#pragma once
#include <stack>
#include <string>
#include <iostream>
#include "header.h"
#include <queue>
using namespace std;

//Function defenitions to link the main and function files together

bool is_open(char ch);

bool is_close(char ch);

bool is_balanced(const string& expression);

bool is_operator(char c);

int get_precedence(char c);

bool is_close_parenth(char c);

string infixToPostfix(const string& expression);
//Class def for queue functions
class MyQueue {
	private:
		queue<int> elements;

	public:
		void enqueue(int element);
		int dequeue();
		int front() const;
		bool isEmpty() const;
		size_t size() const;

};