//Coresponding Header
#include "Solution.h"

//C system includes


//C++ system includes
//#include <cstdint>
//#include <iostream>


//3rd-party includes


//Own includes
#include "utils/CommonDefines.h"


void Solution::compute([[maybe_unused]]std::vector<PackedImage> &images) {
	FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
	//TODO: fill solution

	for(auto &image : images){
		pixelRedEyeFilter(image.pixels);
	}

}


void Solution::compute([[maybe_unused]]std::vector<StrideImage> &images) {
	FunctionTracer<std::chrono::milliseconds> tracer("compute", "ms");
	//TODO: fill solution
	//no need for this one
}




inline void Solution::pixelRedEyeFilter(std::vector<Pixel>& pixels){

	for(auto &pixelData : pixels){

		if(pixelData.red >= 200 ){
			pixelData.red -= 150;
		}
	}
}

