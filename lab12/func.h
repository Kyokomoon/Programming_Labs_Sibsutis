struct point{   //струтура с координатами точек
        float x1,y1;
        float x2,y2;
        
};
struct parabola {   //струтура парабола 
        float a, b, c; //коэфициенты
        float D;    //дискриминант 
        struct point *xy; 
};
void sech(struct parabola *p);
void create_p(struct parabola *list, int n);
