#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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
            cout << x << " ";
        }
        cout << endl;
    }
    cout << "line size " << size << endl;
    int pos = 0;
    int collision = 0;
    for (auto row : trees){
        for (auto x : row){
            if (pos == x) collision++;
        }
        pos += 3;
        pos = pos % size;
    }
    cout << "collision " << collision << endl;
    return 0;
}


/*
..##.......
#...#...#..
.#....#..#.
..#.#...#.#
.#...##..#.
..#.##.....
.#.#.#....#
.#........#
#.##...#...
#...##....#
.#..#...#.#
*/