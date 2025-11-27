#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int a[t];
    int total = 0;

    for(int i = 0; i < t; i++){
        cin >> a[i];
    }

    int maximum=a[0];
    for(int i=0; i<t; i++){
        if(a[i]>maximum){
            maximum=a[i];
        }
    }

    for(int i = 0; i < t; i++){
        total += maximum - a[i];
    }

    cout << total;
}
