 #include <graphics.h>
 #include <math.h>
 #include <iostream>
 #include <stdlib.h>
 using namespace std;
 int main() {
 int gd = DETECT, gm;
 int i, j, rx, ry;
 initgraph(&gd, &gm, NULL);
 for (i = 0; i < 500; i++) {
 line(20, 380, 580, 380);
 if (i % 2 == 0) {
 line(25 + i, 380, 35 + i, 340);
 line(45 + i, 380, 35 + i, 340);
 line(35 + i, 310, 25 + i, 330);
 delay(20);
 } else {
 line(35 + i, 380, 35 + i, 340);
 line(25 + i, 310, 40 + i, 330);
 delay(20);
 }
 line(35 + i, 340, 35 + i, 310);
 circle(35 + i, 300, 10);
 line(35 + i, 310, 50 + i, 330);
 line(50 + i, 330, 50 + i, 280);
 line(15 + i, 280, 85 + i, 280);
 arc(50 + i, 280, 0, 180, 35);
 arc(55 + i, 330, 0, 180, 5);
 for (j = 0; j < 10; j++) {
 rx = rand() % 580;
 ry = rand() % 380;
 line(rx, ry, rx, ry + 9);
 }
 delay(200);
 cleardevice();
 }
 getch();
 closegraph();
 return 0;
 }