#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>

class Animal {
protected:
    std::string name;
    int age;
    std::string species;

public:
    Animal(std::string n, int a, std::string s) : name(n), age(a), species(s) {}
    virtual void display() const {
        std::cout << "Name: " << name << ", Age: " << age << ", Species: " << species << std::endl;
    }
    virtual ~Animal() {}
};

class Hyena : public Animal {
public:
    Hyena(std::string n, int a) : Animal(n, a, "Hyena") {}
    void display() const override {
        std::cout << "Hyena - Name: " << name << ", Age: " << age << std::endl;
    }
};

class Lion : public Animal {
public:
    Lion(std::string n, int a) : Animal(n, a, "Lion") {}
    void display() const override {
        std::cout << "Lion - Name: " << name << ", Age: " << age << std::endl;
    }
};

class Tiger : public Animal {
public:
    Tiger(std::string n, int a) : Animal(n, a, "Tiger") {}
    void display() const override {
        std::cout << "Tiger - Name: " << name << ", Age: " << age << std::endl;
    }
};

class Bear : public Animal {
public:
    Bear(std::string n, int a) : Animal(n, a, "Bear") {}
    void display() const override {
        std::cout << "Bear - Name: " << name << ", Age: " << age << std::endl;
    }
};

std::vector<Animal*> animals;
std::map<std::string, int> speciesCount;

void readFromFile(const std::string& filename) {
    std::ifstream infile(filename);
    std::string name, species;
    int age;

    while (infile >> name >> age >> species) {
        Animal* animal = nullptr;
        
        if (species == "Hyena") {
            animal = new Hyena(name, age);
        } else if (species == "Lion") {
            animal = new Lion(name, age);
        } else if (species == "Tiger") {
            animal = new Tiger(name, age);
        } else if (species == "Bear") {
            animal = new Bear(name, age);
        }

        if (animal) {
            animals.push_back(animal);
            speciesCount[species]++;
        }
    }
    infile.close();
}

void writeToFile(const std::string& filename) {
    std::ofstream outfile(filename);

    for (const auto& entry : speciesCount) {
        outfile << "Species: " << entry.first << " - Total: " << entry.second << std::endl;
    }

    for (const auto& animal : animals) {
        animal->display();
    }

    outfile.close();
}

int main() {
    readFromFile("arrivingAnimals.txt");
    writeToFile("newAnimals.txt");

    for (Animal* animal : animals) {
        delete animal;
    }

    return 0;
}
