#include "LineCircle.h"

LineCircle::LineCircle() : ColorCircle() {  // 構築子
    strokeWidth = 0;
}

LineCircle::LineCircle(int cx, int cy, int r, std::string c, int width) : ColorCircle(cx, cy, r, c) {  // 属性を指定する構築子
    strokeWidth = width;
}

void LineCircle::draw(svg* svgObj) {  // Circle クラスの draw () を上書き（オーバーライド）する
    svgObj->drawCircle(x, y, rad, color, strokeWidth);
}

void LineCircle::setWidth(int width) {
    strokeWidth = width;
}