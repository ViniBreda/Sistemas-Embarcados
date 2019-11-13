/*
Arquivo main.
*/

#include "../inc/crypto.hpp"
#include "../inc/sheet.hpp"
#include "../inc/rasp.hpp"

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
            capture_img();
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