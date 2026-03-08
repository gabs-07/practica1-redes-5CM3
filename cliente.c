#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PUERTO 8080

int main() {

    int socket_cliente;
    struct sockaddr_in direccion_servidor;
    char mensaje[1024];

    socket_cliente = socket(AF_INET, SOCK_STREAM, 0);

    direccion_servidor.sin_family = AF_INET;
    direccion_servidor.sin_port = htons(PUERTO);

    inet_pton(AF_INET, "127.0.0.1", &direccion_servidor.sin_addr);

    connect(socket_cliente, (struct sockaddr *)&direccion_servidor, sizeof(direccion_servidor));

    printf("Conectado al servidor. Escribe 'salir' para cerrar la conexion.\n");

    while(1) {

        printf("Escribe un mensaje: ");
        fgets(mensaje, 1024, stdin);

        send(socket_cliente, mensaje, strlen(mensaje), 0);

        if(strncmp(mensaje,"salir",5)==0) {
            printf("Cerrando conexion...\n");
            break;
        }
    }

    close(socket_cliente);

    return 0;
}