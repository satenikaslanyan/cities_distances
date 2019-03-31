#include "distances_btw_cities.hpp"

int main()
{
    Graph g;

    std::string v1 = "Yerevan";
    std::string v2 = "Gyumri";
    std::string v3 = "Ashtarak";
    std::string v4 = "Vanadzor";

    g.add_edge(v1, v2, 120);
    g.add_edge(v1, v3, 20);
    g.add_edge(v1, v4, 120);
    g.add_edge(v2, v3, 100);
    g.add_edge(v2, v4, 60);
    g.add_edge(v3, v4, 100);

    std::cout << "Please input two cities ";
    std::cout << "(Yerevan, Gyumri, Astharak, Vanadzor)" << std::endl;
    std::string s1, s2;
    s1 = get_string();
    s2 = get_string();

    g.print_path(s1, s2);
}
     
