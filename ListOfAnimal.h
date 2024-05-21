#ifndef LISTOFANIMAL_H
#define LISTOFANIMAL_H
#include<bits/stdc++.h>
#include"Animal.h"
#include"Cat.h"
#include"Bird.h"
#include"Dog.h"
using namespace std ;
class ListOfAnimal {
	private:
		vector<Animal*> animals ;
	public:
		ListOfAnimal();
		void mainMenu();
		void addNewAnimal(Animal* animal);
		void inputAnimal();
		void outputAnimal();
		void searchAnimalByBirthYear();
		void assessLevelOfExtinction();
		Animal* findById();
		void assessLevelOfThreat();
		void identifyHabitat();
		void caculateBMI();
		void searchAnimalBySpecies();// Ngoc lam chuc nang 11
		void exportToFile(); //ngoc lam chuc nang 21
		void searchAnimalByNationality(); //ngoc lam chuc nang so 9
		//~ListOfAnimal();
};
#endif
