#include <stdlib.h>
#include <iostream>
#include <list>

using namespace std;

enum AnimalType {DOG, CAT};


class AnimalShelter{
public:
	AnimalShelter();
	~AnimalShelter();
	void enqueue(AnimalType anAnimal);
	void dequeueAny();
	void dequeueCat();
	void dequeueDog();
	void printShelter();
protected:
	list<AnimalType> shelter;
};

AnimalShelter::AnimalShelter() {
	shelter = list<AnimalType>();
}

AnimalShelter::~AnimalShelter() {
	shelter.clear();
}

void AnimalShelter::enqueue(AnimalType anAnimal) {
	shelter.push_back(anAnimal);
}

void AnimalShelter::dequeueAny() {
	if (shelter.empty())
		return;

	// not empty
	shelter.pop_front();
}


void AnimalShelter::dequeueCat() {
	
	// find first cat then dequeue
	auto it = shelter.begin();
	while(*it != AnimalType::CAT) {
		it++;
	}

	// here it is CAT or no CAT
	if (it == shelter.end())
		return;
	else {
		shelter.erase(it);
	}
}


void AnimalShelter::dequeueDog() {
	
	// find first cat then dequeue
	auto it = shelter.begin();
	while(*it != AnimalType::DOG) {
		it++;
	}

	// here it is CAT or no CAT
	if (it == shelter.end())
		return;
	else {
		shelter.erase(it);
	}
}


void AnimalShelter::printShelter() {
	for (auto it = shelter.begin(); it != shelter.end(); it++) {
		if (*it == AnimalType::DOG)
			cout << "dog" << " ";
		else if (*it == AnimalType::CAT)
			cout << "cat" << " ";
	}
	cout << endl;
}

void main() {
	AnimalShelter animalShelter = AnimalShelter();
	animalShelter.enqueue(AnimalType::DOG);
	animalShelter.enqueue(AnimalType::CAT);
	animalShelter.enqueue(AnimalType::CAT);
	animalShelter.enqueue(AnimalType::DOG);
	animalShelter.enqueue(AnimalType::CAT);
	
	animalShelter.printShelter();
	
	//animalShelter.dequeueAny();
	animalShelter.dequeueCat();
	animalShelter.dequeueDog();
	animalShelter.dequeueDog();
	animalShelter.printShelter();
}

