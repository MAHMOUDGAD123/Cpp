#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> towerBuilder(size_t nfloors)
{
  std::vector<std::string> tower;
  tower.reserve(nfloors);
  uint32_t base_size = 2 * nfloors - 1;
  int32_t spaces((base_size - 1) / 2);

  for (uint32_t i(0), stars(1); i < nfloors; i++, stars += 2)
  {
    std::string sp(spaces--, ' ');
    tower.emplace_back(sp + std::string(stars, '*') + sp);
  }
  return tower;
}

int main()
{
  std::vector<std::string> tower = towerBuilder(1);

  for (const std::string &S : tower)
    std::cout << S << "\n";
}