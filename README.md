This program implements a basic Bank Management System that allows a user to perform various banking operations such as creating an account, depositing money, withdrawing money, and checking the account details. Below are the main features and components of the code:
Account Class
  Private Members:
    * accountnumber: Stores the account number (generated randomly).
    * name: Stores the name of the account holder.
    * balance: Stores the balance in the account.
  Public Methods:
    * Account(): Default constructor to initialize members.
    * to_string(): Converts an integer to a string (used for account number generation).
    * genAccnorandom(): Generates a 7-digit random account number.
    * createAccount(): Allows the user to create a new account, inputs the name, sets balance to 0, and writes account details to a file.
    * checkaccnumber(): Validates if the entered account number matches the stored one.
    * deposit(): Allows the user to deposit money after verifying the account number.
    * withdraw(): Allows the user to withdraw money after verifying the account number and ensuring sufficient balance.
    * displayAccount(): Displays account details if the account number matches.
