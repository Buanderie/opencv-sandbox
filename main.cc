
#include <iostream>
#include <unistd.h>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// #define PROCESS_IMAGE

int main( int argc, char** argv )
{

    srand(time(NULL));

#ifndef PROCESS_IMAGE
    namedWindow( "frame" );
    cv::VideoCapture cap( argv[1] );
    bool isPlaying = true;

    cv::Mat frame;

    for(;;)
    {
        if( isPlaying )
        {
            cap >> frame;
            if( frame.cols <= 0 || frame.rows <= 0 )
                continue;

        }

        imshow("frame", frame);

        char c = cv::waitKey(5);
        if( c == ' ' )
        {
            isPlaying = !isPlaying;
        }
        else if( c == 'q' )
        {
            break;
        }

    }
#else
    cv::Mat frame = cv::imread( argv[1] );
    imshow( "frame", frame );
    cv::waitKey(0);
#endif

    return 0;

}

