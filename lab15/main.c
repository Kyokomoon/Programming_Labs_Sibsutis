#include <stdio.h>//Библиотека ввода вывода
#include <stdlib.h>

typedef struct sotrudnik{// Структура для хранения информации о сотруднике
	char name[15];//Имя
	char lastname[20];//Фамилия
	char ochestvo[20];//Отчество
	int zarabotok;//Заработок
}info;
 info p, *t=&p;
int main(){//Главная Функция
	char filename[10];//Название файла
	int i=1,max=-1;
	printf("\nВведите имя файла : ");
	scanf("%s",filename);//Считывание имени файла
	FILE *f; char ch;//объявление файла
	f=fopen(filename,"wb");//открытие файла на запись
	while(i!=0){//пока не введен 0
		printf("\nЗаписать сотрудника-1, закончить-0 :");//выбор пользователя
		scanf("%d", &i);//считываем выбор
		if(i==1){//заполение информации о сотруднике
			printf("Введите имя сотрудника: ");
			scanf("%s",t->name);
			printf("Введите фамилию сотрудника: ");
			scanf("%s",t->lastname);
			printf("Введите отчество сотрудника: ");
			scanf("%s",t->ochestvo);
			printf("Введите заработок сотрудника: ");
			scanf("%d",&t->zarabotok);
			fwrite(&p, sizeof(p),1,f);//запись в файл
		}
		else i=0;//если введено другое значение отличное от еденицы
	}
	fclose(f);//закрытие файла
	f = fopen(filename,"rb");//открытие файла на чтение
	fread(&p, sizeof(p), 1, f);
	while (!feof(f))//пока не конец файла
 	{ 	if(t->zarabotok>max) max=t->zarabotok;//узнаем максимальный заработок среди сотрудников
		fread(&p, sizeof(p), 1, f);
 	}
	fseek(f,0,SEEK_SET);//Возвращаемся в начало файла
	fread(&p, sizeof(p), 1, f);
	printf("---------------------------");
	while (!feof(f))//пока не конец файла
        {       if(t->zarabotok==max) printf("\nСотрудник:%s %s %s \nЗаработок: %d\n",t->name,t->lastname,t->ochestvo,t->zarabotok);//выводим сотрудников с максимальным значением  заработка
                fread(&p, sizeof(p), 1, f);
        }
	printf("---------------------------");
  	fclose(f);//закрытие файла
}
