#include <stdio.h>

class Circle { 
    private:
        int x, y;
        int rad;

    public:
        Circle (); 
        Circle (int cx, int cy, int r = 10);
        void setPosition (int x, int y);
        void setRadius (int rad);
        int getRadius ();
        void draw ();
        
        void getPosition(int xy[]);
        
};
