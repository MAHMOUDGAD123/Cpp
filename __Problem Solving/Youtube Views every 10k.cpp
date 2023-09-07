#include <iostream>

using namespace std;


long long YoutubeViewsEvery10K(long long Views)
{
  return (Views / 10000 + 1) * 10000;
}

int main(void)
{

  cout << "\n\n";
  cout << "\n\n-> [1] Next views  = " << YoutubeViewsEvery10K(15000);
  cout << "\n\n-> [1] Next views  = " << YoutubeViewsEvery10K(0);
  cout << "\n\n-> [2] Next views  = " << YoutubeViewsEvery10K(1);
  cout << "\n\n-> [3] Next views  = " << YoutubeViewsEvery10K(123);
  cout << "\n\n-> [4] Next views  = " << YoutubeViewsEvery10K(1234);
  cout << "\n\n-> [5] Next views  = " << YoutubeViewsEvery10K(10000);
  cout << "\n\n-> [6] Next views  = " << YoutubeViewsEvery10K(45616);
  cout << "\n\n-> [7] Next views  = " << YoutubeViewsEvery10K(5164512);
  cout << "\n\n-> [8] Next views  = " << YoutubeViewsEvery10K(5616549561);
  cout << "\n\n-> [9] Next views  = " << YoutubeViewsEvery10K(11498491512);
  cout << "\n\n-> [10] Next views = " << YoutubeViewsEvery10K(100000000000);
  cout << "\n\n\n\n";

  return 0;
}