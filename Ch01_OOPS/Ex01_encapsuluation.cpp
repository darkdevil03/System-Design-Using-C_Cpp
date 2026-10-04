#include <iostream>

using namespace std;

class AreaOfRectangle {
    private:
    int width;
    int height;

    public:
    int x =10;
    AreaOfRectangle() {
        // Default Area of Rectangle
        width = 2;
        height = 1;
    }

    void setValues(int width, int height) {
        this->width = width ;
        this->height = height ;
    }

    int getArea() {
        return width * height ;
    }
};


int main() {
    AreaOfRectangle *rect = new AreaOfRectangle();

    cout << "X : "<< rect->x << endl;

    rect->setValues(10, 20);
    cout << "Area of rectangle : " << rect->getArea() << endl;

    free(rect);

    return EXIT_SUCCESS;
}
