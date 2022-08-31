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

	for(auto &image : images){
		for(auto &pixelData : image.pixels){

			uint8_t& redDataOriginal = pixelData.red;

			if(redDataOriginal > limitRedData){
				redDataOriginal -= 150;
			}
		}
	}

}



void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
	FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
	//TODO: fill solution



}
