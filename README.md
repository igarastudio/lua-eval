# lua-eval

This is a simple example to show how to use Lua with CMake. It
evaluates all the given arguments as one Lua expression. For example:

```
lua-eval a=2 b=3 "print(a+b)"
```

Will print `5`
