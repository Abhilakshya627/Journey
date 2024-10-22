#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> a,int n,int m,int mid){
    int scount=1,psum=0;
    for(int i=0;i<n;i++){
        if(a[i]+psum<=mid){
            psum+=a[i];
        }
        else{
            scount++;
            if(scount>m || a[i]>mid) return false;
            psum=a[i];
        }
    }
    return true;
}

int allocateBooks(vector<int> a,int n, int m){
    int s=0,sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
    }
    int e=sum,ans=-1,mid=s+(e-s)/2;
    while(s<=e){
        if(isPossible(a,n,m,mid)){
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    vector<int> a={10,20,30,40};
    int n=a.size();
    int m=2;
    cout<<allocateBooks(a,n,m);

    return 0;

}