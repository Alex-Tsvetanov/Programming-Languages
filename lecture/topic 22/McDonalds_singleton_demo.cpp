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

class Menu : public MenuItem
{
	std::vector<MenuItem*> elements;

public:
	Menu(const std::vector<MenuItem*>& elements) : MenuItem()
	{
		for (auto item : elements)
		{
			this->elements.push_back(item);
		}
	}
	~Menu()
	{
		for (auto item : elements)
		{
			delete item;
		}
	}
	virtual const char* getName() const
	{
		return "Menu";
	}
	void prepare() const
	{
		std::cout << getName() << " (";
		for (auto item : elements)
		{
			std::cout << item->getName() << ", ";
		}
		std::cout << ") is being prepared." << std::endl;
	}
};

// Кухнята, която отговаря за приготвянето на поръчката
class Kitchen
{
	static unsigned int id_of_next_restaurant;

private:
	friend class Cashier; // Позволяваме на касиера да има достъп до private членовете

	unsigned int id;
	std::string location;

	// Private методи за подготовка на компонентите - само за приятели
	void prepareBurger() const
	{
		Burger burger;
		std::cout << this->id << ") ";
		burger.prepare();
	}

	void pourDrink() const
	{
		Drink drink;
		std::cout << this->id << ") ";
		drink.pour();
	}

	void fryFries() const
	{
		Fries fries;
		std::cout << this->id << ") ";
		fries.fry();
	}

	void prepareMenu() const
	{
		Menu menu = Menu({new Burger(), new Fries(), new Drink()});
		std::cout << this->id << ") ";
		menu.prepare();
	}

public:
	Kitchen(std::string location)
	{
		this->location = location;
		this->id = id_of_next_restaurant;
		id_of_next_restaurant++;
	}
	void serve() const
	{
		std::cout << "Meal is ready to be served!" << std::endl;
	}
};

unsigned int Kitchen::id_of_next_restaurant = 1;

class MenuList
{
private:
	std::vector<const MenuItem*> items;

	// Private конструктор, който зарежда елементите на менюто
	MenuList()
	{
		items = {new Burger(), new Drink(), new Fries()}; // Примерни елементи в менюто
	}

	~MenuList()
	{
		for (auto& item : items)
		{
			delete item;
		}
	}

public:
	// Метод за достъп до единствената инстанция на Menu
	static MenuList& getInstance()
	{
		static MenuList instance;
		return instance;
	}

	// Забрана за копиране и присвояване
	MenuList(const MenuList&) = delete;
	MenuList& operator=(const MenuList&) = delete;

	// Метод за показване на менюто
	void showMenu() const
	{
		std::cout << "Menu items:" << std::endl;
		for (const auto& item : items)
		{
			std::cout << "- " << item->getName() << std::endl;
		}
	}

	// Метод за добавяне на нов елемент в менюто
	void addItem(const MenuItem* item)
	{
		items.push_back(item);
	}
};

// Касиерът, който поема поръчката и координира кухнята
class Cashier
{
private:
	Kitchen* kitchen;

public:
	Cashier(Kitchen* kitchen)
	{
		this->kitchen = kitchen;
	}
	// Показване на менюто на клиента
	void displayMenu() const
	{
		MenuList::getInstance().showMenu();
	}

	void makeStandardOrder()
	{
		std::cout << "Starting a standard order..." << std::endl;
		kitchen->prepareBurger();
		kitchen->pourDrink();
		kitchen->fryFries();
		kitchen->serve();
	}

	void makeCustomOrder(bool includeBurger, bool includeDrink, bool includeFries)
	{
		std::cout << "Starting a custom order..." << std::endl;
		if (includeBurger)
		{
			kitchen->prepareBurger();
		}
		if (includeDrink)
		{
			kitchen->pourDrink();
		}
		if (includeFries)
		{
			kitchen->fryFries();
		}
		kitchen->serve();
	}
};

// Симулиране на процеса на поръчка
int main()
{
	Kitchen SerdikaCenter("SerdikaCenter, Sitnyakovo Blvd 48");
	Kitchen TheMall("The Mall, Tsarigradsko shose Blvd 115");

	Cashier cashier1 = Cashier(&SerdikaCenter);
	Cashier cashier2 = Cashier(&SerdikaCenter);
	Cashier cashier3 = Cashier(&SerdikaCenter);

	Cashier cashier4 = Cashier(&TheMall);
	Cashier cashier5 = Cashier(&TheMall);

	// Стандартна поръчка
	cashier1.makeStandardOrder();

	// Персонализирана поръчка (само напитка и картофки)
	cashier4.makeCustomOrder(false, true, true);

	return 0;
}
