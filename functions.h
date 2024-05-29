#pragma once
#include <list>
#include <string>
#include "constants.h"

struct Person {
    std::string name;
    int age;
    std::string status;
};

void printList(const std::list<Person>& lst);
void printFunctionsList();

bool loadDataFromFile(std::list<Person>& lst, const std::string& filename);
bool saveToFile(const std::list<Person>& lst, const std::string& filename);

std::list<Person>::iterator findElementByName(std::list<Person>& lst, const std::string& name);

void resetAllElements(std::list<Person>& lst);

void sortByParam(std::list<Person>& lst, int param);


