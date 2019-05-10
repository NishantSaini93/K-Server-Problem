//This is implementation file PartTwo.cpp
#include "PartTwo.hpp"
#include "Weights.hpp"
#include<iostream>
#include<vector>
#include<fstream>
#include<typeinfo>
#include<string>
#include "ConnectedGraph.hpp"
#include<random>
#include "RandomGenerations.hpp"
using namespace std;
//This function define part two of project
int performPartTwo(){
	//This variable is for exiting main while loop
	bool flagForExiting=false;
	while(!flagForExiting){
		char optionChoosed;
		cout<<endl<<"Choose graph 1-6 by entering number(enter 7 to exit)"<<endl;
		cout<<"graph1=15 nodes"<<endl;
		cout<<"graph2=20 nodes"<<endl;
		cout<<"graph3=26 nodes"<<endl;
		cout<<"graph4=30 nodes"<<endl;
		cout<<"graph5=34 nodes"<<endl;
		cout<<"graph6=50 nodes"<<endl;


		cin>>optionChoosed;
		
		string selectedGraph;
		switch(optionChoosed){
			case '1':
				selectedGraph="graph1.txt";
				break;
			case '2':
				selectedGraph="graph2.txt";				
				break;
			case '3':
				selectedGraph="graph3.txt";				
				break;
			case '4':
				selectedGraph="graph4.txt";
				break;
			case '5':
				selectedGraph="graph5.txt";
				break;
			case '6':
				selectedGraph="graph6.txt";
				break;
			case '7':
			return 0;
			break;
			default:
			cout<<"try again"<<endl;

			
		}
		//String variable for reading line by lines
		string lineByLine;
		ifstream openFile(selectedGraph);
		//Vector for saving graph,we set the size of array graph as 51 hardcoded as problem have <=50 nodes
        vector<int> graph[51];
        int numberOfVertex;

        
		//logic to create graph from file
		if(openFile.is_open()){
			int i=0;
			while(getline(openFile,lineByLine)){
				//for ignoring comments
				if(lineByLine[0]=='%'){
					continue;
				}
				else{

					vector<int> edgeVector;
					size_t position = 0;
					string delimiter=" ";
					string numberAtPositionOne;
					string numberAtPositionTwo;
					string number;
					
					while ((position = lineByLine.find(delimiter)) != string::npos) {
					    number = lineByLine.substr(0, position);					    
					    numberAtPositionOne=number;
					    lineByLine.erase(0, position + delimiter.length());					    
					}

					if(i>0){					
						numberAtPositionTwo=lineByLine;
						graph[stoi(numberAtPositionOne)].push_back(stoi(lineByLine));
						graph[stoi(lineByLine)].push_back(stoi(numberAtPositionOne));
						

					}else{
						numberOfVertex=stoi(numberAtPositionOne);
					}
					

					

                 
				}
				i=i+1;
				}
			openFile.close();
			vector<int> request;
			int decision=checkConnected(graph,numberOfVertex);
			if(decision==1){
			generateRandom(graph,numberOfVertex);

			}
			else{
				cout<<"Graph is not connected"<<endl;
			}

			
		}
		else{
			cout<<"Cannot Open File"<<endl;
		}
	}
return 0;
	
}