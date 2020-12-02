#include <iostream>

#include <sstream>
#include <string>
#include <fstream>

#include <regex>

using namespace std;

int main() {   
   
    // example: 
    // 6-9 z: qzzzzxzzfzzzz 
    // [1-9]+\-[1-9]+ [a-z]:
    std::ifstream infile("day2_input.txt");
    std::string line;
    const std::regex base_regex("([0-9]+)\\-([0-9]+) ([a-zA-Z0-9_]+): ([a-zA-Z0-9_]+)");
    std::smatch base_match;
    int valid_uwu = 0;

    while (std::getline(infile, line))
    {
        std::regex_match(line, base_match, base_regex);
        int lower_bound = std::stoi(base_match[1].str());
        int upper_bound = std::stoi(base_match[2].str());
        string password = base_match[4];
        char rule = base_match[3].str()[0];
        int count = 0;
        std::cout << line << endl;
        std::cout << " has a lower_bound " << lower_bound << endl;
        std::cout << " has a upper_bound " << upper_bound << endl;
        std::cout << " rule char " << base_match[3] << endl;
        std::cout << " password " << base_match[4] << endl;
        for (auto x : password){
            if (x == rule) count++;
        }
        cout << "count " << count << endl;
        if (count >= lower_bound && upper_bound >= count){
            cout << "valid uwu" << endl;
            valid_uwu++;
        } 
        else {
            cout << "cancelled" << endl;
        }
    }
    cout << "answer" << valid_uwu << endl;

}