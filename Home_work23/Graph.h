#pragma once
#include <list>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <stack>

class Graph
{
public:
	enum class ConnectionType
	{
		undirected,
		directed
	};

	Graph(const unsigned int & vertixes, ConnectionType type = ConnectionType::undirected)
		: m_vertixes(vertixes), m_connectionType(type) {}

	//virtual void addEdge(int v, int w) = 0;

	/*virtual void BFS(int vertex = 0) {};
	virtual void DFS(int vertex = 0) {};*/

protected:
	unsigned int m_vertixes;
	ConnectionType m_connectionType;
};

// using adjacency list
class GraphAdjList : public Graph
{
public:
	GraphAdjList(const unsigned int & Vertixes, ConnectionType type)
		: Graph(Vertixes, type)
	{
		m_list.resize(Vertixes);
	}

	void addEdge(int v, int w) {
		//Check if w is not already in the list of v
		for (int& val : m_list[v]) {
			if (val == w) {
				return;
			}
		}
		m_list[v].push_back(w);

		if (m_connectionType == ConnectionType::undirected)
		{
			m_list[w].push_back(v);
		}	
	}

	void BFS(int vertex = 0) {
		// Mark all the vertices as not visited
		std::unordered_set<int> visited;
		std::list<int> queue;

		// Mark the current node as visited and enqueue it
		visited.insert(vertex);
		queue.push_back(vertex);

		while (!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			int currentVertex = queue.front();
			std::cout << currentVertex << " ";  //or make anything else with it: push to vector, string, another object, whatever
			queue.pop_front();

			// Get all adjacent vertices
			for (int adjacent : m_list[currentVertex])
			{
				if (!visited.count(adjacent))
				{
					visited.insert(adjacent);
					queue.push_back(adjacent);
				}
			}
		}
	}
	void DFS(int vertex) {
		std::unordered_set <int> visited(m_vertixes);

		std::cout << vertex;
		visited.insert(vertex);
		recursionDFS(vertex, visited);
	}
	std::size_t numberOfNodesInLevel(int level) const {
		std::unordered_set<int> visited;
		std::vector<int> array,temp;

		visited.insert(0);
		array.push_back(0);

		for (int i = 1; i < level; ++i) {
			temp = array;
			array.clear();
			for(int num : temp){
				for (int adjacent : m_list[num]) {
					if (!visited.count(adjacent)) {
						visited.insert(adjacent);
						array.push_back(adjacent);
					}
				}
			}
		}
		return array.size(); 
	} //#TODO IMPLEMLENT
	bool isStronglyConnected() const {
		if (m_connectionType == Graph::ConnectionType::undirected) { return true; } // time saving
		std::unordered_set<int> visited;
		std::stack<int> stack;
		
		visited.insert(0);
		fillOrder(0, visited, stack);


		GraphAdjList trans_graph(m_vertixes, m_connectionType);
		for (int i = 0; i < m_vertixes; ++i) {
			for (int adjacent : m_list[i]) {
				trans_graph.addEdge(adjacent, i);
			}
		}
		visited.clear();
		visited.insert(0);
		std::stack<int> SCC;
		trans_graph.fillOrder(stack.top(), visited, SCC);
		if (SCC.size() == m_vertixes) return true;
		return false;
	}
private:
	std::vector<std::list<int> > m_list;
	void recursionDFS(int vertex, std::unordered_set <int>& visited) {
		for (int adjacent : m_list[vertex]) {
				if (!visited.count(adjacent)) {
					std::cout << adjacent;
					visited.insert(adjacent);
					recursionDFS(adjacent, visited);
			}
		}
	}
	void fillOrder(int vertex, std::unordered_set <int>& visited, std::stack<int>& stack) const {

		for (int adjacent: m_list[vertex]) {
			if (!visited.count(adjacent)) {
				
				visited.insert(adjacent);
				fillOrder(adjacent, visited, stack);
			}
		}

		stack.push(vertex);
		
	}
	
};

//#TODO HW
class GraphAdjMatrix : public Graph
{
public:
	GraphAdjMatrix(const unsigned int & vertixes, ConnectionType type = ConnectionType::undirected)
		: Graph(vertixes, type)
	{
		m_vector.resize(vertixes);
		for (auto & arr: m_vector) {
			arr.resize(vertixes);
		}
		
	}; //#TODO, IMPLEMENT if needed

	void addEdge(const unsigned int & v, const unsigned int & w) {
		if (v == w || w >= m_vertixes || v >= m_vertixes) { return; }
		

		m_vector[v][w] = true;
		if(m_connectionType == Graph::ConnectionType::undirected){
			m_vector[w][v] = true;
		}
	}; //#TODO IMPLEMENT
	void BFS(int vertex = 0) {
		std::unordered_set<int> visited;
		std::list<int> queue;

		// Mark the current node as visited and enqueue it
		visited.insert(vertex);
		queue.push_back(vertex);

		while (!queue.empty())
		{
			// Dequeue a vertex from queue and print it
			int currentVertex = queue.front();
			std::cout << currentVertex << " ";  //or make anything else with it: push to vector, string, another object, whatever
			queue.pop_front();

			for (int i = 0; i < m_vertixes; ++i) {
				if (m_vector[currentVertex][i] == true && !visited.count(i)) {
					visited.insert(i);
					queue.push_back(i);
				}
			}
		}
	}
	void DFS(int vertex = 0) {
		std::unordered_set <int> visited(m_vertixes);
		
		std::cout << vertex;
		visited.insert(vertex);
		recursionDFS(vertex, visited);
	};	//#TODO IMPLEMENT

private:
	//#TODO
	std::vector<std::vector<int>> m_vector;
	void recursionDFS(int vertex, std::unordered_set <int>& visited) {
		for (int i = 0; i < m_vertixes; ++i) {
			if (m_vector[vertex][i] == true) {
				if (!visited.count(i)) {
					std::cout << i;
					visited.insert(i);
					recursionDFS(i, visited);
				}
			}
		}
	}
};
