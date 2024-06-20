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

    // Center of rotation
    cv::Point2f center(src.cols / 2.0, src.rows / 2.0);

    // Rotation angle
    double angle = 45.0;

    // Scaling factor
    double scale = 1.0;

    // Get the rotation matrix
    cv::Mat rotMat = cv::getRotationMatrix2D(center, angle, scale);

    // Destination matrix
    cv::Mat dst;

    // Apply the rotation
    cv::warpAffine(src, dst, rotMat, src.size());

    // Display the result
    cv::imshow("Original Image", src);
    cv::imshow("Rotated Image", dst);
    cv::waitKey(0);

    return 0;
}
