#include "GreedySolution.hpp"
#include "Contains.hpp"
//this file include greedy solution
int computeGreedy(vector<vector<int>>  arrayD,vector<int> configuration,vector<int> request,int numberOfVertex){

	
	int cost=0;
	int currentArray[4];
	for(int i=0;i<4;i++){
		currentArray[i]=configuration[i];
	}
	for(int eachRequest=0;eachRequest<request.size();eachRequest++){
		int minimumOnLine=99999999;
		int distance;
		int decision=performContains(request[eachRequest],currentArray);

		if(decision==1){
			continue;
		}else{
			for(int ind=0;ind<4;ind++){
				if(ind==0){
					int temparr[]={request[eachRequest],currentArray[1],currentArray[2],currentArray[3]};
					
					
					distance=arrayD[request[eachRequest]-1][currentArray[0]-1];
					int tempx=distance;



					if(tempx<minimumOnLine){
						minimumOnLine=tempx;
						//updating current configuration
						currentArray[0]=temparr[0];
						currentArray[1]=temparr[1];
						currentArray[2]=temparr[2];
						currentArray[3]=temparr[3];
						

					}
				}
				else if(ind==1){
					int temparr[]={request[eachRequest],currentArray[0],currentArray[2],currentArray[3]};

					
					
					distance=arrayD[request[eachRequest]-1][currentArray[1]-1];
					int tempx=distance;

					if(tempx<minimumOnLine){
						minimumOnLine=tempx;
						//updating current configuration
						currentArray[0]=temparr[0];
						currentArray[1]=temparr[1];
						currentArray[2]=temparr[2];
						currentArray[3]=temparr[3];

					}
				}
				else if(ind==2){
					int temparr[]={request[eachRequest],currentArray[0],currentArray[1],currentArray[3]};

					
					distance=arrayD[request[eachRequest]-1][currentArray[2]-1];
					int tempx=distance;

					if(tempx<minimumOnLine){
						minimumOnLine=tempx;
						//updating current configuration
						currentArray[0]=temparr[0];
						currentArray[1]=temparr[1];
						currentArray[2]=temparr[2];
						currentArray[3]=temparr[3];

					}
				}
				else{
					int temparr[]={request[eachRequest],currentArray[0],currentArray[2],currentArray[1]};

					
					
					distance=arrayD[request[eachRequest]-1][currentArray[3]-1];
					int tempx=distance;

					if(tempx<minimumOnLine){
						minimumOnLine=tempx;
						//updating current configuration
						currentArray[0]=temparr[0];
						currentArray[1]=temparr[1];
						currentArray[2]=temparr[2];
						currentArray[3]=temparr[3];

					}
				}

			}
			
			cost=cost+minimumOnLine;
		}


	}
	
	
	return cost;

}