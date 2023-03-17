#include "Models/Signal.h"
#include <string>
#include <fstream>


void read_while_not_comment(std::ifstream& file, std::string& s) {
    while (!file.eof()) {
        std::getline(file, s);
        //std::cout << s << '\n';
        if (s[0] != '#')
            return;
    }
    
}


Signal parse_from_txt(std::ifstream& file) {
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
    signal.set_sampling_frequency(std::stoull(s));

    //date parsing
    read_while_not_comment(file, s);
    parse_date(s, signal);
    

    return signal;

}

void parse_date(const std::string& s, Signal& signal) {
    std::string tokens[3];
    std::size_t counter = 0;
    std::size_t pos = 0;

    while (pos != std::string::npos) {
        std::size_t end_pos = str.find('-', pos);
        if (end_pos == std::string::npos) {
            tokens[counter++] = str.substr(pos);
            break;
        }
        tokens[counter++] = str.substr(pos, end_pos - pos);
        pos = end_pos + 1;
    }

    signal.start_time.tm_hour = tokens[0];
    signal.start_time.tm_min = tokens[1];
    signal.start_time.tm_sec = tokens[1];
    return 0;
}