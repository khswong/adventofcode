#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <regex>

using namespace std;

bool is_reachable(int cur_index, int goal_index, vector<vector<int>> &graph, unordered_map<int, bool> &visited)
{
    if (cur_index == goal_index) return false;
    visited[cur_index] = true;
    vector<int> vertices = graph[cur_index];
    cout << "visited " << cur_index << endl;
    if (vertices.size() == 1)
    {
        return false;
    }
    for (auto x : vertices){
        cout << x << " ";
    }
    cout << endl;
    for (auto itr = vertices.begin(); itr != vertices.end(); ++itr)
    {   
        if (*itr == goal_index)
        {
            return true;
        }
        if (!visited[*itr])
        {
            cout << " visiting next " << *itr << endl;
            if (is_reachable(*itr, goal_index, graph, visited))
            {
                return true;
            }
        }
    }
    return false;
}

int main() {
    std::ifstream infile("day7_input.txt");
    std::string line;
    
    int sum = 0;
    int index = 0;
    unordered_map<string, int> bag_color_index;
    vector<vector<int>> adjacency_list;
    vector<vector<string>> parsed_list;

    regex preamble("([a-z]+ [a-z]+) bags contain");
    regex bag_search("[\\d]+ ([a-z]+ [a-z]+) bags?");
    smatch base_match;
    smatch color_match;
    // ([a-z]+ [a-z]+) bags contain ([\d]+) ([a-z]+ [a-z]+) bags? 
    while (std::getline(infile, line))
    {
        vector<string> bag_of_bags;
        regex_search(line, base_match, preamble);
        bag_color_index[base_match[1]] = index;
        bag_of_bags.push_back(base_match[1]);
        index++;
        cout << base_match[1] << " contains ";
        string suffix = base_match.suffix();
        auto colors_begin = std::sregex_iterator(suffix.begin(), suffix.end(), bag_search);
        auto colors_end = std::sregex_iterator();
        for (std::sregex_iterator i = colors_begin; i != colors_end; ++i)
        {
            color_match = *i;
            std::string match_str = color_match[1].str();
            std::cout << match_str << '\n';
            bag_of_bags.push_back(match_str);
        }
        parsed_list.push_back(bag_of_bags);
        cout << endl;
    }

    for (auto x : parsed_list){
        vector<int> vertices;
        for (auto y : x){
            vertices.push_back(bag_color_index[y]);
        }
        adjacency_list.push_back(vertices);
    }

    int shiny_gold_node = bag_color_index["shiny gold"];
    cout << "shiny gold node: " << shiny_gold_node << endl;
    for (auto x : adjacency_list){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < index; ++i ){
        cout << "checking " << i << endl;
        if (is_reachable(i, shiny_gold_node, adjacency_list, visited)) {
            sum++;
            cout << "reachable" << endl;
        }
        visited.clear();
    }

    cout << "total: " << sum << endl;

    return 0;
}