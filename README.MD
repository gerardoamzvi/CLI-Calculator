# CLI Calculator in C | calc

A simple command-line calculator built in C, as a learning project to discover C fundamentals (pointers, strings, CLI arguments, REPL).

## Build

```bash
make
```

> **Note (Windows):** If `make` is not recognized, use `mingw32-make` instead. This is because `make` is not installed by default on Windows — `mingw32-make` is the equivalent that comes with MinGW/msys64.

Or manually:
```bash
gcc -Wall -Wextra main.c -o calc -lm
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
calc> ans * 2
16.000000
calc> x = 5
Variable x = 5.000000 saved
calc> x + ans
21.000000
calc> 3 ^ 2
9.000000
calc> 10 % 3
1.000000
calc> history
1 : 3 + 5 = 8.000000
2 : ans * 2 = 16.000000
calc> help
calc> exit
```

## Features

- Basic operations: `+` `-` `*` `/`
- Modulo `%` and power `^`
- Decimal numbers
- Interactive REPL mode
- `ans` — reuse last result in next calculation
- Session history with `history` command
- Variables — save and reuse values (`x = 5`, then `x * 2`)
- `help` command with full usage guide
- Error handling: division by zero, invalid input

## TODO

- [x] Session history
- [x] `help` command
- [x] Variables (`x = 5`, then `x * 2`)
- [x] Additional operators: `%` (modulo), `^` (power)
- [ ] Expressions with parentheses (`(3 + 5) * 2`)