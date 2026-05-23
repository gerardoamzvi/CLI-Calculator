# CLI Calculator in C | calc

A simple command-line calculator built in C, as a learning project to discover C fundamentals (pointers, strings, CLI arguments, REPL).

## Build

```bash
make
```

> **Note (Windows):** If `make` is not recognized, use `mingw32-make` instead. This is because `make` is not installed by default on Windows — `mingw32-make` is the equivalent that comes with MinGW/msys64.

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

## TODO

- [ ] Session history (remember last calculations)
- [ ] `help` command listing all features
- [ ] Additional operators: `%` (modulo), `^` (power)
- [ ] Variables (`x = 5`, then `x * 2`)
- [ ] Expressions with parentheses (`(3 + 5) * 2`)