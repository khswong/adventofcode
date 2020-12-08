#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    std::ifstream infile("day6_input.txt");
    std::string line;
    unordered_map<char, int> alphabet;
    int sum = 0;
    while (std::getline(infile, line))
    {
        if (!line.size()){
            for (auto x : alphabet){
                sum++;
            }
            alphabet.clear();
        }
        for (auto x : line){
            if (x != ' '){
                alphabet[x]++;
            }
        }
    }

    for (auto x : alphabet)
    {
        sum++;
    }
    cout << "total: " << sum << endl;

    return 0;
}