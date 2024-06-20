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

    // Translation distances
    double tx = 100; // Translate x by 100 pixels
    double ty = -50; // Translate y by 50 pixels

    // Get the translation matrix
    cv::Mat transMat = (cv::Mat_<double>(2, 3) << 1, 0, tx, 0, 1, ty);
    std::cout << transMat << std::endl;

    // Destination matrix
    cv::Mat dst;

    // Apply the translation
    cv::warpAffine(src, dst, transMat, src.size());

    // Display the result
    cv::imshow("Original Image", src);
    cv::imshow("Translated Image", dst);
    cv::waitKey(0);

    return 0;
}
