#include <bits/stdc++.h>
#include <string>
using namespace std;

bool subsetSum(int ar[], int total,  int n){

    if(total == 0){
        return true;
    }

    if(total < 0 || n == 0){
        return false;
    } 

    if(ar[n-1] <= total){
        return subsetSum(ar, total - ar[n-1], n-1) || subsetSum(ar, total, n-1);
    }

    return subsetSum(ar, total, n-1);

}

int main(){

    int ar[] = {1,2,5};
    int size = sizeof(ar)/sizeof(ar[0]);
    int total = 4;

    cout<<subsetSum(ar, total, size);
}