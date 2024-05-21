#include<bits/stdc++.h>
#include"ListOfAnimal.h"
using namespace std ;
ListOfAnimal::ListOfAnimal(){}

void ListOfAnimal::mainMenu(){
	int choice ;
	bool flag = true;
	do {
		cout<<"---List Of Fuction---"<<endl;
		cout<<"1.Them moi Animal"<<endl;//1
		cout<<"2.Danh sach Animal"<<endl; //2
		cout<<"3.Chinh sua thong tin Animal"<<endl; //7
		cout<<"4.Xoa thong tin Animnal"<<endl;//4
		cout<<"5.Sap xep Animal theo nam sinh"<<endl;//12
		cout<<"6.Danh gia tinh cach Animal"<<endl;//6
		cout<<"7.Tim kiem dong vat theo ID"<<endl;//10
		cout<<"8.Tim kiem dong vat theo chung loai"<<endl;//11 ngoc lam chuc nang nay
		cout<<"9.Tinh toan chi so can nang Animal"<<endl; //13
		cout<<"10.Danh gia muc do nguy hiem Animal"<<endl;//15
		cout<<"11.Xac dinh kich thuoc Animal"<<endl;//16
		cout<<"12.Tinh tong so dong vat 4 chan"<<endl; //17
		cout<<"13.Tinh tong so dong vat biet bay"<<endl; //18
		cout<<"14.Xuat file Animal"<<endl;//21
		cout<<"15.Kiem tra muc do ve sinh Animal"<<endl;//22
		cout<<"16.Danh gia muc do tuyet chung Animal"<<endl;//23
		cout<<"17.Theo doi chu ky sinh san Animal"<<endl; //24
		cout<<"18.Xac dinh moi truong song Animal"<<endl;//25
		cout<<"19.Tim kiem quoc tich cua dong vat"<<endl;//9
		cout<<"26.Exit the program."<<endl;
		cout<<"Choose your option: "; cin>>choice;
		switch(choice) {
			case 1:{
				inputAnimal();
				break;
			}
			case 2:{
				outputAnimal();
				break;
			}
			case 3:{
				break;
			}
			case 8:{
                searchAnimalBySpecies();
				break;}
			case 14:{
                exportToFile();
				break;}
            case 19:{
                searchAnimalByNationality();
				break;}
			case 26:{
				flag = false ;
				cout<<"Exiting the program..."<<endl;
			}
		}
	}while(flag);
}

void ListOfAnimal::addNewAnimal(Animal* animal){
	animals.push_back(animal);
}

