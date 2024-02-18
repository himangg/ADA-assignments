//Rotation of marble block is allowed. So 2x1 block can be sold for 1x2 also.
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void preprocess(vector<vector<int>>* cost){
    //Checking if price (i,j) is more or (j,i). Changing smaller one. (As block can be rotated for max price)
    for (int i=0; i<min((*cost).size(),(*cost)[0].size()); i++){
        if ((*cost)[0][i]>(*cost)[i][0]){
            (*cost)[i][0]=(*cost)[0][i];
        }else{
            (*cost)[0][i]=(*cost)[i][0];
        }
    }
}

void solve(vector<vector<int>>* cost_dp){
    for(int row=0; row<(*cost_dp).size(); row++){
        for (int col=0; col<(*cost_dp)[0].size(); col++){
            vector<int> comparision_array;              //To compare all max cases
            comparision_array.push_back((*cost_dp)[row][col]);         //If selling whole block as 1 is most profitable

            for (int i=0; i<row; i++){
                //Taking each case of vertical division into consideration. Best prices fetched for both divisions from dp
                comparision_array.push_back((*cost_dp)[row-i-1][col]+(*cost_dp)[i][col]);    
            }
            for(int j=0; j<col; j++){
                //Taking each case of horizontal division into consideration. Best prices fetched for both divisions from dp
                comparision_array.push_back((*cost_dp)[row][col-j-1]+(*cost_dp)[row][j]);
            }

            //Comparing all cases for max price :-
            (*cost_dp)[row][col] = *(max_element(comparision_array.begin(),comparision_array.end()));      
        }
    }
}

int main() {    
    vector<vector<int>> cost_matrix={{1,1,1,1,1},{1,100,1,1,1},{1,1,1,1,1},{1,1,1,1000,1}};

    preprocess(&cost_matrix);
    solve(&cost_matrix);
    
    // for(int i=0; i<cost_matrix.size(); i++){
    //     for(int j=0; j<cost_matrix[0].size(); j++){
    //         cout<<"dp["<<i<<"]["<<j<<"]"<<"="<<cost_matrix[i][j]<<endl;
    //     }
    //     cout<<endl;
    // }

    cout<<"ANSWER: "<<cost_matrix[cost_matrix.size()-1][cost_matrix[0].size()-1]<<endl;
}
