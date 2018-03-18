#include <iostream>
#include <string>

using namespace std;

class Weapon
{
private:
    bool ready; // готово ли оружие к стрельбе
public:
    Weapon():ready(true){} // конструтор по умолчанию
    Weapon(bool a): ready(a){} // конструтор с параметром
    Weapon(const Weapon &other){this->ready=other.ready;} // конструтор копирования
    void showReload(){if(ready) cout<<"нет нужды."<<endl; else cout<<"Перезарядка..."<<endl;}
    ~Weapon(){} // деструтор
};

class AUTO : virtual public Weapon
{
public:
    int maxlenght;
    int maxrange;
    AUTO():maxlenght(46),maxrange(1500){} // конструтор по умолчанию
    void showRange(){cout<<"Максимальная дальность: "<<maxrange<<endl;}
    void showLenght(){cout<<"Максимальная длина автоматического оружия: "<<maxlenght<<endl;}
    friend void test(int maxlenght);

    class SEMI_AUTO: virtual public Weapon
    {
    public:
        int maxLenght;
        SEMI_AUTO():maxLenght(37){}
        void showLenght(){cout<<"Максимальная длина полу-автоматического оружия: "<<maxLenght<<endl;}
        friend void test(int maxLenght);
    };
};

class grenade
{
public:
    float radius;
    void showRaius(){cout<<"Радиус взрыва: "<<radius<<endl;}

};

class explosive : virtual public Weapon
{
private:
    int ammo;
public:
    int Lenght;
    friend grenade;
    explosive():ammo(7), Lenght(76), Weapon(false){}
    void showAmmo(){cout<<"Боеприпасов в наличии: "<<ammo<<endl;}
};



void test(int a){if (a>60) cout<<"БА-баах"<<endl;
                else if (a>40) cout<<"тра-та-та-та-та..."<<endl;
                else cout<<"тра-та-та...тра-та-та..."<<endl;}

int main()
{
    setlocale(0, "rus");

    AUTO ak47;
    ak47.showReload();
    ak47.showLenght();
    ak47.showRange();
    test(ak47.maxlenght);
    cout<<endl;
    AUTO::SEMI_AUTO FSM1453;
    FSM1453.showReload();
    FSM1453.showLenght();
    test(FSM1453.maxLenght);
    cout<<endl;
    explosive bazuka;
    bazuka.showReload();
    bazuka.showAmmo();
    test(bazuka.Lenght);

    return 0;
}
