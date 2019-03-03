1. The initial post-fork value of the variable in the child process is the same as that of the parent process. Both are able to read and write independently from their own copies of the variable.

2. Both parent and child processes can access the file descriptor returned by open. When writing to the file concurrently, depending on process scheduling the writes will occur in different orders, but the write operations themselves are atomic and do not interleave data. See [this SO post](https://stackoverflow.com/questions/50623946/is-a-write-operation-in-unix-atomic).

3. This can be done without calling 'wait' by creating a pipe and having the child print its line only after reading a value from the pipe. The parent writes the expected value after printing its line.

4. I think there are many variants of the exec functions for convenience. They are all front-ends for execve, but provide alternative functionality for common use cases.

5. In the child, wait returns -1 since there it has no child processes of its own. In the parent, the PID of the child is returned and the resulting status indicates the child exited normally.
