# push_swap

![img](https://github.com/wyholger/push_swap/blob/main/img/visual.gif?raw=true)

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

В терминал будут выводиться инструкции по порядку применяя которые конкретно этот массив отсортируется.

Проверить его отсортированность можно с помощью приложения checker,
которое нужно запустить параллельно с push_swap и подать в него те же аргументы что и в push_swap.

Мой алгоритм сортировки работает так:
1. Находим максимальное, минимальное, и медианное значение в стеке.
2. Переносим в стек B все элементы, кроме максимального и минимального значения. При чем по принципу если значение больше медианного оно кладется в нижнюю часть стека B, а если меньше то в верхнюю.
3. Проставляем каждому элементу количество инструкций за которое его можно поставить в нужное место в стеке А.
4. Выбираем элемент с наименьшим количеством просчитанных шагов.
5. Производим нужные инструкции для того чтобы положить этот элемент в нужное место в стеке А.
6. Возвращаемся к пункту 3, пока в стеке B есть элементы.

** Так же я оптимизировал алгоритм в самом начале, находя максимальную последовательность уже отсортированных чисел и во 2-ом пункте не отправляя их в стек B, оставляю в стеке А т.к. эта последовательность уже отсортированна. 
Только для этого нужно совершить манипуляции с максимальным и минимальным элементом, чтобы они стояли в начале и конце стека А соответственно.

## Сборка на macOS
```
git clone https://github.com/wyholger/push_swap.git push_swap
```
```
cd push_swap
```
```
make bonus
```
## Использование 
Вывод инструкций для сортировки поданного массива
```
./puah_swap 4 0 2 -50 -889...
```
Проверка на отсортированность массива используя инструкции выдаваемые ./push_swap. Выведет OK или KO.
```
ARG="3 2 1 5"; ./push_swap $ARG | ./checker $ARG
```
Проверка на количество инструкций затраченных на сортировку данного массива. Выведет количество инструкций.
```
ARG="3 2 1 5"; ./push_swap $ARG | wc -l
```
Запуск визуализатора сортировки, в круглых скобках задается диапазон чисел который в случайном порядке будет подан аргументом.
```
python3 tester/pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`
```
