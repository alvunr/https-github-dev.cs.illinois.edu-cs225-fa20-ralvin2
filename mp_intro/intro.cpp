#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"

#include <string>



using namespace cs225;

PNG* setupOutput(unsigned w, unsigned h) {
  //std::cout << "test on  " << __LINE__ << std::endl;
  PNG* image = new PNG(w, h);
  return image;
  //std::cout << "test on  " << __LINE__ << std::endl;
  
}

void rotate(std::string inputFile, std::string outputFile) {
  
  PNG* imageRotate = new PNG();
  imageRotate->readFromFile(inputFile);
  unsigned imageWidth = imageRotate->width();
  unsigned imageHeight = imageRotate->height();
  //creates a blank template for new png image
  PNG* blankOutput = setupOutput(imageWidth,imageHeight);
  
  for (unsigned y = 0; y < imageHeight; y++) {
    for (unsigned x = 0; x < imageWidth; x++) {
      HSLAPixel & starting = imageRotate->getPixel(x,y);
      HSLAPixel & ending = imageRotate->getPixel(imageWidth - 1- x,imageHeight - 1 - y);
      starting = ending;
      //HSLAPixel & outputPixels = blankOutput->getPixel(x,y);
      
    }
  }
  
  imageRotate->writeToFile(outputFile);
  delete imageRotate;
  delete blankOutput;
  
  
  // TODO: Part 2
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  
  
  
  
  
  // TODO: Part 3

  return png;
}
