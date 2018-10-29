// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

#include "TransformChar.hpp"

std::string transformChar(const char in_char)
{
    // Uppercase alphabetic characters
    if (std::isalpha(in_char))
    {
      std::string tmp_string;
      tmp_string += std::toupper(in_char);
      return tmp_string;
    }

    // Transliterate digits to English words
    switch (in_char) {
      case '0':
        return("ZERO");
        break;
      case '1':
        return("ONE");
        break;
      case '2':
        return("TWO");
        break;
      case '3':
        return("THREE");
        break;
      case '4':
        return("FOUR");
        break;
      case '5':
        return("FIVE");
        break;
      case '6':
        return("SIX");
        break;
      case '7':
        return("SEVEN");
        break;
      case '8':
        return("EIGHT");
        break;
      case '9':
        return("NINE");
        break;
    }

    // If the character isn't alphabetic or numeric, DONT add it.
    // Our ciphers can only operate on alphabetic characters.
    return "";
}
  
