#include <iostream>

//Вариант 3 сравнение на равенство ==

using namespace std;
class Image
{
    int* img;
    int mx;
    int my;
public:
    Image(int tmx, int tmy) :mx(tmx), my(tmy)
    {
        img = new int[mx * my]();
    }
    virtual ~Image();
    int get(int x, int y);
    int set(int x, int y, int color);
    friend bool operator==(Image& arrInt, Image& arrInt2);
    void show();

};

Image::~Image()
{
    delete[] img;
}

int Image::get(int x, int y)
{
    try
    {
        if (mx*my < y*my + x)
            throw 132;
        if ((mx < x && my < y) || mx < x || my < y)
            throw 101;
    }
    catch (int error)
    {
        cout << "ERROR: " << error << endl;
        exit(-1);
    }

    return img[y*my+x];
}

int Image::set(int x, int y, int color)
{
    try
    {
        if (mx * my < y*my + x)
            throw 123;
        if (color > 255 || color < -1)
            throw 111;
    }
    catch (int error)
    {
        cout << "ERROR: " << error << endl;
        exit(-1);
    }

    img[y*my+x] = color;
}

void Image::show()
{
    for (int i = 0; i < my; i++)
    {
        for (int j = 0; j < mx; j++)
        {
            cout << img[i * mx + j] << " ";
        }
        cout << endl;
    }
}

bool operator==(Image& arrInt, Image& arrInt2)
{
    return (arrInt.mx == arrInt2.mx && arrInt.my == arrInt2.my);
}

int main()
{
    Image img1(8, 8);
    Image img2(8, 8);
    if (img1 == img2)
        cout << "The Images have the same format" << endl;
    
    img1.set(4, 4, 245);
    img2.set(3, 3, 124);

    img1.get(4, 4);
    img2.get(3, 3);

    img1.show();
    cout << endl;
    img2.show();

    return 0;
}
