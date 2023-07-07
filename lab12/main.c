#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "func.h" //подключение заголовочного файла
int main(){
        srand(time(NULL)); //для рандомных значений
        int i,n; //количество парабол
        printf("Введите количество парабол: ");
        scanf("%d", &n); //считывание количества парабол

        struct parabola list[n], *p = NULL; //объявление струтуры
        create_p(list,n);//создание парабол 
        for(i = 0; i < n; i++){ //вывод результатов
                printf("\nУравнение выглядит так: \n\t y= %.2fx^2 + %.2fx + %.2f", \
                list[i].a, list[i].b, list[i].c);
                p = &list[i];
                sech(p);
                if(p->D >0){
                        printf("\n\tD=%f",p->D);
                        printf("\nТочки пересечения x1 = %.2f , x2 = %.2f", p->xy->x1, p->xy->x2);
                        
                }
                else if(p->D == 0.0){
                        printf("\n\tD=%f",p->D);
                        printf("\nТочка пересечения - %.2f", p->xy->x1);
                }
                else{
                        printf("\n\tD=%f",p->D);
                        printf("\nПересечения нет");
                }

        }
        p = NULL;

}
