#include <vector>
#include <iostream>

class Vertex;

class Edge
{
    private:
        Vertex* first_city;
        Vertex* second_city;
        int distance;
    public:
        Edge(Vertex* f_city, Vertex* s_city, int dist);
        Vertex* get_first_city();
        Vertex* get_second_city();
        int get_distance();
};

Edge::Edge(Vertex* f_city, Vertex* s_city, int dist)
{
    first_city = f_city;
    second_city = s_city;
    distance = dist;
}

Vertex* Edge::get_first_city()
{
    return first_city;
}
       
Vertex* Edge::get_second_city() 
{
    return second_city;
}
 
int Edge::get_distance() 
{
    return distance;
}

class Vertex
{
    private:
        std::string name;
        std::vector<Edge> edges;
    public:
        Vertex(std::string n);
        void add_edge(Vertex* v, int dist);
        void print_edges(std::string s);
        std::string get_name();
        std::vector<Edge> get_edges();
};

Vertex::Vertex(std::string n)
{
    name = n;     
}
        
void Vertex::add_edge(Vertex* v, int dist)
{
    Edge new_edge(this, v, dist);
    edges.push_back(new_edge);
}

void Vertex::print_edges(std::string s)
{
    std::cout << "Distance from " << name << " to ";
    for (std::vector<Edge>::iterator it = edges.begin(); it != edges.end(); ++it)
    {
        if ((*it).get_second_city()->get_name() == s) {
            std::cout << (*it).get_second_city()->get_name() <<
                " - " << (*it).get_distance() << std::endl;
        }
    }
}

std::string Vertex::get_name() 
{
    return name;
}

std::vector<Edge> Vertex::get_edges() 
{
    return edges;
}


class Graph
{
    private:
        std::vector<Vertex*> vertices;
    public:
        Graph() {}
        void insert(Vertex* v);
        void print_graph(std::string s1, std::string s2);
};

void Graph::insert(Vertex* v)
{   
    vertices.push_back(v);
}

void Graph::print_graph(std::string s1, std::string s2)
{   
    for (std::vector<Vertex*>::iterator it = vertices.begin(); it != vertices.end(); ++it) {
        if ((*it)->get_name() == s1) {
            (*it)->print_edges(s2);
        }
    }
}

std::string get_int()
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
