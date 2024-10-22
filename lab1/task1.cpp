/**
 * @file task1.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2024-10-09
 * 
 * @copyright Copyright (c) 2024
 * Задача 1:
 * Създайте клас, който описва часово време (Time) със следните характеристики:
 *     - час, със стойности от 0 - 23 (24-часови формат) 
 *     - минути, със стойности от 0 - 59
 *     - секунди, със стойности от 0 - 59
 * Класът съдържа следните член - функции:
 *     - За задаване на стойности за час, минути и секунди, като се прави
 *          проверка за съответния диапазон от позволени стойности.
 *     - За отпечатване на времето в два формата:
 *          чч:мм:сс – например: 13:24:07
 *          чч:мм:сс AM/PM – например: 13:24:07 PM
 *          Демонстрирайте функционалността на класа чрез създаване на обект в main().
 */

#include <iostream>
#include <iomanip>

class Time {
private:
    int hour, minutes, seconds;
public:
    Time(int hour = 0, int minutes = 0, int seconds = 0) {
        this->setHour(hour);
        this->setMinutes(minutes);
        this->setSeconds(seconds);
    }

    int getHour() const { return hour; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    void setHour(int hour) {
        if (0 <= hour && hour < 24)
            this-> hour = hour; 
        else
            throw "Invalid seconds";
    }

    void setMinutes(int minutes) {
        if (0 <= minutes && minutes < 60)
            this-> minutes = minutes; 
        else
            throw "Invalid seconds";
    }
    
    void setSeconds(int seconds) {
        if (0 <= seconds && seconds < 60)
            this-> seconds = seconds; 
        else
            throw "Invalid seconds";
    }

    void print24h() const {
        std::cout << std::setfill('0') << std::setw(2) << hour << ":" << std::setfill('0') << std::setw(2) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << " ";
    }
    void print12h() const {
        std::cout << std::setfill('0') << std::setw(2) << hour % 12 << ":" << std::setfill('0') << std::setw(2) << minutes << ":" << std::setfill('0') << std::setw(2) << seconds << " ";
        if (hour > 12) {
            std::cout << "PM";
        } else if (hour < 12) {
            std::cout << "AM";
        } else if (minutes > 0 or seconds > 0) {
            std::cout << "PM";
        } else {
            std::cout << "AM";
        }
    }
};

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    Time x (a, b, c);
    x.print24h();
    std::cout << std::endl;
    x.print12h();
    std::cout << std::endl;
}