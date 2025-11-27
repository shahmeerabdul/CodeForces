#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int k;
    cin>>n>>k;
    int team=0;
    int a[50];
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    for(int i=0; i<n; i++){
        if(a[i]>0 && a[i]>=a[k-1]){
            team++;
        }
    }

    cout<<team;
}