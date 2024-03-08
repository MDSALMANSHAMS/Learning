const { Image } = require("image-js");

// Loading an image is asynchronous and will return a Promise.
Image.load("images/Notebook.png").then(function (image) {
  console.log("Width", image.width);
  console.log("Height", image.height);
  console.log("colorModel", image.colorModel);
  console.log("components", image.components);
  console.log("alpha", image.alpha);
  console.log("channels", image.channels);
  console.log("bitDepth", image.bitDepth);

  var grey = grey();
  grey.save("Notebook-grey_1.jpg");
});

function unsharpMaskWithoutBlur(imageData, amount) {
  const data = imageData.data;

  for (let i = 0; i < data.length; i += 4) {
    const originalPixelValue = data[i];
    const sharpenedPixelValue =
      originalPixelValue + amount * (originalPixelValue - data[i]); // since it's already blurred, we use the original pixel value
    data[i] = sharpenedPixelValue;
    data[i + 1] = sharpenedPixelValue;
    data[i + 2] = sharpenedPixelValue;
  }

  return imageData;
}

// async function process() {
//   let image = await IJS.Image.load(document.getElementById("color").src);

//   const canvas = document.createElement("canvas");
//   const context = canvas.getContext("2d");

//   context.drawImage(image, 0, 0, capturedWidth, capturedHeight);
//   const imageData = context.getImageData(0, 0, capturedWidth, capturedHeight);

//   let grey = gaussianBlur(imageData, 50);
//   document.getElementById("result").src = grey.toDataURL();
// }
// process();

// function gaussianBlur(imageData, radius) {
//   const data = imageData.data;
//   const width = imageData.width;
//   const height = imageData.height;
//   const newData = new Uint8ClampedArray(data.length);

//   const kernel = generateGaussianKernel(radius);
//   const kernelSize = kernel.length;
//   const kernelRadius = Math.floor(kernelSize / 2);

//   for (let y = 0; y < height; y++) {
//     for (let x = 0; x < width; x++) {
//       let sumR = 0;
//       let sumG = 0;
//       let sumB = 0;
//       let sumA = 0;

//       for (let ky = 0; ky < kernelSize; ky++) {
//         for (let kx = 0; kx < kernelSize; kx++) {
//           const pixelX = x + kx - kernelRadius;
//           const pixelY = y + ky - kernelRadius;

//           if (pixelX >= 0 && pixelX < width && pixelY >= 0 && pixelY < height) {
//             const index = (pixelY * width + pixelX) * 4;
//             const kernelValue = kernel[ky][kx];

//             sumR += data[index] * kernelValue;
//             sumG += data[index + 1] * kernelValue;
//             sumB += data[index + 2] * kernelValue;
//             sumA += data[index + 3] * kernelValue;
//           }
//         }
//       }

//       const newIndex = (y * width + x) * 4;
//       newData[newIndex] = sumR;
//       newData[newIndex + 1] = sumG;
//       newData[newIndex + 2] = sumB;
//       newData[newIndex + 3] = sumA;
//     }
//   }

//   return new ImageData(newData, width, height);
// }

// function generateGaussianKernel(radius) {
//   const size = radius * 2 + 1;
//   const sigma = radius / 3;
//   const kernel = [];

//   for (let y = -radius; y <= radius; y++) {
//     const row = [];
//     for (let x = -radius; x <= radius; x++) {
//       const distance = x * x + y * y;
//       const weight =
//         Math.exp(-distance / (2 * sigma * sigma)) /
//         (2 * Math.PI * sigma * sigma);
//       row.push(weight);
//     }
//     kernel.push(row);
//   }
//   return kernel;
// }
