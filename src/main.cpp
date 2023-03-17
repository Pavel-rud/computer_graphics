#include <Parsers/Txtparser.h>
#include <fstream>
int main() {
    std::ifstream file("file.txt");
    auto a = parse_from_txt(file);
    
    for(auto b : a.get_channels()) {
        for (auto c : b.frequency) {
            std::cout << c.second.year << ' ' << c.second.month << ' ' <<  c.second.day << ' ' << c.second.hour << ' ' << c.second.min << ' ' << c.second.sec << std::endl;
        }
        std::cout << "------\n";
    }
}