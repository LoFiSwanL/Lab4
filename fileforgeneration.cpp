#include "fileforgeneration.h"
#include <iostream>
#include<algorithm>
#include <sstream>
#include <cmath>

using namespace std;


constexpr int index0 = 0; //comand
constexpr int index1 = 1; //field
constexpr int index2 = 2; //freq

Comand_set generator::get_equal_freq(){
    const size_t num_operations = var9_freq.size();
    const double equal_freq = 1.0 / num_operations;

    Comand_set equal_freqs = var9_freq;
    for(auto &op: equal_freqs){
        get<index2>(op) = equal_freq;
    }

    return equal_freqs;
}

Comand_set generator::get_bad_freq(){
    return {{"read", 0, 0.1}, {"write", 0, 0.1}, {"read", 1, 0.1}, {"write", 1, 0.1}, {"read", 2, 0.4}, {"write", 2, 0.05}, {"string",   -1, 0.15}};
}

vector<string> generator::generate_comands(const Comand_set &freq, long long num_operations)
{
    vector<double> weights;
    for(const auto &op: freq){
        weights.push_back(get<index2>(op));
    }

    random_device rd;
    mt19937 generator(rd());
    
    discrete_distribution<> distribution(weights.begin(), weights.end());

    vector<string> commands;
    const string write_value = " 1";

    for(long long i = 0; i < num_operations; i++){
        int index  = distribution(generator);
        const auto &op = freq[index];
        string command = get<index0>(op);

        if(command == "read" || command == "write"){
            command += " " + to_string(get<index1>(op));
        }
        if(command.rfind("write", 0) == 0){
            command += write_value;
        }
        commands.push_back(command);
    }

    return commands;
}

void generator::generate_file(const string &file, const Comand_set &freq, long long num_operations)
{
    cout << "Generate file: " << file << " (" << num_operations << " commands)" << endl;
    vector<string> commands = generate_comands(freq, num_operations);

    ofstream output_file(file);
    if(!output_file.is_open()){
        cerr << "Cant open file" << endl;
        return;
    }

    for(const auto &comand: commands){
        output_file << comand << endl;
    }
    
    cout << "Succesful generate" << endl;
}

void generator::generate_all_files(long long num_operations){
    cout << "Start...\n" << endl;

    const auto equal = get_equal_freq();
    for(int i = 1; i < 4; i++){
        generate_file("commands_A_" + to_string(i) + ".txt", var9_freq, num_operations);
    }

    for(int i = 1; i < 4; i++){
        generate_file("commands_B_" + to_string(i) + ".txt", equal, num_operations);
    }

    const auto bad = get_bad_freq();
    for(int i = 1; i < 4; i++){
        generate_file("commands_C_" + to_string(i) + ".txt", bad, num_operations);
    }

    cout << "\nEnd." << endl;
}