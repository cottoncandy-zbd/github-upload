#include <math.h>

#include <iostream>

#include "LineCircle.h"
#include "svg.h"

#define PI 3.141592
#define WIDTH 640
#define HEIGHT 400
#define R 100

int main(int argc, char *argv[]) {
    svg svgObj;                   // Object for generating SVG document
    int numCircles, strokeWidth;  // 円の個数と半径

    float X, Y, r, x, y;  // 円の描画位置と半径

    std::string circleColor, lineColor;  // 円の描画色（配置／環状円）
    ColorCircle **c_circles;             // 配置円
    LineCircle *l_circles[2];            // 環状円

    // *******************************************
    // take in arguments
    if (argc < 4) {
        std::cout << "Lack of Arguments !";
        return 0;
    }
    numCircles = atoi(argv[1]);
    circleColor = argv[2];
    lineColor = argv[3];
    strokeWidth = atoi(argv[4]);

    // *******************************************
    // Create and draw outline and inline circles

    r = R * sin(PI / numCircles);  // radius of small color circles

    svgObj.open("circle.html", WIDTH, HEIGHT);  // ファイルを開く

    l_circles[0] = new LineCircle(WIDTH / 2, HEIGHT / 2, 100 + r, lineColor, strokeWidth);
    l_circles[1] = new LineCircle(WIDTH / 2, HEIGHT / 2, 100 - r, lineColor, strokeWidth);

    //draw the circle
    l_circles[0]->draw(&svgObj);
    l_circles[1]->draw(&svgObj);

    // *******************************************
    // Create and draw small color circles

    c_circles = new ColorCircle *[numCircles];

    for (int k = 0; k < numCircles; k++) {
        // X and Y are original coordinate
        X = cos((2.0 * PI / numCircles) * k) * R;
        Y = sin((2.0 * PI / numCircles) * k) * R;

        //turn X and Y into x and y coordinate of the SVG system
        x = X + WIDTH / 2;
        y = HEIGHT / 2 - Y;

        // set position, radius and color for each circle
        c_circles[k] = new ColorCircle(x, y, r, circleColor);

        //draw the circle
        c_circles[k]->draw(&svgObj);
    }

    svgObj.close();

    return (1);
}