#include <utility>
#include <iostream>
#include <vector> 
#include <string>
#include <algorithm>


int main()
{
std::cout << "students points : \n";


std::vector<std::pair<std::string, int>> students_points;
students_points.push_back({"ali",100});
students_points.push_back(std::make_pair("ahmet",48));
students_points.emplace_back("ahmet",24);

for(const auto& student : students_points) {
    std::cout<<student.first<<" : "<<student.second<<"\n";
}

std::sort(students_points.begin(), students_points.end(),
        [](const auto& a, const auto& b) { 
            return a.second > b.second;
        });

for(const auto& student : students_points)
{
    std::cout<<student.first<<" : "<<student.second<<"\n";
}

std::cout<<"under the 80 point student \n";

for(const auto& big : students_points)
{
    if (big.second >= 101)
    {
        std::cout<<big.first<<" : "<<big.second <<"\n";
        break;
    }

    
}


return 0;
}