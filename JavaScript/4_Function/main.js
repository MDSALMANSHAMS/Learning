function greet(){
    console.log("how r u?");
}
greet();

let walk = function(){
    console.log("walk");
};
walk();

function sum(discount, ...args){
    //discount = discount || 0.2;
    const total = args.reduce((a, b) => a + b);
    console.log(total);
    return total * (1 - discount);
}
console.log(sum(0.2, 2, 5, 6, 34));