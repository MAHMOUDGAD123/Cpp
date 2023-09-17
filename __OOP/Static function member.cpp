#include <iostream>

// https://www.geeksforgeeks.org/static-member-function-in-cpp/?ref=gcse
// https://www.geeksforgeeks.org/static-keyword-cpp/?ref=gcse

using namespace std;

class clsBox
{
private:
  static int _Width;
  static int _Height;
  static int _Wide;

public:
  static void New_Dimentions(int Width, int Height, int Wide)
  {
    _Width = Width;
    _Height = Height;
    _Wide = Wide;
  }

  int getBoxSize()
  {
    return _Width * _Height * _Wide;
  }
};

// initialize dimentions
int clsBox::_Width = 0; 
int clsBox::_Height = 0; 
int clsBox::_Wide = 0; 




int main(void)
{
  // put new dimention before make Boxes (before create objects)
  clsBox::New_Dimentions(10, 10, 10);

  clsBox Box1, Box2;

  cout << "\n\n- Box1 Size = ";
  cout << Box1.getBoxSize() << endl;

  cout << "- Box2 Size = ";
  cout << 2 * Box2.getBoxSize() << endl; // size = 2 * Box1_size

  return 0;
}