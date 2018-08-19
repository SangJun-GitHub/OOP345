/**********************************
| Subject        : Workshop 2     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.6.1       |
**********************************/
#include <iostream>
#include <string>

using namespace std;

namespace sict {
   class Text {
      unsigned int lineNumber;
      string* lineContent;

   public:
      Text();
      Text(char* fileName);
      Text(const Text& text);
      Text& operator=(const Text& text);
      Text(Text&& text);
      Text& operator=(Text&& text);
      ~Text();
      size_t size() const;
   };
}