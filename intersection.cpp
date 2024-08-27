#include <iostream>
using namespace std;

struct Rectangle {
    int x, y, w, h;
};

bool isOverlapping(Rectangle rec1, Rectangle rec2) {
    if (rec1.x + rec1.w < rec2.x || rec2.x + rec2.w < rec1.x) {
        return false;
    }
    if (rec1.y + rec1.h < rec2.y || rec2.y + rec2.h < rec1.y) {
        return false;
    }
    return true;
}

int main() {
    Rectangle rec1 = {1, 1, 3, 3};
    Rectangle rec2 = {2, 2, 2, 2};

    if (isOverlapping(rec1, rec2)) {
        cout << "Rectangles overlap" << endl;
    } else {
        cout << "Rectangles do not overlap" << endl;
    }

    return 0;
}
