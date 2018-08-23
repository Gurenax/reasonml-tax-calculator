/* Get annual salary from arguments */
/* let annualSalary = Array.length(Sys.argv) > 2 ? int_of_string(Sys.argv[2]) : 0 */
let annualSalary = switch(Array.length(Sys.argv) > 2) {
  | true => int_of_string(Sys.argv[2])
  | false => 0
}

Js.log("The annual salary is: "++string_of_int(annualSalary));

/* Function to calculate the tax brackeet */
let calculateTaxBracket = salary => {
    if(salary <= 18200) { "Tax Bracket 1" }
    else if(salary > 18200 && salary <= 37000) { "Tax Bracket 2" }
    else if(salary > 37000 && salary <= 90000) { "Tax Bracket 3" }
    else if(salary > 90000 && salary <= 180000) { "Tax Bracket 4" }
    else if(salary > 180000) { "Tax Bracket 5" }
    else "None"
}

/* Calculate the tax bracket */
let taxBracket = calculateTaxBracket(annualSalary)
Js.log(taxBracket)

/* Function to calculate the annual tax */
