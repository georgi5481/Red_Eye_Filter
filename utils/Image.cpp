//Corresponding header
#include "Image.h"

//C++ headers
#include <fstream>
#include <iostream>
#include <istream>
#include <cstdint>

//Own includes


namespace {
	Pixel parsePixel(uint32_t inputRgba) {
	  Pixel px;
	  px.red = static_cast<uint8_t>( (inputRgba & 0xFF000000) >> 24);			//getting out the three values RGB
	  px.green = static_cast<uint8_t>( (inputRgba & 0x00FF0000) >> 16);			//using masks and & after that we LShitft the bits to use them
	  px.blue = static_cast<uint8_t>( (inputRgba & 0x0000FF00) >> 8);
	  px.alpha = static_cast<uint8_t>( (inputRgba & 0x000000FF));
	  return px;
	}
}



PackedImage::PackedImage(const Resolution &res) : resolution(res), pixels(res.width * res.height) {	//input the struct and get the info from it
}

bool PackedImage::operator==(const PackedImage &other) const {
  return (resolution == other.resolution) && (pixels == other.pixels);		//use this for comparing the two values of the input and output value
}

std::istream& operator>>(std::istream &istream, PackedImage &img) {		//will parse(get the three values from the PackedImage)
  uint32_t pixelValue = 0;
  for (Pixel &pixel : img.pixels) {		//for every image we input -> make me a reference pointing to the pixels
    istream >> pixelValue;				//get the number
    pixel = parsePixel(pixelValue);		//parse it and place it into the reference point(pixel variable)
  }

  return istream;
}





StrideImage::StrideImage(const Resolution &res): resolution(res),	redPixels(res.width * res.height),					//extract the infrom the input object and put it into the four variables
																	greenPixels(res.width * res.height),
																	bluePixels(res.width * res.height),
																	alphaPixels(res.width * res.height) {
}

bool StrideImage::operator==(const StrideImage &other) const {			//compair all the four integers and see if the object file is the same
  return (resolution == other.resolution) &&
         (redPixels == other.redPixels) &&
         (greenPixels == other.greenPixels) &&
         (bluePixels == other.bluePixels) &&
         (alphaPixels == other.alphaPixels);
}

std::istream& operator>>(std::istream &istream, StrideImage &img) {

  const int32_t totalPixels = img.resolution.width * img.resolution.height;			//get the number of pixels

  uint32_t pixelValue = 0;
  Pixel currPixel;

  for (int32_t i = 0; i < totalPixels; ++i) {	//till we iterate all the pixels one by one
    istream >> pixelValue;						//place the data
    currPixel = parsePixel(pixelValue);			//parse the data and place it into currPixel
    img.redPixels[i] = currPixel.red;			//
    img.greenPixels[i] = currPixel.green;
    img.bluePixels[i] = currPixel.blue;
    img.alphaPixels[i] = currPixel.alpha;
  }

  return istream;
}

