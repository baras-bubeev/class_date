/*Создать класс типа - дата с полями: день (1-31), месяц (1-12), год(целое число).
Класс имеет конструктор, 
функции-члены получения дня,месяца и года,
а также две функции-члены печати по шаблону: "5 января 1997 года" и "05.01.1997"; 
функции-члены должны проверять корректность задаваемых параметров.
порожденный класс фио-дата рождения, вычисление возраста*/
#include<stdio.h>
#include<locale>
#include<conio.h>
int LongMonth[] = { 1,3,5,7,8,10,12 };
const char* sMonth[] =
{
	"января",
	"февраля",
	"марта",
	"апреля",
	"мая",
	"июня",
	"июля",
	"августа",
	"сентября",
	"октября",
	"ноября",
	"декабря"
};
class date
{
public:
	date();
	int Day, Month, Year;
	int setDay();
	int setMonth();
	int setYear();
	void DateCheck();
	void ShowDate1();
	void ShowDate2();
};

date::date(){
	Day = 1;
	Month = 1;
	Year = 1900;
}

int date::setDay() {
	int d=0;
	while (d < 1 || d>31) {
		printf("\nВведите день: ");
		scanf_s("%d", &d);
		if (d < 1 || d > 31) { 
			printf("\n*******************************");
			printf("\n*  Дата введена некорректно!  *");
			printf("\n*******************************");
		}
		Day = d;
	}
	return Day;
}

int date::setMonth() {
	int m=0;
	while (m < 1 || m>12) {
		printf("\nВведите месяц (в числовом формате): ");
		scanf_s("%d", &m);
		if (m < 1 || m > 12) {
			printf("\n*******************************");
			printf("\n*  Месяц введен некорректно!  *");
			printf("\n*******************************");
		}
		Month = m;
	}
	return Month;
}

int date::setYear() {
	int y=0;
	while (y < 1 || y>9999) {
		printf("\nВведите год: ");
		scanf_s("%d", &y);
		if (y < 1 || y>9999) {
			printf("\n*****************************");
			printf("\n*  Год введен некорректно!  *");
			printf("\n*****************************");
		}
		Year = y;
	}
	return Year;
}

void date::DateCheck() {
	int i;
	bool ch=false;
	if (Day == 31) {
		for (i = 0; i < sizeof(LongMonth); i++) {
			if (Month == LongMonth[i])
				break;
		}
		if (sizeof(LongMonth) <= i)
			ch = true;
	}
	if (Month == 2 && Day > 28 + ((Year % 4 == 0) ? 1 : 0))
		ch = true;
	if (ch) {
		Day = 1;
		printf("\n*************************************************");
		printf("\n*  Дата введена неверно и исправлена системно!  *");
		printf("\n*************************************************");
	}
}

void date::ShowDate1() {
	printf("\n***************************");
	printf("\n*  %2d %8s %4d года  *", Day, sMonth[Month - 1], Year);
	printf("\n***************************");
}

void date::ShowDate2() {
	printf("\n****************");
	printf("\n*  %02d.%02d.%04d  *", Day, Month, Year);
	printf("\n****************");
}

date Date;

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
	list[i].Day=Day;
	person::setMonth();
	list[i].Month=Month;
	person::setYear();
	list[i].Year=Year;
}

void person::ShowPerson(int i) {
	printf("\n|%2d|%10s| %10s|  %02d.%02d.%04d |", i+1, list[i].name, list[i].surname, list[i].Day, list[i].Month, list[i].Year);
	printf("\n|--|----------|-----------|-------------|");
}

void person::Calc() {
	int rec, calc;
	printf("\nВведите номер записи: ");
	scanf_s("%d", &rec);
	calc = 2019 - list[rec - 1].Year;
	printf("\n************************************");
	printf("\n*  Возраст на данный момент: %4d  *", calc);
	printf("\n************************************");
}

person Person;

void main(){
	setlocale(LC_ALL, "Russian");
	int a=0, i=0, n;
	while (a != 7) 	{
		printf("\n1.Ввод даты.");
		printf("\n2.Вывод даты по шаблону: \"1 января 1900 года\".");
		printf("\n3.Вывод даты по шаблону: \"01.01.1900\".");
		printf("\n4.Добавить человека.");
		printf("\n5.Вывод данных.");
		printf("\n6.Рассчитать возраст человека.");
		printf("\n7.Выход.");
		printf("\nВыберите действие: ");
		scanf_s("%d", &a);
		switch (a) {
		case 1:
			Date.setDay();
			Date.setMonth();
			Date.setYear();
			Date.DateCheck();
			break;
		case 2:
			Date.ShowDate1();
			break;
		case 3:
			Date.ShowDate2();
			break;
		case 4:
			Person.setPerson(i);
			i++;
			break;
		case 5:
			printf("\n|--|----------|-----------|-------------|");
			printf("\n|  |       Имя|    Фамилия|Дата рождения|");
			printf("\n|--|----------|-----------|-------------|");
			if (i == 0) {
				printf("\n**************************************");
				printf("\n*         Данные не введены!         *");
				printf("\n**************************************");
			}
			for(n=0; n<i; n++) 
			Person.ShowPerson(n);
			break;
		case 6:
			if (i == 0) {
				printf("\n**************************************");
				printf("\n*         Данные не введены!         *");
				printf("\n**************************************");
				break;
			}
			Person.Calc();
			break;
		case 7:
			exit(0);

		default:
			printf("\nВведено неверное значение!\n");
			break;
		}
	}
	_getch();
}