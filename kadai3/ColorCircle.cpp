#include "ColorCircle.h"

ColorCircle::ColorCircle() : Circle() {  // 構築子
    color = "black";
}

ColorCircle::ColorCircle(int cx, int cy, int r, std::string c) : Circle(cx, cy, r) {  // 属性を指定する構築子
    color = c;
}

void ColorCircle::draw(svg* svgObj) {  // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(x, y, rad, color);
}

void ColorCircle::setColor(std::string c) {  // 色の設定
    color = c;
}