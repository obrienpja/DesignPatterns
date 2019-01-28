#include <iostream>

using namespace std;

struct Square
{
    int side{ 0 };


    explicit Square(const int side)
            : side(side)
    {
    }
};

struct Rectangle
{
    virtual int width() const = 0;
    virtual int height() const = 0;

    int area() const
    {
        return width() * height();
    }
};

struct SquareToRectangleAdapter : Rectangle
{
    SquareToRectangleAdapter(const Square& square)
    {
        wid = square.side;
        hei = square.side;
    }

    virtual int width() const override { return wid; }
    virtual int height() const override { return hei; }

    int wid, hei;


};

int main()
{
    const int sq_side = 5;

    Square sq{sq_side};

    SquareToRectangleAdapter sq_to_rect{sq};

    cout << sq_to_rect.width() << endl;
    cout << sq_to_rect.height() << endl;

    return 0;
}
