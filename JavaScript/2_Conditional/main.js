// // Operators
// let a = 7;
// let b = 10;
// console.log("a + b = ", a + b);

// // Condition
// let age = prompt("enter age");
// if (age >= 18){
//     console.log("You can vote");
// } else{
//     console.log("You can't vote");
// }

// // Ex.1
// function islandscape(width, height){
//     return (width > height);
// }
// console.log(islandscape(200, 100));

// Ex.2
function checkSpeed(speed){
    const speedLimit = 70;
    const kmPerPoint = 5;
    if (speed <= speedLimit){
        console.log("Ok");
    }
    else{
        const point = Math.floor((speed - speedLimit) / kmPerPoint);
        if (point >= 1){
            console.log("your point is", point);
        }
        else {
            console.log("Ok");
        }
        if (point >= 12){
            console.log("your license is cancelled");
        }
    }
}
checkSpeed(77);