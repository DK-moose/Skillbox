#include <iostream>
#include <string>

using namespace std;

class Animal
{
private: 
	string typeAnimal;
	string sound1;
	string sound2;

public:
	virtual string GetTypeAnimal()
	{
		return typeAnimal;
	}

	virtual string GetFirstSound()
	{
		return sound1;
	}

	virtual string GetSecondSound()
	{
		return sound2;
	}

};

class Dog : virtual public Animal
{
private:
	string typeAnimal = "Dog";
	string sound1 = "Bark";
	string sound2 = "Woof";

public:
	string GetTypeAnimal()
	{
		return typeAnimal;
	}

	string GetFirstSound()
	{
		return sound1;
	}

	string GetSecondSound()
	{
		return sound2;
	}
};

class Cat : virtual public Animal
{
private:
	string typeAnimal = "Cat";
	string sound1 = "Meow";
	string sound2 = "Purr";

public:
	string GetTypeAnimal()
	{
		return typeAnimal;
	}

	string GetFirstSound()
	{
		return sound1;
	}

	string GetSecondSound()
	{
		return sound2;
	}
};

void meeting(Animal* a, Animal* b)
{
	if (a->GetTypeAnimal() == b->GetTypeAnimal())
		cout << a->GetSecondSound() << " " << b->GetSecondSound() << endl;
	else
		cout << a->GetFirstSound() << " " << b->GetFirstSound() << endl;
}

int main()
{
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	meeting(dog, dog);
	meeting(dog, cat);
	meeting(cat, dog);
	meeting(cat, cat);
	return 0;
}
