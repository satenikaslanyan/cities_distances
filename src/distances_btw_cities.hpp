#include <vector>
#include <iostream>

class Edge
{
    private:
        std::string first_city;
        std::string second_city;
        int distance;
    public:
        Edge(std::string f_city, std::string s_city, int dist);
        std::string get_first_city();
        std::string get_second_city();
        int get_distance();
};

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

class Graph
{
    private:
        std::vector<Edge> edges;
    public:
        Graph() {}
        void print_path(std::string s1, std::string s2);
        void add_edge(std::string s1, std::string s2, int dist);
};

void Graph::add_edge(std::string s1, std::string s2, int dist)
{
    Edge new_edge(s1, s2, dist);
    edges.push_back(new_edge);
}

void Graph::print_path(std::string s1, std::string s2)
{
    for (std::vector<Edge>::iterator it = edges.begin(); it < edges.end(); ++it) {
        if ((*it).get_first_city() == s1 && (*it).get_second_city() == s2) {
            std::cout << "Distance from " <<  (*it).get_first_city() << " to " << 
                (*it).get_second_city() << " - " << 
                (*it).get_distance() << std::endl;
        } else if ((*it).get_second_city() == s1 && (*it).get_first_city() == s2) {
             std::cout << "Distance from " <<  (*it).get_second_city() << " to " <<
                (*it).get_first_city() << " - " <<
                (*it).get_distance() << std::endl;
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
