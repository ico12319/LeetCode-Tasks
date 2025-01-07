#include <iostream>
#include <queue>

//1845. Seat Reservation Manager
//Design a system that manages the reservation state of n seats that are numbered from 1 to n.Implement the SeatManager class:
//SeatManager(int n) Initializes a SeatManager object that will manage n seats numbered from 1 to n. All seats are initially available.
//int reserve() Fetches the smallest-numbered unreserved seat, reserves it, and returns its number.
//void unreserve(int seatNumber) Unreserves the seat with the given seatNumber.


class seat_manager{
private:
    std::priority_queue<int,std::vector<int>,std::greater<int>> pq;
    
    void fill_pq(int n){
        std::vector<int> temp;
        for(int i = 1;i<=n;i++)
            temp.push_back(i);
    
        pq = std::priority_queue<int, std::vector<int>, std::greater<int>>(temp.begin(), temp.end());
    }
    
public:
    seat_manager(int n){
        fill_pq(n);
    }
    int reserve(){
        int smallest = pq.top();
        pq.pop();
        return smallest;
    }
    void unreserve(int number){
        pq.push(number);
    }
};

int main(int argc, const char * argv[]) {

    seat_manager manager(5);
    std::cout<<manager.reserve()<<std::endl;
    std::cout<<manager.reserve()<<std::endl;
    manager.unreserve(2);
    std::cout<<manager.reserve()<<std::endl;
    
    
    
}
