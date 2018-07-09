#if 1
// flood fill algorithm
// author Narmatha Gopal
// ref::https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/
// Given seed pixel value. Group the values same as seed pixel value based on 4 or 8 neighbourhood
// label each group with unique value. Here it is multiple of 10 (Group-1 : 10, Group-2 : 20 etc..)

#include <iostream>
#include<conio.h>
#include "opencv2\highgui\highgui.hpp"
#include"opencv2\imgproc\imgproc.hpp"

using namespace std;

enum NEIGHBOURHOOD_PXL{
	FOUR,
	EIGHT
};

void fill_recursive(cv::Mat &image, int x, int y, uchar seed_pxl_val, uchar replace_pxl, NEIGHBOURHOOD_PXL FILL = FOUR){
	if (x < 0 || y < 0 || x > image.rows - 1 || y > image.cols - 1)
		return;
	if (image.at<uchar>(y, x) != seed_pxl_val)
		return;
	image.at<uchar>(y, x) = replace_pxl;
	fill_recursive(image, x - 1, y, seed_pxl_val, replace_pxl);
	fill_recursive(image, x + 1, y, seed_pxl_val, replace_pxl);
	fill_recursive(image, x, y - 1, seed_pxl_val, replace_pxl);
	fill_recursive(image, x, y + 1, seed_pxl_val, replace_pxl);

	if (FILL == EIGHT){
		fill_recursive(image, x - 1, y - 1, seed_pxl_val, replace_pxl);
		fill_recursive(image, x - 1, y + 1, seed_pxl_val, replace_pxl);
		fill_recursive(image, x + 1, y - 1, seed_pxl_val, replace_pxl);
		fill_recursive(image, x + 1, y + 1, seed_pxl_val, replace_pxl);
	}

}

#endif

int main()
{

	cv::Mat image = (cv::Mat_<uchar>(5, 5) << 1, 2, 1, 1, 2, 2, 2, 2, 1, 1, 1, 3, 3, 2, 1, 1, 2, 2, 1, 2, 1, 1, 1, 1, 1);
	cout << image << endl;
	uchar seed_pxl_val = 2;
	int replace_pxl = 10;
	

	for (int i = 0; i < image.rows; i++){
		for (int j = 0; j < image.cols; j++){
			if (image.at<uchar>(i, j) == seed_pxl_val){
				fill_recursive(image, j, i, seed_pxl_val, replace_pxl);
				replace_pxl += 10;
			}
		}
	}
	cout << "out " << endl << image;
	cv::waitKey(0);
	return 0;


}
