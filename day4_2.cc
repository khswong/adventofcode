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
    ifstream infile("day4_input.txt");
    string line;
    /*

    byr (Birth Year) - four digits; at least 1920 and at most 2002.
    iyr (Issue Year) - four digits; at least 2010 and at most 2020.
    eyr (Expiration Year) - four digits; at least 2020 and at most 2030.
    hgt (Height) - a number followed by either cm or in:
        If cm, the number must be at least 150 and at most 193.
        If in, the number must be at least 59 and at most 76.
    hcl (Hair Color) - a # followed by exactly six characters 0-9 or a-f.
    ecl (Eye Color) - exactly one of: amb blu brn gry grn hzl oth.
    pid (Passport ID) - a nine-digit number, including leading zeroes.
    cid (Country ID) - ignored, missing or not.

    */
    vector<regex> fields = {
        regex("byr:(200[0-2]|19[2-9][\\d]) "),
        regex("iyr:20(1\\d|20) "),
        regex("eyr:20(2\\d|30) "),
        regex("hgt:(1([5-8]\\d|9[0-3])cm|(59|6\\d|7[0-6])in) "),
        regex("hcl:#([0-9a-f]){6} "),
        regex("ecl:(amb|blu|brn|gry|grn|hzl|oth) "),
        regex("pid:[\\d]{9} "),
    };
    smatch base_match;
    int valid_uwu = 0;

    vector<string> passports;
    string passport = "";
    while (getline(infile, line))
    {
        passport += line;
        passport += " ";
        if (!line.size())
        {
            passports.push_back(passport);
            passport.clear();
        }
    }
    passports.push_back(passport);

    for (auto cur_passport : passports)
    {
        cout << cur_passport << endl;
        int matches = 0;
        for (auto field : fields)
        {
            if (regex_search(cur_passport, base_match, field)) {
                cout << "match ";
                matches++;
            }
        }
        cout << matches << " ";
        if (matches == 7) {
            valid_uwu++;
            cout << "valid" << endl;
        } else{
            cout << "invalid" << endl;
        }
    }
    cout << "answer" << valid_uwu << endl;

}