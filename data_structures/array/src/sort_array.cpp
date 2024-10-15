#include <algorithm>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {3, 2, 1, 6, 7, 8};
    std::sort(arr.begin(), arr.end());
    for(int x :  arr){
        std::cout<<x<< " ";
    }

    return 0;
}
