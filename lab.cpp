#include <iostream>
#include <string>

using namespace std;

static string type1="кумулятивная"; // объявляем статические данные
static string type2="термобарическая";

class Weapon // класс-родитель оружие
{
private:
    bool ready; // готово ли оружие к стрельбе
public:
    Weapon():ready(true){} // конструтор по умолчанию
    Weapon(bool a): ready(a){} // конструтор с параметром
    Weapon(const Weapon &other){this->ready=other.ready;} // конструтор копирования
    void showReload(){if(ready) cout<<"нет нужды."<<endl; else cout<<"Перезарядка..."<<endl;}//вызываем функцию
    ~Weapon(){} // деструтор
};

class AUTO : virtual public Weapon //класс-потомок автоматическое оружие
{
public:
    int maxlenght;// максимальная длина оружия
    int maxrange;// максимальная дальность выстрела
    AUTO():maxlenght(46),maxrange(1500){} // конструтор по умолчанию
    void showRange(){cout<<"Максимальная дальность: "<<maxrange<<endl;}//вызываем функции
    void showLenght(){cout<<"Максимальная длина автоматического оружия: "<<maxlenght<<endl;}
    friend void test(int maxlenght);//дружественная функция тестовой стрельбы

    class SEMI_AUTO: virtual public Weapon //вложенный класс полу-автоматическое оружие
    {
    public:
        int maxLenght; //максимальная длина оружия
        SEMI_AUTO():maxLenght(37){} // конструтор по умолчанию
        void showLenght(){cout<<"Максимальная длина полу-автоматического оружия: "<<maxLenght<<endl;}
        friend void test(int maxLenght); //дружественная функция тестовой стрельбы
        ~SEMI_AUTO(){}// деструтор
    };
    ~AUTO(){}// деструтор
};

class grenade // класс взрывчатки
{
public:
    float radius; // радиус поражения
    void showRaius(){cout<<"Радиус взрыва: "<<radius<<endl;} //вызываем функцию
};

class explosive : virtual public Weapon // класс оружия взрывного действия
{
private:
    int ammo; //боеприпасы
public:
    int Lenght; // длина оружия
    friend grenade; // дружественный класс для оружия ипользующего его
    explosive():ammo(7), Lenght(76), Weapon(false){}// конструтор
    void showAmmo(){cout<<"Боеприпасов в наличии: "<<ammo<<endl;}
    void typeAmmo(string type){cout<<"тип боеприпасов: "<<type<<endl;}
    ~explosive(){}// деструтор
};



void test(int a){if (a>60) cout<<"БА-баах"<<endl; //функция тестовой стрельбы
                else if (a>40) cout<<"тра-та-та-та-та..."<<endl;
                else cout<<"тра-та-та...тра-та-та..."<<endl;}

int main()
{
    setlocale(0, "rus");// установка локали

    AUTO ak47; //вызываем все необходимое для автоматического оружия
    ak47.showReload();
    ak47.showLenght();
    ak47.showRange();
    test(ak47.maxlenght);
    cout<<endl;
    AUTO::SEMI_AUTO FSM1453; //вызываем все необходимое для полу-автоматического оружия
    FSM1453.showReload();
    FSM1453.showLenght();
    test(FSM1453.maxLenght);
    cout<<endl;
    explosive bazuka; //вызываем все необходимое для оружия взрывного действия
    bazuka.showReload();
    bazuka.showAmmo();
    bazuka.typeAmmo(type1);
    test(bazuka.Lenght);

    return 0;
}
