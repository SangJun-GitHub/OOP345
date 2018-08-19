/**********************************
| Subject        : Workshop 1     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.5.11      |
**********************************/
#include <iostream>
#include "process.h"
using namespace std;

int main(int argc, char *argv[]) 
{
   extern int STORED;
   cout << "Command Line :";
   for (int i = 0; i < argc; i++)
   {
      cout << " " << argv[i];
   }
   cout << endl;
   if (argc <= 1)
   {
      cout << "Insufficient number of arguments (min 1)" << endl;
      return 1;
   }
   else {
      cout << "Maximum number of characters stored : " << STORED << endl;
      for (int i = 1; i < argc; i++)
      {
         process(argv[i]);
      }
      return 0;
   }
}
