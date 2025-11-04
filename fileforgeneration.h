#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <tuple>

using Comand_set = std::vector<std::tuple<std::string, int, double>>;

class generator{
    const Comand_set var9_freq = {{"read", 0, 0.1}, {"write", 0, 0.1}, {"read", 1, 0.1}, {"write", 1, 0.1}, {"read", 2, 0.4}, {"write", 2, 0.05}, {"string",   -1, 0.15}};

    void generate_file(const std::string &file, const Comand_set &freq, long long num_operations);

    std::vector<std::string> generate_comands(const Comand_set &freq, long long num_operations);

public:
    static constexpr long long DEFAULT_OPS_COUNT = 10000;

    void generate_all_files(long long num_operations = DEFAULT_OPS_COUNT);

    Comand_set get_equal_freq();
    Comand_set get_bad_freq();
};