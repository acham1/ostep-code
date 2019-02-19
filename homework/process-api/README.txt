1. The initial post-fork value of the variable in the child process is the same as that of the parent process. Both are able to read and write independently from their own copies of the variable.

2. Both parent and child processes can access the file descriptor returned by open. When writing to the file concurrently, depending on process scheduling the writes will occur in different orders, but the write operations themselves are atomic and do not interleave data. See [this SO post](https://stackoverflow.com/questions/50623946/is-a-write-operation-in-unix-atomic).
