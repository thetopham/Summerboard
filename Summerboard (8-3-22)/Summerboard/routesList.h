#ifndef H_routesList
#define H_routesList

#include <iostream> 
#include <string>
#include <limits>

using namespace std;


class routesList {

public:
    routesList() { m_head = nullptr; }
    routes* lookup(routes* other);
    void Insert(routes* routess);
    void print();

private:
    class Node {
    public:
        Node(routes* routes = nullptr, Node* next = nullptr) {
            m_routes = routes; m_next = next;
        }
        routes* m_routes;
        Node* m_next;
    };
    Node* m_head;
}; 
#endif
