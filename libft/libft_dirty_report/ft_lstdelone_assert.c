#include "assertion.h"



void ft_lstdelone_test(int test_nb, void *content, void (*f)(void *ptr))
{
    t_list *node;
    pid_t frk;
    int stat;

    printf("Test %d:\n", test_nb);
    if (!content || !f)
    {
        /*
            nul protection check
        */
        frk = fork();
        if( frk < 0)
        {
            printf("Error fork in %s", __func__);
            return ;
        }
        if(frk == 0)
        {
            ft_lstdelone(content, f);
            exit(0);
        }
        else
        {
            waitpid(frk, &stat, 0);
            if(stat == 0)
                printf("\tCheck null protection -> "TEST_OK"\n");
            else
                printf("\tCheck null protection -> "TEST_NOK"\n");
            return ;
        }
    }
    else
    {
        node = ft_lstnew(&content);
        if(!node)
        {
            printf("Error creation node test %d\n", test_nb);
            f(content);
            return ;
        }
        ft_lstdelone(node, f);
        if (!content)
            printf("\tDelete content node"TEST_OK"\n");
        else
            printf("\tDelete content node"TEST_NOK"\n");
    }
    
}

void ft_lstdelone_assert(void)
{
    char *test_name = "ft_lstdelone";
    TEST_STAR(test_name);
    char **split;
    int **data;
    int test_nb;

    //Test 1
    test_nb = 1;
    split = ft_split("hello_berlin_comment_ca_va?", '_');
    if(!split)
    {
        printf("Error split creation in ft_lstdelone_assert\n");
        return ;
    }
    ft_lstdelone_test(test_nb++, split, delete_split);

    //Test 2
    data = create_arr(5, 5);
    if (!data)
    {
        printf("Error split creation in ft_lstdelone_assert\n");
        return ;
    }
    ft_lstdelone_test(test_nb++, data, delete_tab);
    
    //Test 3
    ft_lstdelone_test(test_nb++, NULL, NULL);

    TEST_END(test_name);
    SEP;
    NL;
}