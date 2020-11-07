#include <math.h>

#include <iostream>

#include "LineCircle.h"
#include "svg.h"

#define PI 3.141592
#define WIDTH 640
#define HEIGHT 400
#define R 100

int main() {
    svg svgObj;                // SVGドキュメントを生成するオブジェクト
    float X, Y, radius, x, y;  // 円の描画位置と半径
    int N, circleWidth;
    std::string circleColor;

    std::cout << "Input the number of circles N => ";
    std::cin >> N;
    std::cout << "Input the color of circles => ";
    std::cin >> circleColor;
    std::cout << "Input the width of circles => ";
    std::cin >> circleWidth;

    radius = R * sin(PI / N);

    LineCircle **circ = new LineCircle *[N];  // 動的確保。空の配列の領域を確保。２重ポインタで受け取る。

    svgObj.open("circle.html", WIDTH, HEIGHT);  // ファイルを開く

    for (int k = 0; k < N; k++) {
        circ[k] = new LineCircle();  // クラスのインスタンスの領域を確保して配列に代入

        // X and Y are original coordinate
        X = cos((2.0 * PI / N) * k) * R;
        Y = sin((2.0 * PI / N) * k) * R;

        //turn X and Y into x and y coordinate of the SVG system
        x = X + WIDTH / 2;
        y = HEIGHT / 2 - Y;

        // set position, radius and color for each circle
        circ[k]->setPosition(x, y);  // ポインタなので、-> で参照する！
        circ[k]->setRadius(radius);  // 円の半径の指定
        circ[k]->setColor(circleColor);
        circ[k]->setWidth(circleWidth);

        //draw the circle
        circ[k]->draw(&svgObj);
    }

    svgObj.close();
}
