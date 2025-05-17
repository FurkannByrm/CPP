#pragma once
#include <regex>
#include <string_view>
#include <map>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>




class Analyzer {
    
    public:
    Analyzer() = default;
    Analyzer(const std::string&);
    void definePattern();
    void viewMatches()const;
    void saveLogError();
    
    private:
    std::map<std::string, int> matches_;
    std::map<std::string,std::regex> regex_map;
    std::vector<std::string> error_line_list_;
    std::vector<std::string> ip_list_;
    
    // std::vector<std::regex> pattern_;
};


