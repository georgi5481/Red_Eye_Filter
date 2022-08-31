//C++ includes:
#include <vector>
#include <iostream>
#include <cstdint>

//own includes
#include "utils/FileParser.h"
#include "utils/Image.h"
#include "utils/SolutionEvaluator.h"
#include "Solution.h"



int32_t main([[maybe_unused]]int32_t argc, [[maybe_unused]]char *argv[]) {
  //Use the provided implementation that best suits your needs
	using Image = PackedImage;
  //using Image = StrideImage;

  std::vector<Image> inputImages;
  std::vector<Image> outputImages;

  int32_t err = FileParser<Image>::generateData(inputImages, outputImages);	//gives the whole image

  if (EXIT_SUCCESS != err) {							//checks for errors
    std::cerr << "FileParser::generateData() failed" << std::endl;
    return EXIT_FAILURE;
  }

  Solution solution;			//our solution is made as an object
  solution.compute(inputImages);		//we call our compute method we implemented and give the input image

  err = SolutionEvaluator<Image>::compare(inputImages, outputImages);			//method for printing the images and compairing them by the process

  if (EXIT_SUCCESS != err) {		//checks for a missmatch at the method upwards
    std::cout << "Solution status - [FAIL]" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Solution status - [SUCCESS]" << std::endl;
  return EXIT_SUCCESS;
}

