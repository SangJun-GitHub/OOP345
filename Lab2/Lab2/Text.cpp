/**********************************
| Subject        : Workshop 2     |
| Name           : Sang Jun Park  |
| Student number : 112293170      |
| Date           : 2018.6.1       |
**********************************/
#include <iostream>
#include <fstream>
#include <string>
#include "Text.h"

namespace sict 
{
   Text::Text() : lineNumber(0), lineContent(nullptr) 
   {}

   Text::Text(char* fileName) : lineNumber(0), lineContent(nullptr) 
   {
      fstream file(fileName, ios::in);
      if (file.is_open()) 
      {
         string line;
         while (getline(file, line))
            lineNumber++;
         file.clear();
         file.seekp(0);
         lineContent = new string[lineNumber];
         for (size_t i = 0; i < lineNumber; i++) 
         {
            getline(file, lineContent[i]);
            auto fr = lineContent[i].find('\r');
            if (fr != string::npos)
               lineContent[i].erase(fr, 1);
         }
         file.close();
      }else{
         cerr << "Fail to open '" << fileName << "'\n";
         exit(1);
      }
   }

   Text::Text(const Text& text) : lineNumber(0), lineContent(nullptr)
   {
      *this = text;
   }

   Text& Text::operator=(const Text& text) 
   {
      if (this != &text)
      {
         delete[] lineContent;
         lineNumber = text.lineNumber;
         lineContent = new string[lineNumber];
         for (size_t i = 0; i < lineNumber; i++)
            lineContent[i] = text.lineContent[i];
      }
      return *this;
   }

   Text::Text(Text&& text): lineNumber(0), lineContent(nullptr)
   {
      *this = move(text);
   }

   Text& Text::operator=(Text&& text) 
   {
      if (this != &text) 
      {
         lineNumber = text.lineNumber;
         delete[] lineContent;
         lineContent = text.lineContent;
         text.lineContent = nullptr;
         text.lineNumber = 0;
      }
      return *this;
   }

   Text::~Text() 
   {
      delete[] lineContent;
   }

   size_t Text::size() const 
   {
      return lineNumber;
   }
}