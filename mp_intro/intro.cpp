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
      HSLAPixel & ending = blankOutput->getPixel(imageWidth - x - 1, imageHeight - y - 1);
      ending = starting;
      //HSLAPixel & outputPixels = blankOutput->getPixel(x,y);
      
    }
  }
  
  blankOutput->writeToFile(outputFile);
  delete imageRotate;
  delete blankOutput;
  
  
  // TODO: Part 2
}

cs225::PNG myArt(unsigned int width, unsigned int height) {
  cs225::PNG png(width, height);
  
  //PNG* artPng = new PNG();
  //unsigned imageWidth = artPng->get.width();
  for (unsigned x = 0; x < width; x++) {
    for (unsigned y = 0; y < height; y++) {
      
      double distanceOne = (width/3);
      double distanceTwo = (2*width/3);
      
    
      if (x < distanceOne) {
        HSLAPixel & pixel = png.getPixel(x,y);
        HSLAPixel pixelTwo(100, 1.0, 0.5);
        pixel = pixelTwo;
      }
      
      
      if (x >= distanceOne && x < distanceTwo){
        HSLAPixel & pixel = png.getPixel(x,y);
        HSLAPixel pixelTwo(260, 1.0, 0.5);
        pixel = pixelTwo;
      }
      
  
      if (x >= distanceTwo){
        HSLAPixel & pixel = png.getPixel(x,y);
        HSLAPixel pixelTwo(360, 1.0, 0.5);
        pixel = pixelTwo;
      }
    
    }
  }
  
  
  // TODO: Part 3

  return png;
}
