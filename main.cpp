/*������� ����� ���� - ���� � ������: ���� (1-31), ����� (1-12), ���(����� �����).
����� ����� �����������, 
�������-����� ��������� ���,������ � ����,
� ����� ��� �������-����� ������ �� �������: "5 ������ 1997 ����" � "05.01.1997"; 
�������-����� ������ ��������� ������������ ���������� ����������.
����������� ����� ���-���� ��������, ���������� ��������*/
#include<stdio.h>
#include<locale>
#include<conio.h>
int LongMonth[] = { 1,3,5,7,8,10,12 };
const char* sMonth[] =
{
	"������",
	"�������",
	"�����",
	"������",
	"���",
	"����",
	"����",
	"�������",
	"��������",
	"�������",
	"������",
	"�������"
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
		printf("\n������� ����: ");
		scanf_s("%d", &d);
		if (d < 1 || d > 31) { 
			printf("\n*******************************");
			printf("\n*  ���� ������� �����������!  *");
			printf("\n*******************************");
		}
		Day = d;
	}
	return Day;
}

int date::setMonth() {
	int m=0;
	while (m < 1 || m>12) {
		printf("\n������� ����� (� �������� �������): ");
		scanf_s("%d", &m);
		if (m < 1 || m > 12) {
			printf("\n*******************************");
			printf("\n*  ����� ������ �����������!  *");
			printf("\n*******************************");
		}
		Month = m;
	}
	return Month;
}

int date::setYear() {
	int y=0;
	while (y < 1 || y>9999) {
		printf("\n������� ���: ");
		scanf_s("%d", &y);
		if (y < 1 || y>9999) {
			printf("\n*****************************");
			printf("\n*  ��� ������ �����������!  *");
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
		printf("\n*  ���� ������� ������� � ���������� ��������!  *");
		printf("\n*************************************************");
	}
}

void date::ShowDate1() {
	printf("\n***************************");
	printf("\n*  %2d %8s %4d ����  *", Day, sMonth[Month - 1], Year);
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
	printf("\n������� ���: ");
	scanf_s("%s", list[i].name, 10);
	printf("\n������� �������: ");
	scanf_s("%s", list[i].surname, 10);
	printf("\n������� ���� ��������: ");
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
	printf("\n������� ����� ������: ");
	scanf_s("%d", &rec);
	calc = 2019 - list[rec - 1].Year;
	printf("\n************************************");
	printf("\n*  ������� �� ������ ������: %4d  *", calc);
	printf("\n************************************");
}

person Person;

void main(){
	setlocale(LC_ALL, "Russian");
	int a=0, i=0, n;
	while (a != 7) 	{
		printf("\n1.���� ����.");
		printf("\n2.����� ���� �� �������: \"1 ������ 1900 ����\".");
		printf("\n3.����� ���� �� �������: \"01.01.1900\".");
		printf("\n4.�������� ��������.");
		printf("\n5.����� ������.");
		printf("\n6.���������� ������� ��������.");
		printf("\n7.�����.");
		printf("\n�������� ��������: ");
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
			printf("\n|  |       ���|    �������|���� ��������|");
			printf("\n|--|----------|-----------|-------------|");
			if (i == 0) {
				printf("\n**************************************");
				printf("\n*         ������ �� �������!         *");
				printf("\n**************************************");
			}
			for(n=0; n<i; n++) 
			Person.ShowPerson(n);
			break;
		case 6:
			if (i == 0) {
				printf("\n**************************************");
				printf("\n*         ������ �� �������!         *");
				printf("\n**************************************");
				break;
			}
			Person.Calc();
			break;
		case 7:
			exit(0);

		default:
			printf("\n������� �������� ��������!\n");
			break;
		}
	}
	_getch();
}