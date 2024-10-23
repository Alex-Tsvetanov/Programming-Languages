/*
Задача 1: Да се дефинира клас за описание на правоъгълник (по аналог на
класа triangle) с две член-функции face(), която се отличава по наличието
на аргумент и по действие – освен лицето, тя връща и периметъра на
правоъгълника.
*/

class Rectangle
{
	double w, h;

public:
	Rectangle(double w, double h);
	Rectangle();

	double face() const;
	double face(double& p) const;
};

Rectangle::Rectangle(double w, double h) : w(w), h(h)
{
}

Rectangle::Rectangle() : Rectangle(0, 0)
{
}

double Rectangle::face() const
{
	return w * h;
}

double Rectangle::face(double& p) const
{
	p = 2 * (w + h);
	return w * h;
}
