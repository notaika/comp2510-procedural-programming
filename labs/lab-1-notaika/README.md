[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/P7LOX4wp)
Welcome to your first lab! This repository contains 3 C programs.

1.  **`ex1_finance.c`**: Needs debugging (Calculations are wrong).
2.  **`ex2_access.c`**: Needs debugging (Security flaws).
3.  **`ex3_shipping.c`**: Needs logic (You must write the code).

Your goal is to fix the broken programs and implement the missing logic for the coin machine.

## Instructions

1.  **Clone** this repository to your local machine.
2.  **Compile** the files using `gcc` with the warning flags
    *   *Example:* `gcc -g -Wall -Wextra -Werror -std=c2x ex1_finance.c -o ex1`
3.  **Run** the executable.
    *   *Example:* `./ex1`
4.  **Observe** the output. Does it match what the program *should* do?
5.  **Fix/Edit** the code in your text editor.
6.  **Fill out the "Lab Report"** at the bottom of this README.
7.  **Commit** your changes and **Push** back to GitHub.

---

## The Exercises

### Exercise 1: Finance (`ex1_finance.c`)
This program attempts to calculate a year-end salary with a 10% bonus.
*   **The Problem:** The math is wrong, and the output prints wrong numbers.
*   **Your Job:** Fix the issues and report below!

### Exercise 2: Access Control (`ex2_access.c`)
This is a security system that requires a specific PIN (`1234`) to disarm.
*   **The Problem:** The system lets everyone in, no matter what number they type. Also, the output messages look messy.
*   **Your Job:** Fix the issues and report below!

### Exercise 3: Jungle Shipping (`ex3_shipping.c`)
This program calculates the shipping cost for a package based on weight, distance, and speed.
*   **The Problem:** The code logic is missing! The program runs, but costs are always $0.00.
*   **Your Job:** Write the logic to implement the pricing rules found in the comments.
    1.  **Validation:** Reject negative weights or distances.
    2.  **Base Cost:** \$5.00 base. Add \$2/kg only for weight *above* 5kg.
    3.  **Distance:** Add $0.10/km only for distance *above* 100km.
    4.  **Express:** Double the total price if the `is_overnight` boolean is `true`.

---

## Lab Report

### Exercise 1: Finance
* **What was the logic bug?**
  > _**Note:**_ I'm assuming that the only salary we're calculating is the `int salary = 50000;`, thus didn't have the
  > need to change `salary` and `final_salary` as a float.  
  > ___
  > Line 9: `float bonus_multiplier = bonus_percentage / 100;`
  >
  > The original statement performed integer division before assigning the result to a float.  
  > 
  > This truncated the decimal values, providing the wrong % calculation, which in this case results in 0.  
  > 
  > By explicitly casting one of the operands to `float`, I forced one of the numbers to be of type `float`
  > and when doing the division, the answer gets automatically promoted to a `float` before assignment.

* **What was the syntax/format bug?**
  > Line 18: Changed `%f` to `%d` in the `printf()` statement.  
  > 
  > Since `final_salary` was declared as an `int`, using `%f` caused the program to misinterpret the variable's memory bits as a float, resulting in incorrect output.


### Exercise 2: Access Control
* **Why did the program allow any password to work?**
  > Line 11: `if user_input = access_code`  
  > 
  > The previous code used an assignment operator (`=`) instead of the equality operator (`==`).
  > With the assignment operator, the if statement would evaluate "true" every time, no matter what the user typed
  > as long as the user input is also a non-zero number.  
  >  
  > Changed assignment operator `=`to the relational (equality) operator `==` to compare the two values properly.

* **How did you fix the "System Disarmed" message printing every time?**
  > The compiler ignores whitespaces and indentation so without the curly braces `{ }` to indicate a block statement,
  > the `if` statement only works on the line IMMEDIATELY right after it, excluding line 13 out of it which causes it to run every time.
  >
  > To fix it, I added surrounding curly brackets `{ }` around the if statement to indicate the bounds of that code block.

### Exercise 3: Shipping Test Case
Run your finished `ex3_shipping.c` with the following inputs. What is the final cost?

**Test Case A:**
*   Weight: `10`
*   Distance: `50`
*   Overnight: `0`
*   **Your Result:** $15.00

**Test Case B:**
*   Weight: `2`
*   Distance: `200`
*   Overnight: `1`
*   **Your Result:** $30.00

**Test Case C (Error Check):**
*   Weight: `-5`
*   **Did your program print an error message?** Yes