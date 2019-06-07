#include "RandomGenerations.hpp"
#include "Weights.hpp"
#include<iostream>
#include<vector>
/**
*This function is responsible for generating different type of requests
*@param vector Graph of nodes
*@param numberOfVertex Number of nodes in graph
*@return 0 on completion
*/
int generateRandom(vector<int> graph[], int numberOfVertex) {
	int numberOfRequest;
	vector<int> *request=new vector<int>;
	cout << "Enter number of requests you want to generate randomly in between 20 to 1000:";
	cin >> numberOfRequest;
	char chooseOption;
	cout << "Choose how you want to generate request" << endl;
	cout << "Enter 1 for generating random request" << endl;
	cout << "Enter 2 for generating random request between two halfs of total nodes" << endl;
	cout << "Enter 3 for generating random request which are divisible by 2" << endl;
	cout << "Enter 4 for sequence of number after generating a random number" << endl;
	cout << "Enter 5 for requesting two starting nodes and then two end nodes again and again" << endl;
	cout << "Enter 6 for requesting three starting nodes and then three end nodes again and again" << endl;

	cin >> chooseOption;
	//this is for generation for request
	if (chooseOption == '1') {
		for (int i = 0; i =! numberOfRequest; i++) {
			random_device generateInteger;
			default_random_engine generator(generateInteger());
			uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
			int number = integetGenerator(generator);
			request->push_back(number);
		}
	}
	else if (chooseOption == '2') {
		int halfPart = int(numberOfVertex / 2);
		int i = 0;
		while (request->size() < numberOfRequest) {
			if (i % 2 == 0) {
				random_device generateInteger;
				default_random_engine generator(generateInteger());
				uniform_int_distribution<int> integetGenerator(1, halfPart - 1);
				int number = integetGenerator(generator);
				request->push_back(number);
				i++;
			}
			else {
				random_device generateInteger;
				default_random_engine generator(generateInteger());
				uniform_int_distribution<int> integetGenerator(halfPart + 1, numberOfVertex - 1);
				int number = integetGenerator(generator);
				request->push_back(number);
				i++;
			}
		}
	}
	else if (chooseOption == '3') {
		while (request->size() < numberOfRequest) {
			random_device generateInteger;
			default_random_engine generator(generateInteger());
			uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
			int number = integetGenerator(generator);
			if (number % 2 == 0) {
				request->push_back(number);
			}
		}
	}
	else if (chooseOption == '4') {
		random_device generateInteger;
		default_random_engine generator(generateInteger());
		uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
		int number = integetGenerator(generator);
		while (request->size() < numberOfRequest) {
			if (number == numberOfVertex) {
				random_device generateInteger;
				default_random_engine generator(generateInteger());
				uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
				number = integetGenerator(generator);
			}
			else {
				number = number + 2;
				if (number <= numberOfVertex) {
					request->push_back(number);
				}
				else {
					random_device generateInteger;
					default_random_engine generator(generateInteger());
					uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
					number = integetGenerator(generator);

				}
			}
		}
	}
	else if (chooseOption == '5') {
		while (request->size() < numberOfRequest) {
			request->push_back(1);
			if (request->size() < numberOfRequest) {
				request->push_back(2);
				if (request->size() < numberOfRequest) {
					request->push_back(numberOfVertex);
					if (request->size() < numberOfVertex) {
						request->push_back(numberOfVertex - 1);
					}
				}
			}
		}
	}
	else if (chooseOption == '6') {
		while (request->size() < numberOfRequest) {
			request->push_back(1);
			if (request->size() < numberOfRequest) {
				request->push_back(2);
				if (request->size() < numberOfRequest) {
					request->push_back(3);
					if (request->size() < numberOfVertex) {
						request->push_back(numberOfVertex);
						if (request->size() < numberOfVertex) {
							request->push_back(numberOfVertex - 1);
							if (request->size() < numberOfVertex) {
								request->push_back(numberOfVertex - 2);
							}
						}
					}
				}
			}
		}
	}

	else {
		cout << "try again";
		return 0;
	}
	//this is for generating initial configurations
	char selectConfig;
	cout << "select type of initial configuration:" << endl;
	cout << "1 for random generation" << endl;
	cout << "2 for manually entering" << endl;
	cin >> selectConfig;
	vector<int> configuration;
	set<int> confirmConfiguration{};
	if (selectConfig == '1') {

		while (configuration.size() < 4) {
			random_device generateInteger;
			default_random_engine generator(generateInteger());
			uniform_int_distribution<int> integetGenerator(1, numberOfVertex - 1);
			int number = integetGenerator(generator);
			if (confirmConfiguration.count(number) == 0) {
				configuration.push_back(number);
				confirmConfiguration.insert(number);
			}
		}
	}//This is for manual setting of server
	else if (selectConfig == '2') {
		while (configuration.size() < 4) {
			cout << "Enter configuration (server should be at different location)" << endl;
			int one;
			int two;
			int three;
			int four;
			cout << "Enter the first server location:" << endl;
			cin >> one;
			cout << "Enter the second server location:" << endl;
			cin >> two;
			cout << "Enter the third server location:" << endl;
			cin >> three;
			cout << "Enter the fourth server location:" << endl;
			cin >> four;
			if (one != two && two != three && three != four) {
				configuration.push_back(one);
				configuration.push_back(two);
				configuration.push_back(three);
				configuration.push_back(four);
			}
			else {
				cout << "try again put different locations for servers" << endl;
			}
		}
	}
	else {
		cout << "try again" << endl;
		return 0;
	}
	//This call to calculate pairwise distance
	computeDistancesFromFile(graph, configuration, *request, numberOfVertex);
	delete request;
	return 0;
}