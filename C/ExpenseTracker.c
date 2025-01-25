#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Define the structure for an expense
struct Expense {
    float amount;
    char category[30];
    char date[11]; // Format: DD-MM-YYYY
    char description[100];
};

// Function prototypes
void addExpense();
void viewExpenses();
void calculateTotal();
void saveExpensesToFile();
void loadExpensesFromFile();
int isValidDate(const char* date);

#define MAX_EXPENSES 100
struct Expense* expenses = NULL;
int expenseCount = 0;

int main() {
    int choice;

    // Load expenses from file (if any)
    loadExpensesFromFile();

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Clear the newline character from input buffer

        switch (choice) {
            case 1:
                addExpense();
                break;
            case 2:
                viewExpenses();
                break;
            case 3:
                calculateTotal();
                break;
            case 4:
                saveExpensesToFile();
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void addExpense() {
    if (expenses == NULL) {
        expenses = (struct Expense*)malloc(sizeof(struct Expense) * MAX_EXPENSES);
    }

    struct Expense newExpense;

    printf("Enter amount: ");
    while (scanf("%f", &newExpense.amount) != 1 || newExpense.amount <= 0) {
        printf("Invalid amount. Please enter a positive number: ");
        while(getchar() != '\n'); // Clear the input buffer
    }
    getchar(); // Clear newline

    printf("Enter category: ");
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // Remove newline

    printf("Enter date (DD-MM-YYYY): ");
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = 0; // Remove newline

    // Validate date format
    if (!isValidDate(newExpense.date)) {
        printf("Invalid date format. Please use DD-MM-YYYY.\n");
        return;
    }

    printf("Enter description: ");
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

void viewExpenses() {
    if (expenseCount == 0) {
        printf("No expenses recorded yet.\n");
        return;
    }

    printf("\nRecorded Expenses:\n");
    for (int i = 0; i < expenseCount; i++) {
        printf("\nExpense %d:\n", i + 1);
        printf("Amount: %.2f\n", expenses[i].amount);
        printf("Category: %s\n", expenses[i].category);
        printf("Date: %s\n", expenses[i].date);
        printf("Description: %s\n", expenses[i].description);
    }
}

void calculateTotal() {
    if (expenseCount == 0) {
        printf("No expenses to calculate total.\n");
        return;
    }

    float total = 0;
    for (int i = 0; i < expenseCount; i++) {
        total += expenses[i].amount;
    }

    printf("\nTotal Expenses: %.2f\n", total);
}

void saveExpensesToFile() {
    FILE* file = fopen("expenses.txt", "w");
    if (!file) {
        printf("Unable to open file for saving.\n");
        return;
    }

    for (int i = 0; i < expenseCount; i++) {
        fprintf(file, "%.2f,%s,%s,%s\n", expenses[i].amount, expenses[i].category, expenses[i].date, expenses[i].description);
    }

    fclose(file);
}

void loadExpensesFromFile() {
    FILE* file = fopen("expenses.txt", "r");
    if (!file) {
        return; // If no file exists, just return.
    }

    expenses = (struct Expense*)malloc(sizeof(struct Expense) * MAX_EXPENSES);
    while (fscanf(file, "%f,%29[^,],%10[^,],%99[^\n]\n", &expenses[expenseCount].amount, expenses[expenseCount].category, expenses[expenseCount].date, expenses[expenseCount].description) == 4) {
        expenseCount++;
    }

    fclose(file);
}

int isValidDate(const char* date) {
    if (strlen(date) != 10) return 0;

    // Check if the date format is correct
    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5) {
            if (date[i] != '-') return 0;
        } else if (!isdigit(date[i])) {
            return 0;
        }
    }
    return 1;
}
