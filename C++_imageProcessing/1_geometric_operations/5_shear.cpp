#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    // Read the image
    cv::Mat src = cv::imread("F:/My_projects/Learning/C++_imageProcessing/images/object.jpg");
    if (src.empty())
    {
        std::cerr << "Error: Could not open or find the image.\n";
        return -1;
    }

    // Shearing factors
    double shearX = 0.5; // Shear in x direction
    double shearY = 0.2; // Shear in y direction

    // Get the shearing matrix
    cv::Mat shearMat = (cv::Mat_<double>(2, 3) << 1, shearX, 0, shearY, 1, 0);

    // Destination matrix
    cv::Mat dst;

    // Apply the shearing
    cv::warpAffine(src, dst, shearMat, src.size());

    // Display the result
    cv::imshow("Original Image", src);
    cv::imshow("Sheared Image", dst);
    cv::waitKey(0);

    return 0;
}
