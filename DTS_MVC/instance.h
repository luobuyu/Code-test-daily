#pragma once

#include <fstream>
#include <iostream>
using namespace std;

struct node
{
	int nodeId;
	node *next;
	node() : nodeId(-1), next(nullptr){};
	node(int id) : nodeId(id), next(nullptr){};
};

class instance
{
public:
	int vertexNum;
	int edgeNum;

	int *vertexDegree;
	node *adjacList;

	instance(const char *inFile)
	{
		ifstream fin;
		fin.open(inFile, ios::in);
		if (fin.is_open())
		{
			fin >> vertexNum >> vertexNum >> edgeNum;
			vertexDegree = new int[vertexNum]();
			adjacList = new node[vertexNum];
			for (int edgeId = 0; edgeId < edgeNum; edgeId++)
			{
				int v1 = -1, v2 = -1;
				fin >> v1 >> v2;
				v1--, v2--;
				vertexDegree[v1]++;
				vertexDegree[v2]++;
				node *node1 = new node(v2);
				node1->next = adjacList[v1].next;
				adjacList[v1].next = node1;
				node *node2 = new node(v1);
				node2->next = adjacList[v2].next;
				adjacList[v2].next = node2;
			}
			fin.close();
		}
		else
		{
			cerr << "cannot open the file!" << endl;
		}
	}

	~instance()
	{
		delete[] vertexDegree;
		for (int nodeId = 0; nodeId < vertexNum; nodeId++)
		{
			node *ptr = adjacList[nodeId].next;
			while (ptr)
			{
				node *tmp = ptr->next;
				delete ptr;
				ptr = tmp;
			}
		}
		delete[] adjacList;
	}
};