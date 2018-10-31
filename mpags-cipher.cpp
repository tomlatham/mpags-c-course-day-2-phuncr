// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "TransformChar.hpp"
#include "processCommandLine.hpp"
#include "runCaesarCipher.hpp"

// For std::isalpha and std::isupper
#include <cctype>

// Parsing command line arguments

bool processCommandline(
         const std::vector<std::string>& args,
         bool& helpRequested,
         bool& versionRequested,
         std::string& inputFileName,
         std::string& outputFileName);

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Add a typedef that assigns another name for the given type for clarity
//  typedef std::vector<std::string>::size_type size_type;
//  const size_type nCmdLineArgs {cmdLineArgs.size()};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool flag{true};
  std::string inputFile {""};
  std::string outputFile {""};
  size_t key{5};
  bool encrypt{true};

  // Parsing command line arguments

  flag = processCommandline(cmdLineArgs, helpRequested, versionRequested,
                          inputFile, outputFile, key, encrypt);

  if(!flag) return 1;

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // Read in user input from stdin/file
  if (!inputFile.empty()) 
  {
      std::ifstream in_file {inputFile};
      if(!in_file.good())
      {
          std::cout << "Failure to open input file" << std::endl;
          return(1);
      }
      while(in_file >> inputChar)
      {
          inputText += transformChar(inputChar);
      }
      in_file.close();
  }
  else
  {
      // Loop over each character from user input
      // (until Return then CTRL-D (EOF) pressed)
      while(std::cin >> inputChar)
      {
          inputText += transformChar(inputChar);
      }
   }

  /* Run CaesarCipher */

  inputText = runCaesarCipher(inputText, key, encrypt);

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFile.empty())
  {
      std::ofstream out_file {outputFile};
      if(!out_file.good())
      {
          std::cout << "Failure to open output file" << std::endl;
          return(1);
      }
      out_file << inputText;
      out_file.close();
  }
  else
  {
      std::cout << std::endl;
      std::cout << inputText << std::endl;
  }

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
