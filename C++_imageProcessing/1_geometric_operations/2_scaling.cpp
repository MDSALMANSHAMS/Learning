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

    // Scaling factors
    double scaleX = 0.3;
    double scaleY = 0.3;

    // Destination matrix
    cv::Mat dst;

    // Resize the image
    cv::resize(src, dst, cv::Size(), scaleX, scaleY, cv::INTER_LINEAR);

    // Display the result
    cv::imshow("Original Image", src);
    cv::imshow("Scaled Image", dst);
    cv::waitKey(0);

    return 0;
}
