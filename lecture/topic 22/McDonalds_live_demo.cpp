#include <algorithm>
#include <iostream>

class MenuItem
{
public:
	virtual const char* getName() const = 0;
};

// Класове за различни компоненти на поръчката
class Burger : public MenuItem
{
public:
	virtual const char* getName() const
	{
		return "Burger";
	}
	void prepare() const
	{
		std::cout << getName() << " is being prepared." << std::endl;
	}
};

class Drink : public MenuItem
{
public:
	virtual const char* getName() const
	{
		return "Drink";
	}
	void pour() const
	{
		std::cout << getName() << " is being poured." << std::endl;
	}
};

class Fries : public MenuItem
{
public:
	virtual const char* getName() const
	{
		return "Fries";
	}
	void fry() const
	{
		std::cout << getName() << " are being fried." << std::endl;
	}
};

// Кухнята, която отговаря за приготвянето на поръчката
class Kitchen
{
public:
	// Private методи за подготовка на компонентите - само за приятели
	void prepareBurger() const
	{
		Burger burger;
		std::cout << "Kitchen) ";
		burger.prepare();
	}

	void pourDrink() const
	{
		Drink drink;
		std::cout << "Kitchen) ";
		drink.pour();
	}

	void fryFries() const
	{
		Fries fries;
		std::cout << "Kitchen) ";
		fries.fry();
	}

	Kitchen()
	{
	}

	void serve() const
	{
		std::cout << "Meal is ready to be served!" << std::endl;
	}
};

// Касиерът, който поема поръчката и координира кухнята
class Cashier
{
private:
	Kitchen kitchen;

public:
	Cashier() : kitchen()
	{
	}

	void makeStandardOrder()
	{
		std::cout << "Starting a standard order..." << std::endl;
		kitchen.prepareBurger();
		kitchen.pourDrink();
		kitchen.fryFries();
		kitchen.serve();
	}

	void makeCustomOrder(bool includeBurger, bool includeDrink, bool includeFries)
	{
		std::cout << "Starting a custom order..." << std::endl;
		if (includeBurger)
		{
			kitchen.prepareBurger();
		}
		if (includeDrink)
		{
			kitchen.pourDrink();
		}
		if (includeFries)
		{
			kitchen.fryFries();
		}
		kitchen.serve();
	}
};

// Симулиране на процеса на поръчка
int main()
{
	Kitchen SerdikaCenter;
	
	Cashier cashier;

	// Стандартна поръчка
	cashier.makeStandardOrder();

	// Персонализирана поръчка (само напитка и картофки)
	cashier.makeCustomOrder(false, true, true);

	return 0;
}
