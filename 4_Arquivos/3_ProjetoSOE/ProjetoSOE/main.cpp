#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
//#include </usr/include/alpr.h>

#include <iostream>
#include <array>

using namespace cv;
//using namespace alpr;

int main(int argc, char** argv) {
    
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
    namedWindow("Webcam", WINDOW_AUTOSIZE);
    for(;;){
        Mat frame; // cria uma matriz de frames
        cap >> frame; // passa as capturas de imagem da camera, feitas em VideoCapture, para a matriz frame
        imshow("Webcam", frame); // mostra os frames capturados pelo VideoCapture
        imwrite("./WebCamImage.png", frame);
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
    
    return 0;
}