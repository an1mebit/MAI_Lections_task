#include <iostream>

//Вариант 3 сравнение на равенство ==

using namespace std;
template<typename DataType, std::size_t mx, std::size_t my>
class Image
{
    DataType* img;
    size_t tmx = mx;
    size_t tmy = my;

public:
    Image()
    {
        img = new int[mx * my]();
    }
    virtual ~Image();
    int get(int x, int y);
    int set(int x, int y, int color);
    friend bool operator==(Image& arrInt, Image& arrInt2) { return (arrInt.tmx == arrInt2.tmx && arrInt.tmy == arrInt2.tmy); };
    void show();

};

template<typename DataType, std::size_t mx, std::size_t my>
Image<DataType, mx, my>::~Image()
{
    delete[] img;
}

template<typename DataType, std::size_t mx, std::size_t my>
int Image<DataType, mx, my>::get(int x, int y)
{
    try
    {
 
        if ((mx < x && my < y) || mx < x || my < y)
            throw 101;
    }
    catch (int error)
    {
        cout << "ERROR: " << error << endl;
        exit(-1);
    }

    return img[y * my + x];
}

template<typename DataType, std::size_t mx, std::size_t my>
int Image<DataType, mx, my>::set(int x, int y, int color)
{
    try
    {
        if ((mx <= x && my <= y) || mx <= x || my <= y)
            throw 123;
        if (color > 255 || color < -1)
            throw 111;
    }
    catch (int error)
    {
        cout << "ERROR: " << error << endl;
        exit(-1);
    }

    img[y * my + x] = color;
}

template<typename DataType, std::size_t mx, std::size_t my>
void Image<DataType, mx, my>::show()
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

int main()
{
    Image<int, 8, 8> img1;
    Image<int, 8, 8> img2;
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
