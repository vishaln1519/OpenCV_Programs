/* A simple code to access pixels of image and modify them*/
#include <opencv2/opencv.hpp> 
#include <stdint.h>
using namespace std;
using namespace cv;

int main( int argc, char** argv ) {

	Mat img = imread("audi.jpg",CV_LOAD_IMAGE_COLOR); // Reading original image Hint: Edit the imread first aparameter as per the picture you need
	Mat img_mod = imread("audi.jpg",CV_LOAD_IMAGE_COLOR); // Reading original image which will be modified
	if( img.empty() )
	{
		cout << "There is no such image"; // error checking
		return -1;
	}
	
	for(int r = 0; r <img_mod.rows;r++)
	{
		for(int c = 0; c <img_mod.cols;c++)
		{
			img_mod.at<cv::Vec3b>(r,c)[1] = img_mod.at<Vec3b>(r,c)[1] * 0.5;  // We can change the vector index to 1 or 2 to access other components of a RGB channel
		}
	}
	
	namedWindow( "img", WINDOW_AUTOSIZE );
	namedWindow( "img_mod", WINDOW_AUTOSIZE );
	imshow( "img", img );
	imshow("img_mod",img_mod);
	
	waitKey( 0 );
	destroyWindow( "Example1" );
	return 0;
}