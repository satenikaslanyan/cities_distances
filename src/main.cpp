#include "distances_btw_cities.hpp"

int main()
{
    Graph g;

    Vertex v1 = Vertex("Yerevan");
    Vertex v2 = Vertex("Gyumri");
    Vertex v3 = Vertex("Ashtarak");
    Vertex v4 = Vertex("Vanadzor");

    Vertex* vp1 = &v1;
    Vertex* vp2 = &v2;
    Vertex* vp3 = &v3;
    Vertex* vp4 = &v4;

    v1.add_edge(vp2, 120);
    v1.add_edge(vp3, 20);
    v1.add_edge(vp4, 120);
    v2.add_edge(vp1, 120);
    v2.add_edge(vp3, 100);
    v2.add_edge(vp4, 60);
    v3.add_edge(vp1, 20);
    v3.add_edge(vp2, 100);
    v3.add_edge(vp4, 100);
    v4.add_edge(vp1, 120);
    v4.add_edge(vp2, 60);
    v4.add_edge(vp3, 100);

    g.insert(vp1);
    g.insert(vp2);
    g.insert(vp3);
    g.insert(vp4);

    std::string s1, s2;
    s1 = get_int();
    s2 = get_int();

    g.print_graph(s1, s2);
}
     
