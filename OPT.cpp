#include "OPT.hpp"
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include "Contains.hpp"
/**
*This is the function to compute Optimal solution cost
*@param arrayD Pairwise distance matrix
*@param configuration Current placement of server
*@param request It contains the series of request for servers
*@param numberOfVertex Number of node present in space
*@return Optimal cost after processing requests
*/
int computeOPT(vector<vector<int>>  arrayD, vector<int> configuration, vector<int> request, int numberOfVertex) {
	map<int, vector<int>> trackOfCombination;
	int index = 0;
	map<string, int> calculateWfa;
	//It create map for storing different configuration
	for (int node1 = 1; node1 <= numberOfVertex - 3; node1++) {
		for (int node2 = node1 + 1; node2 <= numberOfVertex - 2; node2++) {
			for (int node3 = node2 + 1; node3 <= numberOfVertex - 1; node3++) {
				for (int node4 = node3 + 1; node4 <= numberOfVertex; node4++) {
					vector<int> arrayOfNumberInCombinaton;
					arrayOfNumberInCombinaton.push_back(node1);
					arrayOfNumberInCombinaton.push_back(node2);
					arrayOfNumberInCombinaton.push_back(node3);
					arrayOfNumberInCombinaton.push_back(node4);
					trackOfCombination[index] = arrayOfNumberInCombinaton;
					string keyMap = to_string(node1) + to_string(node2) + to_string(node3) + to_string(node4);
					calculateWfa[keyMap] = 0;
					index = index + 1;
				}
			}
		}
	}
	map<string, int> calculateWfa2;
	for (int eachRequest = 0; eachRequest < request.size() + 1; eachRequest++) {
		//eachRequest==0 means for phi
		if (eachRequest == 0) {
			for (int i = 0; i < trackOfCombination.size(); i++) {
				int currentVector[4];
				vector<int> vectorForCombination = trackOfCombination[i];
				//convert vector to array
				for (int k = 0; k < vectorForCombination.size(); k++) {
					currentVector[k] = vectorForCombination[k];
				}
				int vectorOne[4];
				for (int k = 0; k < configuration.size(); k++) {
					vectorOne[k] = configuration[k];
				}
				//calculating values for phi
				int minimum = 99999999;
				sort(currentVector, currentVector + 4);
				do {
					int temp1, temp2, temp3, temp4;
					temp1 = arrayD[currentVector[0] - 1][vectorOne[0] - 1];
					temp2 = arrayD[currentVector[1] - 1][vectorOne[1] - 1];
					temp3 = arrayD[currentVector[2] - 1][vectorOne[2] - 1];
					temp4 = arrayD[currentVector[3] - 1][vectorOne[3] - 1];
					int result = temp1 + temp2 + temp3 + temp4;
					if (result < minimum) {
						minimum = result;
					}
				} while (next_permutation(currentVector, currentVector + 4));
				string keyMap = to_string(vectorForCombination[0]) + to_string(vectorForCombination[1]) + to_string(vectorForCombination[2]) + to_string(vectorForCombination[3]);
				calculateWfa2[keyMap] = minimum + calculateWfa[keyMap];
			}
			calculateWfa = calculateWfa2;
		}
		//When request arrives
		else {
			for (int i = 0; i < trackOfCombination.size(); i++) {
				int currentVector[4];
				vector<int> vectorForCombination = trackOfCombination[i];
				for (int k = 0; k < vectorForCombination.size(); k++) {
					currentVector[k] = vectorForCombination[k];
				}
				//Calling Contains function to check configuration contains the requested element already
				int decision = performContains(request[eachRequest - 1], currentVector);
				if (decision == 1) {
					string keyMap = to_string(vectorForCombination[0]) + to_string(vectorForCombination[1]) + to_string(vectorForCombination[2]) + to_string(vectorForCombination[3]);
					calculateWfa2[keyMap] = calculateWfa[keyMap];
				}
				else {
					int minimumOnLine = 99999999;
					int distance;
					for (int ind = 0; ind < 4; ind++) {
						if (ind == 0) {
							int temparr[] = { request[eachRequest - 1],vectorForCombination[1],vectorForCombination[2],vectorForCombination[3] };
							sort(temparr, temparr + 4);
							string keyMap = to_string(temparr[0]) + to_string(temparr[1]) + to_string(temparr[2]) + to_string(temparr[3]);
							distance = arrayD[request[eachRequest - 1] - 1][vectorForCombination[0] - 1];
							//here we are calculating new value
							int tempx = distance + calculateWfa[keyMap];
							if (tempx < minimumOnLine) {
								minimumOnLine = tempx;
							}
						}
						else if (ind == 1) {
							int temparr[] = { request[eachRequest - 1],vectorForCombination[0],vectorForCombination[2],vectorForCombination[3] };
							sort(temparr, temparr + 4);
							string keyMap = to_string(temparr[0]) + to_string(temparr[1]) + to_string(temparr[2]) + to_string(temparr[3]);
							distance = arrayD[request[eachRequest - 1] - 1][vectorForCombination[1] - 1];
							int tempx = distance + calculateWfa[keyMap];
							if (tempx < minimumOnLine) {
								minimumOnLine = tempx;
							}
						}
						else if (ind == 2) {
							int temparr[] = { request[eachRequest - 1],vectorForCombination[0],vectorForCombination[1],vectorForCombination[3] };
							sort(temparr, temparr + 4);
							string keyMap = to_string(temparr[0]) + to_string(temparr[1]) + to_string(temparr[2]) + to_string(temparr[3]);
							distance = arrayD[request[eachRequest - 1] - 1][vectorForCombination[2] - 1];
							int tempx = distance + calculateWfa[keyMap];
							if (tempx < minimumOnLine) {
								minimumOnLine = tempx;
							}
						}
						else {
							int temparr[] = { request[eachRequest - 1],vectorForCombination[0],vectorForCombination[2],vectorForCombination[1] };
							sort(temparr, temparr + 4);
							string keyMap = to_string(temparr[0]) + to_string(temparr[1]) + to_string(temparr[2]) + to_string(temparr[3]);
							distance = arrayD[request[eachRequest - 1] - 1][vectorForCombination[3] - 1];
							int tempx = distance + calculateWfa[keyMap];
							if (tempx < minimumOnLine) {
								minimumOnLine = tempx;
							}
						}
					}
					string keyMap = to_string(vectorForCombination[0]) + to_string(vectorForCombination[1]) + to_string(vectorForCombination[2]) + to_string(vectorForCombination[3]);
					calculateWfa2[keyMap] = minimumOnLine;
				}
			}
			calculateWfa = calculateWfa2;
		}
	}//end of request loop
	//Getting minimum from the last row of WFA value table(which would be optimal)
	int OPTCost = 99999999;
	for (int i = 0; i < trackOfCombination.size(); i++) {
		int currentVector[4];
		vector<int> vectorForCombination = trackOfCombination[i];
		//convert vector to array
		for (int k = 0; k < vectorForCombination.size(); k++) {
			currentVector[k] = vectorForCombination[k];
		}
		sort(currentVector, currentVector + 4);
		string val = to_string(currentVector[0]) + to_string(currentVector[1]) + to_string(currentVector[2]) + to_string(currentVector[3]);
		int newVal = calculateWfa[val];
		if (newVal < OPTCost) {
			OPTCost = newVal;
		}
	}
	return OPTCost;
}