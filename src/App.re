/* Get annual salary from arguments */
/* let annualSalary = Array.length(Sys.argv) > 2 ? int_of_string(Sys.argv[2]) : 0 */
let annualSalary = switch(Array.length(Sys.argv) > 2) {
  | true => int_of_string(Sys.argv[2])
  | false => 0
}

Js.log("The annual salary is: "++string_of_int(annualSalary));

/* Determine tax brackeet */

/*=if(B1<=18200,"Tax Bracket 1",IF(AND(B1>18200,B1 <=37000),"Tax Bracket 2",IF(AND(B1>37000,B1 <=90000),"Tax Bracket 3",IF(AND(B1>90000,B1 <=180000),"Tax Bracket 4",IF(B1>180000,"Tax Bracket 5")))))*/



/* let taxBracket = switch(taxBracket)  */