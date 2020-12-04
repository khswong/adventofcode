#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int collisions(std::vector<std::vector<int>> trees, int size, int right, int down){
    int pos = 0;
    int collision = 0;
    for (auto itr = trees.begin(); itr < trees.end(); itr = std::next(itr, down)){
        for (auto x : (*itr)){
            if (pos == x) collision++;
        }
        pos += right;
        pos = pos % size;
    }
    return collision; 
}

int main() {
    std::ifstream infile("day3_input.txt");
    std::string line;
    std::vector<std::vector<int>> trees;
    int size = 0;
    while (std::getline(infile, line))
    {
        std::vector<int> row;
        int pos = 0;
        size = line.size();
        for (auto x : line){
            if (x == '#') {
                row.push_back(pos);
            }
            pos++;
        }
        trees.push_back(row);
    }
    for (auto row : trees){
        for (auto x : row){
         //   cout << x << " ";
        }
        cout << endl;
    }
    cout << "line size " << size << endl;
    /*
    Right 1, down 1.
    Right 3, down 1. (This is the slope you already checked.)
    Right 5, down 1.
    Right 7, down 1.
    Right 1, down 2.
    */
    long collision = collisions(trees, size, 3, 1);
    cout << "collision " << collision << endl;
    collision = collision * collisions(trees, size, 1, 1);
    cout << "collision " << collision << endl;
    collision = collision * collisions(trees, size, 5, 1);
    cout << "collision " << collision << endl;
    collision = collision * collisions(trees, size, 7, 1);
    cout << "collision " << collision << endl;
    collision = collision * collisions(trees, size, 1, 2);
    cout << "collision " << collision << endl;
    return 0;
}