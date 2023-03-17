#include "Models/Signal.h"
#include <string>
#include <fstream>
#include <array>

void read_while_not_comment(std::istream& file, std::string& s) {
    while (!file.eof()) {
        std::getline(file, s);
        
        if (s[0] != '#')
            return;
    }
    
}

std::array<std::string,3> parse_three_entities(const std::string& str, Signal& signal, const char& delimiter) {
    std::array<std::string,3> tokens;
    std::size_t counter = 0;
    std::size_t pos = 0;

    while (pos != std::string::npos) {
        std::size_t end_pos = str.find(delimiter, pos);
        if (end_pos == std::string::npos) {
            tokens[counter++] = str.substr(pos);
            break;
        }
        tokens[counter++] = str.substr(pos, end_pos - pos);
        pos = end_pos + 1;
    }

    return tokens;
}
void parse_date(const std::string& str, Signal& signal) {
    auto tokens = parse_three_entities(str, signal, '-');
    signal.start_time.day = stoi(tokens[0]);
    signal.start_time.month  = stoi(tokens[1]);
    signal.start_time.year = stoi(tokens[2]);  
}

void parse_time(std::string& str, Signal& signal) {
    auto tokens = parse_three_entities(str, signal, ':');
    signal.start_time.hour = std::stod(tokens[0]);
    signal.start_time.min  = std::stod(tokens[1]);
    signal.start_time.sec = std::stod(tokens[2]);
}


void parse_channels_names(std::string& str, Signal& signal) {
    std::vector<std::string> tokens;
    std::string delimiter = ";";
    size_t pos = 0;

    while ((pos = str.find(delimiter)) != std::string::npos) {
        signal.add_channel(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
    }
}


void recalculate_time(timedate& time, double delta) {
    time.sec += delta;
    if (time.sec >= 60) {
        time.sec -= 60;
        time.min += 1;
    }
    if (time.min >= 60) {
        time.min -= 60;
        time.hour += 1;
    }
    if (time.hour >= 24) {
        time.hour -= 24;
        time.day += 1;
    }

    if (time.day >= 31) {
        time.day -= 31;
        time.month += 1;
    }
    if (time.month >= 12) {
        time.month -= 12;
        time.year += 1;
    }
}

void parse_frequency(std::istream& file, Signal& signal) {
    double number;
    timedate time = signal.start_time;
    uint64_t chan_count = signal.get_channel_count();

    for (uint64_t i = 0; i < signal.get_reports_count(); ++i) {
        file >> number;
        signal.get_channels()[i % chan_count].frequency.push_back({number, time});
        if ((i % chan_count) == (chan_count - 1))
            recalculate_time(time, 1.0/signal.get_sampling_frequency());
    }

}


Signal parse_from_txt(std::istream& file) {
    std::string s;
    Signal signal;


    //channel parsing
    read_while_not_comment(file, s);
    signal.set_channel_count(std::stoull(s)); 
    
    //reports parsing
    read_while_not_comment(file,s);
    signal.set_reports_count(std::stoull(s));

    //sampling parsing
    read_while_not_comment(file, s);
    signal.set_sampling_frequency(std::stod(s));

    //date parsing
    read_while_not_comment(file, s);
    parse_date(s, signal);

    //time parsing 
    read_while_not_comment(file, s);
    parse_time(s, signal);

    //channels name parsing
    read_while_not_comment(file, s);
    parse_channels_names(s, signal);

    //frequency parsing
    parse_frequency(file, signal);
    
    return signal;

}

