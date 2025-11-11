/* sys_print.c
 *
 * Demonstrates printing to stdout by issuing the `write` syscall
 * via inline x86_64 assembly (syscall instruction).
 *
 * Compile:
 *   gcc sys_print.c -o sys_print
 *
 * Run:
 *   ./sys_print
 */

#include <stdio.h>    // for perror (optional)
#include <string.h>   // for strlen()
#include <unistd.h>   // for STDOUT_FILENO
#include <stdint.h>   // for integer types
#include <sys/types.h>

ssize_t my_write_syscall(int fd, const void *buf, size_t count) {
    /* Use inline assembly to call the syscall:
     * Syscall ABI (x86_64 Linux):
     *   rax: syscall number (1 = write)
     *   rdi: arg0 (fd)
     *   rsi: arg1 (buf)
     *   rdx: arg2 (count)
     * After syscall, rax contains return value (bytes written or -errno).
     *
     * We'll move values into registers and invoke `syscall`.
     */
    ssize_t ret;

    asm volatile(
        "movq $1, %%rax\n\t"    /* syscall number 1 = write */
        "movq %1, %%rdi\n\t"    /* first arg: fd */
        "movq %2, %%rsi\n\t"    /* second arg: buf */
        "movq %3, %%rdx\n\t"    /* third arg: count */
        "syscall\n\t"           /* make syscall */
        "movq %%rax, %0\n\t"    /* save return value into ret */
        : "=r"(ret)             /* output operand */
        : "r"((long)fd), "r"(buf), "r"((long)count) /* inputs */
        : "rax", "rdi", "rsi", "rdx", "rcx", "r11", "memory"
    );

    return ret;
}

void my_print(const char *s) {
    if (s == NULL) return;
    size_t len = strlen(s);

    /* We ignore the return value here, but we could check it for errors. */
    ssize_t written = my_write_syscall(STDOUT_FILENO, s, len);
    if (written < 0) {
        /* optional: print an error via regular stdio if syscall failed */
        perror("my_write_syscall failed");
    }
}

int main(void) {
    my_print("Hello from my_print (syscall)!\n");
    my_print("This uses inline assembly and the write syscall.\n");
    return 0;
}
