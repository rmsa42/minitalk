# Minitalk [42 Project]
This 42 project challenges us to communicate between two processes using `signals`.

In this project, the `server` prints its PID and waits indefinitely for a message. The `client` is the one who can give the message to the `server`, bit by bit. After 8 bits received the `server` prints the corresponding letter, until there's no more bits from the `client`.

All files and directories containing *_bonus are for the Bonus part

## Table of Contents
1. [Overview](#overview)
2. [About Signals](#about-signals)
3. [About Bitwise Operations](#about-bitwise-operations)
4. [Project Structure](#project-structure)
5. [Dependencies](#dependencies)
6. [How to Use](#how-to-use)
7. [Code Example](#code-example)
8. [Bonus](#bonus)
9. [Contributing](#contributing)

## Overview
This project tests our knowledge about Unix `signals` and `bitwise` operations in C.

### Explanation:

The way the `client` sends its message is through `signals`, respectively the `SIGUSR1` and `SIGUSR2`. So we have two `signals` and a bit can either be `0` or `1`, so we design `SIGUSR1` to `0` and `SIGUSR2` to `1`. Now with every bit we send the `server` can know if the bit is `0` or `1` through the `signal` received.

How the server knows it received a `signal`?

Easy, we just implement a `signal handler` in the `server` with the help of a function called `sigaction()` (More about sigaction [here](https://man7.org/linux/man-pages/man2/sigaction.2.html)). The `sigaction()` function permits the implementaion of the `signal handler` in the `server`, which can now know when it receives a `signal` from the `client`.

Now, it's a matter of doing some `bitwise` operations and we are done. After the `server` acknowledges which `signal` (bit) came from the `client`, we will operate that bit with the number zero. Why? Because zero in binary is `00000000` and with `bitwise` operations we can change the bits until we have the letter we want.

So if the `server` receives the bit `1`, we will operate the zero `00000000` in binary with the number one in binary `00000001` with the `bitwise` operation known as `OR` (`|`). This means that if a `0` is compared to a `0` it stays the same otherwise it changes to `1`. This operation is made with all 8 bits, so if the `server` receives the bit `1` it will always change the variable that hold the `00000000`, because it's all zeros. If the `server` receives the bit `0` it does nothing.

Ok, this is only for the first bit, now for the second and beyond. For the subsequent bits, that are `1`,  what we want to know it's the order (if it was the first, `order = 1`, etc ...) because depending on the order we will make another `bitwise` operation called `Left Shift`. Basically we will left shift our number one `000000001` 8 times `-` the number of the order of the bit. So if the `order = 2` and it's a bit `1` we will left shift `8 - 2` the `00000001` and the result is `01000000`.

Now with this result `01000000` we will make the `OR` operartion against `00000000` and the result will be `01000000`. Basically we just put the bit `1` in rigth spot everu time and in the eigth time we print the char.

## About Signals
In a Unix system we have a lot of `signals`, whom have their own purpose, like `SIGINT` which is a interrupt signal, but in all this `signals` there are two that their purpose is defined by the `user`. The `signals` i am talking about are the `SIGUSR1` and `SIGUSR2`, these don't have predifined purposes so i can use them for whatever i want. (More about [signals](https://www.tutorialspoint.com/unix/unix-signals-traps.htm))

## About Bitwise Operations
`Bitwise` operations are names given to all the operations we can do with bits. Operations with bits is normally used in `data compression` and `encryption`. (More about [bitwise](https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/tutorial/))

## Project Structure
- `minitalk/`: Main directory containing the `src` and `src_bonus` directories, and the `Makefile`.
- `src`: Contains all the source code.
- `libft`: Contains `libft` library
- `src_bonus`: Contains all the source code for the bonus part.

## Dependencies
- Libft (it is already included, more information [here](https://github.com/rmsa42/libft))

## How to Use
1. Clone the repository.
2. Navigate to the `minitalk` directory: `cd minitalk/`.
3. Compile the program, creating the `server` and the `client`: `make`.
4. Run the `server`: `./server`
5. Run the `client` (in another terminal): `./client server_pid message`
Now every time we run the `client` the message will be printed in the server

## Code Example
An example of the `client` sending the message `Hello` to the `server` and the `server` printing the message.

The `server`
```bash
PID: 100
Waiting for Message...
    Hello
```
The `client`
```bash
./client 100 Hello 
```

## Bonus
The bonus part of this project consists in making the `server` acknowledge every `signal` from the `client` by sending back a `signal` to the `client`.

To accomplish this task, the server needs to know the `client` PID to send back the `signal` and we also need a `signal handler` in the `client`. So to know the `client` PID we can tinker around the `sigaction()`. We can activate a flag in the `sigaction` struct to know the PID of the process that send a message to the `server`, so the `client` PID.

## Contributing
I welcome contributions. If you have any bug fix or improvement, feel free to submit a pull request on the repository.
