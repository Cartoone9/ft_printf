<div align="center">
  <img src="https://i.ibb.co/cmF80PB/image.png" alt="Project score">
</div>

# ft_printf

This repository contains my ft_printf project, an early assignment from 42 School. The goal was to build a custom (mini) version of the standard C library's printf function. This project was instrumental in solidifying my understanding of variadic arguments, intricate string parsing, and efficient output buffering in C. 

## Table of Contents

- [About](#ft_printf)
- [Usage](#usage)
- [Example](#example)
- [Note on Project State](#note-on-project-state)
- [Known Issues & Fix Suggestions](#known-issues--fix-suggestions)
- [License](#license)

## Usage

This project is only asking for a static library file (`.a`) and not a working program, to compile it you can use:
```bash
make
# or
make bonus
```

To run your tests you will need a main, for example:
```C
#include <stdio.h>

int ft_printf(const char *str, ...);

int main(void)
{
    int count_original;
    int count_ft;

    count_original = printf("Original: Char: %c | String: %s | Int: %i | Hex: %x | Percent: %%\n", 'A', "Test String", 12345, 6789);
    count_ft = ft_printf("ft_printf: Char: %c | String: %s | Int: %i | Hex: %x | Percent: %%\n", 'A', "Test String", 12345, 6789) - 1; // minus one to account for the extra char: "Original" vs "ft_printf"
    printf("Original count: %d, ft_printf count: %d\n\n", count_original, count_ft);

    count_original = printf("Original Bonus: String : '%-10s' | Int: '%+05d' | Hex: '%#x'\n", "Hello", 42, 255);
    count_ft = ft_printf("ft_printf Bonus: String : '%-10s' | Int: '%+05d' | Hex: '%#x'\n", "Hello", 42, 255) - 1; // minus one to account for the extra char: "Original" vs "ft_printf"
    printf("Original Bonus count: %d, ft_printf Bonus count: %d\n", count_original, count_ft);

    return (0);
}
```

To compile an executable, ensure that both `main.c` and `libftprintf.a` are present in the current directory, then run the following command:
```bash
cc -Wall -Werror -Wextra main.c -L. -lftprintf -o ft_printf
```

## Example
  
Using the main provided above:  
<img width="640" height="167" alt="image" src="https://github.com/user-attachments/assets/a32fadf5-123e-468d-a327-484a1040e325" />  
  
## Note on Project State

All projects from my 42 cursus are preserved in their state immediately following their final evaluation. While they may contain mistakes or stylistic errors, I've chosen not to alter them. This approach provides a clear and authentic timeline of my progress and learning journey as a programmer.

## Known Issues & Fix Suggestions

This code relies on undefined behavior when handling variadic arguments. In my implementation, I repeatedly call `va_arg()` on the same `va_list` to iterate over the arguments. While this appears to work on Ubuntu (where each call to `va_arg()` advances the list as expected), it is not portable and may fail on other systems like macOS, where the behavior can differ. The correct approach is to use `va_copy()` to create a copy of the `va_list` when multiple iterations are needed. This ensures consistent and defined behavior across different platforms.

There's also unprotected `malloc()` in the following functions: `ft_nullstr()`, `ft_sixtreculn_fill()`, `ft_conv_prct()`.

## License

[MIT](https://choosealicense.com/licenses/mit/)
