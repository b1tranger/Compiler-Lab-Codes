A **lambda** (or **lambda expression**) in programming is an **anonymous, inline function**—a small, unnamed block of code you can define right where you need it, store in a variable, or pass directly as an argument to another function.

Instead of writing a separate named function elsewhere in your file for a one-off task, a lambda lets you write the logic on the spot.

### Key Characteristics

* **Anonymous:** It has no formal function name (though in languages like C++, you can assign it to a variable using `auto`).
* **Closure / State Capture:** Unlike a standard standalone function, a lambda can "capture" and access variables from the surrounding scope where it was created.
* **Lightweight:** Ideal for short callbacks, sorting rules, filters, or localized helper logic.

### How It Looks in C++

A C++ lambda consists of three core parts: `[ capture ] ( parameters ) { body }`

* **`[ ]` (Capture Clause):** Decides which outside variables the lambda can see (e.g., `[&]` by reference, `[=]` by value, or `[]` for none).
* **`( )` (Parameters):** Just like a normal function's arguments (e.g., `(int x)` or `(auto val)`).
* **`{ }` (Body):** The actual code that executes when the lambda is called.

```cpp
int factor = 10;

// Defines a lambda that captures 'factor' and multiplies 'x' by it
auto multiply = [factor](int x) { 
    return x * factor; 
};

int result = multiply(5); // result is 50

```

*(Note: Outside of programming, **lambda ($\lambda$)** is also the 11th letter of the Greek alphabet, famously used in mathematics and theoretical computer science—specifically **Lambda Calculus**, the formal mathematical foundation from which functional programming and programming lambdas get their name.)*