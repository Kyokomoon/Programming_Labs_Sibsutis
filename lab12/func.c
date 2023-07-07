#include <stdlib.h>
#include <math.h>
#include "func.h"
void sech(struct parabola *p){  //функция для нахождения пересечения с осью х
        float x1, x2, pr1, pr2;
        struct point *pxy = (struct point*)malloc(sizeof(struct point));
        p->D = (pow((p->b),2)) - (4*(p->a)*(p->c)); //нахождение дискриминаниа 
        if((int)p->D==0){   //если дискриминант равен 0
                x1 = (-(p->b))/(2*(p->a)); //находим точку пересечения
                pxy->x1 = x1;// координата х
                pxy->y1 = 0; //координата у
                p->xy =pxy;
        }
        else if(p->D>0){    //если дискриминант больше 0
                x1 = (-(p->b) + sqrt(p->D))/(2*(p->a));//находим точку пересечения
                x2 = (-(p->b) - sqrt(p->D))/(2*(p->a));//находим точку пересечения
                pxy->x1 = x1;   // координата х
                pxy->x2 = x2;   // координата х
                pxy->y1 = 0;    //координата у
                pxy->y2 = 0;    //координата у
                p->xy =pxy;
        }
        else{ //если дискриминант меньше 0
                p->xy = NULL;
        }
}
void create_p(struct parabola *list, int n){ //создание парабол
        int i, x;
        float ap, bp, cp;
        for(i=0;i<n;i++){
                list[i].a = rand()%30 - 15; //коофициент а
                list[i].b = rand()%30 - 15; //коофициент b
                list[i].c = rand()%50 - 25; //коофициент c
        }
}