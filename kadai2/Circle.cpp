#include "Circle.h"


Circle::Circle () { // 引数を指定しない構築子 
    x = y = 0; rad = 10;
} 

Circle::Circle (int cx, int cy, int r) {  // 引数を指定する構築子
    x = cx; y = cy; rad = r; 
}

void Circle::setPosition (int x, int y) { 
    this->x = x; this->y = y; // this->x はメンバ変数の x であり，引数 x とは異なる変数！
}

void Circle::setRadius (int rad) { 
    this->rad = rad; // this->rad と rad は異なる変数！
}

int Circle::getRadius () {
    return rad;
}

void Circle::draw (svg* svgObj) { // 円の描画関数（svg オブジェクトのポインタを受け取る）
    svgObj->drawCircle(x, y, rad); // 中心 (x,y)、半径 r の円の輪郭描画（SVG形式）
}


void Circle::getPosition(int xy[]) {
  xy[0] = this->x;
  xy[1] = this->y;
}
