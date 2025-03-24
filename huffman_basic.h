#pragma once
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>


struct nodes
{
    char value;//word
    int numbers;//
    int direction;//0:left 1:right
    //nodes * up;
    //nodes * down;
};


class humffman_tree
{
    public:
          std::vector<nodes> sets_node;
          std::map<int,nodes> sor_node;
          std::map<char,std::string> after_code;
          std::map<char,int> uints_tables(std::string values);
          nodes min_v(std::map<char,int> sets);
          void build_tables(std::string values);
          void clean_();
};




