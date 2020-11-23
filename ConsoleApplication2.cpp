// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string.h>

using namespace std;

class Cartoon
{
protected:
	char genre[100];
	int god;

public:

	virtual void print() = 0;
	Cartoon(char*, int); //конструктор Cartoon
	~Cartoon();	//деструктор Cartoon
};

class Name :public Cartoon
{
protected:
	char name[100];
	int count;
public:
	Name(char*, int, char*, int); //конструктор Name
	~Name(); //деструктор Name
	void print();
};

class Producer : public Cartoon
{
protected:
	char firstName[100];
	char secondName[100];

public:
	Producer(char*, int, char*, char*);	//конструктор Producer
	~Producer();	//деструктор Producer
	void print();
};


class Description : public Cartoon
{
protected:
	char studio[100];
	int seson;

public:
	Description(char*, int, char*, int); //конструктор Description
	~Description();	//деструктор Discription
	void print();
};



Cartoon::Cartoon(char* s1, int z1)
{
	strcpy_s(genre, 100, s1);
	god = z1;
	cout << "Конструктор - Cartoon" << endl;
}
Cartoon::~Cartoon()
{
	cout << "Деструктор - Cartoon" << endl;
}

Name::Name(char* s1, int z1, char* s2, int z2) :Cartoon(s1, z1)
{
	strcpy_s(name, 100, s2);
	count = z2;
	cout << "Конструктор - Name" << endl;
}
Name::~Name()
{
	cout << "Деструктор - Name" << endl;
}
void Name::print()
{
	cout << "Мультфильм - " << name << " состоит из" << count << " серий, жанр: " << genre << " , год выпуска - " << god << endl;
}


Producer::Producer(char* s1, int z1, char* s3, char* p1) :Cartoon(s1, z1)
{
	strcpy_s(firstName, 100, s3);
	strcpy_s(secondName, 100, p1);
	cout << "Конструктор - Producer" << endl;
}
Producer::~Producer()
{
	cout << "Деструктор - Producer" << endl;
}
void Producer::print()
{
	cout << "Сценарист - " << firstName << " " << secondName << " написал сценарий для жанра - " << genre << " года выпуска - "<< god << endl;
} 


Description::Description(char* s1, int z1, char* s4, int z3) :Cartoon(s1, z1)
{
	strcpy_s(studio, 100, s4);
	seson = z3;
	cout << "Конструктор - Description" << endl;
}
Description::~Description()
{
	cout << "Деструктор - Description" << endl;
}
void Description::print()
{
	cout << "Студия, которая выпустила мультфильм - " << genre << " кол-во сезонов - " << god << " жанр - " << studio << "год - "<< seson << endl;
}




int main()
{
	setlocale(LC_ALL, "Russian");
	char s1[100], s2[100], s3[100], s4[100], p1[100], s5[100], s6[100], s7[100];
	int z1, z2, z3, z4, z5, rez;
	cout << "Введите жанр мультфильма - " << endl;
	cin >> s1;
	cout << "Введите год выпуска - " << endl;
	while (!(cin >> z1))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторный ввод: ";
	}


	cout << "Введите название мультфильма - " << endl;
	cin >> s2;
	cout << "Введите кол-во серий - " << endl;
	while (!(cin >> z2))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Повторный ввод: ";
	}

	
	cout << "Введите фамилию сценариста -  " << endl;
	cin >> s3;
	cout << "Введите имя сценариста - " << endl;
	cin >> p1;

	
	cout << "Введите жанр мультфильма - " << endl;
	cin >> s5;
	
	cout << "Год выпуска - " << endl;
	while (!(cin >> z4))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}
	

	cout << "Введите студию выпуска мультфильма - " << endl;
	cin >> s6;
	
	cout << "Введите кол-во сезонов:" << endl;
	while (!(cin >> z5))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}

	cout << "Введите жанр - " << endl;
	cin >> s4;

	cout << "Введите год выпуска - " << endl;
	while (!(cin >> z3))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Введите ещё раз: ";
	}
	

	cout << "Для просмотра информации - 1, если не желаете - 2" << endl;
	cin >> rez;
	while (rez != 1 && rez != 2)
	{
		cout << "Ввели неправильно" << endl;
		cout << "Введите снова: " << endl;
		cin >> rez;
	}
	if (rez == 1)
	{
		Cartoon* ptr[3]; //массив указателей на абстрактный базовый класс
		Name name(s1, z1, s2, z2);
		Producer producer(s5, z4, s3, p1);
		Description desc(s6, z5, s4, z3);
		ptr[0] = &name;         	// инициализация массива указателей ptr
		ptr[1] = &producer;
		ptr[2] = &desc;

		name.print();
		producer.print();
		desc.print();
	}
	else
	{
		return 0;
	}

	
}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
