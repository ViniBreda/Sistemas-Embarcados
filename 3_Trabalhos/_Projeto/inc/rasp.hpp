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
#include "../inc/sheet.hpp"


#define PIR 0 // definindo porta para leitura do sensor PIR (sensor de movimento)
#define CTRL 1 // definindo porta para controle do portão
#define RLED 2 // Pino para led vermelho
#define GLED 3 // Pino para led verde
#define BLED 4 // Pino para led azul

std::string exec(const char* cmd);
bool capture_img(cv::Mat frame);


#endif
