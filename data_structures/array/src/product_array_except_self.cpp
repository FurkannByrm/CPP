#include <bits/stdc++.h>
#include <vector>

std::vector<int> productExceptSelf(std::vector<int>& arr){
    int n = arr.size();

    std::vector<int> prod(n,1);
    for(int i=0; i<n; i++){

        for(int j =0; j<n; j++)
        {
            if(i != j)
            {
                prod[i] *= arr[j];
            }
        }
    }

    return prod;

}
int main()
{

    std::vector<int> arr = {10,3,5,6,2};
    std::vector<int> res = productExceptSelf(arr);
    for (int val: res)
        std::cout<<val<< " ";

    return 0;
}
