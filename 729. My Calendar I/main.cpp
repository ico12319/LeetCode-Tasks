#include <iostream>
#include <set>

//729. My Calendar I
//You are implementing a program to use as your calendar. We can add a new event if adding the event will not cause a double booking.A double booking happens when two events have some non-empty intersection (i.e., some moment is common to both events.).The event can be represented as a pair of integers startTime and endTime that represents a booking on the half-open interval [startTime, endTime), the range of real numbers x such that startTime <= x < endTime.

class calendar{
private:
    std::set<std::pair<int,int>> start_end_dates;
    
    static bool can_date_be_booked(int start,int end,int end_prev,int start_next){
        return start >= end_prev && end <= start_next;
    }
    
public:
    calendar() = default;
    bool book(int start_time,int end_time){
        if(start_end_dates.empty()){
            start_end_dates.insert(std::make_pair(start_time,end_time));
            return true;
        }
        auto info = start_end_dates.insert(std::make_pair(start_time,end_time));
        if(!info.second)
            return false;
        auto it = info.first;
        auto prev = std::prev(it);
        auto next = std::next(it);
        
        if(next != start_end_dates.end() && prev != start_end_dates.end()){
            if(can_date_be_booked(start_time, end_time, prev->second, next->first))
                return true;
            else{
                start_end_dates.erase({start_time,end_time});
                return false;
            }
        }
        else if(next != start_end_dates.end()){
            if(end_time <= next->first)
                return true;
            else{
                start_end_dates.erase(it);
                return false;
            }
        }
        else if(prev != start_end_dates.end()){
            if(start_time >= prev->second)
                return true;
            else{
                start_end_dates.erase(it);
                return false;
            }
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    calendar calendar;
    std::cout<<calendar.book(10, 20)<<std::endl;
    std::cout<<calendar.book(15, 25)<<std::endl;
    std::cout<<calendar.book(20, 30)<<std::endl;
}
