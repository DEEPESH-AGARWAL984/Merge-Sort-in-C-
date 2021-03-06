#include<iostream>
#include<stdlib.h>
using namespace std;
void merge(int arr[],int start,int mid,int end){ //Merge Function.
	int n1=mid-start+1;
	int n2 = end-mid;
	
	int arr1[n1];
	int arr2[n2];
	for(int i=0;i<n1;i++){
		arr1[i] = arr[start+i];
	}
	for(int j=0;j<n2;j++){
		arr2[j] = arr[mid+1+j];
	}
	int i =0;
	int j =0;
	int k = start;
	
	while( i<n1 && j<n2){
		if(arr1[i]<=arr2[j]){
			arr[k]=arr1[i];
			i++;
			k++;
		}
		else{
			arr[k]=arr2[j];
			j++;
			k++;
		}
	}
	while(i<n1){
		arr[k]=arr1[i];
		i++;
		k++;
	}
	while(j<n2){
		arr[k]=arr2[j];
		j++;
		k++;
	}
}

void display(int arr[],int size){ //Function to display the sorted array.
	for(int i=0;i<size;i++){
		cout<<" "<<arr[i];
	}
}

void mergeSort(int arr[],int start,int end){ //Mergesort Function
	int mid;
	if(start<end){
		mid = (start+end)/2;		//To break(divide) the array into two sub-arrays
 		mergeSort(arr,start,mid);
		mergeSort(arr,mid+1,end);	/*Calling the mergesort function recursively i.e. 
									from start to mid of array & from mid+1 to end of the array*/		
		merge(arr,start,mid,end);
		}
}
int main(){
	int n;
	cout<<"Enter the size:";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements of array: "<<endl;
	for(int i=0;i<n;i++){
	cin>>arr[i];
		}
	mergeSort(arr,0,n-1);
	cout<<"Sorted Array: "<<endl;
	display(arr,n);
}
