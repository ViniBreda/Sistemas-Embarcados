/*
Arquivo main.
*/

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
using namespace cv;

std::string exec(const char* cmd) { // leitura da saída do terminal de determinada função
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
    wiringPiSetup(); // inicio do setup de pinos da rasp FALTA O OUTPUT DO CONTROLE DO PORTÃO DA GARAGEM
    pinMode(PIR, INPUT);   // setando o pino do PIR como entrada digital
    VideoCapture cap(0); // abre a camera padrão do sistema
    {
    if(!cap.isOpened()) // se não houver câmera, acusa erro
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
            imwrite("./WebCamImage.png", frame); // salva o frame atual no arquivo WebCamImage.png para ser lido pelo openalpr
            i++; // conta a quantidade de leituras feitas
            system("clear");
            std::cout << "Presence Detected " << i << std::endl;
            plate = exec("alpr -c br -p @@@#### -n 2 ./WebCamImage.png"); // salva a saída do comando de terminal do OpenALPR em uma variável
            if(strlen(plate.c_str()) > 25){ // pega as letras e numeros da placa caso alguma seja reconhecida
                std::string plateL(plate, 24, 3);
                plateL[3] = '\0';
                std::string plateN(plate, 27, 4);
                plateN[4] = '\0';
                std::cout << plate << std::endl;
                std::string plateR(plate, 8, 1);
                plateR[1] = '\0';
                //std::cout << plateR << std::endl;
                if (plateR != "1"){ // se houverem duas possibilidades de placa, salva a segunda em outra variável
                    std::string plateL2(plate, 77, 3);
                    plateL2[3] = '\0';
                    std::string plateN2(plate, 80, 4);
                    plateN2[4] = '\0';
                    std::cout << plateL << ' ' << plateN << std::endl;
                    std::cout << plateL2 << ' ' << plateN2 << std::endl;
                }
            }
            else // se não reconhece alguma placa, mostra somente o output do comando de terminal
                std::cout << plate << std::endl;
        }
        if(waitKey(30) >= 0) break; // fecha o programa se 
                
    }
    system("clear");
//    int j = 0;
//    for(j=0; j < strlen(plate.c_str()); j++){
//        std::cout << plate[j] << ' ' << j << std::endl;
//    }
    return 0;
}