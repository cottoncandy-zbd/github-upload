#include <iostream>
#include "Circle.h"
#include <math.h>

#define PI 3.141592
#define WIDTH 640
#define HEIGHT 400
#define R 100

int main() {
  svg svgObj;               // SVGドキュメントを生成するオブジェクト
  float X, Y, radius, x, y; // 円の描画位置と半径
  int N;

  std::cout << "Input the number of circle N => ";
  std::cin >> N;

  radius = R * sin(PI / N);

  Circle **circ = new Circle *[N]; // 動的確保。空の配列の領域を確保。２重ポインタで受け取る。

  svgObj.open("circle.html", WIDTH, HEIGHT); // ファイルを開く

  for (int k = 0; k < N; k++)
  {
    circ[k] = new Circle(); // クラスのインスタンスの領域を確保して配列に代入

    // X and Y are original coordinate
    X = cos((2.0 * PI / N) * k) * R;
    Y = sin((2.0 * PI / N) * k) * R;

    // std::cout << "X = " << X << " and Y= " << Y << '\n';

    //turn X and Y into x and y coordinate of the SVG system
    x = X + WIDTH / 2;
    y = HEIGHT / 2 - Y;

    circ[k]->setPosition(x, y); // ポインタなので、-> で参照する！
    circ[k]->setRadius(radius); // 円の半径の指定

    //draw the circle
    circ[k]->draw(&svgObj);
  }

  svgObj.close();
}
