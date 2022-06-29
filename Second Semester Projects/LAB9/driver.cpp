#include "GraphList.h"

int main()
{
    ifstream ifs;
    int numVertices, fromVert, toVert;
    string line;

    ifs.open("graph.txt");

    if (!ifs.is_open())
    {
        cerr << "Error! File not found";
        return 0;
    }

    getline(ifs, line);
    numVertices = stoi(line);

    GraphList* graph = new GraphList(numVertices);

    cout << "There are " << numVertices << " vertices in the graph\n\n";

    while(getline(ifs, line))
    {
        fromVert = stoi(line.substr(0));
        toVert = stoi(line.substr(2));
        cout << "Adding an edge from " << fromVert << " to " << toVert << "." << endl;
        graph->addEdge(fromVert, toVert);
    }

    graph->printGraph();

    return 0;
}