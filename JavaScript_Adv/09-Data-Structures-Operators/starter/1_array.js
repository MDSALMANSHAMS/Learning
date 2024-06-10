// 1
// const arr = [3, 5, 7];
// const a = arr[0];
// const b = arr[1];
// const c = arr[2];
// console.log(a, b, c);

//const [x, y, z] = arr;
//console.log(x, y, z);
// console.log(arr);

// 2
// Data needed for first part of the section
const restaurant = {
  name: 'Classico Italiano',
  location: 'Via Angelo Tavanti 23, Firenze, Italy',
  categories: ['Italian', 'Pizzeria', 'Vegetarian', 'Organic'],
  starterMenu: ['Focaccia', 'Bruschetta', 'Garlic Bread', 'Caprese Salad'],
  mainMenu: ['Pizza', 'Pasta', 'Risotto'],

  order(starterI, mainI) {
    return [this.starterMenu[starterI], this.mainMenu[mainI]];
  },

  openingHours: {
    thu: {
      open: 12,
      close: 22,
    },
    fri: {
      open: 11,
      close: 23,
    },
    sat: {
      open: 0, // Open 24 hours
      close: 24,
    },
  },
};

let [first, , second] = restaurant.categories;
//console.log(first, second);

// switching
// const temp = first;
// first = second;
// second = temp;
// console.log(first, second);
[first, second] = [second, first];
//console.log(first, second);

// reciving
const [myOrder_1, myOrder_2] = restaurant.order(3, 1);
//console.log(myOrder_1, myOrder_2);

const { name, openingHours, location } = restaurant;
//console.log(name, openingHours, location);

const { name: restaurantName, openingHours: hours, location: tag } = restaurant;
//console.log(restaurantName, hours, tag);

// Default values
const { menu = [], starterMenu: starters = [] } = restaurant;
//console.log(menu, starters);

// Mutating variables
let a = 111;
let b = 999;
const obj = { a: 23, b: 7, c: 14 };
({ a, b } = obj);
//console.log(a, b);

// Nested objects
const {
  fri: { open: o, close: c },
} = openingHours;
//console.log(o, c);

// 3
// nested
const nested = [4, 2, [7, 1]];
const [i, , j] = nested;
//console.log(i, j);
const [k, , [, l]] = nested;
//console.log(k, l);

//default
const [u = 1, v = 1, w = 1] = [4, 5];
//console.log(u, v, w);

//4. spread operator
const arr = [7, 8, 9];
const badNewArr = [1, 2, arr[0], arr[1], arr[2]];
//console.log(badNewArr);

const newArr = [1, 2, ...arr];
// console.log(newArr);
// console.log(...newArr);

const newMenu = [...restaurant.mainMenu, 'salad'];
//console.log(newMenu);

//copy array
const mainMenuCopy = [...restaurant.mainMenu];

// join 2 array
const menuAll = [...restaurant.starterMenu, ...restaurant.mainMenu];
//console.log(menuAll);

// Iterables string
const str = 'Jonas';
const letters = [...str, ' ', 'S.'];

for (let i = 0; i < letters.length; i++) {
  //console.log(letters[i]);
}

// object
const newRestaurant = { foundedIN: 2000, ...restaurant, fonder: 'Guiseppe' };
//console.log(newRestaurant);

// Rest Pattern and Parameters
// 1) Destructuring

// SPREAD, because on RIGHT side of =
const arrr = [1, 2, ...[3, 4]];

// REST, because on LEFT side of =
const [ab, bc, ...others] = [1, 2, 3, 4, 5];
//console.log(ab, bc, others);

const [pizza, , risotto, ...otherFood] = [
  ...restaurant.mainMenu,
  ...restaurant.starterMenu,
];
//console.log(pizza, risotto, otherFood);

// Objects
const { sat, ...weekdays } = restaurant.openingHours;
//console.log(weekdays);

// 2) Functions
const add = function (...numbers) {
  let sum = 0;
  for (let i = 0; i < numbers.length; i++) sum += numbers[i];
  //console.log(sum);
};

add(2, 3);
add(5, 3, 7, 2);
add(8, 2, 5, 3, 2, 1, 4);

const x = [23, 5, 7];
add(...x);

restaurant.orderPizza('mushrooms', 'onion', 'olives', 'spinach');
restaurant.orderPizza('mushrooms');

// The for-of Loop
//const menu = [...restaurant.starterMenu, ...restaurant.mainMenu];

for (const item of menuAll); //console.log(item);

for (const [i, el] of menuAll.entries()) {
  //console.log(`${i + 1}: ${el}`);
}

// console.log([...menu.entries()]);
