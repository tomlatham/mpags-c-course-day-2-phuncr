// Standard Library includes
#include <string>
#include <iostream>
#include <vector>

#include "runCaesarCipher.hpp"

std::string runCaesarCipher( const std::string& inputText,
                             const size_t key, const bool encrypt)
{
    std::string alphabeta {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"}; 
    std::string outputText {""};
    int shift {1};
    int newl {0};

    if(!encrypt) shift = -1;

    for(size_t i=0; i<inputText.size(); i++)
    {
        for(size_t j=0; j<alphabeta.size(); j++)
        {
           if(inputText[i]==alphabeta[j])
           {
               newl = j + shift*key;
               while(newl<0) newl += alphabeta.size();
               outputText += alphabeta[(newl)%(alphabeta.size())];
               break;
           }
        }
    }
    
    return outputText;
}
