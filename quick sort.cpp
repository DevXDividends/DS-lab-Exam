TC:O(n log n) SC:O(1)
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
int findPivotAndSort(int a[],int low,int high){
    int i=low;
    int j=high;
    int pivot=a[low];
    while(i<j){
        while(a[i]<=pivot && i<high)i++;
        while(a[j]>=pivot && j>low)j--;
        if(i<j)swap(a[i],a[j]);
    }
    swap(a[low],a[j]);
    return j;
}
void quick_sort(int a[],int low,int high){
    if(low>=high)return;
    int mid=findPivotAndSort(a,low,high);
    quick_sort(a,low,mid-1);
    quick_sort(a,mid+1,high);
}

int main() {
    int a[4]={6,4,2,1};
    int n=4;
    quick_sort(a,0,n-1);
    cout<<"sorted array: ";
    for(int i=0;i<n;i++)cout<<a[i]<<" ";
    return 0;
}
