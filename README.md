# CoretechProjects
This repo contains projects made for cse subjects:

I) C
   Project : Expense Tracker
   
   Features:
   
      1) Input Validation: Added validation for the amount to ensure it's a positive number and for the date format.
      
      2) Dynamic Memory Allocation: The program uses dynamic memory for expenses, which will allow handling a variable number of records.
      
      3) File Persistence: Expenses are saved to a file (expenses.txt) and loaded on program start, ensuring data is persistent.
      
      4) Date Validation: A helper function checks if the date is in DD-MM-YYYY format.
      
      5) Modularity: The code is divided into smaller functions, each with a clear responsibility.
      
      6) Search Functionality: Allow the user to search for expenses by category, date, or amount range.
      
      7) Edit or Delete Expenses: Enable the user to modify or delete a specific expense. This feature adds flexibility in managing expenses

II) CPP

III) JAVA: Weather Forecast 

   Features:

- Real-Time Weather Information: The primary objective of this project is to provide users with access to real-time weather data, ensuring the information is current and accurate. This serves to meet the increasing demand for timely weather updates.
      
- Secure Data Retrieval: A key objective is to establish secure and reliable connections with external data sources through the utilization of Java's HTTP capabilities, specifically the HttpURLConnection class. This is vital to ensure the trustworthy retrieval of weather data.
      
- OpenWeatherMap Integration: The project aims to seamlessly integrate with the OpenWeatherMap API, which offers extensive coverage of weather-related information, enhancing the richness and comprehensiveness of the data accessible to users.

IV) Python

V) OS
Project: Bank Simulation System
Features:

### Features:
1. **Bank Account Operations**: Customers can create accounts, deposit funds, withdraw money, transfer funds, and check account balances.
2. **Transaction Logging**: All transactions (deposit, withdrawal, transfer) are logged with timestamps for tracking.
3. **Interest Application**: The system supports applying interest on account balances based on a specified percentage.
4. **Account Deletion**: Users can delete accounts by entering the account number.
5. **Multi-Account Management**: Multiple accounts can be created and managed within the bank system.
6. **Customer Interaction**: Customers interact with the system through a simple text-based menu, selecting actions like deposit, withdrawal, or transfer.
7. **Real-time Transaction History**: Users can view the transaction history for each account, helping track past actions.
8. **Dynamic Account Creation**: New accounts can be created during runtime, simulating real-world banking operations.
9. **Balance Check**: Users can check the current balance of their accounts.
10. **Input Validation**: Ensures users provide valid input for operations like deposit amounts or choosing valid menu options.

### OS Principles Used:
1. **Concurrency**: The system simulates potential concurrent access, where multiple users could perform actions at the same time on different accounts.
2. **Synchronization (Mutual Exclusion)**: In real-world systems, synchronization mechanisms (like mutexes) would be used to avoid race conditions when accessing shared resources (bank accounts).
3. **Atomicity**: Bank operations like withdrawals, deposits, and transfers are atomic, ensuring they either complete fully or fail entirely, preserving system consistency.
4. **Resource Management**: Bank accounts are treated as shared resources, with operations performed on them managed efficiently to avoid conflicts.
5. **Memory Management**: Accounts are created dynamically during runtime, simulating how memory (resources) is allocated in an OS for processes.
6. **Input/Output Operations**: The program handles input from users (deposit amounts, transfer actions) and outputs responses (balances, transaction logs), akin to I/O operations in an OS.
7. **Error Handling**: The program handles errors like insufficient funds or invalid account numbers, which simulates how an OS handles exceptions.
8. **Time Management**: Each transaction is logged with a timestamp, which is akin to managing time in an OS for scheduling and logging activities.
9. **State Management**: The bank system keeps track of the state of each account (balance, transaction history), similar to how an OS tracks the state of processes.
10. **User Interaction**: The system uses user prompts and feedback, similar to how operating systems provide interactive environments for user input.

These features and principles create a simulated banking environment that incorporates core aspects of how operating systems manage resources and concurrent processes.

VI) DBMS

VII) ML

VIII) Data Science

IX) DSA

X) SEPM
