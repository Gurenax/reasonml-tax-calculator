// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Sys = require("bs-platform/lib/js/sys.js");
var Caml_array = require("bs-platform/lib/js/caml_array.js");
var Pervasives = require("bs-platform/lib/js/pervasives.js");
var Caml_format = require("bs-platform/lib/js/caml_format.js");

var match = Sys.argv.length > 2;

var annualSalary = match ? Caml_format.caml_float_of_string(Caml_array.caml_array_get(Sys.argv, 2)) : 0.0;

console.log("The annual salary is: " + Pervasives.string_of_float(annualSalary));

function calculateTaxBracket(salary) {
  if (salary <= 18200.0) {
    return "Tax Bracket 1";
  } else if (salary > 18200.0 && salary <= 37000.0) {
    return "Tax Bracket 2";
  } else if (salary > 37000.0 && salary <= 90000.0) {
    return "Tax Bracket 3";
  } else if (salary > 90000.0 && salary <= 180000.0) {
    return "Tax Bracket 4";
  } else if (salary > 180000.0) {
    return "Tax Bracket 5";
  } else {
    return "None";
  }
}

var taxBracket = calculateTaxBracket(annualSalary);

console.log("The tax bracket is: " + taxBracket);

function calculateAnnualTax(salary) {
  var taxBracket = calculateTaxBracket(salary);
  var compute = function (nSalary, num1, num2, num3) {
    return (nSalary - num1) * num2 + num3;
  };
  switch (taxBracket) {
    case "None" : 
    case "Tax Bracket 1" : 
        return 0.0;
    case "Tax Bracket 2" : 
        return compute(salary, 18200.0, 0.19, 0.0);
    case "Tax Bracket 3" : 
        return compute(salary, 37000.0, 0.325, 3572.0);
    case "Tax Bracket 4" : 
        return compute(salary, 90000.0, 0.37, 20797.0);
    case "Tax Bracket 5" : 
        return compute(salary, 180000.0, 0.45, 54097.0);
    default:
      return 0.0;
  }
}

var annualTax = calculateAnnualTax(annualSalary);

console.log("The annual tax is: " + Pervasives.string_of_float(annualTax));

function calculateAnnualTaxedIncome(annualSalary, annualTax) {
  return annualSalary - annualTax;
}

var annualTaxedIncome = annualSalary - annualTax;

console.log("The annual taxed income is: " + Pervasives.string_of_float(annualTaxedIncome));

function calculateIncomeLessMedicalLevy(taxedSalary, annualSalary) {
  return taxedSalary - annualSalary * 0.02;
}

var incomeLessMedicalLevy = calculateIncomeLessMedicalLevy(annualTaxedIncome, annualSalary);

console.log("The annual taxed income less medical levy(2%) is: " + Pervasives.string_of_float(incomeLessMedicalLevy));

function calculateMonthlyNetEarnings(taxedSalary) {
  return taxedSalary / 12.0;
}

var monthlyNetEarnings = incomeLessMedicalLevy / 12.0;

console.log("The monthly net earnings is: " + Pervasives.string_of_float(monthlyNetEarnings));

exports.annualSalary = annualSalary;
exports.calculateTaxBracket = calculateTaxBracket;
exports.taxBracket = taxBracket;
exports.calculateAnnualTax = calculateAnnualTax;
exports.annualTax = annualTax;
exports.calculateAnnualTaxedIncome = calculateAnnualTaxedIncome;
exports.annualTaxedIncome = annualTaxedIncome;
exports.calculateIncomeLessMedicalLevy = calculateIncomeLessMedicalLevy;
exports.incomeLessMedicalLevy = incomeLessMedicalLevy;
exports.calculateMonthlyNetEarnings = calculateMonthlyNetEarnings;
exports.monthlyNetEarnings = monthlyNetEarnings;
/* annualSalary Not a pure module */
