//  Write C++ program to implement Cohen Southerland line clipping algorithm.
 
 #include <iostream>
 #include <graphics.h>
 using namespace std;
 static int x_max, y_max, x_min, y_min;
 static const int INSIDE = 0;
 static const int LEFT = 1;
 static const int RIGHT = 2;
 static const int BOTTOM = 4;
 static const int TOP = 8;
 int binarycode(double x, double y) {
 int code = INSIDE;
 if (x < x_min)
 code |= LEFT;
 else if (x > x_max)
 code |= RIGHT;
 if (y < y_min)
 code |= BOTTOM;
 else if (y > y_max)
 code |= TOP;
 return code;
 }
 void cohensutherlandclip(double x1, double y1, double x2, double y2) {
 int code1 = binarycode(x1, y1);
 int code2 = binarycode(x2, y2);
 bool accept = false;
 while (true) {
 if ((code1 == 0) && (code2 == 0)) {
 accept = true;
 break;
 }
 else if (code1 & code2) {
 break;
 }
 else {
 int code_out;
 double x, y;
 if (code1 != 0)
 code_out = code1;
 else
 code_out = code2;
 if (code_out & TOP) {
 x = x1+(x2- x1) * (y_max- y1) / (y2- y1);
 y =y_max;
 }
 else if (code_out & BOTTOM) {
x = x1+(x2- x1) * (y_min- y1) / (y2- y1);
 y =y_min;
 }
 else if (code_out & RIGHT) {
 y =y1+(y2- y1) *(x_max- x1) / (x2- x1);
 x = x_max;
 }
 else if (code_out & LEFT) {
 y =y1+(y2- y1) *(x_min- x1) / (x2- x1);
 x = x_min;
 }
 if (code_out == code1) {
 x1 = x;
 y1 = y;
 code1 = binarycode(x1, y1);
 }
 else {
 x2 = x;
 y2 = y;
 code2 = binarycode(x2, y2);
 }
 }
 }
 if (accept) {
 delay(1000);
 rectangle(x_min, y_min, x_max, y_max);
 line(x1, y1, x2, y2);
 }
 }
 int main() {
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, NULL);
 cout << "Enter left, top and right, bottom of window: ";
 cin >> x_min >> y_min >> x_max >> y_max;
 rectangle(x_min, y_min, x_max, y_max);
 int x1, y1, x2, y2;
 cout << "Enter the end points of the line: ";
 cin >> x1 >> y1 >> x2 >>y2;
 delay(500);
 cleardevice();
 cohensutherlandclip(x1, y1, x2, y2);
 getch();
 closegraph();
 return 0;
 }