void ListOfAnimal::inputAnimal(){
	int count ;
	cout<<"Nhap so luong Animal:"; cin>>count;
	for(int i=0 ;i<count;i++){
		cout<<"---Danh sach Animal---"<<endl;
		cout<<"1.Them moi Cat"<<endl;
		cout<<"2.Them moi Dog"<<endl;
		cout<<"3.Them moi Bird"<<endl;
		cout<<"4.Return main menu."<<endl;
		cout<<"Choose option:"; int choice; cin>>choice;
		switch(choice){
			case 1: {
				Cat* cat = new Cat();
				cat->input();
				addNewAnimal(cat);
				break;
			}
			case 2: {
				Dog* dog = new Dog();
				dog->input();
				addNewAnimal(dog);
				break;
			}
			case 3:{
				Bird* bird = new Bird();
				bird->input();
				addNewAnimal(bird);
				break;
			}

			case 4:{
				mainMenu();
				break;
			}
			default:{
				cout<<"Does not exist!"<<endl;
				mainMenu();
				break;
			}
		}
	}
	mainMenu();
}
void ListOfAnimal::outputAnimal(){
	cout<<"---Danh sach Animal---"<<endl;
	for(Animal* animal:animals){
		if(Dog* dog = dynamic_cast<Dog*>(animal)){
			dog->output();
		}else if (Cat* cat = dynamic_cast<Cat*>(animal)){
			cat->output();
		}else if(Bird* bird = dynamic_cast<Bird*>(animal)){
			bird->output();
		}
	}
}
void ListOfAnimal::searchAnimalByBirthYear(){
	vector<Animal*> birthYearAnimals ;
	int searchBirthYear ;
	cout<<"Enter search birthYear"; cin>>searchBirthYear ;
	for(Animal* animal:animals){
		if(animal->getBirthYear() == searchBirthYear){
			birthYearAnimals.push_back(animal);
		}
	}
	for(Animal* animal:birthYearAnimals){
		if(Dog* dog = dynamic_cast<Dog*>(animal)){
			dog->output();
		}else if (Cat* cat = dynamic_cast<Cat*>(animal)){
			cat->output();
		}else if(Bird* bird = dynamic_cast<Bird*>(animal)){
			bird->output();
		}
	}
}
Animal* ListOfAnimal::findById(){
	string findId;
	cout<<"Enter find ID:"; getline(cin,findId);
	for(Animal* animal:animals){
		if(animal->getId() == findId){
			return animal;
		}
	}
	return nullptr;
}
void ListOfAnimal::assessLevelOfExtinction(){
	Animal* animal = findById();
	animal->output();
	if(animal->getRarityLevel()==1){
		cout<<"-Endangered-"<<endl;
	}else if (animal->getRarityLevel()==2){
		cout<<"-Extinct in the wild-"<<endl;
	}else if(animal->getRarityLevel()==3){
		cout<<"-Extinct-"<<endl;
	}
}
void ListOfAnimal::assessLevelOfThreat(){
	Animal* animal = findById();
	animal->output();
	if(animal->getThreatLevel()==1){
		cout<<"-No threat-"<<endl;
	}else if(animal->getThreatLevel()==2){
		cout<<"-Slight threat-"<<endl;
	}else if(animal->getThreatLevel()==3){
		cout<<"-Very Threatening-"<<endl;
	}
}
void ListOfAnimal::identifyHabitat(){
	Animal* animal = findById();
	animal->output();
	if (animal->getHabitat()=="can"){
		cout<<"-Animal lives on land-"<<endl;
	}else if (animal->getHabitat()=="nuoc"){
		cout<<"-Animal lives underwater-"<<endl;
	}else if (animal->getHabitat()=="troi"){
		cout<<"-Animal lives in the sky-"<<endl;
	}
}
void ListOfAnimal::caculateBMI(){
	Animal* animal = findById();
	animal->output();
	float weight = animal->getWeight();
	float height = animal->getHeight();
	float BMI = weight / pow(height,3);

	if (BMI < 3) {
        cout << "Underweight" << endl;
    } else if (BMI >= 3 && BMI <= 5) {
        cout << "Normal weight" << endl;
    } else if (BMI > 5 && BMI <= 7) {
        cout << "Overweight" << endl;
    } else {
        cout << "Obese" << endl;
    }
}
void ListOfAnimal::searchAnimalBySpecies() {
    string searchSpecies;
    cout << "Enter species to search: ";
    cin.ignore();
    getline(cin, searchSpecies);

    vector<Animal*> speciesAnimals;
    for (Animal* animal : animals) {
        if (animal->getSpecies() == searchSpecies) {
            speciesAnimals.push_back(animal);
        }
    }

    if (speciesAnimals.empty()) {
        cout << "No animals found for the species: " << searchSpecies << endl;
    } else {
        cout << "--- Animals of species " << searchSpecies << " ---" << endl;
        for (Animal* animal : speciesAnimals) {
            if (Dog* dog = dynamic_cast<Dog*>(animal)) {
                dog->output();
            } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
                cat->output();
            } else if (Bird* bird = dynamic_cast<Bird*>(animal)) {
                bird->output();
            }
        }
    }
}
//ngoc lam chuc nang 11
void ListOfAnimal::exportToFile() {
    ofstream outFile("animals.txt");
    if (!outFile) {
        cout << "Error opening file for writing!" << endl;
        return;
    }
    for (Animal* animal : animals) {
        outFile << "ID: " << animal->getId() << endl;
        outFile << "Species: " << animal->getSpecies() << endl;
        outFile << "Age: " << animal->getAge() << endl;
        outFile << "Birth Year: " << animal->getBirthYear() << endl;
        outFile << "Habitat: " << animal->getHabitat() << endl;
        outFile << "Hobbies: " << animal->getHobbies() << endl;
        outFile << "Sound: " << animal->getSound() << endl;
        outFile << "Threat Level: " << animal->getThreatLevel() << endl;
        outFile << "Population: " << animal->getPopulation() << endl;
        outFile << "Reproduction Rate: " << animal->getReproductionRate() << endl;
        outFile << "Gender: " << (animal->getGender() ? "Male" : "Female") << endl;
        outFile << "Death Year: " << animal->getDeathYear() << endl;
        outFile << "Food Type: " << animal->getFoodType() << endl;
        outFile << "Color: " << animal->getColor() << endl;
        outFile << "Vaccine Reaction: " << (animal->getVaccineReaction() ? "Yes" : "No") << endl;
        outFile << "Reproductive Characteristic: " << animal->getReproductiveCharacteristic() << endl;
        outFile << "Nationality: " << animal->getNationality() << endl;
        outFile << "Fur Type: " << animal->getFurType() << endl;
        outFile << "Body Structure: " << animal->getBodyStructure() << endl;
        outFile << "Weight: " << animal->getWeight() << endl;
        outFile << "Height: " << animal->getHeight() << endl;
        outFile << "Health Status: " << animal->getHealthStatus() << endl;
        outFile << "Feeding Frequency: " << animal->getFeedingFrequency() << endl;
        outFile << "Diseases: " << animal->getDiseases() << endl;
        outFile << "Personality: " << animal->getPersonality() << endl;
        outFile << "Reproductive Health: " << animal->getReproductiveHealth() << endl;
        outFile << "Rarity Level: " << animal->getRarityLevel() << endl;
        outFile << "Mood Status: " << animal->getMoodStatus() << endl;
        outFile << "Body Temperature: " << animal->getBodyTemperature() << endl;
        outFile << endl;
    }
    outFile.close();
    cout << "Animal data has been exported to animals.txt" << endl;

}//ngoc lam chuc nang 21
void ListOfAnimal::searchAnimalByNationality() {
    string searchNationality;
    cout << "Enter nationality to search: ";
    cin.ignore();
    getline(cin, searchNationality);

    vector<Animal*> nationalityAnimals;
    for (Animal* animal : animals) {
        if (animal->getNationality() == searchNationality) {
            nationalityAnimals.push_back(animal);
        }
    }

    if (nationalityAnimals.empty()) {
        cout << "No animals found for the nationality: " << searchNationality << endl;
    } else {
        cout << "--- Animals of nationality " << searchNationality << " ---" << endl;
        for (Animal* animal : nationalityAnimals) {
            if (Dog* dog = dynamic_cast<Dog*>(animal)) {
                dog->output();
            } else if (Cat* cat = dynamic_cast<Cat*>(animal)) {
                cat->output();
            } else if (Bird* bird = dynamic_cast<Bird*>(animal)) {
                bird->output();
            }
        }
    }
}//ngoc lam chuc nang 9
