// // Concept
// const num =[3, 4];

// num.push(5, 6);
// console.log(num);

// num.unshift(1, 2);
// console.log(num);

// num.splice(2, 0, 'a', 'b');
// console.log(num);

// // Ex.1
// function arrayFromRange(min, max) {
//     const array = [];
//     for (let i = min; i <= max; i++) {
//         array.push(i);
//     }
//     return array;
// }
// const num = arrayFromRange(-1, 5);
// console.log(num);

// Ex.2
const myArray = [1, 2, 3, 4, 5];
function numExist(array, num){
    for (let i = 0; i <= array.length; i++){
        if (array[i] === num) return true;
    }
    return false;
}
const result = numExist(myArray, 3);
console.log(result);