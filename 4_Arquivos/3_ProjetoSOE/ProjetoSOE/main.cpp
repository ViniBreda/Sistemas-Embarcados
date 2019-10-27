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

#define PIR 0
using namespace cv;
//using namespace alpr;

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

int main(int argc, char** argv) {
    system("clear");
    wiringPiSetup();
    pinMode(PIR, INPUT);
//    Alpr openalpr("br", "/usr/share/openalpr/config/openalpr.defaults.conf");
//    
//    openalpr.setTopN(10);
//    openalpr.setDefaultRegion("br");
//    if (!openalpr.isLoaded())
//    {
//        std::cerr << "Error loading OpenALPR" << std::endl;
//        return 1;
//    }
//        
    VideoCapture cap(0); // abre a camera padrão do sistema
    if(!cap.isOpened()) // se não houver câmera, acusa erro
    {
        std::cerr << "No camera found!" << std::endl;
        return -1;
    }
    cap.set(CAP_PROP_FPS, 30);
    std::string plate;
    int i = 0;
    namedWindow("Webcam", WINDOW_AUTOSIZE);
    for(;;){
        Mat frame; // cria uma matriz de frames
        cap >> frame; // passa as capturas de imagem da camera, feitas em VideoCapture, para a matriz frame
        imshow("Webcam", frame); // mostra os frames capturados pelo VideoCapture
        if(digitalRead(PIR)){
            imwrite("./WebCamImage.png", frame);
            i++;
            system("clear");
            std::cout << "Presence Detected " << i << std::endl;
            //sleep(2);
            //system("alpr -c br ./WebCamImage.png");
            plate = exec("alpr -c br -p @@@#### -n 2 ./WebCamImage.png");
            if(strlen(plate.c_str()) > 25){
                std::string plateL(plate, 24, 3);
                plateL[3] = '\0';
                std::string plateN(plate, 27, 4);
                plateN[4] = '\0';
                std::cout << plate << std::endl;
                std::string plateR(plate, 8, 1);
                plateR[1] = '\0';
                //std::cout << plateR << std::endl;
                if (plateR != "1"){ 
                    std::string plateL2(plate, 77, 3);
                    plateL2[3] = '\0';
                    std::string plateN2(plate, 80, 4);
                    plateN2[4] = '\0';
                    std::cout << plateL << ' ' << plateN << std::endl;
                    std::cout << plateL2 << ' ' << plateN2 << std::endl;
                }
            }
            else
                std::cout << plate << std::endl;
        }
        if(waitKey(30) >= 0) break;
                
//        AlprResults results = openalpr.recognize("./WebCamImage.png");
//    
//        for (int i = 0; i < results.plates.size(); i++)
//        {
//            AlprPlateResult plate = results.plates[i];
//            std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;
//
//            for (int k = 0; k < plate.topNPlates.size(); k++)
//            {
//                AlprPlate candidate = plate.topNPlates[k];
//                std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
//                std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
//            }
//        }  
    }
    system("clear");
//    int j = 0;
//    for(j=0; j < strlen(plate.c_str()); j++){
//        std::cout << plate[j] << ' ' << j << std::endl;
//    }
    return 0;
}