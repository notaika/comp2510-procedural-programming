[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/Xkub_r4_)
# Lab 2: Loops, Arrays & Strings

## ⚠️ Important: Autograding & Strict Output
This assignment is auto-graded. The computer looks for **specific text** in your output.
1.  **Do not** change the format of the answer lines (e.g., don't change `Moved to` to `Walking to`).
2.  You can print prompts (like "Enter a word:"), but the **results** must match exactly.
3.  Make sure your code compiles with `gcc -Wall -Wextra`.

---

## Part 1: Palindrome Detector
**File:** `part1.c`

Write a program that checks if a word is a **palindrome** (reads the same forwards and backwards).

**Requirements:**
1.  Use a **`for` loop** to compare characters from the start and end of the string.
2.  **Input:** A single word (no spaces).
3.  **Output:** Print exactly one of the messages below.

**Test Case 1:**
*   Input: `racecar`
*   Output: `Is a palindrome`

**Test Case 2:**
*   Input: `hello`
*   Output: `Not a palindrome`

---

## Part 2: The Dungeon Crawler
**File:** `part2.c`

You are coding the movement engine for a grid-based RPG. The hero starts at **(0, 0)** with **100 Stamina**.

**Requirements:**
1.  **Input:** Read a single string of commands (e.g., `WWSS`).
2.  **Loop:** Use a **`while` loop** to process moves until `\0`, 0 Stamina, or a Trap (`T`).
3.  **Switch & Logic:**
    *   `W`/`S`: Move Y +/- 1. Cost: 1 Stamina.
    *   `D`/`A`: Move X +/- 1. Cost: 1 Stamina.
    *   `P`: Potion (+5 Stamina). Print `> Drank potion.`
    *   `T`: **Trap**. Stop the loop immediately. Print `> TRAP HIT!`
4.  **DRY Rule (Clean Code):**
    *   Use a flag variable (e.g., `int moved = 0;`) inside the loop. 
    *   Print `> Hero moved to (x, y)` **only once** per iteration, and only if a move occurred.

**Example Run:**
```text
Enter path: WWT
> Hero moved to (0, 1)
> Hero moved to (0, 2)
> TRAP HIT!
Final Position: (0, 2), Stamina: 98