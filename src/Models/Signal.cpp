#include <Models/Signal.h>
#include <utility> 
#include <algorithm> 

auto my_cmp = [](const std::pair<double,timedate>& p1, const std::pair<double,timedate>& p2) {
        if (p1.second.year != p2.second.year)
            return p1.second.year < p2.second.year;
        
        if (p1.second.month != p2.second.month)
            return p1.second.month < p2.second.month;

        if (p1.second.day != p2.second.day)
            return p1.second.day < p2.second.day;

        if (p1.second.hour != p2.second.hour)
            return p1.second.hour < p2.second.hour;

        if (p1.second.min != p2.second.min)
            return p1.second.min < p2.second.min;

        return p1.second.sec < p2.second.sec;
        
    };

std::pair<Channel::iterator, Channel::iterator> Channel::get_window(timedate start_time, timedate end_time) {
    
    auto left_it = std::lower_bound(
        this->frequency.begin(), 
        this->frequency.end(), 
        std::make_pair(0.0,start_time),
        my_cmp
    );

    auto right_it = std::upper_bound(
        this->frequency.begin(),
        this->frequency.end(),
        std::make_pair(0.0,end_time),
        my_cmp
    );

    return {left_it, right_it};
}