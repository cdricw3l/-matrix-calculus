#include "assertion.h"

void ft_lstnew_test(int test_nb, void *content)
{
    t_list *node;

    #ifdef __APPLE__
        size_t (*f)(const void *ptr);
        f = malloc_size;
    #endif
    #ifdef  __unix__
        size_t (*f)(void *ptr);
        f = malloc_usable_size;
    #endif
    printf("Test %d:\n", test_nb++);

    node = ft_lstnew(content);
    if(!node)
        printf("Error allocation in lst_new test nb %d\n", test_nb);
    
    //check the content
    if(node->content == content)
        printf("\tcontent compare ->"TEST_OK"\n");
    else
        printf("\tcontent compare ->"TEST_NOK"\n");
    
    //check the size structure
    if (f(node) == sizeof(t_test))
        printf("\tmemory size of node ->"TEST_OK"\n");
    else
        printf("\tmemory size of node ->"TEST_NOK"\n");

    // check the next node
    if (node->next == NULL)
        printf("\tnode next check ->"TEST_OK"\n");
    else
        printf("\tnode next check ->"TEST_NOK"\n");

    free(node);
}

void ft_lst_new_assert(void)
{
    char *test_name = "ft_lst_new";
    int test_nb;
    TEST_STAR(test_name);
    char *str;
    int r;
    
    test_nb  = 1;

    //test 1
    str = strdup("hello_berlin");
    ft_lstnew_test(test_nb++,str);
    free(str);

    //test 2
    r = 10;
    ft_lstnew_test(test_nb++,&r);

    //test 3
    ft_lstnew_test(test_nb++, NULL);

    TEST_END(test_name);
    SEP;
    NL;
}