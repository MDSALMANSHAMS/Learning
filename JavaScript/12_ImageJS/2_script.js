// const { Image } = require(['image-js']);

// execute().catch(console.error);

// async function execute() {
//   let image = await Image.load('images/Notebook.png');
//   let grey = image
//     .grey()
//     .resize({ width: 200 }) 
//     .rotate(30); 
//   return grey.save('NB.png');
// }

import { Image } from require('image-js');


Image.load('NB.png').then(async (img) => {
  const grey = img.grey();
  await grey.save('grey_2.png');
});