#include <iostream>
#include <vector>
#include <time.h>

//TODO: модель времени

class Channel {
    using container = std::vector<std::pair<double, tm>>;
    using iterator = container::iterator;
public:
    container frequency(); 
    std::string name;
    std::pair<iterator, iterator> get_window(tm start_time, tm end_time);
};


class Signal{
public:
    const std::vector<Channel>& get_channels() {return Channels;}
    uint64_t get_reports_count() {return reports_count;} // N
    void set_reports_count(uint64_t count) {reports_count = count;}

    uint64_t get_sampling_frequency() {return sampling_frequency;}
    void set_sampling_frequency(uint64_t count) {sampling_frequency = count;}

    uint64_t get_channel_count() {return channel_count;}
    void set_channel_count(uint64_t count) {channel_count = count;}
    
    tm start_time;
    tm end_time;

private:
    uint64_t sampling_frequency; // частота дискретизации
    uint64_t reports_count;
    uint64_t channel_count;
    std::vector<Channel> Channels;
};

