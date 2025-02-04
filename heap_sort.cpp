/*Write a program in C or C++ to sort a given array using Heap sort algorithm.*/

#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return;
}

void heap(int arr[],int n,int i){
	int largest=i;
	int left=2*i+1;
	int right=2*i+2;
	if(left<n && arr[left]>arr[largest])largest=left;
	if(right<n && arr[right]>arr[largest])largest=right;
	if(largest!=i){
		swap(arr,i,largest);
		heap(arr,n,largest);
	}
}

void heapsort(int arr[],int n){
	for(int i=n/2;i>=0;i--){
		heap(arr,n,i);
	}
	for(int i=n-1;i>=0;i--){
		swap(arr,0,i);
		heap(arr,i,0);
	}
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}


int main(){
	int arr[6]={50,60,10,30,20,40};
	heapsort(arr,6);
	display(arr,6);
	return 0;
}
