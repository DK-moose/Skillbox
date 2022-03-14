#include <iostream>
#include <string>

using namespace std;

class Toy
{
private:
	string name;

public:
	Toy(string name) : name(name) {};
	Toy() : name("SomeToy") {};
	string GetName() { return name; };
};

class shared_ptr_toy
{
private:
	Toy* toy;
	int *linkCounter = new int(1);

public:
	shared_ptr_toy(string name)
	{
		toy = new Toy(name);
	};

	shared_ptr_toy(shared_ptr_toy& otherToy)
	{
		toy = new Toy(*otherToy.toy);
		linkCounter = otherToy.GetLinkCounter();
		*linkCounter = *linkCounter + 1;
		otherToy.SetLinkCounter(linkCounter);
	};

	shared_ptr_toy& operator=(shared_ptr_toy& otherToy)
	{
		if (this == &otherToy)
		{
			*linkCounter = *linkCounter + 1;
			otherToy.SetLinkCounter(linkCounter);
			return *this;
		}
		if (toy != nullptr)
		{
			*linkCounter = *linkCounter - 1;
			otherToy.SetLinkCounter(linkCounter);
			delete toy;
		}
		toy = new Toy(*otherToy.toy);
		return *this;
	};

	string GetName()
	{
		return toy->GetName();
	};

	~shared_ptr_toy()
	{
		*linkCounter = *linkCounter - 1;
		delete toy;
	};

	void SetLinkCounter(int* linkCounter)
	{
		this->linkCounter = linkCounter;
	}

	int* GetLinkCounter()
	{
		return linkCounter;
	}

	void reset()
	{
		*linkCounter = 0;
	}
};

shared_ptr_toy make_shared_toy()
{
	return shared_ptr_toy("SomeToy");
}

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
	Dog() : name("SomeName"), age(0), lovelyToy(make_shared_toy()) {};
	Dog(string name, int age, shared_ptr_toy lovelyToy) : name(name), age(age), lovelyToy(make_shared_toy(lovelyToy)) {};
	void PrintDog()
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Lovely toy: " << lovelyToy.GetName() << endl << endl;
	};
};

int main()
{
	shared_ptr_toy ball = make_shared_toy("Ball");
	shared_ptr_toy bone = make_shared_toy("Bone");
	Dog *dog1 = new Dog("Sharik", 5, ball);
	Dog *dog2 = new Dog("Bobik", 3, ball);
	Dog *dog3 = new Dog("Tuzik", 4, ball);
	Dog *dog4 = new Dog("Jack", 7, bone);
	Dog *dog5 = new Dog("Sam", 8, bone);

	delete dog1;
	delete dog3;
	delete dog4;

	dog2->PrintDog();
	dog5->PrintDog();

	ball.reset();
	bone.reset();
	return 0;
}
