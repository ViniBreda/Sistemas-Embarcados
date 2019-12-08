/*
Arquivo main.
*/

#include "../inc/crypto.hpp"
#include "../inc/sheet.hpp"
#include "../inc/rasp.hpp"

using namespace cv;

int main(int argc, char** argv) {
    system("clear");
    wiringPiSetup(); // inicio do setup de pinos da rasp FALTA O OUTPUT DO CONTROLE DO PORTÃO DA GARAGEM
    pinMode(PIR, INPUT);   // setando o pino do PIR como entrada digital
	pinMode(CTRL, OUTPUT);
    VideoCapture cap(0); // abre a camera padrão do sistema
    if(!cap.isOpened()){ // se não houver câmera, acusa erro
        std::cerr << "No camera found!" << std::endl;
        return -1;
    }
    cap.set(CAP_PROP_FPS, 30);
    namedWindow("Webcam", WINDOW_AUTOSIZE);
    for(;;){
        Mat frame; // cria uma matriz de frames
        cap >> frame; // passa as capturas de imagem da camera, feitas em VideoCapture, para a matriz frame
        // imshow("Webcam", frame); // mostra os frames capturados pelo VideoCapture
        if(digitalRead(PIR)){ // caso haja leitura no sensor de presença
            if(capture_img(frame)){ // inicia o processo de leitura e reconhecimento de placa
                digitalWrite(GLED, HIGH); // indica quando a abertura do portão é iniciada
				digitalWrite(CTRL, HIGH); // caso encontre uma placa que está no banco de placas permitidas ativa o controle
				usleep(500);
			}
        }
        if(waitKey(30) >= 0) break; // fecha o programa se uma tecla for pressionada
		digitalWrite(CTRL, LOW); // desliga o controle
        digitalWrite(BLED, LOW); // indica reconhecimento da placa
        digitalWrite(RLED, LOW); // indica reconhecimento da placa
        digitalWrite(GLED, LOW); // indica reconhecimento da placa
        
                
    }
    system("clear");
    return 0;
}
