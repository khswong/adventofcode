/**
 * Before you leave, the Elves in accounting just need you to fix your expense report (your puzzle input); apparently, something isn't quite adding up.
 *
 * Specifically, they need you to find the two entries that sum to 2020 and then multiply those two numbers together.
 *
 * For example, suppose your expense report contained the following:
 *
 * 1721
 * 979
 * 366
 * 299
 * 675
 * 1456
 * 
 * In this list, the two entries that sum to 2020 are 1721 and 299. Multiplying them together produces 1721 * 299 = 514579, so the correct answer is 514579.
 *
 * Of course, your expense report is much larger. Find the two entries that sum to 2020; what do you get if you multiply them together?
**/

#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    std::ifstream infile("day1_input.txt");
    std::string line;
    std::vector<int> nums;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a;
        if (!(iss >> a) ) {break;}
        /** this loop is still o(n^2)
         * but i think its technically still more efficient bc it terminates early
         */
        for (auto x : nums) {
            if ((a + x) == 2020){
                cout << "a: " << a << " b: " << x << endl;
                cout << a * (x) << "is the answer" << endl;
                return 0;
            }
        }
        nums.push_back(a);
    }
    return 0;
}