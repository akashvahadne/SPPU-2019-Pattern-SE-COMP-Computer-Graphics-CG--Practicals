//  Write C++ program to draw 2-D object or equilateral triangle and rhombus
// and perform following basic transformations, Scaling a)Translation c) Rotation. Apply the
// concept of operator overloading.
 
 #include <iostream>
 #include <graphics.h>
 #include <math.h>
 using namespace std;
 class trans {
 public:
 float transco[3][3];
 float scalco[3][3];
 float rotco[3][3];
 void drawtri(float [3][3]);
 // Function to draw the triangle
 void translation(int, int, float [3][3]); // Translation function
 void scaling(float, float, float [3][3]); // Scaling function
 void rotation(float, float [3][3]);
 };
 // Rotation function
 void trans::drawtri(float co[3][3]) {
 line(co[0][0], co[1][0], co[0][1], co[1][1]);
 line(co[0][1], co[1][1], co[0][2], co[1][2]);
 line(co[0][2], co[1][2], co[0][0], co[1][0]);
 }
 void trans::translation(int tx, int ty, float orico[3][3]) {
 cin >> tx >> ty;
 for (int i = 0; i < 3; i++) {
 transco[0][i] = orico[0][i] + tx;
 transco[1][i] = orico[1][i] + ty;
 transco[2][i] = 1;
 }
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 cout << transco[i][j] << " ";
 }
 cout << endl;
 }
 }
 void trans::scaling(float sx, float sy, float orico[3][3]) {
 cin >> sx >> sy;
 for (int i = 0; i < 3; i++) {
 scalco[0][i] = orico[0][i] * sx;
 scalco[1][i] = orico[1][i] * sy;
 scalco[2][i] = 1;
 }
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 cout << scalco[i][j] << " ";
 }
 cout << endl;
 }
}
 void trans::rotation(float theta, float orico[3][3]) {
 cin >> theta;
 theta = theta * (M_PI / 180);
 for (int i = 0; i < 3; i++) {
 rotco[0][i] = orico[0][i] * cos(theta)- orico[1][i] * sin(theta);
 rotco[1][i] = orico[0][i] * sin(theta) + orico[1][i] * cos(theta);
 rotco[2][i] = 1;
 }
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 cout << rotco[i][j] << " ";
 }
 cout << endl;
 }
 }
 int main() {
 initwindow(800, 800);
 trans t;
 int tx, ty;
 float sx, sy, theta;
 float orico[3][3] = {{300, 250, 350}, {200, 300, 300}, {1, 1, 1}};
 for (int i = 0; i < 3; i++) {
 for (int j = 0; j < 3; j++) {
 cout << "ori " << i << " " << j << "-> " << orico[i][j] << " ";
 }
 cout << endl;
 }
 t.drawtri(orico);
 int c;
 cout << "Enter your choice:\n";
 cout << "1. Translation\n";
 cout << "2. Scaling\n";
 cout << "3. Rotation\n";
 cin >> c;
 switch (c) {
 case 1:
 t.translation(tx, ty, orico);
 t.drawtri(t.transco);
 break;
 case 2:
 t.scaling(sx, sy, orico);
 t.drawtri(t.scalco);
 break;
 case 3:
 t.rotation(theta, orico);
 t.drawtri(t.rotco);
 break;
default:
 cout << "Invalid choice.";
 break;
 }
 getch();
 closegraph();
 return 0;
 }