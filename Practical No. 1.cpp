// Write C++ program to draw a concave polygon and fill it with desired
// color using scan fill algorithm. Apply the concept of inheritance.
 
 #include <iostream>
 #include <graphics.h>
 using namespace std;
 int main()
 {
 int gd = DETECT, gm;
 initgraph(&gd, &gm, NULL);
 setcolor(GREEN);
 int cnt, temp, i, j, n, ymax, ymin, yscan;
 float inter_x[10], m[10], dx, dy;
 int x[10], y[10];
 cout << "Enter the number of vertices of polygon: ";
 cin >> n;
 for (int i = 0; i < n; ++i) {
 cout << "Enter vertex " << i+1 << " of polygon (x, y): ";
 cin >> x[i] >> y[i];
 }
 x[n] = x[0];
 y[n] = y[0];
 for (int i = 0; i < n; ++i) {
 line(x[i], y[i], x[i+1], y[i+1]);
 }
 ymax = 0;
 ymin = 480;
 for (int i = 0; i < n; ++i) {
 if (y[i] > ymax) ymax = y[i];
 if (y[i] < ymin) ymin = y[i];
 }
 for (i = 0; i < n; ++i) {
 dx = x[i+1]- x[i];
 dy =y[i+1]- y[i];
 if (dy == 0) {
 m[i] = 0;
 } else if (dx == 0) {
 m[i] = 1;
 } else {
 m[i] = (float)dx / dy;
 }
 }
 for (yscan = ymax; yscan > ymin; yscan--) {
 cnt = 0;
for (i = 0; i < n; ++i) {
 if ((y[i] > yscan && y[i+1] <= yscan) || (y[i] <= yscan && y[i+1] > yscan)) {
 inter_x[cnt] = x[i] + (yscan- y[i]) * m[i];
 cnt++;
 }
 }
 for (j = 0; j < cnt-1; ++j) {
 for (i = 0; i < cnt-j-1; ++i) {
 if (inter_x[i] > inter_x[i+1]) {
 temp =inter_x[i];
 inter_x[i] = inter_x[i+1];
 inter_x[i+1] = temp;
 }
 }
 }
 for (j = 0; j < cnt-1; j += 2) {
 line(inter_x[j], yscan, inter_x[j+1], yscan);
 }
 delay(100);
 }
 getch();
 closegraph();
 return 0;
 }