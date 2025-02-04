/*Write a program in C or C++ to sort a given array using Quick sort algorithm.*/

#include<iostream>
using namespace std;

void swap(int arr[],int i,int j){
	int temp=arr[i];
	arr[i]=arr[j];
	arr[j]=temp;
	return;
}

int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1;
	int j;
	for(int j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr,i,j);
		}
	}
	swap(arr,i+1,high);
	return i+1;
}

void quicksort(int arr[],int low,int high){
	if(low<high){
		int j=partition(arr,low,high);
		quicksort(arr,low,j-1);
		quicksort(arr,j+1,high);
	}
}

void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[5]={5,3,9,7,1};
	quicksort(arr,0,4);
	display(arr,5);
	return 0;
}
