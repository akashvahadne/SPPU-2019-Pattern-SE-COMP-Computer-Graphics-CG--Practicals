//  Write OpenGL program to draw Sun Rise and Sunset..
 
 #include <iostream>
 #include <graphics.h>
 #include <cstdlib>
 #include <dos.h>
 #include <cmath>
 using namespace std;
 #define ORANGE 14
 int main()
 {
 int gdriver = DETECT, gmode;
 initgraph(&gdriver, &gmode, "");
 int errorcode = graphresult();
 if (errorcode != grOk)
 {
 cout << "Graphics error: " << grapherrormsg(errorcode) << endl;
 cout << "Press any key to halt";
 exit(1);
 }
 int i, j;
 setbkcolor(BLUE);
 setcolor(RED);
 rectangle(0, 0, getmaxx(), getmaxy());
 outtextxy(250, 240, "::::PRESS ANY KEY TO CONTINUE:::::");
 while (!kbhit());
 for (i = 50, j = 0; i <= 250 && j <= 250; i += 5, j += 5)
 {
 delay(120);
 cleardevice();
 if (i <= 150)
 {
 setcolor(YELLOW);
 setfillstyle(SOLID_FILL, YELLOW);
 fillellipse(i, 300- j, 20, 20);
 }
 else
 {
 setcolor(ORANGE);
 setfillstyle(SOLID_FILL, ORANGE);
 fillellipse(i, 300- j, 20, 20);
 }
 }
 delay(1000);
 cleardevice();
 setcolor(RED);
setfillstyle(SOLID_FILL, RED);
 fillellipse(300, 50, 20, 20);
 delay(150);
 int k, l;
 for (k = 305, l = 55; k <= 550 && l <= 300; k += 5, l += 5)
 {
 delay(120);
 cleardevice();
 if (k <= 450)
 {
 setcolor(ORANGE);
 setfillstyle(SOLID_FILL, ORANGE);
 fillellipse(k, l, 20, 20);
 }
 else
 {
 setcolor(YELLOW);
 setfillstyle(SOLID_FILL, YELLOW);
 fillellipse(k, l, 20, 20);
 }
 }
 getch();
 closegraph();
 return 0;
 }