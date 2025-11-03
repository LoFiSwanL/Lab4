#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>

struct operation_frequency{
    std::string command;
    int index;
    double freq;
};

class generator{
    const std::vector<operation_frequency> var9_freq = {{"read", 0, 0.1}, {"read", 0, 0.1}, {"write", 0, 0.1}, {"read", 1, 0.1}, {"write", 1, 0.1}, {"read", 2, 0.4}, {"write", 2, 0.05}, {"string", -1, 0.15}};

    void generate(const std::string &fileName, const std::vector<operation_frequency> &freq, long long num_operations);

    std::vector<std::string> generate_comands(const std::vector<operation_frequency> &freq, long long num_operations);

public:
    
};