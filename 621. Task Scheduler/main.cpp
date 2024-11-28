#include <iostream>
#include <queue>
#include <map>

//621. Task Scheduler
//You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.Return the minimum number of CPU intervals required to complete all tasks.

int leastInterval(std::vector<char>& tasks, int n) {
    std::map<char, int> occur;
    for(const auto& s : tasks)
        occur[s]++;
   
    std::priority_queue<int> pq;
    for(const auto& pair : occur)
        pq.push(pair.second);
    
    std::queue<std::pair<int,int>> count_and_idle_time;
    int time = 0;
    while(!pq.empty() || !count_and_idle_time.empty()){
        time++;
        
        if(!pq.empty()){
            int curr_max = pq.top();
            pq.pop();
            if(curr_max - 1 != 0)
                count_and_idle_time.push({curr_max - 1,time + n});
        }
        if(!count_and_idle_time.empty() && time == count_and_idle_time.front().second){
            int value = count_and_idle_time.front().first;
            count_and_idle_time.pop();
            pq.push(value);
        }
    }
    return time;
    
}

int main(int argc, const char * argv[]) {
    std::vector<char> v = {'A','A','A','B','C'};
    std::cout<<leastInterval(v, 3)<<std::endl;
}
