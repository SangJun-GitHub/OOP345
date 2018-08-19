/**********************************
| Subject        : Workshop 1     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.5.11      |
**********************************/
#include <iostream>
#include "CString.h"

int STORED = w1::MAX;

namespace w1
{
   CString::CString(char* string)
   {
      if (string[0] == '\0') 
      {
         m_string[0] = '\0';
      }else{
         for (int i = 0; i < MAX; i++) 
         {
            m_string[i] = string[i];
         }
         m_string[MAX] = '\0';
      }
   }
   void CString::display(std::ostream& out)const 
   {
      out << m_string;
   }
   std::ostream& operator<<(std::ostream& out, const CString& string)
   {
      static int num = 0;
      out << num << ": ";
      string.display(out);
      num++;
      return out;
   }
}