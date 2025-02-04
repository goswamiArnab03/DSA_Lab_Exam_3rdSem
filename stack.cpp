/*Write a menu driven program in C/C++ to implement a Stack using array and perform the
following operations.
(a) isFull() function to check whether the Stack is full or not.
(b) isEmpty() function to check whether the Stack is empty or not.
(c) peek() function to read the stack top element without deleting it.
(d) push(item) function to insert an element item in the Stack.
(e) pop() function to read and remove an element from the Stack.
(f) display() function to display the entire stack.*/

#include<iostream>
#include<stdlib.h>
#define MAX 100
using namespace std;

class Stack{
	int arr[MAX],top;
	public:
		Stack(){
			top=-1;
		}
		
		bool isFull(){
			return (top==MAX-1);
		}
		
		bool isEmpty(){
			return (top==-1);
		}
		
		void peek(){
			if(isEmpty()){
				cout<<"Stack is empty!"<<endl;
				return;
			}
			cout<<"The last element is"<<arr[top]<<endl;
			return;
		}
		void push(int item){
			if(isFull()){
				cout<<"The stack is full"<<endl;
				return;
			}
			arr[++top]=item;
			return;
		}
		
		void pop(){
			if(isEmpty()){
				cout<<"Stack is empty!"<<endl;
				return;
			}
			top--;
			cout<<"Element deleted successfully"<<endl;
			return;
		}
		
		void display(){
			if(isEmpty()){
				cout<<"Stack is empty!"<<endl;
				return;
			}
			cout<<"The stack is: ";
			for(int i=0;i<=top;i++){
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			return;
		}
};

int main(){
	Stack st;
	cout<<"Enter 0 for exit"<<endl;
	cout<<"Enter 1 for check full"<<endl;
	cout<<"Enter 2 for check empty"<<endl;
	cout<<"Enter 3 for peek"<<endl;
	cout<<"Enter 4 for push"<<endl;
	cout<<"Enter 5 for pop"<<endl;
	cout<<"Enter 6 for display"<<endl;
	int p;
	while(1){
		cout<<"Enter your choice: ";
		cin>>p;
		switch(p){
			case 1:
				if(st.isFull()){
					cout<<"Stack is full!"<<endl;
				}
				else{
					cout<<"Stack is not full"<<endl;
				}
				break;
			case 2:
				if(st.isEmpty()){
					cout<<"Stack is empty"<<endl;
				}
				else{
					cout<<"Stack is not empty"<<endl;
				}
				break;
			case 3:
				st.peek();
				break;
			case 4:
				int item;
				cout<<"Enter item to push: ";
				cin>>item;
				st.push(item);
				break;
			case 5:
				st.pop();
				break;
			case 6:
				st.display();
				break;
			
			case 0:
				exit(0);
			default:
				cout<<"Invalid input!"<<endl;
				break;
		}
	}
}
