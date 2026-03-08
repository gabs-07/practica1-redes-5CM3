#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PUERTO 8080

int main() {

    int socket_servidor, socket_cliente;
    struct sockaddr_in direccion;
    int tam_direccion = sizeof(direccion);
    char mensaje[1024];

    socket_servidor = socket(AF_INET, SOCK_STREAM, 0);

    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = INADDR_ANY;
    direccion.sin_port = htons(PUERTO);

    bind(socket_servidor, (struct sockaddr *)&direccion, sizeof(direccion));

    listen(socket_servidor, 3);

    printf("Servidor esperando conexion...\n");

    socket_cliente = accept(socket_servidor, (struct sockaddr *)&direccion, (socklen_t*)&tam_direccion);

    while(1) {

        memset(mensaje, 0, 1024);
        recv(socket_cliente, mensaje, 1024, 0);

        printf("Cliente dice: %s", mensaje);

        if(strncmp(mensaje,"salir",5)==0) {
            printf("Conexion cerrada por el cliente\n");
            break;
        }
    }

    close(socket_cliente);
    close(socket_servidor);

    return 0;
}