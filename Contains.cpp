#include "Contains.hpp"
#include<iostream>
using namespace std;
int performContains(int currentRequest,int currentConfiguration[]){
    bool flag=false;
	for(int i=0;i<4;i++){
		
		if(currentConfiguration[i]==currentRequest){
			flag=true;
			//cout<<currentConfiguration[i]<<" "<<currentRequest<<endl;
		}
	}
	
	if(flag==true){
		return 1;
	}
	else{
		return 0;
	}
}