//Write a program to nd the nth Fibonacci number using tail recursion.

#include<iostream>
using namespace std;

int fibo(int n,int a=0,int b=1){
	if(n==0)return a;
	if(n==1)return b;
	else return fibo(n-1,b,a+b);
}

int main(){
	cout<<fibo(9);
	return 0;
}
