#include <iostream>
#include <utility>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>


enum class TaskPriority {LOW, MEDIUM, HIGH, CRITICAL};

std::string priorityToString( TaskPriority priority){

    switch (priority) {
        case TaskPriority::HIGH : return "HIGH";
        case TaskPriority::LOW  : return "LOW";
        case TaskPriority::MEDIUM : return "MEDIUM";
        case TaskPriority::CRITICAL : return "CRITICAL";
        default: return "UNKNOW";
    }
}

int main(){

    std::queue<std::pair<std::string, TaskPriority>> taskQueue;
    taskQueue.push(std::make_pair("C++ working",TaskPriority::HIGH));
    taskQueue.push(std::make_pair("interpreter: addition AST node", TaskPriority::CRITICAL));
    taskQueue.push({"working english",TaskPriority::MEDIUM});
    taskQueue.emplace("Reading Book",TaskPriority::LOW);
    
    std::cout<<"queue order : "<<taskQueue.size()<<"\n";
    
    std::vector<std::pair<std::string, TaskPriority>> sorted_task;
    size_t orginal_size = taskQueue.size();

    for(size_t i = 0; i<orginal_size; ++i){

        sorted_task.push_back(taskQueue.front());
        taskQueue.pop();
    }

    std::sort(sorted_task.begin(), sorted_task.end(),
    [](const auto& a, const auto& b){
        return static_cast<int>(a.second) > static_cast<int>(b.second);
    });

    for(const auto& vec : sorted_task){

        std::cout<<vec.first<<" : "<<priorityToString(vec.second)<<"\n";
    }

    std::cout<<"Operation is carried out in order: \n";

    for(const auto& queue : sorted_task){
        taskQueue.push(std::make_pair(queue.first,queue.second));
    }
    while (!taskQueue.empty())
    {

        std::cout<<"processing.. "<<taskQueue.front().first<< ", Priority : ["<<priorityToString(taskQueue.front().second)<<"] \n";
        taskQueue.pop();

    }
    

    return 0;
}