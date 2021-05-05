#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(5);
    int sum = 0;

    bool mat[vec.size()+1][sum+1];
    for(int i=0;i<=vec.size();i++){
        
        for(int j=0;j<=sum;j++){
            
            if(j == 0){
                mat[i][j] = true;
                continue;
            }
            
            if(i == 0){
                mat[i][j] = false;
                continue;
            }
            
            if(vec[i-1] <= j){
                mat[i][j] = mat[i-1][j] || mat[i-1][j - vec[i-1]];
            
            } else{
                mat[i][j] = mat[i-1][j];    
            }
            
        }
    }
    cout<<mat[vec.size()][sum];
}