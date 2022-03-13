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

public:
	shared_ptr_toy(string name)
	{
		toy = new Toy(name);
	}

	shared_ptr_toy(const shared_ptr_toy& otherToy)
	{
		toy = new Toy(*otherToy.toy);
	}

	shared_ptr_toy& operator=(const shared_ptr_toy& otherToy)
	{
		if (this == &otherToy)
			return *this;
		if (toy != nullptr)
			delete toy;
		toy = new Toy(*otherToy.toy);
		return *this;
	}

	string GetName()
	{
		return toy->GetName();
	}

	~shared_ptr_toy() { delete toy; };
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

int main()
{
	shared_ptr_toy someToy = make_shared_toy();
	cout << someToy.GetName() << endl;
	shared_ptr_toy ball = make_shared_toy("Ball");
	cout << ball.GetName() << endl;
	shared_ptr_toy copyBall = make_shared_toy(ball);
	cout << copyBall.GetName() << endl;
	return 0;
}
