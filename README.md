# Condl

condl is a condition based programing language

# TODO

[ ] make the language compiled
[ ] make the language interpreted
[ ] make the language able to handle jumps
[ ] make the language able to handle variable
[ ] make the language able to handle memory management
[ ] make the language able to use syscalls
[ ] make the language able to solve rule110
[ ] make the language able to solve project euler

# Documentation

## registers

### return register

immutable

this register stores the result of the last operation

symbole : `#r`

```
1| a < 5 ? 3a+2 : 2a
2| b *   ? 0    : #r
```

### line register

mutable

this register stores the current line number set it to jump to an other line

symbole : `#l`

```
1| a * ? 0 : 0
2| 1   ? a + 1 : 0
3| a < 3 & #l * ? 2 : 4
4| a = 3 ? 1 : 0
```

### memory register

immutable

this register store the address of the begining of the program's memory block 2kb

symbole : `#m`

```
1| a * ? #m : 0
2| {a} * ? 1 : 0
```

### calls registers

mutable

those register store the argument and the call number to execute a syscall

symboles : `#1` to `#6` and `#c`

```
1| #1 * ? 0  : 0
2| #c * ? 60 : 0
3| 1    ? call : 0
```

## conditionals expressions

### variables assignement

variables are mutables that can 

### registers assagnement

### conditions
