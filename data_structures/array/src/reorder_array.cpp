#include <bits/stdc++.h>
#include <utility>
#include <vector>

bool comp(const std::pair<int,int>& v1,
          const std::pair<int, int>& v2)
{
    return v1.second < v2.second;
}

void reorder (std::vector<int>& arr, int index[], int n)
{
    std::vector<std::pair<int,int> > a(n);
    for(int i=0; i<n; i++)
        {
            a[i].first = arr[i];
            a[i].second = index[i];
        }

        sort(a.begin(), a.end(), comp);

    for(int i = 0; i < n; i++)
        {
            arr[i] = a[i].first;
        }
}

int main()
{
    std::vector<int> arr = {50, 40, 70, 60, 90};
    int index[] = {3, 0, 4, 1, 2};
    int n = arr.size();
    reorder(arr,index,n);
    std::cout<<"Reorder array is : \n ";
    for(int i = 0; i<n; i++)
        std::cout<<arr[i]<< " ";
    return 0;
}
