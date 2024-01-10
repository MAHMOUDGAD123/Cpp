#include <iostream>
#include <fstream>
#include <string>

/* Explorer function */
static void explore()
{
  std::ifstream is("Websites.txt");
  std::string site;

  if (is)
  {
    while (std::getline(is, site))
      system(site.c_str());

    is.close();
  }

  return;
}

/* Main Function */
int main(int argc, char *argv[])
{
  explore();

  return 0;
}
