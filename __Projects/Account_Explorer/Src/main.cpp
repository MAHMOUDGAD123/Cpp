#pragma warning(disable : 4996)

#include "../Headers/Account.h"
#include "../Screens/Account_Explorer.h"

int main(int argc, char *argv[])
{
  while (1)
    AccountExplorer::Run();

  return 0;
}
