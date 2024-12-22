// Write C++ program to draw the following pattern. Use DDA line and
// Bresenham‘s circle drawing algorithm. Apply the concept of encapsulation.

 #include <conio.h>
 #include <iostream>
 #include <graphics.h>
 #include <math.h>
 using namespace std;
 class drawpattern {
 private:
 float dx, dy, i, length;
 public:
 int x1, y1, x2, y2;
 int xmid, ymid;
 int xc, yc, r;
 void getdata();
 void ddaline(int x1, int y1, int x2, int y2);
 void bdrawcircle(int xc, int yc, int r);
 };
 void drawpattern::getdata() {
 cout << "Enter x1: ";
 cin >> x1;
 cout << "Enter y1: ";
 cin >> y1;
 cout << "Enter x2: ";
 cin >> x2;
 cout << "Enter y2: ";
 cin >> y2;
 }
 void drawpattern::ddaline(int x1, int y1, int x2, int y2) {
 float x, y;
 dx = (x2- x1);
 dy = (y2- y1);
 if (abs(dx) >= abs(dy))
 length = abs(dx);
 else
 length = abs(dy);
 dx = dx/length;
 dy = dy/length;
 x =x1;
 y =y1;
 i = 1;
 while (i <= length) {
 putpixel((int)x, (int)y, 15);
 x = x+dx;
 y =y+dy;
 i++;
}
 }
 void drawpattern::bdrawcircle(int xc, int yc, int r) {
 int x = 0, y = r;
 int d = 3- 2 * r;
 putpixel(xc + x, yc- y, 15);
 do {
 putpixel(xc + x, yc + y, 15);
 putpixel(xc- x, yc + y, 15);
 putpixel(xc + x, yc- y, 15);
 putpixel(xc- x, yc- y, 15);
 putpixel(xc + y, yc + x, 15);
 putpixel(xc- y, yc + x, 15);
 putpixel(xc + y, yc- x, 15);
 putpixel(xc- y, yc- x, 15);
 if (d < 0) {
 d =d+4*x+6;
 } else {
 d =d+4*(x-y)+10;
 y--;
 }
 x++;
 } while (x <= y);
 }
 int main() {
 initwindow(800, 800);
 cleardevice();
 drawpattern d;
 d.getdata();
 d.ddaline(d.x1, d.y1, d.x2, d.y1);
 d.ddaline(d.x2, d.y1, d.x2, d.y2);
 d.ddaline(d.x2, d.y2, d.x1, d.y2);
 d.ddaline(d.x1, d.y2, d.x1, d.y1);
 d.xmid = abs((d.x1 + d.x2)) / 2;
 d.ymid = abs((d.y1 + d.y2)) / 2;
 d.ddaline(d.xmid, d.y1, d.x2, d.ymid);
 d.ddaline(d.x2, d.ymid, d.xmid, d.y2);
 d.ddaline(d.xmid, d.y2, d.x1, d.ymid);
 d.ddaline(d.x1, d.ymid, d.xmid, d.y1);
 float sidex = abs(d.x2- d.x1);
 float sidey = abs(d.y2- d.y1);
 float cal = pow(sidex, 2) + pow(sidey, 2);
 cal = 2 * sqrt(cal);
 float rad = (sidex * sidey) / cal;
cout << sidex << " " << sidey << " " << rad << endl;
 d.bdrawcircle(d.xmid, d.ymid, (int)rad);
 getch();
 closegraph();
 return 0;
 }