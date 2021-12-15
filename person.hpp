#include "date.hpp"

class person : public date {
public:
	struct personstr
	{
		char surname[10];
		char name[10];
		int Day;
		int Month;
		int Year;
	};
	struct personstr list[];
	void setPerson(int i);
	void ShowPerson(int i);
	void Calc();
}; 

void person::setPerson(int i) {
	printf("\nВведите имя: ");
	scanf_s("%s", list[i].name, 10);
	printf("\nВведите фамилию: ");
	scanf_s("%s", list[i].surname, 10);
	printf("\nВведите дату рождения: ");
	person::setDay();
	list[i].Day=_Day;
	person::setMonth();
	list[i].Month=_Month;
	person::setYear();
	list[i].Year=_Year;
}

void person::ShowPerson(int i) {
	printf("\n|%2d|%10s| %10s|  %02d.%02d.%04d |", i+1, list[i].name, list[i].surname, list[i].Day, list[i].Month, list[i].Year);
	printf("\n|--|----------|-----------|-------------|");
}

void person::Calc() {
	int rec, calc;
	printf("\nВведите номер записи: ");
	scanf_s("%d", &rec);
	calc = 2020 - list[rec - 1].Year;
	printf("\n************************************");
	printf("\n*  Возраст на данный момент: %4d  *", calc);
	printf("\n************************************");
}