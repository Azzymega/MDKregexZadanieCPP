#include <iostream>
#include <regex>
#include <iterator> 
using namespace std;

int main()
{
    std::string output;
    std::string target = "Завтра в 09:00";
    static const auto regex = std::regex("\\d{2}:\\d{2}");
    auto words_begin = std::sregex_iterator(target.begin(), target.end(), regex);
    auto words_end = std::sregex_iterator();
    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        std::smatch match = *i;
        output = match.str();
    }
    if (std::stoi(output.substr(0, 2)) > 23  || std::stoi(output.substr(2, 4)) > 59) {
        cout << "Error";
    }
    else {
        cout << output;
    }
}
