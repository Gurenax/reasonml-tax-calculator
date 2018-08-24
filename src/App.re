/* Get annual salary from arguments */
let annualSalary = switch(Array.length(Sys.argv) > 2) {
  | true => float_of_string(Sys.argv[2])
  | false => 0.0
}
Js.log("The annual salary is: "++string_of_float(annualSalary))

/* Function to calculate the tax brackeet */
let calculateTaxBracket = (salary: float) : string => {
    if(salary <= 18200.0) { "Tax Bracket 1" }
    else if(salary > 18200.0 && salary <= 37000.0) { "Tax Bracket 2" }
    else if(salary > 37000.0 && salary <= 90000.0) { "Tax Bracket 3" }
    else if(salary > 90000.0 && salary <= 180000.0) { "Tax Bracket 4" }
    else if(salary > 180000.0) { "Tax Bracket 5" }
    else "None"
}

/* Calculate the tax bracket */
let taxBracket = calculateTaxBracket(annualSalary)
Js.log("The tax bracket is: "++taxBracket)

/* Function to calculate the annual tax */
let calculateAnnualTax = (salary: float) : float => {
  /* Calculate the tax bracket */
  let taxBracket = calculateTaxBracket(salary)

  /* Computing floats require . after their operator */
  let compute = (nSalary: float, num1: float, num2: float, num3: float) : float => (nSalary -. num1) *. num2 +. num3

  switch(taxBracket) {
    | "Tax Bracket 1" => 0.0
    | "Tax Bracket 2" => compute(salary, 18200.0, 0.19, 0.0)
    | "Tax Bracket 3" => compute(salary, 37000.0, 0.325, 3572.0)
    | "Tax Bracket 4" => compute(salary, 90000.0, 0.37, 20797.0)
    | "Tax Bracket 5" => compute(salary, 180000.0, 0.45, 54097.0)
    | _ => 0.0
  }
}

/* Calculate the annual tax */
let annualTax = calculateAnnualTax(annualSalary)
Js.log("The annual tax is: "++string_of_float(annualTax))


/* Function to calculate income less annual tax */
let calculateIncomeLessAnnualTax = (annualSalary: float, annualTax: float): float => annualSalary -. annualTax

/* Calculate income less annual tax */
let incomeLessAnnualTax = calculateIncomeLessAnnualTax(annualSalary, annualTax)
Js.log("The income less annual tax is: "++string_of_float(incomeLessAnnualTax))

/* Function to calculate income less medical levy */
let calculateIncomeLessMedicalLevy = (taxedSalary: float, annualSalary: float): float => {
  let medicalLevyPercentage = 0.02
  taxedSalary -. (annualSalary *. medicalLevyPercentage)
}

/* Calculate income less medical levy */
let incomeLessMedicalLevy = calculateIncomeLessMedicalLevy(incomeLessAnnualTax, annualSalary)
Js.log("The income less medical levy(2%) is: "++string_of_float(incomeLessMedicalLevy))