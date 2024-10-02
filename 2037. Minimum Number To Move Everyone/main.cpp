#include <iostream>
// 2037. Minimum Number of Moves to Seat Everyone
// There are n availabe seats and n students standing in a room. You are given an array seats of length n, where seats[i] is the position of the ith seat. You are also given the array students of length n, where students[j] is the position of the jth student.You may perform the following move any number of times:Increase or decrease the position of the ith student by 1 (i.e., moving the ith student from position x to x + 1 or x - 1) Return the minimum number of moves required to move each student to a seat such that no two students are in the same seat.Note that there may be multiple seats or students in the same position at the beginning.


int minMovesToSeat(std::vector<int>& seats,std::vector<int>& students){
    std::sort(seats.begin(),seats.end());
    std::sort(students.begin(),students.end());

    int res = 0;
    const size_t n = seats.size();
    for(int i=0;i<n;i++){
        int temp = abs(seats[i] - students[i]);
        res+=temp;
    }
    return res;
}

int main(int argc, const char * argv[]) {
    
    std::vector<int> seats = {4,1,5,9};
    std::vector<int> students = {1,3,2,6};
    std::cout<<minMovesToSeat(seats, students)<<std::endl;
    
    // 1 3 5
    // 2 4 7
}
