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
    int group_size = 0;
    while (std::getline(infile, line))
    {
        if (!line.size()){
            for (auto x : alphabet){
                if(x.second == group_size) sum++;
            }
            cout << "group size " << group_size << endl;
            alphabet.clear();
            group_size = 0;
        } else {
            group_size++;
        }
        for (auto x : line){
            if (x != ' '){
                alphabet[x]++;
            }
        }   
    }

    for (auto x : alphabet)
    {
        if(x.second == group_size) sum++;
    }
    cout << "total: " << sum << endl;

    return 0;
}