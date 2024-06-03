#include "functions.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <regex>

bool loadDataFromFile(std::list<Person>& people, const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << '\n';
        return false;
    }

    std::string line;
    while (std::getline(file, line)) {
        try { 
            std::istringstream iss(line);
            Person person;
            std::string age;
	        std::getline(iss, person.name, ';');			
            std::getline(iss, age, ';');
	    	std::getline(iss, person.status, ';');
            if (!person.name.empty() && validAge(age) && !person.status.empty()) {
                person.age = std::stoi(age);
                people.push_back(person);
            }else if (line.empty()) return true;
            else return false;
	    }
	    catch (const std::exception& e) {
		    std::cerr << "Данные неверные в файле" << std::endl;
		    return false;
	    }
        }

    file.close();
	return true;
}
bool validAge(std::string age) {
	std::regex valid_age("[1-9][0-9]?[0-9]?|0");
	return regex_match(age, valid_age);
}
void printList(const std::list<Person>& people) {
    for (const auto& person : people) {
        std::cout << "Name: " << person.name << ", Age: " << person.age << ", Status: " << person.status << std::endl;
    }
}


bool saveToFile(const std::list<Person>& people, const std::string& filename) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file: " << filename << std::endl;
        return false;
    }
    for (const auto& person : people) {
        file << person.name << ";" << person.age << ";" << person.status << std::endl;
    }
    
    file.close();
    return true;
}

std::list<Person>::iterator findElementByName(std::list<Person>& people, const std::string& name) {
    return std::find_if(people.begin(), people.end(), [&name](const Person& person) {
        return person.name == name;
    });
}

void resetAllElements(std::list<Person>& people) {
    for (auto& person : people) {
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

void sortByParam(std::list<Person>& people, int param){

    switch (param)    {
    case 1:
        people.sort([](const Person& a, const Person& b) {
		    return a.name < b.name;
	    });
        break;
    case 2:
        people.sort([](const Person& a, const Person& b) {
		    return a.name > b.name;
	    });
        break;
    case 3:
        people.sort([](const Person& a, const Person& b) {
		    return a.age < b.age;
	    });
        break;
    case 4:
        people.sort([](const Person& a, const Person& b) {
		    return a.age > b.age;
	    });
        break;    
    case 5:
        people.sort([](const Person& a, const Person& b) {
		    return a.status < b.status;
	    });
        break;
    case 6:
        people.sort([](const Person& a, const Person& b) {
		    return a.status > b.status;
	    });
        break;   	
    }
}