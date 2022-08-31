#ifndef SOLUTION_H_
#define SOLUTION_H_
//C++ headers

//Own includes
#include "utils/Image.h"
#include "utils/FunctionTracer.h"
//Forward declarations

class Solution {
public:
  void compute([[maybe_unused]]std::vector<PackedImage> &images);

  void compute([[maybe_unused]]std::vector<StrideImage> &images);

private:
  void pixelReadEyeFilter(Pixel & pixelData);
};

#endif /* SOLUTION_H_ */
