#include "Contains.hpp"
#include<iostream>
using namespace std;
/**
*This function checks if current position of servers covers the current request
*@return int 1 if contains otherwise 0
*/
int performContains(int currentRequest, int currentConfiguration[]) {
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		if (currentConfiguration[i] == currentRequest) {
			flag = true;
		}
	}
	if (flag == true) {
		return 1;
	}
	else {
		return 0;
	}
}