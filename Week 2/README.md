# CS 310 – C++ Programming

## 💳 Credit Card Interest Calculator

This program calculates the **interest on an unpaid credit card balance** using the **average daily balance method**.

## 📘 Description

The program accepts the following inputs:

* Net balance (balance shown on the bill)
* Payment amount
* Number of days in the billing cycle (`d1`)
* Number of days payment was made before the end of the cycle (`d2`)
* Monthly interest rate

It then computes:

1. **Average Daily Balance**
2. **Interest charged for the month**

## 🧮 Formula Used

Average Daily Balance:
[
(\text{netBalance} \times d1 - \text{payment} \times d2) / d1
]

Interest:
[
\text{averageDailyBalance} \times \text{interestRate}
]

## ⚙️ Features

* Uses user input for all financial values
* Calculates interest based on real-world credit card formulas
* Formats output to:

  * Two decimal places
  * Includes thousands separator for readability

## 🚀 How to Run

1. Compile the program:

   ```bash
   g++ main.cpp -o Ch03Exercise07.cpp
   ```

2. Run the program:

   ```bash
   ./Ch03Exercise07
   ```

## 👥 Contributors

* Robert Flowers
* Drew Winkles

## 📌 Example Output

```
Average Daily Balance: $1,234.56
Interest: $18.76
```
