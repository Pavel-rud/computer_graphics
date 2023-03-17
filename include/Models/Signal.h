#include <iostream>
#include <vector>
#include <time.h>


class Channel {
public:
    std::vector<double> frequency();
};


class Signal{
public:
    std::vector<Channel> Channels;
    uint64_t get_reports_count(); // N
    uint64_t get_sampling_frequency();
    tm get_start_time();
    tm get_end_time();

private:
    uint64_t sampling_frequency; // частота дискретизации
    tm start_time;
    tm end_time;
};

