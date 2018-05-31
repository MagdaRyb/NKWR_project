/*
	Program which contains BFS algorithm with slight modification.
	Solution of the following task:
	"Niewyobra¿alne, ale centrala obcej wrogiej agencji s¹siaduje z naszym budynkiem. Plan
	jest prosty, trzeba dotrzeæ do pomieszczenia dowodzenia i aresztowaæ dowódcê. Niestety
	wszystkie pomieszczenia w centrali obcej wrogiej agencji maj¹ drzwi zamkniête, a my nie mamy
	dorobionych kluczy. Dlatego przebijemy siê przez œciany. Masz plany budynku w postaci grafu,
	pomieszczenia to wierzcho³ki, punkt D to punkt dowodzenia, zbiór S to te wierzcho³ki, które
	s¹siaduj¹ z naszym budynkiem (od jednego z nich zaczniemy), zaœ krawêdzie odpowiadaj¹
	œcianom, przez które mo¿emy siê przebiæ. Napisz algorytm, który pozwoli ustaliæ trasê do
	punktu dowodzenia wymagaj¹c¹ przebicia jak najmniejszej liczby œcian."

	HOW TO USE: 
	1. Create instance of Inputer class.
	2. Create insatance of Agency class by calling Inputer instance method - loadParameter.
		Argument is path to file from which the data will be loaded.
		Template of such a file is shown below this instruction.
	3. Call instance method findShortest.
		The printed nodes are the searched answer.

	FILE TEMPLATE:
		number of graph elements
		number of neighbour elements (quantity of S set)
		matrix of graph coincidence, elements are separeted by space
		S set, elements are also separeted by space 
		D node - element to which is path searched 

		Example:
		5 
		2
		0 1 0 0 0
		1 0 1 0 0
		0 1 0 1 1
		0 0 1 0 0
		0 0 1 0 0
		1 0
		4

	The nodes are represented by numbers, indexed from 0. 

	Author: Rosenhof Marcin, Rybicka Magdalena, Smela Damian

*/

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include <list>

#define INFINITE -1

using namespace std;

class Node {
	/* 
	Class which represents graph node. Used during finding the way from one node to another.
	*/
public:
	bool visited;
	int distance;
	Node * prev;
	int id;

	Node(void) {
		visited = false;
		distance = INFINITE;
		prev = NULL;
	}
};

class Graph {
	/*
	Class which represents graph.
	*/
public:
	int n;			// number of nodes in graph
	int ** tab;		// matrix of graph coincidence
};


class Agency {
	/*
	Class which represtens agency.
	*/
public:
	int * S;		// list of neighbour nodes 
	int D;			// destination node
	Graph graph;	// Graph instance which represents agnecy building plan
	int sizeS;		// number of neighbour nodes

	list<int> findWay(int s) {
		// initializing graph nodes and source node
		Node * nodes = new Node[this->graph.n];
		Node * tmp;
		nodes[s].visited = true;
		nodes[s].distance = 0;
		for (int i = 0; i < this->graph.n ; i++) {
			nodes[i].id = i;
		}

		// intializing BFS queue
		queue <Node *> bfs_queue;
		bfs_queue.push(&nodes[s]);

		// BFS algorithm
		while (!bfs_queue.empty()) {
			tmp = bfs_queue.front();
			bfs_queue.pop();
			for (int i = 0; i < this->graph.n; i++) {
				// if this node is the neighbour and was not vistied - visit it
				if (this->graph.tab[i][tmp->id] == 1 && nodes[i].visited == false) {
					nodes[i].prev = tmp;
					nodes[i].visited = true;
					nodes[i].distance = tmp->distance + 1;
					bfs_queue.push(&nodes[i]);
				}
			}
		}

		// starting from destitantion node find path to the source and return it
		list <int> res;
		int current = this->D;
		while (current != s) {
			res.push_front(current);
			current = nodes[current].prev->id;
		}
		res.push_front(s);
		return res;
	}

	void findShortest(void) {
		// find the shortest path from all available neighbour nodes (nodes from S set) 
		list <int> ans, tmp;
		for (int i = 0; i < this->sizeS; i++) {
			tmp = this->findWay(S[i]);
			if (tmp.size() < ans.size() || ans.empty()) {
				ans = tmp;
			}
		}

		// show the found shortest path
		for (auto iterator = ans.begin(); iterator != ans.end(); ++iterator) {
			std::cout << *iterator<< " ";
		}
	}
};

class Inputer {
	/*
	Class responsible for loading parameters. 
	*/
public:
	Agency loadParameter(string path) {
		/*
		This method loads parameters from file to which path is included as the argument.
		Returns Agency class instance initialized by the appropiate parameters file.
		*/
		Agency agency;
		string line;
		ifstream graphFile(path);
		int tmp;
		if (graphFile.is_open())
		{
			graphFile >> agency.graph.n;
			cout << agency.graph.n << "\n";
			agency.graph.tab = new int *[agency.graph.n];
			for (int i = 0; i < agency.graph.n; i++) {
				agency.graph.tab[i] = new int [agency.graph.n];
			}
			graphFile >> agency.sizeS;
			for (int i = 0; i < agency.graph.n; i++) {
				for (int j = 0; j < agency.graph.n; j++) {
					graphFile >> tmp;
					cout << tmp << " ";
					agency.graph.tab[i][j] = tmp;
				}
				cout << endl;
			}
			agency.S = new int [agency.sizeS];
			for (int j = 0; j < agency.sizeS; j++) {
				graphFile >> tmp;
				cout << tmp << " ";
				agency.S[j] = tmp;
			}
			cout << endl;


			graphFile >> agency.D;
			cout << agency.D << endl;
			graphFile.close();
		}

		else cout << "Unable to open file";
		return agency;
	}
};

int main() {
	Inputer loader;
	Agency agency;
	agency = loader.loadParameter("001.txt");
	agency.findShortest();
	system("pause");
	return 0;
}