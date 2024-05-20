// CHALLENGE #4
// Let's improve Steven's tip calculator even more, this time using loops!

// Your tasks:
// Create an array called bills containing all 10 test bill values. Create empty arrays for
// the tips and the totals (tips and totals), Use the calcTip function we wrote before
// (included in the starter code) to calculate tips and total values (bill + tip)
// for every bill value in the bills array. Use a for loop to perform the 10 calculations!

// TEST DATA: 22, 295, 176, 440, 37, 105, 10, 1100, 86, and 52.

const bills = [22, 295, 176, 440, 37, 105, 10, 1100, 86, 52];
let tips = [];
let totals = [];

let calcTip = function (bill) {
  return bill >= 50 && bill <= 300 ? bill * 0.15 : bill * 0.2;
};

for (let i = 0; i < bills.length; i++) {
  // tips[i] = calcTip(bills[i]);
  // totals[i] = bills[i] + tips[i];
  const tip = calcTip(bills[i]);
  tips.push(tip);
  totals.push(tip + bills[i]);
}

console.log(tips);
console.log(totals);
