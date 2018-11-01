// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

#include "processCommandLine.hpp"

bool processCommandline(
         const std::vector<std::string>& args,
         bool& helpRequested,
         bool& versionRequested,
         std::string& inputFileName,
         std::string& outputFileName,
         size_t& key,
         bool& encrypt)
{
  typedef std::vector<std::string>::size_type size_type;

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  for (size_type i {1}; i < args.size(); ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
      break;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
      break;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == args.size()-1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return false;
      }
      else {
        // Got filename, so assign value and advance past it
        inputFileName = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == args.size()-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return false;
      }
      else {
        // Got filename, so assign value and advance past it
        outputFileName = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-k") {
      // Handle key option
      // Next element is key unless -k is the last argument
      if (i == args.size()-1) {
        std::cerr << "[error] -k requires an unsigned int argument [0, 25]" << std::endl;
        // exit main with non-zero return to indicate failure
        return false;
      }
      else {
        // Got key, so assign value and advance past it
        key = std::stoul(args[i+1]);
        if(key>25)
        {
            std::cerr << "[error] k is an integer [0, 25]" << std::endl;
            // exit main with non-zero return to indicate failure
            return false;
        }
        ++i;
      }
    }
    else if(args[i] == "--encrypt")
    {
        encrypt = true;
    }
    else if(args[i] == "--decrypt")
    {
        encrypt = false;
    }
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return false;
    }
  }

  return true;
}

