// // Objects
// const circle = {
//     radius: 1,
//     value : {
//         x : 1,
//         y : 1
//     },
//     isFinite : true,
//     draw : function(){
//         console.log('draw');
//     }
// }
// circle.draw();

// // Factior function
// function createcircle(radius){
//     return{
//         radius,
//         draw(){
//             console.log('create');
//         }
//     };
// }
// const circle_1 = createcircle(1);
// console.log(circle_1);

// // Cloning object
// const circle_2 = Object.assign({color:'red'}, circle_1);
// console.log(circle_2);

// // Ex.1
// const myAddress = {
//     street: 'Okhla road',
//     city : 'Delhi',
//     zipCode : 110025,
// }
// function showAddress(address){
//     for (key in address) {
//         console.log(key, address[key]); 
//     }
// }
// showAddress(myAddress);

// // Ex.2 (Factory)
// function addAddress(street, city, zipCode){
//     return{
//         street,
//         city,
//         zipCode
//     };
// }
// let dadAddress = addAddress('khankah road', 'Munger', 811201);
// console.log(dadAddress);

// // Ex.3 (Constructor)
function addAddress(street, city, zipCode){
    this.street = street;
    this.city = city;
    this.zipCode = zipCode;
}
let officeAddress = new addAddress('Sushant road', 'Gurgaon', 110050);
console.log(officeAddress);