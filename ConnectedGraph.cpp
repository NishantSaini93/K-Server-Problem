#include "ConnectedGraph.hpp"


int checkConnected(vector<int> graph[],int number){
	queue<int> queueOFElementsToProcess;
				queueOFElementsToProcess.push(1);
				set<int> setOfVisitedNodes;
				setOfVisitedNodes.insert(1);
				while(!queueOFElementsToProcess.empty()){
					int currentlyProcessingElement=queueOFElementsToProcess.front();
					queueOFElementsToProcess.pop();
					for(auto neighbor:graph[currentlyProcessingElement]){
						if(setOfVisitedNodes.count(neighbor)==0){
                         	setOfVisitedNodes.insert(neighbor);
                         	queueOFElementsToProcess.push(neighbor);
                         }
					}
				}
				

				if(number==setOfVisitedNodes.size()){
					return 1;
				}

				return 0;
}