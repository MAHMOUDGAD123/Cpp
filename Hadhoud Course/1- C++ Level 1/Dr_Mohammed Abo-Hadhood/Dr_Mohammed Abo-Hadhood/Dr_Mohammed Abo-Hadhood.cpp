
#include <iostream>
#include <string>
#include <chrono>
#include <thread>

using namespace std;

using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;


int main()
{
        

    

        for (;;)
        {

            string choice;
            cout << " One-choice Question : \n\n";
            cout << " *********************************************************" << endl;
            cout << " ***********                                  ************" << endl;
            cout << " **      1- Mohammed Abu-Hadhoud course    2- CS50      **" << endl;
            cout << " ***********                                  ************" << endl;
            cout << " *********************************************************" << endl;
            cout << " just enter (1 or 2)\n\n";
            cout << " What is your Choice : ";
            cin >> choice;
            cout << "\n";
        
            if (choice == "1" || choice == "2")
            {

                if (choice == "1")
                {

                    cout << " *******************************************************************" << endl;
                    cout << " *******************************************************************" << endl;
                    cout << " *******                                                      ******" << endl;
                    cout << " ******* Great Choice you are going to be a great Programmer. ******" << endl;
                    cout << " *******                                                      ******" << endl;
                    cout << " *******************************************************************" << endl;
                    cout << " *******************************************************************" << endl;
                    sleep_for(5s);


 
                }
                
                else if(choice == "2")
                {

                    for (;;)
                    {
                        cout << " ********************" << endl;
                        cout << " *      Looser!     *" << endl;
                        cout << " ********************" << endl;
                        sleep_for(0.5s);
                    }
                    
                   
                }


            }



        }

        
           
                

         

           
}
