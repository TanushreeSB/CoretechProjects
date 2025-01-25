#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Expense {
    float amount;
    char category[30];
    char date[11]; // Format: DD-MM-YYYY
    char description[100];
};

void addExpense();
void viewExpenses();
void calculateTotal();
void editExpense();
void deleteExpense();
void viewExpensesByCategory();

#define MAX_EXPENSES 100
struct Expense expenses[MAX_EXPENSES];
int expenseCount = 0;

int main() {
    int choice;

    while (1) {
        printf("\nExpense Tracker\n");
        printf("1. Add Expense\n");
        printf("2. View Expenses\n");
        printf("3. Calculate Total Expenses\n");
        printf("4. Exit\n");
        printf("5. Edit Expense\n");
        printf("6. Delete Expense\n");
        printf("7. View Expenses by Category\n");
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
                printf("Exiting...\n");
                exit(0);
            case 5:
                editExpense();
                break;
            case 6:
                deleteExpense();
                break;
            case 7:
                viewExpensesByCategory();
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Add a new expense
void addExpense() {
    if (expenseCount >= MAX_EXPENSES) {
        printf("Expense limit reached. Cannot add more expenses.\n");
        return;
    }

    struct Expense newExpense;

    printf("Enter amount: ");
    scanf("%f", &newExpense.amount);
    getchar(); // Clear the newline character

    printf("Enter category: ");
    fgets(newExpense.category, sizeof(newExpense.category), stdin);
    newExpense.category[strcspn(newExpense.category, "\n")] = 0; // Remove newline

    printf("Enter date (DD-MM-YYYY): ");
    fgets(newExpense.date, sizeof(newExpense.date), stdin);
    newExpense.date[strcspn(newExpense.date, "\n")] = 0; // Remove newline

    printf("Enter description: ");
    fgets(newExpense.description, sizeof(newExpense.description), stdin);
    newExpense.description[strcspn(newExpense.description, "\n")] = 0; // Remove newline

    expenses[expenseCount++] = newExpense;
    printf("Expense added successfully!\n");
}

// View all recorded expenses
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

// Calculate the total expenses
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

// Edit an existing expense
void editExpense() {
    int index;
    printf("Enter the expense number to edit (1 to %d): ", expenseCount);
    scanf("%d", &index);
    getchar(); // Clear the newline character

    if (index < 1 || index > expenseCount) {
        printf("Invalid expense number.\n");
        return;
    }

    index--; // Convert to 0-based index

    printf("Editing Expense %d:\n", index + 1);
    printf("Current Amount: %.2f\n", expenses[index].amount);
    printf("Enter new amount: ");
    scanf("%f", &expenses[index].amount);
    getchar(); // Clear the newline character

    printf("Current Category: %s\n", expenses[index].category);
    printf("Enter new category: ");
    fgets(expenses[index].category, sizeof(expenses[index].category), stdin);
    expenses[index].category[strcspn(expenses[index].category, "\n")] = 0;

    printf("Current Date: %s\n", expenses[index].date);
    printf("Enter new date (DD-MM-YYYY): ");
    fgets(expenses[index].date, sizeof(expenses[index].date), stdin);
    expenses[index].date[strcspn(expenses[index].date, "\n")] = 0;

    printf("Current Description: %s\n", expenses[index].description);
    printf("Enter new description: ");
    fgets(expenses[index].description, sizeof(expenses[index].description), stdin);
    expenses[index].description[strcspn(expenses[index].description, "\n")] = 0;

    printf("Expense edited successfully!\n");
}

// Delete an existing expense
void deleteExpense() {
    int index;
    printf("Enter the expense number to delete (1 to %d): ", expenseCount);
    scanf("%d", &index);
    getchar(); // Clear the newline character

    if (index < 1 || index > expenseCount) {
        printf("Invalid expense number.\n");
        return;
    }

    index--; // Convert to 0-based index

    for (int i = index; i < expenseCount - 1; i++) {
        expenses[i] = expenses[i + 1]; // Shift expenses to fill the deleted one
    }

    expenseCount--;
    printf("Expense deleted successfully!\n");
}

// View expenses by category
void viewExpensesByCategory() {
    char category[30];
    printf("Enter category to view: ");
    fgets(category, sizeof(category), stdin);
    category[strcspn(category, "\n")] = 0;

    int found = 0;
    printf("\nExpenses in category %s:\n", category);
    for (int i = 0; i < expenseCount; i++) {
        if (strcmp(expenses[i].category, category) == 0) {
            printf("Amount: %.2f | Date: %s | Description: %s\n", expenses[i].amount, expenses[i].date, expenses[i].description);
            found = 1;
        }
    }

    if (!found) {
        printf("No expenses found in this category.\n");
    }
}
