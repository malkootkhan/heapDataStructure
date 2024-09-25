#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "heapDS.h"  // Include the header file for the functions

// Test case for the add function
void test_createHeap(void) {
    struct heap *h = createHeap(30);
    CU_ASSERT(h->max_size == 30);
    CU_ASSERT(h->curr_size == 0);
    CU_ASSERT(h != NULL);
}
void test_insert(void)
{


    struct heap *h = createHeap(6);
    insert(h, 10);
    insert(h, 20);
    insert(h, 30);
    insert(h, 40);
    insert(h, 50);

    CU_ASSERT(h->data[0] == 50);
    CU_ASSERT(h->data[1] == 40);
    CU_ASSERT(h->data[2] == 20);
    CU_ASSERT(h->data[3] == 10);
    CU_ASSERT(h->data[4] == 30);

    display(h);
}

int main() {
    // Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry()) {
        return CU_get_error();
    }

    // Create a test suite
    CU_pSuite pSuite = CU_add_suite("heapOperationSuite", 0, 0);
    if (pSuite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test cases to the suite
    if ((CU_add_test(pSuite, "test of test_insert()", test_insert) == NULL) ) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run the tests and display results in basic mode
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();

    // Clean up the CUnit registry
    CU_cleanup_registry();
    return CU_get_error();
}
