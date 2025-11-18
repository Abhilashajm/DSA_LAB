#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int i, N;
    float total = 0;
    struct Employee *emp;

    printf("Enter number of employees: ");
    scanf("%d", &N);

    // Dynamic memory allocation for N employees
    emp = (struct Employee *)malloc(N * sizeof(struct Employee));
    printf("\nSize of structure Employee:%d bytes\n",(int)sizeof(struct Employee));

    if (emp == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Input employee data
    printf("\nEnter employee details:\n");
    for (i = 0; i < N; i++) {
        printf("\nEmployee %d ID: ", i + 1);
        scanf("%d", &emp[i].id);

        printf("Employee %d Name: ", i + 1);
        scanf("%s", emp[i].name);

        printf("Employee %d Salary: ", i + 1);
        scanf("%f", &emp[i].salary);

        total += emp[i].salary;
    }

    // Display total salary expenditure
    printf("\nTotal Annual Salary Expenditure = %.2f\n", total);

    // Free allocated memory
    free(emp);
    sizeof(struct Employee);

    return 0;
}
