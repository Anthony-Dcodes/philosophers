#include "test.h"

int main(int argc, char *argv[])
{
	t_simulation	simulation;
	t_philosopher	*philosophers;
	int				ret;

	ret = ERR_OK;
	init_flags(&simulation.flags);
	ret = parser_args(argc, argv, &simulation);
	if (ret != ERR_OK)
		return (ret);
	ret = perfom_mallocs_initialize_mutexes(&simulation, &philosophers);
	if (ret != ERR_OK)
	return (ret);
}

int	perfom_mallocs_initialize_mutexes(t_simulation *simulation, t_philosopher **philosophers)
{
	int	i;
	int	ret;

	i = 0;
	ret = ERR_OK;
	ret = simulation_sem_init(simulation);
	printf("Semaphores created!\n");
	if (ret != ERR_OK)
		return (ret);
	// *philosophers = malloc(sizeof(t_philosopher) * simulation->n_philosophers);
	// if (!philosophers)
	// 	return (ERR_MEMORY);
	// //*forks = malloc(sizeof(t_fork) * simulation->n_philosophers);
	// if (!forks)
	// 	return (ERR_MEMORY);
	// while (i < simulation->n_philosophers)
	// {
	// 	ret = initialize_mutexes(simulation, philosophers, forks, i);
	// 	if (ret != ERR_OK)
	// 		return (ret);
	// 	++i;
	// }
	return (ret);
}
int	simulation_sem_init(t_simulation *simulation)
{
	simulation->print_semaphore = sem_open(SEM_PRINT, O_CREAT, 0666, 1);
	if (simulation->print_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.print_semaphore_created = 1;
	simulation->state_semaphore = sem_open(SEM_STATE, O_CREAT, 0666, 1);
	if (simulation->state_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.state_semaphore_created = 1;
	simulation->meal_semaphore = sem_open(SEM_MEAL, O_CREAT, 0666, 1);
	if (simulation->meal_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.meal_semaphore_created;
	simulation->fork_semaphore = sem_open(SEM_FORKS, O_CREAT, 0666, simulation->n_philosophers);
	if (simulation->fork_semaphore == SEM_FAILED)
		return (ERR_SEMAPHORE);
	simulation->flags.fork_semaphore_created;
	return (0);
}

void	init_flags(t_flags *flags)
{
	memset(flags, 0, sizeof(t_flags));
}

// If success - 0, else 1
int	parser_args(int argc, char *argv[], t_simulation *simulation)
{
	int	i;

	i = 1;
	if (argc != 5 && argc != 6)
	{
		wrong_number_of_args();
		return (ERR_PARSE);
	}
	while (argv[i])
	{
		if (!is_int(argv[i]))
			return (ERR_PARSE);
		++i;
	}
	simulation->n_philosophers = ft_atoi(argv[1]);
	simulation->time_to_die = ft_atoi(argv[2]);
	simulation->time_to_eat = ft_atoi(argv[3]);
	simulation->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		simulation->n_times_must_eat = ft_atoi(argv[5]);
	else
		memset(&simulation->n_times_must_eat, 0, sizeof(int));
	return (0);
}

int	is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+' || str[i] == '0'))
			return (wrong_number_format());
		else if (!ft_isdigit(str[i]))
			return (not_an_int());
		++i;
	}
	if (i > 10 || is_more_then_int_max(str))
		return (not_an_int());
	return (1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		++i;
	}
	return (result);
}

int	is_more_then_int_max(char *nptr)
{
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		++i;
	}
	if (result > INT_MAX)
		return (1);
	return (0);
}
int	wrong_number_format(void)
{
	printf("Wrong number format!\n");
	printf("Use positive int without sign characters > 0!\n");
	printf("It also cannot start with 0!\n");
	return (0);
}

int	not_an_int(void)
{
	printf("Argument not a type(int)!\n");
	printf("All arguments must be type(int)!\n");
	printf("Max value for int: %d!\n", INT_MAX);
	return (0);
}

int	wrong_number_of_args(void)
{
	printf("Wrong number of argumens, 4 needed, 5 optionally!\n");
	printf("number_of_philosophers, time_to_die, time_to_eat, time_to_sleep\n");
	printf("Optional argument: number_of_times_each_philosopher_must_eat\n");
	return (0);
}
