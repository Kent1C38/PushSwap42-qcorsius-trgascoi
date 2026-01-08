#include "libft/includes/libft.h"
#include "push_swap.h"

int parse_options(int argc, char **argv, t_options *opt, int *start_index)
{
    int i;

    opt->sort_mode = SORT_NONE;
    opt->benchmark_enabled = 0;
    i = 1;
    while (i < argc && argv[i][0] == '-' && argv[i][1] == '-')
    {
        if (ft_strcmp(argv[i], "--bench")) {
            if (opt->sort_mode != SORT_NONE)
                return (0);
            if (!ft_strcmp(argv[i++], "--simple"))
                opt->sort_mode = SORT_SIMPLE;
            else if (!ft_strcmp(argv[i++], "--medium"))
                opt->sort_mode = SORT_MEDIUM;
            else if (!ft_strcmp(argv[i++], "--complex"))
                opt->sort_mode = SORT_COMPLEX;
            else if (!ft_strcmp(argv[i++], "--adaptative"))
                opt->sort_mode = SORT_ADAPTATIVE;
            else
                return (0);
        }
        else
            opt->benchmark_enabled = 1;
    }
    *start_index = i;
    return (1);
}