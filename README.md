# Monopoly
Comand line Monopoly, maybe

Инструкция по использованию программы на Linux:
1) Создать карту и стэк шансов используя Map_Editor:
g++ -o o Map_Editor.cpp
Ввести количество клеток, а затем типы клеток (0 – пустая клетка и 1 – шанс) через Enter
Ввести количество шансов, и типы шансов и расстояние/положение (1 – вперед на n клеток и 2 – назад на n клеток, 3 – на клетку номер n) через Enter
2) запустить основную программу:
g++ -pthread -o o main_ALG.cpp для многопоточного выполнения (не получилось реализовать)
или
g++ -o o main_ALG_wt.cpp для линейного  выполнения

все входные данные имеют тип unsigned (short).

Принцип работы программы:
Есть 3 функции try1, try2 и try3.
На вход try1 подается сумма на кубиках при первом броске, в случае не выпадения дубля, затем в try1 рассчитывается и записывается в массив r1 количество набранных очков.
На вход try2 подается сумма на кубиках при первом и втором бросках, в случае выпадения дубля при первом броске, затем в try2 рассчитывается и записывается в двумерный массив r2 количество набранных очков. На при подаче некоторых данных на вход try2, учтены результаты из r1. 
На вход try3 подается сумма на кубиках при первом, втором и третьем бросках, в случае выпадения дубля при первом и втором бросках (в третий раз не важно, дубль выпал или нет), затем в try3 рассчитывается и записывается в двумерный массив r3 количество набранных очков. На при подаче некоторых данных на вход try2, учтены результаты из r2.
Максимальное значение points обновляется, как только появляется его превосходящее.

Оценка сложности:
В худшем дважды вызывается функция Cycle_Check (в среднем вызывается 1 раз)
Ее предназначение состоит в том, чтобы предсказать, что программа уйдет в бесконечный цикл и предотвратить это. 
Ее сложность O((v.siz〖e())〗^2)
Внутри каждой try-функции в цикле do-while происходит обращение к элементу массива field[CurPos], простые вычисления, многократная проверка условия (if-else) и В худшем дважды вызывается функция Cycle_Check (в среднем вызывается 1 раз)
Ее предназначение состоит в том, чтобы предсказать, что программа уйдет в бесконечный цикл и предотвратить это. 
Ее сложность, а на основании изложенного и всей программы: O((v.siz〖e())〗^2).

Оценка использования памяти:
Во время выполнения программы выделяется память для:
Тип структуры данных	Расход
Одномерный массив	O(n)
std::list<>	O(n)
std::vector<>	O(n)

O(n)

