#include <iostream>
#include <string>

using namespace std;

class Toy
{
private:
	string name;

public:
	Toy() : name("SomeToy") {};
	Toy(string name) : name(name) {};
	void PrintToy() { cout << name; };
};

class shared_ptr_toy
{
private:
	Toy* toy;
	int *linkCounter;

public:
	shared_ptr_toy()
	{
		toy = new Toy();
		linkCounter = new int(1);
	};

	shared_ptr_toy(string name)
	{
		toy = new Toy(name);
		linkCounter = new int(1);
	};

	shared_ptr_toy(const shared_ptr_toy& otherToy)
	{
		toy = otherToy.toy;
		*otherToy.linkCounter = *otherToy.linkCounter + 1;
		linkCounter = otherToy.linkCounter;
	};

	shared_ptr_toy& operator=(const shared_ptr_toy& otherToy)
	{
		if (this == &otherToy)
			return *this;
		if (toy != nullptr)
		{
			*linkCounter = *linkCounter - 1;
			if (linkCounter == 0)
			{
				delete toy;
				delete linkCounter;
			}
		}
		toy = new Toy(*otherToy.toy);
		*otherToy.linkCounter = *otherToy.linkCounter + 1;
		linkCounter = otherToy.linkCounter;
	};

	void PtintSharedPtrToy()
	{
		this->toy->PrintToy();
	}

	void reset()
	{
		delete toy;
		delete linkCounter;
	}

	~shared_ptr_toy()
	{
		*linkCounter = *linkCounter - 1;
		if (linkCounter == 0)
		{
			delete toy;
			delete linkCounter;
		}
	};
};

shared_ptr_toy make_shared_toy(string name)
{
	return shared_ptr_toy(name);
}

shared_ptr_toy make_shared_toy(shared_ptr_toy toy)
{
	return shared_ptr_toy(toy);
}

class Dog
{
private:
	string name;
	int age;
	shared_ptr_toy lovelyToy;

public:
	Dog() : name("SomeName"), age(0), lovelyToy(make_shared_toy("SomeToy")) {};
	Dog(string name, int age, string toyName) : name(name), age(age), lovelyToy(make_shared_toy(toyName)) {};
	Dog(string name, int age, shared_ptr_toy toy) : name(name), age(age), lovelyToy(make_shared_toy(toy)) {};
	
	void PrintDog()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Lovely toy: ";
		lovelyToy.PtintSharedPtrToy();
		cout << endl << endl;
	};

	void CopyLovelyToy(const Dog& otherDog)
	{
		lovelyToy = otherDog.lovelyToy;
	}
};

int main()
{
	shared_ptr_toy ball = make_shared_toy("Ball");
	shared_ptr_toy bone = make_shared_toy("Bone");

	Dog dog_1("Sharik", 10, ball);
	Dog dog_2("Bobik", 7, bone);
	Dog dog_3("Tuzik", 8, ball);
	Dog dog_4("Reks", 9, bone);
	Dog dog_5("Pushok", 11, ball);

	dog_1.PrintDog();
	dog_2.PrintDog();
	dog_3.PrintDog();
	dog_4.PrintDog();
	dog_5.PrintDog();

	dog_2.CopyLovelyToy(dog_3);
	dog_4.CopyLovelyToy(dog_3);

	dog_1.PrintDog();
	dog_2.PrintDog();
	dog_3.PrintDog();
	dog_4.PrintDog();
	dog_5.PrintDog();

	ball.reset();
	bone.reset();

	return 0;
}
