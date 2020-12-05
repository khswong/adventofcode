#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

int main() {
    std::ifstream infile("day5_input.txt");
    std::string line;
    unordered_map<int, bool> uuids;
    int min_uuid = 0x3FF, max_uuid = 0; 
    while (std::getline(infile, line))
    {
        int row = 0, col = 0, uuid = 0;
            for (int i = 0; i < 7; ++i){
                if (line[i] == 'B'){
                        row |= 1 << (6 - i);
                }
            }
            for (int i = 0; i < 3; ++i){
                if (line[i + 7] == 'R'){
                    col |= 1 << (2 - i);
                }
            }
            uuid = (row << 3) + col; 
            min_uuid = min_uuid > uuid ? uuid : min_uuid;
            max_uuid = max_uuid > uuid ? max_uuid: uuid;
            uuids[uuid] = true;
    }
    cout << "max uuid " << max_uuid << " min_uuid " << min_uuid << endl;
    for (int i = min_uuid; i <= max_uuid; ++i){
        if (!uuids[i]) cout << "your seat is " << i << endl; 
    }
    return 0;
}