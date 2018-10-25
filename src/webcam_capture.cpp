//opencv
#include "opencv2/opencv.hpp"

//std
#include <iostream>
#include <cstdlib>

//main
int main(int argc, char *argv[])
{
  cv::VideoCapture camera; //OpenCV video capture object
  cv::Mat image; //OpenCV image object
  int cam_id; //camera id . Associated to device number in /dev/videoX
  cv::Scalar_<unsigned char> px_value; //pixel value (4-element vector)
  int central_x, central_y; // To get camera resolution
  unsigned char * pixel; // Pixel of image
  unsigned char * m_pixel; // Modifiable pixel of image

  //check user args
  switch(argc) {
    case 1: //no argument provided, so try /dev/video0
      cam_id = 0;
      break;
    case 2: //an argument is provided. Get it and set cam_id
      cam_id = atoi(argv[1]);
      break;
    default:
      std::cout << "Invalid number of arguments. Call program as: webcam_capture [video_device_id]. " << std::endl;
      std::cout << "EXIT program." << std::endl;
      break;
  }

  //advertising to the user
  std::cout << "Opening video device " << cam_id << std::endl;

  //open the video stream and make sure it's opened
  if( !camera.open(cam_id) ) {
    std::cout << "Error opening the camera. May be invalid device id. EXIT program." << std::endl;
    return -1;
  }

  //capture loop. Out of user press a key
  while(1) {
    //Read image and check it. Blocking call up to a new image arrives from camera.
    if( !camera.read(image) ) {
      std::cout << "No frame" << std::endl;
      cv::waitKey();
    }

    // Get central image pixel
    central_x = image.rows / 2;
    central_y = image.cols / 2;
    pixel = image.ptr(central_x, central_y);
    std::cout << "Central pixel color: at (" << central_x << ", " << central_y << ")" << std::endl;
    std::cout << "  R: " << (int)pixel[2] << std::endl;
    std::cout << "  G: " << (int)pixel[1] << std::endl;
    std::cout << "  B: " << (int)pixel[0] << std::endl;

    //show image in a window
    cv::imshow("Output Window", image);

    // Colorize central pixel as a crosshair with some bright color
    for (int i = -20; i < 20 ; i++) {
      for (int j = -2; j < 2; j++) {
        if (i >= -2 && i <= 2) { continue; }
        m_pixel = image.ptr(central_x + i, central_y + j);
        m_pixel[0] = 57;
        m_pixel[1] = 255;
        m_pixel[2] = 18;
      }
    }
    for (int i = -2; i < 2 ; i++) {
      for (int j = -20; j < 20; j++) {
        if (j >= -2 && j <= 2) { continue; }
        m_pixel = image.ptr(central_x + i, central_y + j);
        m_pixel[0] = 57;
        m_pixel[1] = 255;
        m_pixel[2] = 18;
      }
    }

    // Show modified image
    cv::imshow("Output Window modified", image);

    //Waits 30 millisecond to check if 'q' key has been pressed. If so, breaks the loop. Otherwise continues.
    if( (unsigned char)(cv::waitKey(30) & 0xff) == 'q' ) break;
  }
}
