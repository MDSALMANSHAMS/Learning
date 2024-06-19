#include <opencv2/opencv.hpp>
#include <iostream>

int main()
{
    std::cout << "Starting the application...." << std::endl;

    // Use an absolute path to the image
    std::string imagePath = "F:/My_projects/Learning/C++_imageProcessing/images/art.jpg";

    // Read the image
    cv::Mat image = cv::imread(imagePath);

    // Check if the image was loaded successfully
    if (image.empty())
    {
        std::cerr << "Could not read the image: " << imagePath << std::endl;
        return 1;
    }

    std::cout << "Image read successfully. Displaying the image..." << std::endl;

    // Display the image
    cv::imshow("Display window", image);

    // Wait for a keystroke in the window
    int k = cv::waitKey(0);

    std::cout << "Key pressed: " << k << std::endl;

    // Save the image if 's' is pressed
    if (k == 's')
    {
        cv::imwrite("F:/My_projects/Learning/C++_imageProcessing/src/art_output.jpg", image);
        std::cout << "Image saved as art_output.jpg" << std::endl;
    }

    std::cout << "Exiting the application..." << std::endl;
    return 0;
}
