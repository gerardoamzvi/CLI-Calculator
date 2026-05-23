# CLI Calculator in C | calc

A simple command-line calculator built in C, as a learning project to discover C fundamentals (pointers, strings, CLI arguments, REPL).

## Build

```bash
make
```

Or manually:
```bash
gcc -Wall -Wextra main.c -o calc
```

## Usage

```bash
# Single expression
./calc 3 + 5
./calc 3.5 * 2

# Interactive mode
./calc
calc> 3 + 5
8.000000
calc> exit
```

## Features

- Basic operations: `+` `-` `*` `/`
- Decimal numbers
- Interactive REPL mode
- Error handling: division by zero, invalid input