const first_name = "Salman";
const job = "teacher";
const birth_year = 1999;
const year = 2023;

const salman =
  "I'm " + first_name + ", a " + (year - birth_year) + " year old " + job + "!";
console.log(salman);

const salman_new = `I'm ${first_name}, a ${year - birth_year} year old ${job}!`;
console.log(salman_new);

console.log(`Just a regular string...`);

console.log(
  "String with \n\
multiple \n\
lines"
);

console.log(`String with
multiple
lines`);
