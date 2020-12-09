#include <iostream>

#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

enum instr {
    nop = 0,
    jmp = 1,
    acc = 2,
};

string tail(string const& source, size_t const length) {
  if (length >= source.size()) { return source; }
  return source.substr(source.size() - length);
} // tail


int main() {
    std::ifstream infile("day8_input.txt");
    std::string line;
    unordered_map<int, bool> pc_log;
    unordered_map<string, int> instruction_set;
    instruction_set["nop"] = nop;
    instruction_set["jmp"] = jmp;
    instruction_set["acc"] = acc;
    int pc = 0;
    int accumulator;
    vector<string> program;
    while (std::getline(infile, line))
    {
        program.push_back(line);
    }
    while (!pc_log[pc]){
        string instruction = program[pc];
        pc_log[pc] = true;
        int function_argument = stoi(instruction.substr(4));
        cout << pc << ": ";
        switch (instruction_set[instruction.substr(0, 3)]){
            case jmp:
                cout << "jmp " << function_argument << endl;
                pc += function_argument;
                break;
            case acc:
                cout << "acc " << function_argument << endl;
                accumulator += function_argument;
                pc++;
                break;
            case nop:
                cout << "nop" << endl;
                pc++;
                break;
            default:
                break;
        }
        if (pc > program.size()) break;
    }
    cout << "final accumulator :" << accumulator << endl;
    return 0;
}