#include<conio.h>
#include "person.hpp"

void main(){
	setlocale(LC_ALL, "Russian");
	date Date;
	person Person;
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
