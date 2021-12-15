#include<stdio.h>
#include<locale>

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

protected:
	int _Day;
	int	_Month;
	int	_Year;

public:

	date();
	
	void	setDay();
	void	setMonth();
	void	setYear();

	void	DateCheck();
	void	ShowDate1();
	void	ShowDate2();
};

date::date(){
	_Day = 1;
	_Month = 1;
	_Year = 1900;
}

void date::setDay() {
	int d=0;
	while (d < 1 || d>31) {
		printf("\nВведите день: ");
		scanf_s("%d", &d);
		if (d < 1 || d > 31) { 
			printf("\n*******************************");
			printf("\n*  Дата введена некорректно!  *");
			printf("\n*******************************");
		}
		_Day = d;
	}
}

void date::setMonth() {
	int m=0;
	while (m < 1 || m>12) {
		printf("\nВведите месяц (в числовом формате): ");
		scanf_s("%d", &m);
		if (m < 1 || m > 12) {
			printf("\n*******************************");
			printf("\n*  Месяц введен некорректно!  *");
			printf("\n*******************************");
		}
		_Month = m;
	}
}

void date::setYear() {
	int y=0;
	while (y < 1 || y>9999) {
		printf("\nВведите год: ");
		scanf_s("%d", &y);
		if (y < 1 || y>9999) {
			printf("\n*****************************");
			printf("\n*  Год введен некорректно!  *");
			printf("\n*****************************");
		}
		_Year = y;
	}
}

void date::DateCheck() {
	int i;
	bool ch=false;
	if (_Day == 31) {
		for (i = 0; i < sizeof(LongMonth); i++) {
			if (_Month == LongMonth[i])
				break;
		}
		if (sizeof(LongMonth) <= i)
			ch = true;
	}
	if (_Month == 2 && _Day > 28 + ((_Year % 4 == 0) ? 1 : 0))
		ch = true;
	if (ch) {
		_Day = 1;
		printf("\n*************************************************");
		printf("\n*  Дата введена неверно и исправлена системно!  *");
		printf("\n*************************************************");
	}
}

void date::ShowDate1() {
	printf("\n***************************");
	printf("\n*  %2d %8s %4d года  *", _Day, sMonth[_Month - 1], _Year);
	printf("\n***************************");
}

void date::ShowDate2() {
	printf("\n****************");
	printf("\n*  %02d.%02d.%04d  *", _Day, _Month, _Year);
	printf("\n****************");
}