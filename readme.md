# simplecalc

Just a tutorial project.   
Simplecalc can do arithmetic operations on numbers.

## how to buildl

To build just use
    make
command. And use
    make clean
to delete.

## usage description

Simplecalc can be called by a command:

    simplecalc arg1 arg2 arg3

or without arguments:

    simplecalc

If it is called without arguments, it asks to input arguments from stdin.

The first argument is operation to do,   
the other arguments are numbers for which operation must be done.

Supported operations: sum, difference, product, fraction and square root of float, factorial of positive integer ().   
Text arguments as "+", "-", "sum", "sub", "mul", "div", "fact" and "sqrt" can be used for choose the operation.   
Difference and fraction are implemeted for only 2 arguments.   
Sum and producntion are implemeted for at least 2 arguments.

Error handling:   
if non-float argument is inputed from command line, it is skipped;   
if non-float argument is inputed from stdin, simplecalc asks to retry;   
if wrong arguments quantity is inputed from command line, simplecalc shows an error;   
simplecalc don't allow to input other arguments quantity than 2 from command line;   
if simplecalc detects division by zero, it shows an error;   
undefined operations are replaced with sum.

## usage examples

#### 1
    $ simplecalc + 1.1 2.1 3.1 4.1 5.1
    The sum is 15.500000

#### 2
    $ simplecalc sub 4 3.33
    The difference is 0.670000

#### 3
    $ simplecalc mul 2 abc 3 4
    Error: 'abc' can't be converted to double. Argument was skipped.
    The product is 24.000000

#### 4
    $ simplecalc
    Input operation:
    div
    Input first argument:
    qwerty
    Error: str was not converted to double. Try again:
    5
    Input second argument:
    2
    The quotient is 2.500000

#### 5
    $ simplecalc div 10  0
    Error: division by zero.

#### 6
    $ simplecalc - 15 wasd
    Error: 'wasd' can't be converted to double. Argument was skipped.
    Error: wrong arguments quantity.

#### 7
    $ ./simplecalc fact 5
    The factorial is 120

#### 8
    $ ./simplecalc sqrt 2
    The sqrt is 1.414214

