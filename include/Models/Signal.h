#include <iostream>
#include <vector>
#include <algorithm>

struct timedate {
	double sec;		
	double min;		
	double hour;

	uint32_t day;
	uint32_t month;	
	uint32_t year;	
	
};

class Channel {
    using container = std::vector<std::pair<double, timedate>>;
    using iterator = container::iterator;
public:
    Channel(std::string&& name) : name(std::move(name)) {}
    container frequency; 
    std::string name;
    std::pair<iterator, iterator> get_window(timedate start_time, timedate end_time);
};



class Signal{
public:
    std::vector<Channel>& get_channels() {return Channels;}
    void add_channel(std::string&& name) {Channels.emplace_back(std::move(name));}
    uint64_t get_reports_count() {return reports_count;} // N
    void set_reports_count(uint64_t count) {reports_count = count;}

    double get_sampling_frequency() {return sampling_frequency;}
    void set_sampling_frequency(double count) {sampling_frequency = count;}

    uint64_t get_channel_count() {return channel_count;}
    void set_channel_count(uint64_t count) {channel_count = count;}
    
    timedate start_time;
    timedate end_time;

private:
    double sampling_frequency; // частота дискретизации
    uint64_t reports_count;
    uint64_t channel_count;
    std::vector<Channel> Channels;
};

