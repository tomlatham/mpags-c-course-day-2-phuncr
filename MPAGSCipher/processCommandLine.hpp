#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP


#include <string>

// Parsing command line arguments

bool processCommandline(
         const std::vector<std::string>& args,
         bool& helpRequested,
         bool& versionRequested,
         std::string& inputFileName,
         std::string& outputFileName);


#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

