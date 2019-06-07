#ifndef _GreedySolution_CPP_INCLUDED
#define _GreedySolution_CPP_INCLUDED
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
/**
*This function takes care of operation to produce greedy solution
*@param arrayD Pairwise distance matrix
*@param configuration Current placement of server
*@param request It contains the series of request for servers
*@param numberOfVertex Number of node present in space
*@return cost of greedy solution
*/
int computeGreedy(vector<vector<int>>  arrayD,vector<int> configuration,vector<int> request,int numberOfVertex);
#endif