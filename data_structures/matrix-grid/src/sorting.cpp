#include <algorithm>
#include <iostream>
#include <vector>



int main()
{
    std::vector<std::vector<int>> v = {
                {5,4,7},
                {1,3,8},
                {2,9,6}
    };

    int n = v.size();
    std::vector<int> x;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
        x.push_back(v[i][j]);
        }
    }
    std::sort(x.begin(),x.end());
    int k=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            v[i][j] = x[k++];
        }
    }
    std::cout<<"sorted matrix will be :"<<std::endl;
    for(auto it: v)
    {
        for(auto vt: it)
        {
            std::cout<<vt<<" ";
        }
        std::cout<<std::endl;
    }

    return 0;
}
