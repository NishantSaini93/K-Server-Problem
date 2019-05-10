#include "WFASolution.hpp"
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include "Contains.hpp"
//This function compute the WFA result for the problem
int computeWFA(vector<vector<int>>  arrayD,vector<int> configuration,vector<int> request,int numberOfVertex){
	map<int,vector<int>> trackOfCombination;
	int index=0;
	map<string,int> calculateWfa;
	map<string,int> calculateWfa3;

	map<string,int> WFAMinimum;
	int vectorOne[4];
	int WFACost;
	for(int k=0;k<configuration.size();k++){
		vectorOne[k]=configuration[k];
	}
	//variable to track change in configuration during WFA
	int WFATrackingArray[4];
	for(int parse=0;parse<4;parse++){
			WFATrackingArray[parse]=vectorOne[parse];
		}


	
	//it create map for storing different configuration
	
	for(int node1=1;node1<=numberOfVertex-3;node1++){
		//cout<<node1<<endl;
		
		for(int node2=node1+1;node2<=numberOfVertex-2;node2++){
			for(int node3=node2+1;node3<=numberOfVertex-1;node3++){
				for(int node4=node3+1;node4<=numberOfVertex;node4++){
					vector<int> arrayOfNumberInCombinaton;
					arrayOfNumberInCombinaton.push_back(node1);
					arrayOfNumberInCombinaton.push_back(node2);
					arrayOfNumberInCombinaton.push_back(node3);
					arrayOfNumberInCombinaton.push_back(node4);
					trackOfCombination[index]=arrayOfNumberInCombinaton;
					string keyMap=to_string(node1)+to_string(node2)+to_string(node3)+to_string(node4);
					calculateWfa[keyMap]=0;
					index=index+1;
					
					

				}
				
			}
		}
		

	}

	map<string,int> calculateWfa2;
	//Loop to process requests
	for(int eachRequest=0;eachRequest<request.size()+1;eachRequest++){
		if(eachRequest==0){
			for(int i=0;i<trackOfCombination.size();i++){
				int currentVector[4];
				
				vector<int> vectorForCombination=trackOfCombination[i];

				//convert vector to array
				for(int k=0;k<vectorForCombination.size();k++){
					currentVector[k]=vectorForCombination[k];
				}
				

				//calculating values for phi
				int minimum=99999999;
				sort(currentVector,currentVector+4);
				do{  int temp1,temp2,temp3,temp4;
					temp1=arrayD[currentVector[0]-1][vectorOne[0]-1];
					temp2=arrayD[currentVector[1]-1][vectorOne[1]-1];
					temp3=arrayD[currentVector[2]-1][vectorOne[2]-1];
					temp4=arrayD[currentVector[3]-1][vectorOne[3]-1];
					int result=temp1+temp2+temp3+temp4;
					
					if(result<minimum){

						minimum=result;
					}

					
				}while(next_permutation(currentVector,currentVector+4));
				string keyMap=to_string(vectorForCombination[0])+to_string(vectorForCombination[1])+to_string(vectorForCombination[2])+to_string(vectorForCombination[3]);
				calculateWfa2[keyMap]=minimum+calculateWfa[keyMap];



				
				
				
				
			}
			

			
			
			calculateWfa3=calculateWfa; 
			calculateWfa= calculateWfa2;	
		}


		else{

			for(int i=0;i<trackOfCombination.size();i++){
				int currentVector[4];
				
				vector<int> vectorForCombination=trackOfCombination[i];
				
				
				for(int k=0;k<vectorForCombination.size();k++){
					
					currentVector[k]=vectorForCombination[k];
				}
				
				//Calling Contains function to check configuration contains the request already
				
				int decision=performContains(request[eachRequest-1],currentVector);
				

				if(decision==1){
					string keyMap=to_string(vectorForCombination[0])+to_string(vectorForCombination[1])+to_string(vectorForCombination[2])+to_string(vectorForCombination[3]);
					calculateWfa2[keyMap]=calculateWfa[keyMap];
				}else{
					
					
					
					int minimumOnLine=99999999;
					int distance;
					for(int ind=0;ind<4;ind++){
						if(ind==0){
							int temparr[]={request[eachRequest-1],vectorForCombination[1],vectorForCombination[2],vectorForCombination[3]};
							sort(temparr,temparr+4);
							string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
							distance=arrayD[request[eachRequest-1]-1][vectorForCombination[0]-1];
							int tempx=distance+calculateWfa[keyMap];

							
							if(tempx<minimumOnLine){
								minimumOnLine=tempx;
							//to get distance
								
							}
						}
						else if(ind==1){
							int temparr[]={request[eachRequest-1],vectorForCombination[0],vectorForCombination[2],vectorForCombination[3]};
							
							sort(temparr,temparr+4);
							string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
							distance=arrayD[request[eachRequest-1]-1][vectorForCombination[1]-1];
							int tempx=distance+calculateWfa[keyMap];
							
							if(tempx<minimumOnLine){
								minimumOnLine=tempx;
								
							}
						}
						else if(ind==2){
							int temparr[]={request[eachRequest-1],vectorForCombination[0],vectorForCombination[1],vectorForCombination[3]};
							
							sort(temparr,temparr+4);
							string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
							distance=arrayD[request[eachRequest-1]-1][vectorForCombination[2]-1];
							int tempx=distance+calculateWfa[keyMap];
							
							if(tempx<minimumOnLine){
								minimumOnLine=tempx;
								
							}
						}
						else{
							int temparr[]={request[eachRequest-1],vectorForCombination[0],vectorForCombination[2],vectorForCombination[1]};
							
							sort(temparr,temparr+4);
							string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
							distance=arrayD[request[eachRequest-1]-1][vectorForCombination[3]-1];
							int tempx=distance+calculateWfa[keyMap];
							
							if(tempx<minimumOnLine){
								minimumOnLine=tempx;
								
							}
						}
						
					}
					string keyMap=to_string(vectorForCombination[0])+to_string(vectorForCombination[1])+to_string(vectorForCombination[2])+to_string(vectorForCombination[3]);
					calculateWfa2[keyMap]=minimumOnLine;
					
				}
				


				
				


				
				
				
				
			}
			
			
			calculateWfa3=calculateWfa; 
			calculateWfa= calculateWfa2;	
		}

		//tracking WfA configurations
		
		int findMinimum=9999999;
		int WFAMinimum2[4];
		
		if(eachRequest==0){
			continue;
		}
		else{
			int decision2=performContains(request[eachRequest-1],WFATrackingArray);
			
			
			if(decision2==1){
				continue;
			}else{
				for(int ind=0;ind<4;ind++){
			if(ind==0){
				int temparr[]={request[eachRequest-1],WFATrackingArray[1],WFATrackingArray[2],WFATrackingArray[3]};
				sort(temparr,temparr+4);
				string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
				int local=calculateWfa3[keyMap]+arrayD[request[eachRequest-1]-1][WFATrackingArray[0]-1];
				
				if(local<findMinimum){
					WFAMinimum2[0]=temparr[0];
					WFAMinimum2[1]=temparr[1];
					WFAMinimum2[2]=temparr[2];
					WFAMinimum2[3]=temparr[3];
					findMinimum=local;
				}



			}
			else if(ind==1){
				int temparr[]={request[eachRequest-1],WFATrackingArray[0],WFATrackingArray[2],WFATrackingArray[3]};

				sort(temparr,temparr+4);
				string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
				int local=calculateWfa3[keyMap]+arrayD[request[eachRequest-1]-1][WFATrackingArray[1]-1];
				
				if(local<findMinimum){
					WFAMinimum2[0]=temparr[0];
					WFAMinimum2[1]=temparr[1];
					WFAMinimum2[2]=temparr[2];
					WFAMinimum2[3]=temparr[3];
					findMinimum=local;
				}


			}
			else if(ind==2){
				int temparr[]={request[eachRequest-1],WFATrackingArray[0],WFATrackingArray[1],WFATrackingArray[3]};

				sort(temparr,temparr+4);
				string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);
				int local=calculateWfa3[keyMap]+arrayD[request[eachRequest-1]-1][WFATrackingArray[2]-1];
				
				if(local<findMinimum){
					WFAMinimum2[0]=temparr[0];
					WFAMinimum2[1]=temparr[1];
					WFAMinimum2[2]=temparr[2];
					WFAMinimum2[3]=temparr[3];
					findMinimum=local;
				}
			}
			else{
				int temparr[]={request[eachRequest-1],WFATrackingArray[0],WFATrackingArray[2],WFATrackingArray[1]};

				sort(temparr,temparr+4);
				string keyMap=to_string(temparr[0])+to_string(temparr[1])+to_string(temparr[2])+to_string(temparr[3]);

				int local=calculateWfa3[keyMap]+arrayD[request[eachRequest-1]-1][WFATrackingArray[3]-1];
				
				if(local<findMinimum){
					WFAMinimum2[0]=temparr[0];
					WFAMinimum2[1]=temparr[1];
					WFAMinimum2[2]=temparr[2];
					WFAMinimum2[3]=temparr[3];
					findMinimum=local;
				}
			}
			WFACost=findMinimum;
			

		}	

			}
		
		}
		
		for(int parse=0;parse<4;parse++){
			WFATrackingArray[parse]=WFAMinimum2[parse];
		}


		
	}//end of request loop
	
	
	
	
    

	

	return WFACost;
}