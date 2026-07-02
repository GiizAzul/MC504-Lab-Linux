#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define __NR_rickroll_control 473 

int main() {
    int status;
    long res;

    printf("=== Testando o Rickroll Control System (RCS) ===\n\n");

    // GET
    res = syscall(__NR_rickroll_control, 0, &status);
    if (res < 0) {
        perror("Erro no GET inicial");
        return 1;
    }
    printf("[User] Status atual no Kernel: %d\n", status);

    // SET
    int novo_status = 1;
    printf("[User] Tentando ativar o Rickroll (Set para 1)...\n");
    res = syscall(__NR_rickroll_control, 1, &novo_status);
    if (res < 0) {
        perror("Erro no SET");
        return 1;
    }

    // GET
    res = syscall(__NR_rickroll_control, 0, &status);
    if (res < 0) {
        perror("Erro no GET final");
        return 1;
    }
    printf("[User] Novo status confirmado no Kernel: %d\n", status);

    if (status == 1) {
        printf("\n[User] Sucesso!\n");
    }

    return 0;
}