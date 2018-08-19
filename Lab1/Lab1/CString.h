/**********************************
| Subject        : Workshop 1     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.5.11      |
**********************************/
#include <iostream>

namespace w1
{
   const int MAX = 3;
   class CString 
   {
      char m_string[MAX + 1];
   public:
      CString(char* string);
      void display(std::ostream& out)const;
   };
   std::ostream& operator<<(std::ostream& out, const CString& string);
}
