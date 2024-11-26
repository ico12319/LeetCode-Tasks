#include <iostream>
#include <queue>

//1753. Maximum Score From Removing Stones
//You are playing a solitaire game with three piles of stones of sizes a​​​​​​, b,​​​​​​ and c​​​​​​ respectively. Each turn you choose two different non-empty piles, take one stone from each, and add 1 point to your score. The game stops when there are fewer than two non-empty piles (meaning there are no more available moves).Given three integers a​​​​​, b,​​​​​ and c​​​​​, return the maximum score you can get.

int maximumScore(int a, int b, int c) {
    std::priority_queue<int> pq;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int points = 0;
    while(true){
        int curr_top = pq.top();
        curr_top--;
        pq.pop();
        if(pq.top() == 0)
            break;
        int next = pq.top();
        next--;
        pq.pop();
        points++;
        pq.push(curr_top);
        pq.push(next);
    }
    return points;
}

int main(int argc, const char * argv[]) {
    int a = 4;
    int b = 4;
    int c = 6;
    std::cout<<maximumScore(a, b, c)<<std::endl;
}
