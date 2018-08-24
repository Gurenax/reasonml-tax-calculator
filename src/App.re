/* Get annual salary from arguments */
let annualSalary = switch(Array.length(Sys.argv) > 2) {
  | true => float_of_string(Sys.argv[2])
  | false => 0.0
}

/* Function to calculate the tax brackeet */
let calculateTaxBracket = (salary: float) : string => {
    if(salary <= 18200.0) { "Tax Bracket 1" }
    else if(salary > 18200.0 && salary <= 37000.0) { "Tax Bracket 2" }
    else if(salary > 37000.0 && salary <= 90000.0) { "Tax Bracket 3" }
    else if(salary > 90000.0 && salary <= 180000.0) { "Tax Bracket 4" }
    else if(salary > 180000.0) { "Tax Bracket 5" }
    else "None"
}

/* Function to calculate the annual tax */
let calculateAnnualTax = (salary: float) : float => {
  
  /* Calculate the tax bracket */
  let taxBracket = calculateTaxBracket(salary)

  /* Computing floats require . after their operator */
  let compute = (nSalary: float, num1: float, num2: float, num3: float) : float => (nSalary -. num1) *. num2 +. num3

  /* Compute based on Tax Bracket */
  switch(taxBracket) {
    | "Tax Bracket 1" => 0.0
    | "Tax Bracket 2" => compute(salary, 18200.0, 0.19, 0.0)
    | "Tax Bracket 3" => compute(salary, 37000.0, 0.325, 3572.0)
    | "Tax Bracket 4" => compute(salary, 90000.0, 0.37, 20797.0)
    | "Tax Bracket 5" => compute(salary, 180000.0, 0.45, 54097.0)
    | "None" => 0.0
    | _ => 0.0
  }
}

/* Function to calculate annual taxed income */
let calculateAnnualTaxedIncome = (annualSalary: float, annualTax: float): float => annualSalary -. annualTax

/* Function to calculate income less medical levy */
let calculateIncomeLessMedicalLevy = (taxedSalary: float, annualSalary: float): float => {
  let medicalLevyPercentage = 0.02
  taxedSalary -. (annualSalary *. medicalLevyPercentage)
}

/* Function to calculate monthly net earnings */
let calculateMonthlyNetEarnings = (taxedSalary: float) : float => taxedSalary /. 12.0

/*
 * Output
 */
Js.log("The annual salary is: "++string_of_float(annualSalary))

/* Calculate the tax bracket */
let taxBracket = calculateTaxBracket(annualSalary)
Js.log("The tax bracket is: "++taxBracket)

/* Calculate the annual tax */
let annualTax = calculateAnnualTax(annualSalary)
Js.log("The annual tax is: "++string_of_float(annualTax))

/* Calculate the annual taxed income */
let annualTaxedIncome = calculateAnnualTaxedIncome(annualSalary, annualTax)
Js.log("The annual taxed income is: "++string_of_float(annualTaxedIncome))

/* Calculate income less medical levy */
let incomeLessMedicalLevy = calculateIncomeLessMedicalLevy(annualTaxedIncome, annualSalary)
Js.log("The annual taxed income less medical levy(2%) is: "++string_of_float(incomeLessMedicalLevy))

/* Calculate monthly net earnings */
let monthlyNetEarnings = calculateMonthlyNetEarnings(incomeLessMedicalLevy)
Js.log("The monthly net earnings is: "++string_of_float(monthlyNetEarnings))