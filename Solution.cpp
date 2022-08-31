//Coresponding Header
#include "Solution.h"

//C system includes


//C++ system includes
#include <cstdint>
#include <iostream>


//3rd-party includes


//Own includes
#include "utils/CommonDefines.h"


void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
	FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
	//TODO: fill solution

	constexpr uint8_t limitRedData = 200;
	constexpr uint8_t maximumBrightness = 255;
	uint counter = 0;
	for(auto &image : images){
		std::cout  << "Nomer na image " << counter << std::endl;
		counter++;
		for(auto &pixelData : image.pixels){

			uint8_t& redDataOriginal = pixelData.red;
			uint8_t& blueDataOriginal = pixelData.blue;
			uint8_t& greenDataOriginal = pixelData.green;
			//uint8_t& alphaDataOriginal = pixelData.alpha;


			if(redDataOriginal >= limitRedData ){

					if(redDataOriginal == maximumBrightness ){
							std::cout << "Nameren !!!  RED " << static_cast<int>(pixelData.red) << "  BLUE " <<
									static_cast<int>(pixelData.blue) << "  GREEN " << static_cast<int>(pixelData.green) << "  ALPHA " << static_cast<int>(pixelData.alpha)  <<  std::endl;
							if( blueDataOriginal == maximumBrightness && greenDataOriginal == maximumBrightness){		//we have a maximumbrightness (white pixel)
							continue;
						}
					}

				pixelData.red -= 150;
				std::cout  << static_cast<int>(pixelData.red) << std::endl;
			}
		}
	}

}



void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
	FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
	//TODO: fill solution



}
