#include <sum.h>
#include <munit.h>

static MunitResult test_sum(
    const MunitParameter params[],
    void *data
)
{
    (void) params;
    (void) data;

    int result = sum(2, 3);

    munit_assert_int(result, ==, 5);

    return MUNIT_OK;
}

static MunitTest tests[] = {
    {
        "/two-positive-numbers",
        test_sum,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    },
    {
        NULL,
        NULL,
        NULL,
        NULL,
        MUNIT_TEST_OPTION_NONE,
        NULL
    }
};

static const MunitSuite suite = {
    "/sum",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[])
{
    return munit_suite_main(&suite, NULL, argc, argv);
}