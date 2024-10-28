#include <algorithm>
#include <iostream>
#include <vector>

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
private:
	friend class Cashier;
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
public:
	Kitchen()
	{
	}

private:
	void serve() const
	{
		std::cout << "Meal is ready to be served!" << std::endl;
	}
};

class Menu
{
	static std::vector<const MenuItem*const> items;
public:
	static const std::vector<const MenuItem*const >& getItems()
	{
		return Menu::items;
	}
};

std::vector<const MenuItem*const> Menu::items = {
	new Burger(),
	new Drink(),
	new Fries()
};

class Menu2
{
	std::vector<MenuItem*> items;
public:
	Menu2() {
		items.push_back(new Burger());
		items.push_back(new Drink());
		items.push_back(new Fries());
	}
	static const std::vector<MenuItem*>& getMenu()
	{
		static Menu2 menu;
		return menu.items;
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

	void printMenu()
	{
		std::cout << "Menu:\n";
		const std::vector<const MenuItem* const>& items = Menu::getItems();
		for (const MenuItem*const item : items)
		{
			std::cout << "- " << item->getName() << std::endl;
		}
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
