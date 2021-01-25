#include <iostream>
#include "Cperson.h"
#include "Ctimer.h"
#include "Cvector.h"
#include "Cstring.h"

using namespace std;

//Methods of class Cperson// 
Cperson::Cperson()
{
	name = "Skakun";
	year = "23.11.2001";
}
/*void Cperson::input()
{
	string Name;
	cout << "Enter name: ";
	cin >> Name;
	this->SetName(Name);

	string Year;
	cout << "Enter year: ";
	cin >> Year;
	this->SetYear(Year);
}*/
Cperson::~Cperson()
{
	cout << "Destructor(Cperson-" << this << ") is working" << endl;
}

//Methods of class Ctimer// 
Ctimer::Ctimer(int _min, int _sec)
{
	while (60 < _sec)
	{
		_sec -= 60;
		_min++;
	}

	this->min = _min;
	this->sec = _sec;
}
Ctimer::Ctimer(int _sec)
{
	this->min = 0;

	while (60 < _sec)
	{
		_sec -= 60;
		this->min++;
	}

	this->sec = _sec;
}
Ctimer::~Ctimer() { cout << "Destructor(Ctimer-" << this << ") is working" << endl; }

//Methods of class Cvector// 
Cvector::Cvector(int _x, int _y, int _z)
{
	x = _x;
	y = _y;
	z = _z;
	ShowVector();
}
void Cvector::ShowVector()
{
	cout << "Vector's coordinates: \nx= " << x << "; y=" << y << "; z= " << z << endl;
}
Cvector::~Cvector() { cout << "Destructor(Cvector-" << this << ") is working" << endl; }


//Methods of class Cstring//
Cstring::Cstring(const char* line)
{
	this->size = strlen(line);
	this->string = new char[size + 1];
	for (int i = 0; i < size; i++)
		this->string[i] = line[i];
	this->string[size] = '\0';
}
Cstring::Cstring()
{
	this->string = nullptr;
	this->size = 0;
}
void Cstring::Show()
{
	if (string != nullptr)
		cout << string << endl;
	else
		cout << "Строка пуста!" << endl;
}
Cstring::~Cstring()
{
	cout << "Destructor(Cstring-" << this << ") is working" << endl;
	delete[] this->string;
}


char Decision_3()
{
	char x;
	cout << "\nУкажите, какой из классов вы хотите выбрать и введите соответствующее значение: \n" <<
		"Ctimer - '1'  Cperson - '2'  Cvector - '3'  Cstring - '4'; \n";
	cout << "Вы ввели:";
	cin >> x;
	while (x != '1' && x != '2' && x != '3' && x != '4')
	{
		cout << "Введите один из предложенных вариантов: ";
		cin >> x;
	}

	return x;
}

   void menu()
   {
	   switch (Decision_3())
	   {
	case '1':
	   {
		int min, sec;
		cout << "Введите минуты: ";
		cin >> min;

		  while (min < 0)
		  {
			cout << "Количество минут не может быть меньше нуля, введите значение снова:  ";
			cin >> min;
		  }

		  cout << "Введите секунды: ";
		  cin >> sec;

		   while (sec < 0)
		   {
			 cout << "Количество секунд не может быть меньше нуля, введите значение снова:  ";
			 cin >> sec;
		   }

		Ctimer timer1(min, sec);
		cout << "Минуты: " << timer1.GetMin() << "\t Секунды: " << timer1.GetSec() << endl;

		cout << "Введите секунды: ";
		cin >> sec;

		   while (sec < 0)
		   {
			  cout << "Количество секунд не может быть меньше нуля, введите значение снова:  ";
			  cin >> sec;
		   }

		Ctimer timer2(sec);
		cout << "Минуты: " << timer2.GetMin() << "\t Секунды: " << timer2.GetSec() << endl;
	}
	break;

	case '2':
	{
		Cperson person;
		cout << "Name: " << person.GetName() << "\t Year: " << person.GetYear() << endl;
	}
	break;

	case '3':
	{
		int x, y, z;
		cout << "x: ";
		cin >> x;

		cout << "y: ";
		cin >> y;

		cout << "z: ";
		cin >> z;
		Cvector vector(x, y, z);
	}
	break;

	case'4':
	{
		char line[15] = "Какая-то фраза";
		Cstring str(line);
		str.Show();

		Cstring str1;
		str1.Show();

	}
	}
}