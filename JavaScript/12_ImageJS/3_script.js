async function process() {
  let image = await IJS.Image.load(document.getElementById("color").src);

  const canvas = document.createElement("canvas");
  const context = canvas.getContext("2d");

  context.drawImage(image, 0, 0, capturedWidth, capturedHeight);
  const imageData = context.getImageData(0, 0, capturedWidth, capturedHeight);

  let unsharp = unsharpMaskWithoutBlur(imageData, 50);
  document.getElementById("result").src = unsharp.toDataURL();
}
process();

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
