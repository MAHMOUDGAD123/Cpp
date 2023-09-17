#include <iostream>
#include <vector>
#include <array>

// https://www.youtube.com/watch?v=HcESuwmlHEY&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb&index=47&ab_channel=TheCherno

class Dimention
{
private:
  int X, Y, Z;

public:
  Dimention(int x, int y, int z)
      : X(x), Y(y), Z(z)
  {
    std::cout << "\nConstructed :-(\n";
  }

  Dimention(const Dimention &D)
      : X(D.X), Y(D.Y), Z(D.Z)
  {
    std::cout << "\nCopied :-(\n";
  }

  void Print() const noexcept
  {
    std::cout << *this << std::endl;
  }

  friend std::ostream &operator<<(std::ostream &os, const Dimention &D);
};

std::ostream &operator<<(std::ostream &os, const Dimention &D)
{
  os << "(" << D.X << ", " << D.Y << ", " << D.Z << ")";
  return os;
}

int main()
{
  std::vector<Dimention> Dimentions1;
  std::vector<Dimention> Dimentions2;

  // Request a change in capacity
  // Requests that the vector capacity will be at least enough to contain 3 elements.
  // to avoid resizing & coping data if we add data to vector
  Dimentions1.reserve(3);
  Dimentions2.reserve(3);

  std::cout << "\n\n";

  // this code will construct & copy
  // using push_back() function you need to construct fisrt
  // then copy the constructed object to the heap allocated memory
  // slower
  Dimentions1.push_back({1, 2, 3});
  Dimentions1.push_back({4, 5, 6});
  Dimentions1.push_back({7, 8, 9});

  for (const Dimention &D : Dimentions1)
    D.Print();

  // this code will construct
  // emplace_back() function use the Dimention constructor directly
  // faster
  Dimentions2.emplace_back(1, 2, 3);
  Dimentions2.emplace_back(4, 5, 6);
  Dimentions2.emplace_back(7, 8, 9);

  for (const Dimention &D : Dimentions2)
    D.Print();
}