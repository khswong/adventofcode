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

unordered_map<string, int> instruction_set(
    {{"nop", nop}, {"jmp", jmp}, {"acc", acc}});

string tail(string const &source, size_t const length)
{
    if (length >= source.size())
    {
        return source;
    }
    return source.substr(source.size() - length);
} // tail

bool does_program_loop(vector<string> program){
    unordered_map<int, bool> pc_log;
    int pc = 0;
    int accumulator = 0;
    cout << "program size " << program.size() << endl;
    while (!pc_log[pc])
    {
        string instruction = program[pc];
        pc_log[pc] = true;
        int function_argument = stoi(instruction.substr(4));
        cout << pc << ": ";
        switch (instruction_set[instruction.substr(0, 3)])
        {
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
        if (pc >= program.size()){
            cout << "final accumulator :" << accumulator << endl;
            return true;
            break;
        }
    }
    //cout << "final accumulator :" << accumulator << endl;
    return false;
}

int main() {
    std::ifstream infile("day8_input.txt");
    std::string line;

    vector<string> program;
    while (std::getline(infile, line))
    {
        program.push_back(line);
    }
    bool program_terminates = false;
    int i = 0;
    while (!program_terminates){
        vector<string> program_copy = program;
        string instruction = program[i];
        string function_argument = instruction.substr(4);
        switch (instruction_set[instruction.substr(0, 3)])
        {
        case nop:
            program_copy[i].clear();
            program_copy[i] = "jmp " + function_argument;
            break;
        case jmp:
            program_copy[i].clear();
            program_copy[i] = "nop " + function_argument;
            break;
        case acc:
        default:
            break;
        }
        i++;
        program_terminates = does_program_loop(program_copy);
    }
    return 0;
}