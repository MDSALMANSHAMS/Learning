// CHALLENGE #3
// Let's go back to Mark and John comparing their BMIs!
// This time, let's use objects to implement the calculations!
// Remember: BMI = mass / (height * height) (mass in kg and height in meters).

// Your tasks:
// For each of them, create an object with properties for their full name, mass, and height (Mark Miller and John Smith).
// Name these objects as mark and john, and their properties exactly as fullName, mass and height.
// Create a calcBMI method on each object to calculate the BMI (the same method on both objects).
// Assign the BMI value to a property called bmi (lowercase), and also return it from the method.
// Log to the console who has the higher BMI, together with the full name and the respective BMI.

// Example: "John Smith's BMI (28.3) is higher than Mark Miller's (23.9)!".
// TEST DATA: Marks weighs 78 kg and is 1.69 m tall. John weighs 92 kg and is 1.95 m tall.

const mark = {
  fullName: "Mark Miller",
  mass: 78,
  height: 1.69,

  calcBMI: function (mass, height) {
    bmi = mass / (height * height);
    return bmi;
  },
};

const john = {
  fullName: "John Smith",
  mass: 92,
  height: 1.95,

  calcBMI: function (mass, height) {
    bmi = mass / (height * height);
    return bmi;
  },
};

BMIMark = mark.calcBMI(78, 1.69);
BMIJohn = john.calcBMI(92, 1.95);
//console.log(mark.calcBMI(78, 1.69));
//console.log(john.calcBMI(92, 1.95));

if (BMIMark > BMIJohn) {
  console.log(`Mark's BMI (${BMIMark}) is higher than John's (${BMIJohn})!`);
} else {
  console.log(`John's BMI (${BMIJohn}) is higher than Marks's (${BMIMark})!`);
}
