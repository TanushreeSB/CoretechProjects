# CoreTechProjects

This repository contains a collection of projects developed for various Computer Science Engineering (CSE) subjects. 
Each project showcases a different technology and its application, providing hands-on experience with real-world problems.

## Table of Contents
- [I) C](#i-c)
- [II) C++](#ii-c++)
- [III) Java: Weather Forecast](#iii-java-weather-forecast)
- [IV) Python](#iv-python)
- [V) OS: Bank Simulation System](#v-os-bank-simulation-system)
- [VI) DBMS](#vi-dbms)
- [VII) ML](#vii-ml)
- [VIII) Data Science](#viii-data-science)
- [IX) DSA](#ix-dsa)
- [X) SEPM](#x-sepm)
- [XI) CN: Email Deliver](#xi-cn-email-deliver)

---

## I) C: Expense Tracker

### Features:
1. **Input Validation**: Ensures only valid input is accepted, such as positive expense amounts and valid date formats.
2. **Dynamic Memory Allocation**: Uses dynamic memory for handling an adjustable number of expenses.
3. **File Persistence**: Saves expenses to `expenses.txt`, allowing data to persist between sessions.
4. **Date Validation**: Verifies that the entered date follows the DD-MM-YYYY format.
5. **Modular Design**: Code is organized into smaller functions with clear responsibilities, improving readability and maintainability.
6. **Search Functionality**: Users can search expenses by category, date, or amount range.
7. **Expense Editing and Deletion**: Enables modification or deletion of specific expenses, offering flexibility in managing data.

---

## II) C++: [Project Name]



---

## III) Java: Weather Forecast

### Features:
1. **Real-Time Weather Information**: Provides users with up-to-date weather data.
2. **Secure Data Retrieval**: Utilizes Java's `HttpURLConnection` to securely fetch weather information from external APIs.
3. **OpenWeatherMap API Integration**: Integrates with the OpenWeatherMap API to provide comprehensive weather details.


---

## IV) Python: Music Player App

A GUI-based Music Player built with Tkinter and Pygame.
Users can load songs from a folder, play, pause, resume, and stop them easily.

- Install dependencies first:

pip install pygame


---

## V) OS: Bank Simulation System

### Features:
1. **Bank Account Operations**: Users can create accounts, deposit funds, withdraw money, transfer funds, and check balances.
2. **Transaction Logging**: Logs every transaction with timestamps to provide a detailed history.
3. **Interest Application**: Simulates interest calculation on account balances.
4. **Account Deletion**: Users can delete accounts by entering the account number.
5. **Multi-Account Management**: Supports managing multiple accounts within the system.
6. **Customer Interaction**: A text-based menu allows customers to perform various banking operations.
7. **Real-Time Transaction History**: Users can view transaction logs and track their financial activity.
8. **Dynamic Account Creation**: Allows for creating new accounts dynamically during runtime.
9. **Balance Check**: Users can check the current balance of their accounts.
10. **Input Validation**: Ensures the user provides valid input for different banking operations.

### OS Principles Used:
1. **Concurrency**: Simulates concurrent access where multiple users can perform actions simultaneously.
2. **Synchronization**: Ensures safe access to shared resources, such as bank accounts, using locking mechanisms (mutex).
3. **Atomicity**: Ensures that transactions (deposit, withdrawal, transfer) either complete fully or fail, preserving system consistency.
4. **Resource Management**: Bank accounts are managed efficiently, ensuring no resource conflicts.
5. **Memory Management**: Dynamically allocates memory for bank accounts during runtime.
6. **Input/Output Operations**: Handles user inputs for transactions and outputs transaction logs and balances.
7. **Error Handling**: Manages errors like insufficient funds or invalid inputs.
8. **Time Management**: Tracks transaction timestamps, similar to scheduling in OS processes.
9. **State Management**: Tracks account state (balance, transaction history), similar to process state tracking in OS.
10. **User Interaction**: Prompts users for input and feedback, similar to interactive OS environments.

---

## VI) DBMS: Library Management System

The Library Management System is a web-based application designed to manage the daily operations of a library efficiently. It provides separate login access for students and teachers, allowing each user type to perform role-specific actions such as viewing, borrowing, and managing books. The system also includes functionalities for handling new arrivals, archived books, and fee management

User Roles

# Student Login:

  View available books
  
  Borrow or return books
  
  Check due dates and pending fees

# Teacher Login:

  Add, update, or remove books
  
  Manage archived and new book sections
  
  Track student borrowing records

# Book Management

  Categorization of books into:
  
  New Books – Recently added to the library
  
  Archived Books – Old or reference-only books
  
  Search and filter books by title, author, or category

Real-time availability status

# Fee Management

  Automatic fine calculation for late returns
  
  Payment tracking and history for students
  
  Admin overview of total collected fees

  <img width="1600" height="802" alt="image" src="https://github.com/user-attachments/assets/0fe8182e-cc98-4224-8544-dcb0ae6ece35" />

<img width="1600" height="820" alt="image" src="https://github.com/user-attachments/assets/04ce7161-eca0-4e80-af7a-3cc7116d8ea5" />

<img width="1600" height="843" alt="image" src="https://github.com/user-attachments/assets/e5f31302-80b9-4a74-bd0f-589d5fd8fb15" />

<img width="1600" height="816" alt="image" src="https://github.com/user-attachments/assets/852ee9dc-e113-4c11-aacd-2bd72ab1775a" />

<img width="1561" height="980" alt="image" src="https://github.com/user-attachments/assets/02c5abcf-52c2-4970-9556-3d28b7d46ee6" />
<img width="1600" height="809" alt="image" src="https://github.com/user-attachments/assets/1a8f9523-056f-4894-a24d-35066b80b442" />

<img width="1561" height="969" alt="image" src="https://github.com/user-attachments/assets/49ab1aea-5e3c-4a82-b19f-4754896dece9" />

<img width="1600" height="675" alt="image" src="https://github.com/user-attachments/assets/4f5b5b72-4913-4574-a793-6dbb6226b4c9" />

<img width="1600" height="877" alt="image" src="https://github.com/user-attachments/assets/26dedde5-02cb-4b5d-b635-99962283ee18" />

<img width="1600" height="802" alt="image" src="https://github.com/user-attachments/assets/b4c0775a-5857-4b8b-998c-15a18255842a" />

<img width="1600" height="822" alt="image" src="https://github.com/user-attachments/assets/16c1617b-a9db-498e-a73f-6d2ca96ef4de" />


---

## VII) ML: Pneumonia Disease detection using CNN
1. *AI-Powered Pneumonia Detection*
- Uses a TensorFlow/Keras deep learning model (xray_model.hdf5) trained with 95% accuracy.

- Processes chest X-rays to detect pneumonia or confirm a normal scan.

2. *Advanced Image Preprocessing*
- Enhances X-ray quality using:

- Contrast adjustment (+50%)

- Sharpness enhancement (+20%)

- CLAHE (Contrast Limited Adaptive Histogram Equalization) for better clarity.

- Resizes images to 180x180 pixels for model compatibility.

3. *User-Friendly Interface*
- Real-time upload & analysis: Drag-and-drop X-rays for instant results.

- Sidebar with technical details:

- Model architecture summary.

- Original image metadata (size, format).

4. *Clear visual output:*

- Displays original vs. enhanced X-ray side by side.

- Color-coded results (red for pneumonia, green for normal).

5.  *Medical Guidance & Emergency Advice*
- Tailored recommendations based on results:

- If pneumonia detected: Urgent care steps, warning signs, and ER advice.

- If normal: Preventive measures and follow-up tips.

- Symptom checklist (expandable section) for user reference.

6. *Automated PDF Report Generation*
- Professional report includes:

- Timestamp, filename, diagnosis, and confidence level.

- Customized medical advice.

- Disclaimer for professional review.

- One-click download (PDF format).

7. *Performance & Caching*
- Caches the TensorFlow model to avoid reloading.

- Processes images in 10-15 seconds (with progress spinner).

  <img width="1600" height="829" alt="image" src="https://github.com/user-attachments/assets/ee089974-f58a-4c78-811f-8a9cc9660209" />   <img width="1600" height="810" alt="image" src="https://github.com/user-attachments/assets/0a2584ae-95a6-4bfa-8985-b4854a7f432d" />

 <img width="1600" height="860" alt="image" src="https://github.com/user-attachments/assets/af2fa17a-cf10-4222-a7b9-f476adfedb0f" />   <img width="1600" height="823" alt="image" src="https://github.com/user-attachments/assets/40916bfa-2a33-43f3-8ddd-58f03e695327" />


<img width="1600" height="822" alt="image" src="https://github.com/user-attachments/assets/37a8e2b1-92a8-468e-8451-5f58ae3dfdc2" />



---

## VIII) Data Science : Crypto Currency Price Prediction
1. Requirements:
matplotlib==3.4.2
seaborn==0.9.0
numpy==1.21.1
pandas==1.3.0
scikit_learn==1.0.2

2. dataset: https://www.kaggle.com/sudalairajkumar/cryptocurrencypricehistory
   
3. This is a regression problem where we need to predict the price of Bitcoin Crypto currency. We use Linear, Lasso Regression and Decision tree Regressor

4. MODELS USED

- Logistic Regression= simplest and most common algorithm used for classification problems
- Lasso Regression
- Decision Tree Regressor

5. ACCURACIES

- Logistic Regression Score = 0.9994141897222906
- Lasso Regression Score = 0.9992782274568394
- Random Forest Regressor Score = 0.7965644733090571

CONCLUSION

We can conclude that Linear Regression gives the most accurate results specifically for this problem statement.


---

## IX) DSA



---

## X) SEPM: Leaf Disease Detection and Cure Tips Recommendation System
1. This is a leaf disease detection and cure tips system wherein user can easily upload image of leaf to find the disease.
2. Cure tips will be provided, disease of leaf predicted through confidence score
3. Both heathy and diseased can be distinguished.

<img width="917" height="481" alt="image" src="https://github.com/user-attachments/assets/8f38b2bf-7fc2-4e43-94aa-504ddb8878b4" />

<img width="940" height="426" alt="image" src="https://github.com/user-attachments/assets/498ca633-9616-49ca-8cd9-24a0b7d538f9" />

<img width="940" height="449" alt="image" src="https://github.com/user-attachments/assets/a76389a5-b4a6-417b-a1ee-a6d32a8e3859" />

<img width="940" height="446" alt="image" src="https://github.com/user-attachments/assets/ea7b1719-253c-4e36-b454-eb298bce0d41" />

<img width="685" height="345" alt="image" src="https://github.com/user-attachments/assets/9fc5fe9b-2da6-4b3d-b35f-872cd8687a99" />

<img width="940" height="476" alt="image" src="https://github.com/user-attachments/assets/5e238b7c-eaba-4f9c-bf59-cd79cbf5f950" />

---

## XI) CN: Email Deliver

### Features:
1. It uses SMTP protocol and we can directly send messages to one's email ID.
2. It's easy to use

---

### Contributing:
Feel free to contribute to any of the projects! To get started:
1. Fork the repository.
2. Create a new branch.
3. Make your changes.
4. Submit a pull request.

---
