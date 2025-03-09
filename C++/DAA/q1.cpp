//Given an array of nonnegative integers, design a linear algorithm and implement it using a program to find whether a given key element is present in the array or not. Also, find the total number of comparisons for each input case. (Time Complexity = O(n), where n is the size of input).
#include <bits/stdc++.h>
using namespace std;

int LinearSearch(vector<int> a, int key,int &comp){
    int i;
    for(i=0;i<a.size();i++){
        comp++;
        if(a[i]==key) return i+1;
    }
    return -1;
}

int main(){
    int t;
    cout<<"Abhilakshya Bhatt \nRoll Number: 03\nUniversity Roll Number: 2023975\n";
    cout<<"Enter number of test cases : ";
    cin>>t;
    while(t--){
        int n,comp=0;
        cout<<"Enter size of array : ";
        cin>>n;
        vector<int> a(n);
        cout<<"Enter elements of array : ";
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int key;
        cout<<"Enter key element : ";
        cin>>key;
        int index=LinearSearch(a,key,comp);
        if(index==-1){
            cout<<"Not Present "<<comp<<"\n";
        }else{
            cout<<"Present "<<comp<<"\n";
        }
    }
}