#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int r=5;
    int c=5;
    int moves=0;
    int onerow,onecol;
    int arr[r][c]={};
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin>>arr[i][j];
             if(arr[i][j]==1){
        onerow=i;
        onecol=j;
    }
    }
    }
    moves=abs(onerow-2)+abs(onecol-2);
    cout<<moves;
}
