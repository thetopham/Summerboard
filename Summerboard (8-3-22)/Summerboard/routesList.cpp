#include <iostream>
#include <string>
#include "routes.h"
#include "routesList.h"

using namespace std;

void routesList::Insert(routes* routes)
{
    if (m_head == nullptr || m_head->m_routes->getroute() > routes->getroute()) {
        m_head = new Node(routes, m_head);
    }
    else {
        Node* node = m_head;
        while (node->m_next != nullptr &&
            node->m_next->m_routes->getroute() < routes->getroute()) {
            node = node->m_next;
        }
        node->m_next = new Node(routes, node->m_next);
    }
}

routes* routesList::lookup(routes* other)
{
    Node* node = m_head;

    while (node) {  /* iterate over nodes in list looking for route */
        if (node->m_routes->getroute() == other->getroute())
            return node->m_routes;           /* return pointer to node if found */
        node = node->m_next;
    }
    return nullptr;                         /* nullptr if not */
}

void routesList::print()
{
    Node* node = m_head;

    while (node != nullptr) {
        node->m_routes->routes::printroute();
        node = node->m_next;
    }
}