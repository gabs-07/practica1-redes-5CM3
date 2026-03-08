# Comunicación Cliente-Servidor en C usando Sockets

## Descripción

Este proyecto implementa un sistema básico de comunicación entre un cliente y un servidor utilizando sockets en lenguaje C.

El servidor espera conexiones de un cliente y recibe mensajes enviados desde el cliente. El cliente permite al usuario escribir mensajes desde el teclado y enviarlos al servidor.

La comunicación continúa hasta que el usuario escribe la palabra "salir", lo que provoca el cierre de la conexión.

## Objetivo

Desarrollar una aplicación que demuestre el funcionamiento de la arquitectura cliente-servidor mediante el uso de sockets TCP en C, permitiendo el envío de múltiples mensajes desde el cliente hacia el servidor.

## Tecnologías utilizadas

- Lenguaje C
- Sockets TCP
- Sistema operativo Linux
- Biblioteca `arpa/inet`
- Biblioteca `sys/socket`

### Archivos

- **servidor.c**: Implementa el servidor que escucha conexiones y recibe mensajes.
- **cliente.c**: Permite al usuario escribir mensajes desde el teclado y enviarlos al servidor.
- **compilar.sh**: Script para compilar el cliente y el servidor.
- **ejecutar_servidor.sh**: Script para ejecutar el servidor.
- **ejecutar_cliente.sh**: Script para ejecutar el cliente.

## Funcionamiento

### Servidor

1. Crea un socket.
2. Asocia el socket a un puerto.
3. Espera conexiones de clientes.
4. Acepta la conexión.
5. Recibe mensajes enviados por el cliente.
6. Muestra los mensajes en pantalla.

### Cliente

1. Crea un socket.
2. Se conecta al servidor.
3. Permite al usuario escribir mensajes.
4. Envía los mensajes al servidor.
5. Termina cuando el usuario escribe "salir".

## Compilación y Ejecución

### Compilar el cliente y el servidor

```bash
gcc servidor.c -o servidor
```

```bash
gcc cliente.c -o cliente
```

### Ejecuta el script en este orden: 

```bash
./servidor
```

```bash
./cliente
```

### Ejecuciòn

<img width="600" height="400" alt="Image" src="https://github.com/user-attachments/assets/9bb93e50-fe63-4ee8-86c5-2bab9daaf57f" />

<img width="400" height="200" alt="Image" src="https://github.com/user-attachments/assets/e5781714-96fe-4e38-b0fc-129c23d5de19" />
