# regex_parser

Mainly supporting `.` and `*` operators. Uses dynamic programming, Levenshtein Matrix style. I learned a lot about dynamic programming and C with this project.

Usually I compile with g++:
```
g++ -x c -o regex_parser regex_parser.c
./regex_parser
```

I focused mainly on the algorithm, so I didn't really develop a UI. To make modifications, you can use the main in `regex_parser.c`.

Planning on adding support for other important regex syntax as well:

* () capturing groups
* [] Ranges. Like [abc] or [a-z]
* \s, \w, \S, \W, \b etc.
* Escapes \., \\, \?, \*