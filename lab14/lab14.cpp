#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int arr[MAX_SIZE];
    int size;
    int option;

    // Ввід розміру масиву
    printf_s("Введіть розмір масиву (не більше %d): ", MAX_SIZE);
    scanf_s("%d", &size);

    // Ввід елементів масиву
    printf_s("Введіть елементи масиву:\n");
    for (int i = 0; i < size; i++) {
        printf_s("arr[%d]: ", i);
        scanf_s("%d", &arr[i]);
    }

    // Вибір дії
    printf_s("Оберіть дію:\n");
    printf_s("0 - Знаходження мінімального та максимального елементів, їх позицій та дистанції між ними\n");
    printf_s("1 - Знаходження середнього значення елементів\n");
    printf_s("Ваш вибір: ");
    scanf_s("%d", &option);

    switch (option) {
    case 0:
        // Знаходження мінімального та максимального елементів та їх позицій
    {
        int* min_ptr = arr;
        int* max_ptr = arr;
        for (int i = 1; i < size; i++) {
            if (*(arr + i) < *min_ptr) {
                min_ptr = arr + i;
            }
            if (*(arr + i) > *max_ptr) {
                max_ptr = arr + i;
            }
        }

        // Обчислення відстані між позиціями мінімального та максимального елементів
        int distance = max_ptr - min_ptr;

        // Виведення результатів
        printf_s("Мінімальний елемент: %d (позиція %ld)\n", *min_ptr, min_ptr - arr);
        printf_s("Максимальний елемент: %d (позиція %ld)\n", *max_ptr, max_ptr - arr);
        printf_s("Відстань між позиціями: %d\n", distance);
    }
    break;
    case 1:
        // Знаходження суми елементів масиву
    {
        int sum = 0;
        int* ptr = arr;
        for (int i = 0; i < size; i++) {
            sum += *ptr;
            ptr++;
        }

        // Обчислення середнього значення елементів
        float average = (float)sum / size;

        // Виведення результатів
        printf_s("Середнє значення елементів масиву: %.2f\n", average);
    }
    break;
    default:
        printf_s("Невірний вибір опції.\n");
        break;
    }

    return 0;
}
