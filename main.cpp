#include <iostream>
#include "functions.h"
#include <Windows.h>
#include <regex>

using namespace std;

int main(int argc, char* argv[]) {
   	list<Person> people;
		string fileName = constants::DEFAULT_FILE;
    if(argc == 2) fileName = argv[1];
		else if(argc > 2){
			cerr<<"Error: There are too many arguments"<<endl;
			return 1;
		}

    if(!loadDataFromFile(people,fileName)){
			cerr << "Error when reading data" << endl;
			return 1;
		};

		cout << "The data has been uploaded" << endl;
		string input;
		regex valid_input("[1-4]");
		regex valid_param("[0-6]");
		do {
			do {
				printFunctionsList();
				getline(cin, input);
			} while (!regex_match(input, valid_input));
			cout << endl;
			if (input == "1") {
				string name;
				cout << "Enter full name: ";
				getline(cin, name);
 				std::cout << "Searching for first element with name '" << name << "'"<<endl;
    		auto it = findElementByName(people, name); 
				if (it != people.end()) {
        	cout << "Found: Name: " << it->name << ", Age: " << it->age << ", Status: " << it->status << endl;
    		} else cout << "Element not found" << endl;
			}
			else if (input == "2") {
				string param;
				do {
					
					cout<<"Select the sorting mode:\n0 - Exit the menu\n1 - By name (Ascending)\n2 - By name (Descending)\n3 - By age (Ascending)\n4 - By age (Descending)\n5 - By status (Ascending)\n6 - By status (Descending)"<<endl;;
					getline(cin, param);
				} while (!regex_match(param, valid_param));
				sortByParam(people,std::stoi(param));
				if(!saveToFile(people,fileName)) cerr<<"Error when saving"<<endl;
				printList(people);
			}
			else if (input == "3") {
				resetAllElements(people);
				if(!saveToFile(people,fileName)) cerr<<"Error when saving"<<endl;			
			}
			
	} while (input != "4");
  if(!saveToFile(people,fileName)) cerr<<"Error when saving"<<endl;
	cout << "Goodbye!" << endl;
  return 0;
}