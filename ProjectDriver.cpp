#include "PartTwo.hpp"
#include "PartOne.hpp"
#include <iostream>
/**
*This function contain logic for displaying first screen
*/
int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	bool flagForExit{ true };
	while(flagForExit){
		char choosedOption;
		cout<<endl;
		cout<<endl<<"Evaluate part 1"<<endl;
		cout<<"Evaluate part 2"<<endl;
		cout<<"Enter 1 for evaluating part one and 2 to evalute part two or press 3 for exit"<<endl;
		cin>>choosedOption;
		switch(choosedOption){
			case '1':			
            performPartOne();
			break;
			case '2':
			performPartTwo();
			break;
			case '3':
			cout<<"exit";
			flagForExit=0;
			break;
		}
	}
}


