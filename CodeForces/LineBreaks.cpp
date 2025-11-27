#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, limit;
        cin >> n >> limit;

        int sum = 0;
        int count = 0;

        string first;

        for(int i = 0; i < n; i++){
            string word;
            cin >> word;

            if(i==0){
            first=word;
            }

            if(sum + word.length() <= limit){
                sum += word.length();
                count++;
            }
        }
        if(first.length()>limit){
            cout<<0<<"\n";
        }
        else if(first.length()==limit){
            cout<<1<<"\n";
        }
        
        else{

        cout << count << "\n";
        }   
    }
}
