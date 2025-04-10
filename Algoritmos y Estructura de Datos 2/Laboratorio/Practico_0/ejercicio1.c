#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ARRAY_SIZE 4
struct bound_data {
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length) {
    struct bound_data result = {true, true, false, 0};
    
    for (unsigned int i = 0; i < length; i++) {
        if (arr[i] > value) {
            result.is_upperbound = false;
        }
        if (arr[i] < value) {
            result.is_lowerbound = false;
        }
        if (arr[i] == value && !result.exists) {
            result.exists = true;
            result.where = i;
        }
    }
    return result;
}

int main() {
    int a[ARRAY_SIZE] = {0, -1, 9, 4};
    int value=9;
    
    struct bound_data result = check_bound(value, a, ARRAY_SIZE);
    
    printf("is_upperbound: %s\n", result.is_upperbound ? "true" : "false");
    printf("is_lowerbound: %s\n", result.is_lowerbound ? "true" : "false");
    printf("exists: %s\n", result.exists ? "true" : "false");
    if (result.exists) {
        printf("where: %u\n", result.where);
    }
    
    return 0;
}
