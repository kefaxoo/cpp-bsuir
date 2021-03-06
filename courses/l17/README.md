# Задание 17. Файлы

Задание 1: В цикле вводим символы с клавиатуры и записываем их в файл `1.txt`. Окончание цикла – ввод символа `z`.

Задание 2: Записать в файл `2.txt` числа

    10
    20
    30
    …
    100
Каждое число в отдельной строке.

Задание 3: Считать числа из файла `2.txt` и вывести их сумму.

Задание 4: Разработать приложение для учета драгоценностей, собранных гномами.

|В файле|Расшифровка|
|:-----:|:---------:|
|gold|золото|
|ruby|рубины|
|emerald|изумруды|
|pearl|жемчуг|
|diamond|алмаз|
Все драгоценности находятся в файле `jewels.txt`.

Содержимое файла выглядит примерно так:
```
**e***g*****d********g******e****p*****d***
***p**********gg**********d**********p*****
```
Вместо звездочек могут быть любые символы – это руда. Мы читаем файл, находим драгоценности и ведем их учет. Результат вывести в виде:
```
Гномы собрали драгоценности:
Золото: 4
Рубины: 0
Изумруды: 2
Жемчуг: 3
Алмазы: 3
```

Задача 5: В файле могут быть большие и маленький драгоценности (e и E, d и D и т.д.) Найденные драгоценности записаны в отдельный файл `sklad.txt` – уже без руды:

    egDgEpd
    pgGdp
Подсчитать общую стоимость сокровищ, если
|Драгоценность|Цена маленького самородка|Цена большого самородка|
|:-----------:|:-----------------------:|:---------------------:|
|Золото|1 (g)|5 (G)|
|Жемчуг|5 (p)|10 (P)|
|Рубин|20 (r)|50 (R)|
|Изумруд|40 (e)|80 (E)|
|Алмаз|100 (d)|500 (D)|

Подсчитать стоимость каждой строки в файле "sklad.txt". Отсортировать строки в порядке убывания стоимости (первая – самая дорогая). Вывести отсортированные строки и их стоимость на экран:

    1 dddddDD - 1500
    2 egGd - 146
    3 rpP - 35
    4 r - 20