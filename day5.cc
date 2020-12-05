#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    std::ifstream infile("day5_input.txt");
    std::string line;
    int max_uuid = 0;
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
            if (uuid > max_uuid) max_uuid = uuid;
            cout << "row " << row << endl;
            cout << "col " << col << endl;
            cout << "uuid " << uuid << endl;
    }
    cout << "max uuid " << max_uuid << endl;
    return 0;
}