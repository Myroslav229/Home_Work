#include <iostream>
#include "Graph.h"

//#define TIME_LOG_ENABLED
int getTime() { return 1; }

int main()
{
	GraphAdjMatrix graph(10, Graph::ConnectionType::directed);
	//GraphAdjList graph(10, Graph::ConnectionType::directed);

	//graph.addEdge(0, 1);
	//graph.addEdge(1, 2);
	//graph.addEdge(2, 3);
	//graph.addEdge(3, 0);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 4);
	graph.addEdge(2, 5);
	graph.addEdge(2, 6);
	graph.addEdge(3, 7);
	graph.addEdge(4, 8);
	graph.addEdge(5, 9);

	//std::cout << std::boolalpha << graph.isStronglyConnected();

#ifdef TIME_LOG_ENABLED
	int startTime = getTime();
#endif
	//graph.DFS(0);
	graph.BFS(0);
	//std::cout << graph.numberOfNodesInLevel(1);

#ifdef TIME_LOG_ENABLED
	int endTime = getTime();
	int diff = endTime - startTime;
	std::cout << "Time used for BFS: " << diff << std::endl;
#endif

}