#ifndef _Weights_CPP_INCLUDED
#define _Weights_CPP_INCLUDED
#include<iostream>
#include<vector>
using namespace std;
/**
*This fuction will calculate shortest distance beween any two pairs of nodes.
*@param graph  of nodes
*@return 0 on completion
*/
int computeDistancesFromFile(vector<int> graph[],vector<int> configuration,vector<int> request,int numberOfVertex);
#endif