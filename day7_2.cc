#include <iostream>

#include <sstream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <vector>

#include <regex>

using namespace std;

void count_bags(int &accumulator, int prev_cost, int cur_index, vector<vector<int>> &graph, unordered_map<int, bool> &visited)
{
    cout << "visited " << cur_index << "current bags: " << accumulator << endl;
    auto vertices = graph[cur_index];
    for (int i = 0; i < vertices.size(); ++i){
        if (vertices[i] && !visited[i] && (i != cur_index)){
            accumulator += vertices[i] * prev_cost;
            count_bags(accumulator, vertices[i] * prev_cost, i, graph, visited);
        }
    }
}

int main() {
    std::ifstream infile("day7_input.txt");
    std::string line;
    
    int sum = 0;
    int index = 0;
    unordered_map<string, int> bag_color_index;
    vector<vector<int>> adjacency_matrix;
    vector<unordered_map<string, int>> parsed_list;
    vector<vector<int>> list_costs;

    regex preamble("([a-z]+ [a-z]+) bags contain");
    regex bag_search("([\\d]+) ([a-z]+ [a-z]+) bags?");
    smatch base_match;
    smatch color_match;
    // ([a-z]+ [a-z]+) bags contain ([\d]+) ([a-z]+ [a-z]+) bags? 
    while (std::getline(infile, line))
    {
        unordered_map<string, int> bag_of_bags;
        regex_search(line, base_match, preamble);
        bag_color_index[base_match[1]] = index;
        bag_of_bags[base_match[1]] = 1;
        index++;
        cout << base_match[1] << " contains ";
        string suffix = base_match.suffix();
        auto colors_begin = std::sregex_iterator(suffix.begin(), suffix.end(), bag_search);
        auto colors_end = std::sregex_iterator();
        for (std::sregex_iterator i = colors_begin; i != colors_end; ++i)
        {
            color_match = *i;
            int cost = stoi(color_match[1]);
            std::string match_str = color_match[2].str();
            std::cout << cost << match_str << '\n';
            bag_of_bags[match_str] = cost;
        }
        parsed_list.push_back(bag_of_bags);
        cout << endl;
    }

    adjacency_matrix.resize(index, vector<int>(index));

    for (int i = 0; i < index; ++i){
        for (auto x : parsed_list[i])
        {
            adjacency_matrix[i][bag_color_index[x.first]] = x.second;
        }
    }

    int shiny_gold_node = bag_color_index["shiny gold"];
    cout << "shiny gold node: " << shiny_gold_node << endl;
    for (auto x : adjacency_matrix){
        for (auto y : x){
            cout << y << " ";
        }
        cout << endl;
    }
    unordered_map<int, bool> visited;

    count_bags(sum, 1, shiny_gold_node, adjacency_matrix, visited);

    cout << "total: " << sum << endl;

    return 0;
}