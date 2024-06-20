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

    // Destination matrices
    cv::Mat flippedHorizontally;
    cv::Mat flippedVertically;
    cv::Mat flippedBoth;

    // Flip the image horizontally (flipCode = 1)
    cv::flip(src, flippedHorizontally, 1);

    // Flip the image vertically (flipCode = 0)
    cv::flip(src, flippedVertically, 0);

    // Flip the image both horizontally and vertically (flipCode = -1)
    cv::flip(src, flippedBoth, -1);

    // Display the results
    cv::imshow("Original Image", src);
    cv::imshow("Flipped Horizontally", flippedHorizontally);
    cv::imshow("Flipped Vertically", flippedVertically);
    cv::imshow("Flipped Both", flippedBoth);
    cv::waitKey(0);

    return 0;
}
