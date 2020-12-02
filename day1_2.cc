/**
 * 
 * Using the above example again, the three entries that sum to 2020 are 979, 366, and 675. Multiplying them together produces the answer, 241861950.
 * In your expense report, what is the product of the three entries that sum to 2020?
 * 
 */

#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main() {
    std::ifstream infile("day1_input.txt");
    std::string line;
    std::set<int> nums;
    while (std::getline(infile, line))
    {
        std::istringstream iss(line);
        int a;
        if (!(iss >> a) ) {break;}
        nums.insert(a);
    }
    
    // we are doing a fun binary search i guess
    for (auto num_itr = nums.begin(); num_itr != nums.end(); num_itr ){
        for (auto num_itr2 = std::next(num_itr, 1); num_itr != nums.end(); num_itr2++){
            for (auto num_itr3 = std::next(num_itr2, 1); num_itr3 != nums.end(); num_itr3++){
                if ((*num_itr3) + (*num_itr2) + (*num_itr) == 2020){
                    cout << (*num_itr3) << " " <<  (*num_itr2) << " " << (*num_itr) << "sums to 2020" << endl;
                    cout << (*num_itr3) * (*num_itr2) * (*num_itr) << " is the answer" << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}


/**
this is the example

299 
366
675
979
1456
1721



*/