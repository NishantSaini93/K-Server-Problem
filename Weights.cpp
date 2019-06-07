#include "Weights.hpp"
#include "OPT.hpp"
#include "GreedySolution.hpp"
#include<queue>
#include<set>
#include<map>
#include "WFASolution.hpp"
/**
*This fuction will calculate shortest distance beween any two pairs of nodes.
*@param graph  of nodes
*@return 0 on completion
*/
int computeDistancesFromFile(vector<int> graph[], vector<int> configuration, vector<int> request, int numberOfVertex) {
	/**
	*This vector is implemented to save weights
	*/
	vector<vector<int>>  arrayD(numberOfVertex, vector<int>(numberOfVertex));
	cout << "configuration:";
	for (int i{ 0 }; i < 4; i++) {
		cout << configuration[i] << " ";
	}
	cout << endl;
	
	//This for loop is to calculate weights by using BFS
	for (int vertexV{ 0 }; vertexV < numberOfVertex; vertexV++) {
		for (int vertexU{ 0 }; vertexU < numberOfVertex; vertexU++) {
			if (vertexV == vertexU) {
				arrayD[vertexV][vertexU] = 0;
			}
			else {
				queue<int> queueOFElementsToProcess;
				queueOFElementsToProcess.push(vertexV + 1);
				set<int> setOfVisitedNodes;
				setOfVisitedNodes.insert(vertexV + 1);
				map<int, int> distance;
				distance[vertexV + 1] = 0;
				bool flag{ false };
				
				//Actual BFS is taking place here
				while (!queueOFElementsToProcess.empty()) {
					int currentlyProcessingElement = queueOFElementsToProcess.front();
					queueOFElementsToProcess.pop();
					for (auto neighbor : graph[currentlyProcessingElement]) {
						if (setOfVisitedNodes.count(neighbor) == 0) {
							distance[neighbor] = distance[currentlyProcessingElement] + 1;
							setOfVisitedNodes.insert(neighbor);
							queueOFElementsToProcess.push(neighbor);
						}
						if (neighbor == vertexU + 1) {
							flag = true;
						}

					}
					if (flag == true) {
						arrayD[vertexV][vertexU] = distance[vertexU + 1];
						break;
					}
				}

			}
		}
	}
	cout << "Enter the choice" << endl;
	cout << "1 for WFA solution" << endl;
	cout << "2 for OPT solution" << endl;
	cout << "3 for Greedy Solution" << endl;
	cout << "4 for all of three solutions" << endl;
	char greedyOrOPTOWfa;
	cin >> greedyOrOPTOWfa;

	if (greedyOrOPTOWfa == '1') {
		int cost1 = computeWFA(arrayD, configuration, request, numberOfVertex);
		cout << "WFA:" << cost1 << endl;
	}
	else if (greedyOrOPTOWfa == '2') {
		int cost2 = computeOPT(arrayD, configuration, request, numberOfVertex);
		cout << "OPT:" << cost2 << endl;

	}
	else if (greedyOrOPTOWfa == '3') {
		int cost3 = computeGreedy(arrayD, configuration, request, numberOfVertex);
		cout << "Greedy:" << cost3 << endl;
	}
	else {
		int cost11 = computeWFA(arrayD, configuration, request, numberOfVertex);
		int cost22 = computeOPT(arrayD, configuration, request, numberOfVertex);
		int cost33 = computeGreedy(arrayD, configuration, request, numberOfVertex);
		cout << "WFA:" << cost11 << endl;
		cout << "OPT:" << cost22 << endl;
		cout << "Greedy:" << cost33 << endl;
	}
	return 0;
}