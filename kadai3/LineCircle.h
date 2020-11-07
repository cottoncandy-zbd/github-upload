#include "ColorCircle.h"

class LineCircle : public ColorCircle {
   private:
    int strokeWidth;  // stroke width (line width)
   public:
    LineCircle();                                                 // 構築子
    LineCircle(int cx, int cy, int r, std::string c, int width);  // 違う形式の構築子

    void draw(svg* svgObj);    // Circle クラスの draw () を上書き（オーバーライド）する
    void setWidth(int width);  // 色の設定
};