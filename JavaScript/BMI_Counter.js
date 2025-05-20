function bmi(height, weight) {
  var h = parseFloat(height) / 100;
  var w = parseFloat(weight);
  var bmi = (w / h / h).toFixed(2);
  return bmi;
}
console.log(bmi(173, 52));
