#pragma once
#include <list>
#include <string>
#include "constants.h"

struct Person {
    std::string name;
    int age;
    std::string status;
};
bool validAge(std::string age);
void printList(const std::list<Person>& people);
void printFunctionsList();

bool loadDataFromFile(std::list<Person>& people, const std::string& filename);
bool saveToFile(const std::list<Person>& people, const std::string& filename);

std::list<Person>::iterator findElementByName(std::list<Person>& people, const std::string& name);

void resetAllElements(std::list<Person>& people);

void sortByParam(std::list<Person>& people, int param);


