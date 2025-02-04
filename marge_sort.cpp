//Write a program in C or C++ to sort a given array using Merge sort algorithm.

#include<iostream>
using namespace std;

void Merge(int arr[],int low,int mid,int high){
	int i=low;
	int j=mid+1;
	int k=low;
	int B[1000];
	while(i<=mid && j<=high){
		if(arr[i]<=arr[j]){
			B[k++]=arr[i++];
		}
		else{
			B[k++]=arr[j++];
		}
	}
	while(i<=mid)B[k++]=arr[i++];
	while(j<=high)B[k++]=arr[j++];
	for(int i=low;i<=high;i++){
		arr[i]=B[i];
	}
}

void mergesort(int arr[],int low,int high){
	if(low<high){
		int mid=(low+high)/2;
		mergesort(arr,low,mid);
		mergesort(arr,mid+1,high);
		Merge(arr,low,mid,high);
	}
}
void display(int arr[],int n){
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
}

int main(){
	int arr[5]={5,3,9,7,1};
	mergesort(arr,0,4);
	display(arr,5);
	return 0;
}
