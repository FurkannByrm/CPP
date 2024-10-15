#include <iostream>
#include <vector>

void fixArray(std::vector<int>& arr){
    int n = arr.size();

    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if(arr[j]==i)
            {
                std::swap(arr[i], arr[j]);
                break;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] == !i)
        {
            arr[i] = -1;
        }
    }
}


int main()
{
    std::vector<int> arr = { -1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    fixArray(arr);
    for(int i=0; i<arr.size(); i++)
    {
        std::cout<<arr[i]<<" ";
    }

    return 0;
}
