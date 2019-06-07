#ifndef _OPT_CPP_INCLUDED
#define _OPT_CPP_INCLUDED
#include<vector>
#include<iostream>
using namespace std;
/**
*This is the function to compute Optimal solution cost
*@param arrayD Pairwise distance matrix
*@param configuration Current placement of server
*@param request It contains the series of request for servers
*@param numberOfVertex Number of node present in space
*@return Optimal cost after processing requests
*/
int computeOPT(vector<vector<int>>  arrayD,vector<int> configuration,vector<int> request,int numberOfVertex);
#endif