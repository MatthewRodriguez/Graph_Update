#include "graph.h"

Graph::Graph(){
    nodes.clear();
}

void Graph::addNode(int val){
    Node *n = new Node(val);
    if (nodes.empty())
        nodes.push_back(n);
    else{
        for (int i = 0; i < nodes.size(); i++)
            if (nodes[i]->info == val)
                return;
        nodes.push_back(n);
    }
}

void Graph::addU(){
    addUndirectedEdge(nodes[0], nodes[1]);
}

void Graph::removeU(){
    removeUndiretedEdge(nodes[0], nodes[1]);
}

void Graph::addUndirectedEdge(Node *first, Node *second){
  
    if ((first->list.empty() && second->list.empty()) && (first->info != second->info)){
        first->list.push_back(second);
        second->list.push_back(first);
    }
    else if (first->info == second->info){
        return;
    }
    else{
        for (int i = 0; i < first->list.size(); i++)
            if (first->list[i]->info == second->info)
                return;
        for (int i = 0; i < second->list.size(); i++)
            if (second->list[i]->info == first->info)
                return;
        first->list.push_back(second);
        second->list.push_back(first);
    }
}

void Graph::undirectedEdge(Node *first, Node *second){
    first->list.push_back(second);
}

void Graph::removeUndiretedEdge(Node *first, Node *second){
    if (first->list.empty() && second->list.empty())
        return;
    for (int i = 0; i < first->list.size(); i++){
        if(first->list[i]->info == second->info)
            first->list.erase(first->list.begin()+i);
    }
    for (int i = 0; i < second->list.size(); i++){
        if(second->list[i]->info == first->info)
            second->list.erase(second->list.begin()+i);
    }
}

void Graph::clear(){
    nodes.clear();
}

unordered_set<Node*> Graph::getAllNodes(){
    unordered_set<Node*> s;
    for (int i = 0; i < nodes.size(); i++)
        s.insert(nodes[i]);
    return s;
}

void Graph::printNodes(){
    cout << " { ";
    for (int i = 0; i < nodes.size(); i++)
        cout << nodes[i]->info << " ";
    cout << " } " << endl;
}

void Graph::printU(){
    for (int i = 0; i < nodes.size(); i++){
        cout << nodes[i]->info << ": ";
        for (int j = 0; j < nodes[i]->list.size(); j++)
            cout << nodes[i]->list[j]->info << " ";
        cout << endl;
    }
    cout << endl;
}

void Graph::createRandomUnweightedGraphIter(int n){
    int random, a, b, m = n*5;
    for (int i = 0; i < n; i++){
        random = (rand() % m) + 1;
        addNode(random);
    }
    for (int i = 0; i < nodes.size(); i++){
        if(nodes.size() > 1){
            a = rand() % nodes.size();
            b = rand() % nodes.size();
            addUndirectedEdge(nodes[a], nodes[b]);
        }
    }
}

void Graph::createLinkedList(int n){
    if (nodes.size() < 1)
        return;
    for (int i = 0; i < n; i++){
        addNode(i);
        undirectedEdge(nodes[nodes.size()-2], nodes[nodes.size()-1]);
    }
}
