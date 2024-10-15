#include <iostream>
#include <vector>

//Rotate a Matrix by 180

void rotateMatrix(std::vector<std::vector<int>>& mat){
    int n = mat.size();
    std::vector<std::vector<int>> res(n, std::vector<int>(n));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            res[i][j] = mat[n-i-1][n-j-1];
        }
    }
    mat = res;
}




int main(){
    std::vector<std::vector<int>> mat = {
            {1,2,3},
            {4,5,6},
            {7,8,9}
    };
    rotateMatrix(mat);
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j< mat[i].size(); j++){
        std::cout<<mat[i][j]<<" ";
        }
        std::cout<<"\n";

    }
    return 0;
}
