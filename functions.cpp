#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>

bool loadDataFromFile(std::list<Person>& lst, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << '\n';
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Person person;
	    std::getline(iss, person.name, ';');			
        iss >> person.age;
        iss.ignore(1, ';');
		std::getline(iss, person.status, ';');
        lst.push_back(person);
    }

    file.close();
	return true;
}

void printList(const std::list<Person>& lst) {
    for (const auto& person : lst) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << ", Status: " << person.status << std::endl;
    }
}


bool saveToFile(const std::list<Person>& lst, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return false;
    }
    for (const auto& person : lst) {
        file << person.name << "; " << person.age << "; " << person.status << std::endl;
    }
    
    file.close();
    return true;
}

std::list<Person>::iterator findElementByName(std::list<Person>& lst, const std::string& name) {
    return std::find_if(lst.begin(), lst.end(), [&name](const Person& person) {
        return person.name == name;
    });
}

void resetAllElements(std::list<Person>& lst) {
    for (auto& person : lst) {
        person.name = constants::DEFAULT_NAME;
        person.age = constants::DEFAULT_AGE;
        person.status = constants::DEFAULT_STATUS;
    }
}

void printFunctionsList() {
	std::cout << "1)Find an element with the specified field value\n2)Printing all items in sorted form" << std::endl;
	std::cout << "3)Assigning preset values to all elements" << std::endl;
	std::cout << "4)Exit" << std::endl;
}

void sortByParam(std::list<Person>& lst, int param){

    switch (param)    {
    case 1:
        lst.sort([](const Person& a, const Person& b) {
		    return a.name < b.name;
	    });
        break;
    case 2:
        lst.sort([](const Person& a, const Person& b) {
		    return a.name > b.name;
	    });
        break;
    case 3:
        lst.sort([](const Person& a, const Person& b) {
		    return a.age < b.age;
	    });
        break;
    case 4:
        lst.sort([](const Person& a, const Person& b) {
		    return a.age > b.age;
	    });
        break;    
    case 5:
        lst.sort([](const Person& a, const Person& b) {
		    return a.status < b.status;
	    });
        break;
    case 6:
        lst.sort([](const Person& a, const Person& b) {
		    return a.status > b.status;
	    });
        break;   	
    }
}