///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
//
///* 
// * File:   main.cpp
// * Author: pi
// *
// * Created on 26 de Setembro de 2019, 18:02
// */
//
//#include <cstdlib>
//
//using namespace std;
//
///*
// * 
// */
//int main(int argc, char** argv) {
//
//    return 0;
//}
//

// Example 4

//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <iostream>
//#include <fstream>
//
//// using namespace cv;
//using namespace std;
//
//int g_slider_position = 0;
//int g_run = 1, g_dontset = 0; //start out in single step mode
//cv::VideoCapture g_cap;
//
//void onTrackbarSlide(int pos, void *){
//    g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);
//    if(!g_dontset)
//        g_run = 1;
//    g_dontset = 0;
//}
//
//int main ( int argc, char** argv ){
//    cv::namedWindow("Example 4", cv::WINDOW_AUTOSIZE);
//    g_cap.open( "video.mp4" );
//    int frames = (int) g_cap.get(cv::CAP_PROP_FRAME_COUNT);
//    int tmpw   = (int) g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
//    int tmph   = (int) g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
//    cout << "Video has " << frames << " frames of dimensions(" << tmpw << ", " << tmph << ")." << endl;
//    
//    cv::createTrackbar("Position", "Example 4", &g_slider_position, frames, onTrackbarSlide);
//    
//    cv::Mat frame;
//    for(;;){
//        if(g_run != 0){
//            g_cap >> frame; if(frame.empty()) break;
//            int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
//            g_dontset = 1;
//            
//            cv::setTrackbarPos("Position", "Example 4", current_pos);
//            cv::imshow("Example 4", frame);
//            
//            g_run-=1;
//        }
//        char c = (char) cv::waitKey(10);
//        if(c == 's'){ // single step
//            g_run = 1; 
//            cout << "Single step, run = " << g_run << endl;
//        }
//        if(c == 'r'){ // run mode
//            g_run = -1;
//            cout << "Run mode, run = " << g_run << endl;
//        }
//        if(c = 27)
//            break;
//    }
//    
//    return(0);
//}



// Example 3

//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <iostream>
//
//using namespace cv;
//
//int main (int argc, char **argv){
//    
//    namedWindow("Example3", WINDOW_AUTOSIZE);
//    VideoCapture cap;
//    cap.open(std::string(argv[1]));
//    
//    Mat frame;
//    for(;;){
//        cap >> frame;
//        if(frame.empty()) break; // ran out of film
//        imshow("Example3", frame);
//        if(waitKey(33) >= 0) break;
//    }
//    return 0;
//}

// Example 1 and 2

//#include <opencv2/highgui/highgui.hpp>

//using namespace cv;

//int main ( int argc, char **argv )
//{
//    Mat img = imread(argv[1], -1);
//    if( img.empty() ) return -1;
//    namedWindow( "Example1", WINDOW_AUTOSIZE );
//    imshow( "Example1", img );
//    waitKey( 0 );
//    destroyWindow( "Example1" );
//    return 0;
//}