#include "graph.hpp"

Edge::Edge(std::string f_city, std::string s_city, int dist)
    : first_city(f_city)
    , second_city(s_city)
      , distance(dist)
{}

std::string Edge::get_first_city()
{   
    return first_city;
}       

std::string Edge::get_second_city()
{   
    return second_city;
}       

int Edge::get_distance()
{   
    return distance;
}       

void Graph::add_edge(std::string s1, std::string s2, int dist)
{
    Edge new_edge(s1, s2, dist);
    edges.push_back(new_edge);
}

void Graph::print_path(std::string s1, std::string s2)
{
    for (auto i : edges) {
        if (i.get_first_city() == s1 && i.get_second_city() == s2) {
            std::cout << "Distance from " <<  i.get_first_city() << " to " <<
                i.get_second_city() << " - " <<
                i.get_distance() << std::endl;
        } else if (i.get_second_city() == s1 && i.get_first_city() == s2) {
            std::cout << "Distance from " <<  i.get_second_city() << " to " <<
                i.get_first_city() << " - " <<
                i.get_distance() << std::endl;
        }
    }
}

std::string get_string()
{
    bool fl = false;
    std::string s("");
    do{
        std::cout << "Please input a city: ";
        getline(std::cin, s);
        fl = false;
        if(s != "Yerevan" && s != "Gyumri" && s != "Ashtarak" && s != "Vanadzor") {
            std::cout << "Error, you have entered invalid symbols" << std::endl;
            fl=true;
        }
    } while (fl);
    return s;
}

