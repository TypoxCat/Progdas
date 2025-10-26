#include <iostream>
using namespace std;

double pi = 3.1416;

double distance(int x1,int y1,int x2,int y2);
double radius(int xc,int yc,int x,int y);
double circumference(double r);
double area(double r);

int main(){
    int xc, yc, x, y;
    double rad;
    cout << "The x of center: ";
    cin >> xc;
    cout << "The y of center: ";
    cin >> yc;
    cout << "The x of point: ";
    cin >> x;
    cout << "The y of point: ";
    cin >> y;

    rad = radius(xc,yc, x, y);
    cout << "--- Here are the results ---" << endl;
    cout << "The radius is: " << rad << endl;
    cout << "The diameter is: " << 2*rad << endl;
    cout << "The circumference is: " << circumference(rad) << endl;
    cout << "The area is: " << area(rad) << endl;
    return 0;
}

double distance(int x1,int y1,int x2,int y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double radius(int xc,int yc,int x,int y){
    return distance(xc, yc, x, y);
}

double circumference(double r){
    return 2*pi*r;
}

double area(double r){
    return pi*r*r;
}