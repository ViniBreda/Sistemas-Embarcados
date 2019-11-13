#ifndef RASP__HPP
#define RASP__HPP

#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include </usr/include/wiringPi.h>
#include <unistd.h>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>


#define PIR 0 // definindo porta para leitura do sensor PIR (sensor de movimento)

std::string exec(const char* cmd);
void capture_img();


#endif