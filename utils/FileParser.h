#ifndef FILEPARSER_H_
#define FILEPARSER_H_
//C++ headers
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <chrono>

//Own includes
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

    constexpr auto inputFile = "input.bin";							//path and name of the file
    int32_t err = FileParser<T>::parseFile(inputFile, outInputData);
    if (EXIT_SUCCESS != err) {
      std::cerr << "FileParser::parseFile() failed for file: " << inputFile
                << std::endl;
      return EXIT_FAILURE;
    }

    constexpr auto outputFile = "output.bin";		//name of the output file

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
    std::istringstream istr(line);	//put it in the string - we will use it again and again

    int32_t itemsCount = 0;
    istr >> itemsCount;		//we need the first number as an integer cuz it will set the number of objects in the vector

    outData.reserve(itemsCount);	//lenghted the vector with the needed size

    clearValues(line, istr);	//a function to clear the stream and string

    Resolution res;		//create an object to set the width and height of the image
    for (int32_t i = 0; i < itemsCount; ++i) {
      std::getline(ifstream, line);
      istr.str(line);		//read the line with the resolution

      //parse resolution
      istr >> res.width >> res.height;		//input it
      clearValues(line, istr);			//clear again the stream

      //create item
      T &item = outData.emplace_back(res);	//put the object with the resolution

      std::getline(ifstream, line);		//will get all the data with the pixels till the new two integers for the next pixels
      istr.str(line);		//fill the stream with the same information

      //fill item data
      istr >> item;		//place the info into the object

      clearValues(line, istr);		//empty the stream and string
    }

    return EXIT_SUCCESS;
  }
};

#endif /* FILEPARSER_H_ */
