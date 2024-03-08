// // Traditional method
// function greet(name, callback) {
//     console.log('hi' + ' ' + name);
//     callback();
// }
// function callme(){
//     console.log('back function');
// }
// greet('salman', callme);

// // arrow method
// const calculate = (a, b, operation) => {
//     return operation(a, b);
// }
// const addition = (a, b) => a + b;
// console.log(calculate(3, 4, addition));

// anonymous
const calculate = (a, b, operation) => {
    return operation(a, b);
}
const result = calculate(3, 4, function(num1, num2) {
    return num1 + num2; 
});
console.log(result);