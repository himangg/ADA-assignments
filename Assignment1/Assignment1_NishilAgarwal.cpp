#include <iostream>
#include <windows.h>
#include <cmath>
#include <stdio.h>
using namespace std;

int modif_bins(int* arr, int low, int high, int value){
    int mid=(low+high)/2;
    //cout<<low<<" "<<mid<<" "<<high<<endl;
    if(low>high){
        if (low==0){
            return mid;
        }
        return  mid+1;
    }else if(mid==0){
        if (arr[mid]>value){
            return 0;
        }else{
            return 1;
        }
    }else if(arr[mid]>=value&&arr[mid-1]<=value){
        if (arr[mid]==value){
            return mid+1;
        }
        return mid;
    }else if(arr[mid]<value&&arr[mid-1]<value){
        return modif_bins(arr,mid+1,high,value);
    }else if(arr[mid]>value&&arr[mid-1]>value){
        return modif_bins(arr,low,mid-1,value);
    }
}

int largest3(int n1, int n2, int n3) {
    if (n1 >= n2 && n1 >= n3) {
        return n1;
    } else if (n2 >= n1 && n2 >= n3) {
        return n2;
    } else {
        return n3;
    }
}

int smallest3(int n1, int n2, int n3) {
    //cout<<n1<<" "<<n2<<" "<<n3<<endl;
    if (n1 <= n2 && n1 <= n3) {
        return n1;
    } else if (n2 <= n1 && n2 <= n3) {
        return n2;
    } else {
        return n3;
    }
}

int recur_search(int k, int n, int* arr1, int* arr2,int* arr3,int smallest, int largest){
    int assumed_middle=(largest+smallest)/2;
    int r1=modif_bins(arr1,0,n-1,assumed_middle);
    int r2=modif_bins(arr2,0,n-1,assumed_middle);
    int r3=modif_bins(arr3,0,n-1,assumed_middle);
    int total_lesser_or_equal=r1+r2+r3;

    //cout<<r1<<" "<<r2<<" "<<r3<<" "<<k<<" "<<assumed_middle<<endl;
    //Sleep(100);

    if(smallest==largest){
        return smallest;
    }
    if(total_lesser_or_equal<k){
        return recur_search(k,n,arr1,arr2,arr3,assumed_middle+1,largest);
    }else{
        return recur_search(k,n,arr1,arr2,arr3,smallest,assumed_middle);
    }
}

int kth_element_search(int k, int n, int* arr1, int* arr2,int* arr3){
    int largest=largest3(arr1[n-1],arr2[n-1],arr3[n-1]);
    int smallest=smallest3(arr1[0],arr2[0],arr3[0]);
    return recur_search(k,n,arr1,arr2,arr3,smallest,largest);
}

int main()
{
    int* array1=(int*)malloc(sizeof(int)*5);
    int* array2=(int*)malloc(sizeof(int)*5);
    int* array3=(int*)malloc(sizeof(int)*5);

    for (int i=0; i<5; i++){
        array1[i]=i+1;
    }

    for (int i=0; i<5; i++){
        array2[i]=i+6;
    }

    for (int i=0; i<5; i++){
        array3[i]=i+11;
    }

    for (int k=1; k<=15; k++){
        cout<<"Result : "<<kth_element_search(k,5,array1,array2,array3)<<endl;
    }
    // array3[0]=6;
    // cout<<"Result : "<<kth_element_search(6,5,array1,array2,array3)<<endl;
    return 0;
}
