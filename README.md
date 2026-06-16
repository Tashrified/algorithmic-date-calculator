# Algorithmic Date Calculator

A C program that calculates the exact number of days between two user-provided dates, with robust handling of leap years, invalid input validation, and automatic date reordering.

## Overview
This project demonstrates the practical application of date arithmetic, conditional logic, and input validation in C. It correctly handles edge cases, including leap years, varying month lengths, and out-of-order date input.

## Features
- **Accurate Day Calculation** — Computes exact day intervals between any two dates
- **Leap Year Logic** — Correctly identifies leap years using the Gregorian calendar rule:
  - Divisible by 4 → leap year
  - Divisible by 100 → NOT a leap year
  - Divisible by 400 → leap year (exception to the 100 rule)
- **Input Validation** — Rejects invalid dates:
  - Month must be 1–12
  - Day must be valid for the given month and year
  - Provides clear error messages for invalid input
- **Automatic Date Reordering** — If you enter dates backwards, the program automatically swaps them and calculates correctly
- **Variable Month Handling** — Accounts for months with 28, 29, 30, and 31 days

## Technical Details
**Data Structures:**
- Array-based lookup table for days per month
- Three integer variables for each date (year, month, day)

**Algorithm:**
- Iterates through all years between the two dates, adding 365 or 366 days based on leap year status
- Subtracts days in months before the first date
- Adds days in months before the second date
- Time Complexity: O(n) where n is the number of years between dates

**Code Quality:**
- Helper functions (`isLeapYear()`, `daysInMonth()`) for code reusability
- Proper input formatting using `%02d` for zero-padded display
- Clear variable naming and logic flow

## How to Run

**Compile:**
```bash
gcc date_calculator.c -o date_calculator
```

**Run:**
```bash
./date_calculator
```

## Example Usage

Enter the first date (MM DD YYYY): 01 15 2025

01/15/2025

Enter the second date (MM DD YYYY): 12 25 2025

12/25/2025

Number of dates between the two dates is: 344

## Edge Cases Tested
✓ Leap years (2024 has 366 days)  
✓ Century years (1900 is NOT a leap year, 2000 IS)  
✓ Invalid dates (02 30 2025 rejected)  
✓ Out-of-order input (automatically reordered)  
✓ Same date (returns 0)  
✓ Dates spanning multiple years  

## Files
- `date_calculator.c` — Main program

## Learning Outcomes
- Date arithmetic and calendar logic
- Input validation and error handling
- Array-based lookup patterns
- Conditional logic and loop structures
- Helper function design
