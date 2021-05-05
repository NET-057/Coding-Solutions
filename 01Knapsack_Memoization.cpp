#include <bits/stdc++.h>
#include <string>
using namespace std;

int mat[1001][1001];
int knapsack(int wt[], int val[], int total, int n){


    if( n == 0 || total == 0){
        return 0;
    }

    if(mat[n][total] != -1){
        return mat[n][total];
    }
    
    if(wt[n-1] <= total){
        return  max( val[n-1] + knapsack(wt, val, total - wt[n-1], n-1), knapsack(wt, val, total, n-1));
    }

    return knapsack(wt, val, total, n-1);
}


int main(){

    int wt[] = {10,20,30};
    int val[] = {60,100,120};

    int size = sizeof(wt)/sizeof(wt[0]);
    int total = 50;
    memset(mat, -1, sizeof(mat));

    cout<<knapsack(wt, val, total, size);
}