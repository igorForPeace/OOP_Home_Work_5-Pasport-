#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pasport
{
private:
	char* surname;
	char* name;
	char* patronymic;
	char* male;   // пол обладателя паспорта
	int day;    // дата рождения
	int month;
	int year;
	int number;   // номер паспорта (не более 8 цыфр)
	int authority; // орган что выдал паспорт  (не более 4 цыфр)

public:

	Pasport(const char* surname, const char* name, const char* patronymic, const char* male,
		int day, int month, int year, int number, int authority)
	{
		this->surname = new char[100];
		strcpy_s(this->surname, 99, surname);
		this->name = new char[100];
		strcpy_s(this->name, 99, name);
		this->patronymic = new char[100];
		strcpy_s(this->patronymic, 99, patronymic);
		this->male = new char[100];
		strcpy_s(this->male, 99, male);
		(day <= 31 && day >= 1) ? this->day = day : throw "OPPS!";
		(month >=1 && month <= 12) ? this->month = month : throw "OPPS!";
		(year < 2022) ? this->year = year : throw "OPPS!";
		(number>=10000000&&number<=99999999)?this->number = number: throw "OPPS!";
		(authority>=1000&& authority<=9999)?this->authority = authority: throw "OPPS!";
	}

	Pasport():Pasport("Плахотнюк","Игорь","Витальевич","MALE",29,3,1996,77894523,5116){}

	~Pasport()
	{
		if (surname != nullptr)
		{
			delete[] surname;
		}
		if (name != nullptr)
		{
			delete[] name;
		}
		if (patronymic != nullptr)
		{
			delete[] patronymic;
		}
		if (male!=nullptr)
		{
			delete[] male;
		}
	}

	void SetName(const char* name)
	{
		delete[] this->name;
		this->name = new char[100];
		strcpy_s(this->name, 99, name);
	}

	const char* GetName()
	{
		return name;
	}

	void SetSurname(const char* surname)
	{
		delete[] this->surname;
		this->surname = new char[100];
		strcpy_s(this->surname, 99, surname);
	}

	const char* GetSurname()
	{
		return surname;
	}

	void SetPatronymic(const char* patronymic)
	{
		delete[] this->patronymic;
		this->patronymic = new char[100];
		strcpy_s(this->patronymic, 99, patronymic);
	}

	const char* GetPatronymic()
	{
		return patronymic;
	}

	void SetMale(const char* male)
	{
		delete[] this->male;
		this->male = new char[100];
		strcpy_s(this->male, 99, male);
	}

	const char* GetMale()
	{
		return male;
	}

	
	
	void Print_info()
	{
		cout << "=======================" << endl;
		cout << "Данные гражданина:" << endl;
		cout << "Фамилия: " << GetSurname() << endl;
		cout << "Имя: " << GetName() << endl;
		cout << "Отчество: " << GetPatronymic() << endl;
		cout << "Пол: "<<GetMale() << endl;
		cout << "Дата рождения: " << day << "." << month << "." << year << endl;
		cout << "Номер документа: " << number << endl;
		cout << "Ораган выдачи: " << authority << endl;
	}
};

class Visa
{
private:
	string visa;
public:
	Visa(string visa)
	{
		this->visa = visa;
	}

	Visa() :Visa("Швейцария") {}

	void SetVisa(string visa)
	{
		this->visa = visa;
	}

	string GetVisa() const
	{
		return visa;
	}


};

class International_Passport :public Pasport
{
private:
	Visa* visas;
	int real_size = 0;
public:

	International_Passport():Pasport()
	{
		visas = new Visa[real_size];
	}

	~International_Passport()
	{
		if (visas != nullptr)
		{
			delete []visas;
		}
	}

	void Print_info()
	{
		Pasport::Print_info();
		cout << "Визы:" << endl;
		if (real_size == 0)
		{
			cout << "У вас пока нет виз(" << endl;
		}
		else
		{
			for (int i = 0; i <real_size; i++)
			{
				cout << visas[i].GetVisa() << endl;
			}
		}
	}

	void AddVisa(string visa)
	{
		Visa *temp = new Visa[real_size + 1];
		for (int i = 0; i < real_size; i++)
		{
			temp[i] = visas[i];
		}
		temp[real_size] = visa;
		delete[] this->visas;
		this->visas = temp;
		real_size++;
	}


};



int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	Pasport A;
	A.Print_info();

	International_Passport B;
	B.Print_info();
	B.AddVisa("Англия");
	B.Print_info();
	B.AddVisa("Франция");
	B.AddVisa("США");
	B.Print_info();
	

	
	return 0;
}