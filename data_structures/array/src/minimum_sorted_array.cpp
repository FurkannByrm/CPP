#include <algorithm>
#include <bits/stdc++.h>
#include <vector>

int findMin(const std::vector<int>& rr){

    int res = rr[0];
    for (int i=0; i<rr.size(); i++) {
        res = std::min(res, rr[i]);
    }
        return res;
}

int main()
{
    std::vector<int> arr = {5,23,2,55,21,76};
    std::cout<<findMin(arr)<<std::endl;
    std::sort(arr.begin(), arr.end());
    for (int m : arr) {
        std::cout<<m<<" ";
    }
    return 0;
}
