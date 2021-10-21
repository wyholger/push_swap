# push_swap

Push swap это проект про сортировку на Си. 

Терминальное приложение push_swap принимает в качестве аргумента массив целых, не повторяющихся чисел, 
 со значением не меньше MIN_INT (-2147483648) и не больше MAX_INT (2147483647).

Далее push_swap отсортирует их используя:
 2 стека A и B (изначально все числа заносятся в стек А)

И правила действий которые он может применить к этим стекам:
| instructions  | Description   |
|:-------------:|---------------|
| sa            | swap first two elements of stack A |
| sb            | swap first two elements of stack B |
| ss            | sa and sb at the same time |
| pa            | pops the first elememt on B and puts it on top of A |
| pb            | pops the first elememt on A and puts it on top of B |
| ra            | rotates stuck A up by one|
| rb            | rotates stuck B up by one |
| rr            | rotates both A and B up by one |
| rra           | rotates stuck A down by one |
| rrb           | rotates stuck B down by one |
| rrr           | rotates both A and B down by one |
