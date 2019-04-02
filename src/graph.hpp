#include <vector>
#include <iostream>

#ifndef GRAPH_H
#define GRAPH_H

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

class Graph
{
    private:
        std::vector<Edge> edges;
    public:
        Graph() {}
        void print_path(std::string s1, std::string s2);
        void add_edge(std::string s1, std::string s2, int dist);
};

#endif

std::string get_string();
