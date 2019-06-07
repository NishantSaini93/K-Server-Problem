#include "PartOne.hpp"
#include "Contains.hpp"
#include "ConnectedGraph.hpp"
#include "Weights.hpp"
#include "RandomGenerations.hpp"
/**
*This is function generate graph randomly on the basis of probability.
*@return 0 after executing all instructions
*/
int performPartOne(){
	int numberOfVertex;
	cout<<"Enter the number of nodes:";
	cin>>numberOfVertex;
	int decision{ 0 };
	while(decision==0){
	double probability;
	cout<<"Enter probability from in between 0 to 1"<<endl;
	cin>>probability;
	vector<int> graph[51];
	set<int> setOfConsideredNodes{};
    for(int nodeV=1;nodeV<=numberOfVertex-1;nodeV++){
    	for(int nodeU=nodeV+1;nodeU<=numberOfVertex;nodeU++){
    			random_device randomProbability;
			    default_random_engine generator(randomProbability()); 
			    uniform_real_distribution<double> generateProbability(0,1);
			    double number = generateProbability(generator);			    
			    if(number<=probability){
			    	if(setOfConsideredNodes.count(nodeU)==0){
			    	graph[nodeV].push_back(nodeU);
			    	graph[nodeU].push_back(nodeV);
			    	}
			    }else{
			    	continue;
			    }
			    if(nodeU==numberOfVertex-1){
			    	setOfConsideredNodes.insert(nodeV);
			    }
    	}
    }        
    		decision=checkConnected(graph,numberOfVertex);
			if(decision==1){
			 generateRandom(graph,numberOfVertex);

			}
			else{
				cout<<"Graph is not connected."<<endl;
			}
	}
	return 0;
}