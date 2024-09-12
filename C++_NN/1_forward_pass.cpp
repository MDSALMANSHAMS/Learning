#include <torch/torch.h>
#include <iostream>

struct SimpleCNN : torch::nn::Module {
    // Define layers
    torch::nn::Conv2d conv1{nullptr}, conv2{nullptr};
    torch::nn::Linear fc1{nullptr}, fc2{nullptr};

    // Constructor to initialize layers
    SimpleCNN() {
        conv1 = register_module("conv1", torch::nn::Conv2d(torch::nn::Conv2dOptions(254, 128, 3).stride(1).padding(1)));
        conv2 = register_module("conv2", torch::nn::Conv2d(torch::nn::Conv2dOptions(128, 64, 3).stride(1).padding(1)));
        fc1 = register_module("fc1", torch::nn::Linear(64 * 8 * 8, 128));  // Adjust input features size depending on your input size
        fc2 = register_module("fc2", torch::nn::Linear(128, 10));
    }

    // Forward pass
    torch::Tensor forward(torch::Tensor x) {
        // Apply first convolution, followed by ReLU and max pooling
        x = torch::relu(conv1(x));
        x = torch::max_pool2d(x, 2);

        // Apply second convolution, followed by ReLU and max pooling
        x = torch::relu(conv2(x));
        x = torch::max_pool2d(x, 2);

        // Flatten the tensor for the fully connected layer
        x = x.view({-1, 64 * 8 * 8});  // Adjust dimensions based on input size after pooling

        // Fully connected layers with ReLU activation
        x = torch::relu(fc1(x));
        x = fc2(x);
        return x;
    }
};

int main() {
    // Create an instance of the model
    auto model = std::make_shared<SimpleCNN>();

    // Example input: a batch of 1 sample with 254 channels, and size 32x32
    torch::Tensor input = torch::randn({1, 254, 32, 32});

    // Perform a forward pass
    torch::Tensor output = model->forward(input);

    // Print the output shape and values
    std::cout << "Output shape: " << output.sizes() << std::endl;
    std::cout << "Output values: " << output << std::endl;

    return 0;
}
