#include <stdio.h>
#include <math.h>


struct point
{
    double x;
    double y;
};


struct triangle
{
    struct point a;
    struct point b;
    struct point c;
};

double area (struct triangle t);

double area (struct triangle t)
{
    double s;

    s = 0.5 * fabs ((t.b.x - t.a.x) * (t.c.y - t.a.y) - (t.c.x -
            t.a.x) * (t.b.y - t.a.y));
    return s;
}

double distance (struct point a, struct point b);

double distance (struct point a, struct point b)
{
    double d;
    
    d = sqrt( (a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y ));
    
    return d;
}

int main (void)
{
    struct triangle t = (struct triangle) { {2., 2.}, {-2., 1.}, {0., -3.} };

    double a = area (t);
    
    double p = distance (t.a, t.b) + distance (t.a, t.c) + distance (t.b, t.c);

    double r = 2.*a/p;

    printf ("radius = %f\n", r);

    return 0;
}
