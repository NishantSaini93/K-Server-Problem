#ifndef _WFASolution_CPP_INCLUDED
#define _WFASolution_CPP_INCLUDED
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
/**
*This function compute the WFA result for the problem
*@param arrayD Pairwise distance matrix
*@param configuration Current placement of server
*@param request It contains the series of request for servers
*@param numberOfVertex Number of node present in space
*@return WFACost Work function cost after processing requests
*/
int computeWFA(vector<vector<int>>  arrayD,vector<int> configuration,vector<int> request,int numberOfVertex);
#endif