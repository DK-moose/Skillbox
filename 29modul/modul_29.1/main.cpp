#include <iostream>
#include <string>

using namespace std;

class Animal
{
private: 
	string sound1;
	string sound2;

public:
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
	string sound1 = "Bark";
	string sound2 = "Woof";

public:
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
	string sound1 = "Meow";
	string sound2 = "Purr";

public:
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
	if (a->GetSecondSound() == b->GetSecondSound())
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
