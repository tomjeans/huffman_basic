#include "huffman_basic.h"

std::map<char,int> humffman_tree::uints_tables(std::string values)
{
    std::map<char,int> str_nums;
    for(int index=0;index<values.size();index++)
    {   
        int nums=0;
        //values[index]
        for(int index_=0;index_<values.size();index_++)
        {
            if(values[index]==values[index_])
            {
                nums++;
            }
        }
        str_nums.insert(std::pair<char,int>(values[index],nums));
        
    }
    return str_nums;
}


nodes humffman_tree::min_v(std::map<char,int> sets)
{
    int first = 0;
    char min_char ='\0'; 
    int min_number = 0;
    for(auto single_node:sets)
    {   if(first==0)
        {
            min_number=single_node.second;
            min_char=single_node.first;
            first=1;
        }

        if(min_number>=single_node.second)
        {
            min_number=single_node.second;
            min_char=single_node.first;
        }
    }
    nodes temp;
    temp.value = min_char;
    temp.numbers = min_number;
    return temp;
}

void humffman_tree::build_tables(std::string values)
{
    std::map<char,int> w_int=uints_tables(values);

    nodes first_nodes=min_v(w_int);

    first_nodes.direction = 0;

    w_int.erase(first_nodes.value);

    sor_node.insert(std::pair<int,nodes>(0,first_nodes));

    nodes second_nodes=min_v(w_int);

    second_nodes.direction = 1;

    w_int.erase(second_nodes.value);

    sor_node.insert(std::pair<int,nodes>(1,second_nodes));


    nodes add_nodes;
    add_nodes.numbers = first_nodes.numbers+second_nodes.numbers;
    add_nodes.direction = 1;
    //add_nodes.down = second_nodes;
    sor_node.insert(std::pair<int,nodes>(4,add_nodes));

    

    int gap_v = 3;
    while(w_int.size()>=1)
    {
        nodes new_left=min_v(w_int);
        new_left.direction = 0;
        sor_node.insert(std::pair<int,nodes>(gap_v,new_left));
        w_int.erase(new_left.value);
        

        nodes new_right;
        new_right.numbers = new_left.numbers+add_nodes.numbers;
        new_right.direction = 1;
        //new_right.down = add_nodes;
        sor_node.insert(std::pair<int,nodes>(gap_v+1,new_right));
        gap_v+=2;

        add_nodes = new_right;
    }


    int floor_numbers=sor_node.size()/2;
    int floor_complete = 0;
    for(auto single_node:sor_node)
    {
        std::cout<<" number :"<<single_node.first<<" "<<single_node.second.value<<" "<<single_node.second.direction<<std::endl;
        std::string code_en ="";
        for(int time_c=1;time_c<floor_numbers;time_c++)
        {
            code_en=code_en+"1";

        }
        code_en+=std::to_string(single_node.second.direction);

        //std::map<char,std::string> after_code;

        after_code.insert(std::pair<char,std::string>(single_node.second.value,code_en));

        floor_complete++;

        if(floor_complete==2)
        {
            floor_numbers--;
            floor_complete = 0;
        }
    }


    std::cout<<"====after encode ===="<<std::endl;

    // // for(auto singl_after_code:after_code)
    // // {
    // //     std::cout<<" signed "<<singl_after_code.first<<" "<<singl_after_code.second<<std::endl;
    // // }

    

    //only values


}

void humffman_tree::clean_()
{
    sor_node.clear();
    after_code.clear();
}