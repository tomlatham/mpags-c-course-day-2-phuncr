// Standard Library includes
#include <string>
#include <iostream>
#include <vector>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText,
                             const size_t key, const bool encrypt)
{
    const std::string alphabeta {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; 
    const size_t alphabetSize {alphabeta.size()};

    std::string outputText {""};

    const int shift { encrypt ? 1 : -1 };

    // Make sure that the key is in the range 0 - 25
    const size_t tKey { key % alphabetSize };

    for( const char& inputChar : inputText )
    {
        for(size_t j=0; j<alphabetSize; j++)
        {
           if(inputChar==alphabeta[j])
           {
               outputText += alphabeta[(j+alphabetSize+shift*tKey)%(alphabetSize)];
               break;
           }
        }
    }
    
    return outputText;
}
