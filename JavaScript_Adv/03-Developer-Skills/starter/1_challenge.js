// PROBLEM 1:
// We work for a company building a smart home thermometer. Our most recent task is this:
// "Given an array of temperatures of one day, calculate the temperature amplitude.
// Keep in mind that sometimes there might be a sensor error." (amplitude is max - min)

const temperatures = [3, -2, -6, -1, "error", 9, 13, 17, 15, 14, 9, 5];
let maxTemp = temperatures[0];
let minTemp = temperatures[0];

for (let i = 0; i < temperatures.length; i++) {
  if (typeof temperatures[i] == "string") continue;
  if (temperatures[i] > maxTemp) maxTemp = temperatures[i];
  if (temperatures[i] < minTemp) minTemp = temperatures[i];
  //console.log(minTemp);
}

const amplitude = maxTemp - minTemp;
console.log(amplitude);
