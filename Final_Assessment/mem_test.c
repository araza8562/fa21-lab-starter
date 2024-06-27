#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct
{
    unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));

unsigned long long data_array[(SIZE_WORDS) / 2];

void storing_data(arr_t *array_to_store_data, unsigned long long *data_array);
void comparison(arr_t *stored_data, arr_t *expected_data);

arr_t store_byte_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] =
    { // double_word0         double_word1
        {0x00000000000000EF, 0x0000000000000000},
        {0x000000000000BE00, 0x0000000000000000},
        {0x0000000000AD0000, 0x0000000000000000},
        {0x00000000DE000000, 0x0000000000000000},
        {0x000000EF00000000, 0x0000000000000000},
        {0x0000BE0000000000, 0x0000000000000000},
        {0x00AD000000000000, 0x0000000000000000},
        {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_half_word_expected_data[8] =
    {
        {0x000000000000BEEF, 0x0000000000000000},
        {0x0000000000ADBE00, 0x0000000000000000},
        {0x00000000DEAD0000, 0x0000000000000000},
        {0x000000EFDE000000, 0x0000000000000000},
        {0x0000BEEF00000000, 0x0000000000000000},
        {0x00ADBE0000000000, 0x0000000000000000},
        {0xDEAD000000000000, 0x0000000000000000},
        {0xDE00000000000000, 0x00000000000000EF}};

arr_t store_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_word_expected_data[8] =
    {
        {0x00000000DEADBEEF, 0x0000000000000000},
        {0x000000DEADBEEF00, 0x0000000000000000},
        {0x0000DEADBEEF0000, 0x0000000000000000},
        {0x00DEADBEEF000000, 0x0000000000000000},
        {0xF00DC0DE00000000, 0x0000000000000000},
        {0x0DC0DE0000000000, 0x00000000000000F0},
        {0xC0DE000000000000, 0x000000000000F00D},
        {0xDE00000000000000, 0x0000000000F00DC0}};

arr_t store_double_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_double_word_expected_data[8] =
    {
        {0xDEADBEEFF00DC0DE, 0x0000000000000000},
        {0xADBEEFF00DC0DE00, 0x00000000000000DE},
        {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
        {0xEFF00DC0DE000000, 0x0000000000DEADBE},
        {0xF00DC0DE00000000, 0x00000000DEADBEEF},
        {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
        {0xC0DE000000000000, 0x0000DEADBEEFF00D},
        {0xDE00000000000000, 0x00DEADBEEFF00DC0}};

// Function to store data in the arrays
void storing_data(arr_t *array_to_store_data, unsigned long long *data_array)
{
    for (int i = 0; i < (SIZE_WORDS) / 2; i++)
    {
        int shift_amount = i * (SIZE_WORDS) / 2;                               // Calculate the shift amount
        array_to_store_data[i].double_word[0] = data_array[i] << shift_amount; // Store the values in the first half of the array

        if (shift_amount > 64 - (8 * sizeof(data_array[0]))) // Check if the shift causes overflow into the next 64-bit segment
        {
            unsigned long long overflow = data_array[i] >> (64 - shift_amount);
            array_to_store_data[i].double_word[1] = overflow; // Store the values in the second half of the array if the overflow has occured
        }
    }
}

void comparison(arr_t *stored_data, arr_t *expected_data)
{
    int all_matched = 1; // Assume all comparisons will pass initially

    for (int i = 0; i < (SIZE_WORDS) / 2; i++)
    {
        if (((stored_data[i].double_word[0]) != expected_data[i].double_word[0]) ||
            ((stored_data[i].double_word[1]) != expected_data[i].double_word[1]))
        {
            printf("Test failed\n");
            all_matched = 0; // Set flag to indicate failure
            break;
        }
    }

    if (all_matched)
    {
        printf("Test Passed\n");
    }
}

int store_byte_test()
{
    // EF, BE, AD, DE, EF, BE, AD, DE
    unsigned long long array[8] = {0xEF, 0xBE, 0xAD, 0xDE, 0xEF, 0xBE, 0xAD, 0xDE};
    storing_data(store_byte_data, array);
    comparison(store_byte_data, store_byte_expected_data);
} // store_byte_test

int store_half_word_test()
{
    // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
    unsigned long long array[8] = {0xBEEF, 0xADBE, 0xDEAD, 0xEFDE, 0xBEEF, 0xADBE, 0xDEAD, 0xEFDE};
    storing_data(store_half_word_data, array);
    comparison(store_half_word_data, store_half_word_expected_data);
}

int store_word_test()
{
    // DEADBEEF, F00DC0DE
    unsigned long long array[8] = {0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xDEADBEEF, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE, 0xF00DC0DE};
    storing_data(store_word_data, array);
    comparison(store_word_data, store_word_expected_data);
} // store_word_test

int store_double_word_test()
{
    // 0xDEADBEEFF00DC0DE
    unsigned long long array[8] = {0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE, 0xDEADBEEFF00DC0DE};
    storing_data(store_double_word_data, array);
    comparison(store_double_word_data, store_double_word_expected_data);
} // store_double_word_test

int main()
{
    printf("Checking for store_byte_test \n");
    store_byte_test();
    printf("Checking for store_half_word_test \n");
    store_half_word_test();
    printf("Checking for store_word_test \n");
    store_word_test();
    printf("Checking for store_double_word_test \n");
    store_double_word_test();
} // main