#include <iostream>
#include <vector>

bool searchInMatrix(std::vector<std::vector<int> >&arr, int x)
{
    int m = arr.size(), n = arr[0].size();
    for(int i = 0; i<m; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(arr[i][j] == x)
                return true;
        }
    }
    return false;
}

int main()
{
    int x = 2;
    std::vector<std::vector<int>> arr= {{0,2,4,5,6},
                                        {2,5,7,1,7},
                                        {9,0,2,5,3}};
    if (searchInMatrix(arr, x)) {
        std::cout<<"yeahh"<<std::endl;
    }

    else
    {
        std::cout<< "noooo"<<std::endl;

    }

    return  0;
}
