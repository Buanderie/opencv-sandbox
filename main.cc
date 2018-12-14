
#include <iostream>
#include <unistd.h>

#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{

    srand(time(NULL));
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

    return 0;

}
