/*
Задача 2: Разширете функционалността на задачи 2 и 3, като имплементирате
друга приятелска функция, която да изчислява времето за изминаване на
зададени километри (S = V * T).
*/

#include <iostream>

using namespace std;

class truck; // Предварителна декларация

class car
{
	int passengers;
	int speed;

public:
	car(int p, int s)
	{
		passengers = p;
		speed = s;
	}
	int sp_greater(truck t);
	friend double time_to_travel(double S, car);
};

class truck
{
	int weight;
	int speed;

public:
	truck(int w, int s)
	{
		weight = w;
		speed = s;
	}
	friend int car::sp_greater(truck t);
	friend double time_to_travel(double S, truck);
};
/* Връща положителна стойност, ако скоростта на колата е по-голяма от
тази на камиона. Връща 0, ако скоростите са еднакви. Връща отрицателна
стойност, ако скоростта на камиона е по-голяма от тази на колата. */

int car::sp_greater(truck t)
{
	return speed - t.speed; // Тъй като sp_greater() е член на car, то трябва да се подаде само
} // обектът за камион

double time_to_travel(double S, car c)
{
	return S / c.speed;
}

double time_to_travel(double S, truck t)
{
	return S / t.speed;
}
int main()
{
	int t;
	car c1(6, 55), c2(2, 120);
	truck t1(10000, 55), t2(20000, 72);
	cout << "Comparing c1 and t1 :\n";
	t = c1.sp_greater(t1); // Извиква се като член-функция на car
	if (t < 0)
	{
		cout << "Truck is faster.\n";
	}
	else if (t == 0)
	{
		cout << "Car and truck speed is the same.\n";
	}
	else
	{
		cout << "Car is faster.\n";
	}
	cout << "\nComparing c2 and t2 :\n";
	t = c2.sp_greater(t2); // Извиква се като член-функция на car
	if (t < 0)
	{
		cout << "Truck is faster.\n";
	}
	else if (t == 0)
	{
		cout << "Car and truck speed is the same.\n";
	}
	else
	{
		cout << "Car is faster.\n";
	}
	return 0;
}
