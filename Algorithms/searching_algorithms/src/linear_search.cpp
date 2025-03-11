#include <iostream>
#include <vector>

using std::cout, std::cin;

int linear_searh(std::vector<int>& arr, int x){

    for(int i=0; i<arr.size(); i++)
        if (arr[i] == x)
            return i;
        
    return -1;
        

}


int main()
{

 std::vector<int> arr{2,3,4,5,6,8};  

 cout<<linear_searh(arr,2)<<"\n";


    return 0;
}