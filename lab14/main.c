#include <stdio.h>//Библиотека ввода вывода
#include <stdlib.h>//Библиотека для работы с динамической памятью
#include <string.h>//для работы со строками
#include <locale.h>
int main(){
	setlocale(LC_ALL,"Rus");
	char str[100];//для текста
	char  filename[20];//название начального файла
	char outname[20];//название итогового файла
	char slovo[100];
	char first[100];//первое слово в тексте
	char last[100];//последнее слово в тексте
	int lastlen,len,i,count=0;
	printf("Введите имя файла: ");
	scanf("%s",filename);//считываем имя файла
	printf("Введите имя итогового файла: ");
	scanf("%s",outname);//считываем имя файла
	FILE *myfile, *outfile;//описываем файлы
	if((myfile = fopen(filename, "r"))==NULL){//проверка на открытие файла
		printf("Ошибка открытия файла");
		return -1;
	}
	fscanf(myfile,"%s", first);//получаем первое слово в тексте
	while(!feof(myfile)){//пока не конец файла
		fscanf(myfile,"%s", last);//получаем последнее слово в тексте
	}
	rewind(myfile);//возвращаемся в начало файла
	while(!feof(myfile)){//пкоа не конец файла
		count++;//количество строк
		fgets(str,sizeof(str),myfile);//считывание строки
	}
	lastlen = strlen(last);//длина последнего слова
	len = strlen(str);//длина последней строки
	count=count-2;
	rewind(myfile);//возврат в начало файла
	fscanf(myfile,"%s",first);//переходим на 1 слово вперед
	if((outfile = fopen(outname, "w"))==NULL){//проверка на открытие второго файла
                printf("Ошибка открытия итогового файла");
		return -1;
        }
	fprintf(outfile,"%s", last);//записываем последнее слово в начало
	for(i=0;i<count;i++){//записываем строки
		fgets(str,sizeof(str),myfile);
		fputs(str,outfile);
	}
	fgets(str,(len-lastlen),myfile);//последняя строка минус последнее слово
	fputs(str,outfile);//записываем эту строку
	fprintf(outfile,"%s", " ");//добавляем пробел
	fprintf(outfile,"%s",first);//вписываем первое слово в конец предложения
	fclose(myfile);//закрываем основной файл
	fclose(outfile);//закрываем итоговый файл
}