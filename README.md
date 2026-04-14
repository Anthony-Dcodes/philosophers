*This project has been created as part of the 42 curriculum by advorace.*

# Philosophers

## Description

Philosophers is a concurrent programming project based on the classic Dining Philosophers Problem, originally formulated by Edsger Dijkstra in 1965. The goal is to simulate a scenario where philosophers sit around a table, alternating between thinking, eating, and sleeping, while sharing a limited number of forks. The challenge lies in preventing deadlocks and data races while ensuring no philosopher starves to death.

The project consists of two implementations:

**philo** — a multithreaded solution where each philosopher is a thread and forks are protected by mutexes. A monitor thread detects death and full-meal conditions. All threads share a single memory space, allowing atomic death detection and immediate print blocking through a single mutex.

**philo_bonus** — a multiprocess solution where each philosopher runs as a separate process with a monitor thread inside it. Coordination is handled through POSIX named semaphores. Since processes have separate memory spaces, death signaling relies on exit codes and the parent process orchestrates shutdown via `kill()` and `waitpid()`.

Key design decisions and challenges addressed:

- Deadlock prevention using a "seats" semaphore limiting concurrent eaters to `n/2`
- Race-free death logging by combining flag checks and printing under a single mutex (philo) or using immediate `exit()` from the monitor (philo_bonus)
- Graceful vs forced shutdown tradeoffs — the bonus uses `SIGKILL` from the parent, accepting OS-level cleanup over manual resource management
- Zombie process prevention through proper `waitpid` reaping with `WNOHANG` polling

## Instructions

### Compilation

```bash
# Mandatory part (threads + mutexes)
cd philo
make

# Bonus part (processes + semaphores)
cd philo_bonus
make
```

Both produce a clean build with `-Wall -Wextra -Werror` flags. Use `make clean` to remove object files or `make fclean` for a full clean including the binary. `make re` rebuilds from scratch.

### Execution

```bash
./philo <n_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [n_times_must_eat]

./philo_bonus <n_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [n_times_must_eat]
```

- `n_philosophers` — number of philosophers (and forks)
- `time_to_die` (ms) — time from last meal start until death
- `time_to_eat` (ms) — time spent eating (requires two forks)
- `time_to_sleep` (ms) — time spent sleeping
- `n_times_must_eat` (optional) — simulation stops when all philosophers eat this many times

### Example usage

```bash
./philo 6 800 200 200        # 6 philosophers, should survive indefinitely
./philo 1 800 200 200        # single philosopher, will die (only one fork)
./philo 4 800 200 200 7      # stops after each philosopher eats 7 times
```

### Testing

```bash
# Check for zombie/orphan processes after crashes
ps aux | grep philo

# Kill any leftover processes
pkill -f philo

# Thread error detection (mandatory part)
valgrind --tool=helgrind ./philo 4 800 200 200

# Data race detection (bonus part)
valgrind --tool=drd --trace-children=yes ./philo_bonus 4 800 200 200

# Memory leak check
valgrind --leak-check=full ./philo 4 800 200 200 5
```

Note: the bonus part will show glibc `printf` buffer leaks under valgrind when processes are killed via `SIGKILL` — this is expected and not a code-level leak.

## Resources

- Dijkstra, E.W. — *EWD-310: Hierarchical Ordering of Sequential Processes* (1971), the original formulation of the dining philosophers problem
- `man 2 waitpid`, `man 7 sem_overview`, `man 7 pthreads` — POSIX reference for the core APIs used
- `man 2 fork`, `man 2 kill`, `man 3 exit` — process lifecycle and signal handling
- Lamport, L. — *Specifying Systems* (TLA+), formal verification of concurrent systems (recommended for deeper understanding of correctness guarantees)

### AI usage

AI (Claude by Anthropic) was used as a learning and debugging companion throughout the project. Specifically:

- **Conceptual understanding**: discussing process vs thread tradeoffs, semaphore semantics, deadlock patterns, nested lock acquisition, and the fundamental impossibility of race-free cross-process flag checking with named semaphores alone
- **Debugging**: analyzing valgrind/helgrind/DRD output, tracing race conditions and deadlocks through execution timelines, identifying subtle bugs (e.g., `waitpid(0)` accidentally reaping wrong children, semicolons after while loops)
- **API reference**: understanding `waitpid` flags, `WEXITSTATUS` macros, `sem_wait`/`sem_post` atomicity guarantees, and the distinction between kernel syscalls and glibc wrappers
- **Architecture decisions**: evaluating graceful shutdown vs `SIGKILL`, `pthread_join` vs `pthread_detach`, and the `exit()`-from-monitor pattern that resolved the nested semaphore deadlock in the bonus

All code was written manually. No AI-generated code was copy-pasted into the project.