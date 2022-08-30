#ifndef FILEPARSER_H_
#define FILEPARSER_H_

#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>
#include "CommonDefines.h"
#include "FunctionTracer.h"

namespace {
void clearValues(std::string &line, std::istringstream &istr) {
  line.clear();
  istr.clear();
  istr.str("");
}
}

template <typename T>
class FileParser {
public:
  FileParser() = delete;

  static int32_t generateData(std::vector<T> &outInputData, std::vector<T> &outOutputData) {

    FunctionTracer<std::chrono::milliseconds> tracer("generateData", "ms //not included into solution timings");	//will basically print out how many time elapsed between

    constexpr auto inputFile = "input.bin";
    int32_t err = FileParser<T>::parseFile(inputFile, outInputData);
    if (EXIT_SUCCESS != err) {
      std::cerr << "FileParser::parseFile() failed for file: " << inputFile
                << std::endl;
      return EXIT_FAILURE;
    }

    constexpr auto outputFile = "output.bin";		//the name of the file

    err = FileParser<T>::parseFile(outputFile, outOutputData);	//calling the function down bellow

    if (EXIT_SUCCESS != err) {
      std::cerr << "FileWritter::generateFile() failed for file: " << inputFile << std::endl;
      return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
  }

  static int32_t parseFile(const std::string &fileLocation, std::vector<T> &outData) {

    std::ifstream ifstream(fileLocation, std::ios::in | std::ios::binary);	//reading the file

    if (!ifstream) {
      std::cout << "Error, could not load file: " << fileLocation << std::endl;
      return EXIT_FAILURE;
    }

    std::string line;
    std::getline(ifstream, line);	//read first line
    std::istringstream istr(line);	//put it in the string

    int32_t itemsCount = 0;
    istr >> itemsCount;		//we need the first number as an integer cuz it will set the number of objects in the vector

    outData.reserve(itemsCount);	//lenghted the vector with the needed size

    clearValues(line, istr);	//a function to clear the stream and string

    Resolution res;
    for (int32_t i = 0; i < itemsCount; ++i) {
      std::getline(ifstream, line);
      istr.str(line);

      //parse resolution
      istr >> res.width >> res.height;
      clearValues(line, istr);

      //create item
      T &item = outData.emplace_back(res);

      std::getline(ifstream, line);
      istr.str(line);

      //fill item data
      istr >> item;

      clearValues(line, istr);
    }

    return EXIT_SUCCESS;
  }
};

#endif /* FILEPARSER_H_ */
