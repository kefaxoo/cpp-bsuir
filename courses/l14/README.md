# Задание 14. Организация консольного меню
Задание: 

1) В функции `main` организуем вывод меню:
```
cout << "Главное меню:" << endl;
cout << "1) Создать массив" << endl;
cout << "2) Заполнить массив" << endl;
cout << "3) Вывести массив" << endl;
cout << "4) Найти максимум" << endl;
cout << "5) Найти сумму" << endl;
cout << "6) Заменить элемент" << endl;
cout << "7) Сортировать" << endl;
cout << "0) Выход" << endl;
```
2) Дальше организуем бесконечный цикл `while (true) {...}` куда вкладываем вызов меню и еще…
3) Ожидаем ввод номера пункта от пользователя
4) Добавляем блок `switch`, который, в зависимости от выбранного  варианта вызовет функцию с нужным номером  (f1, f2 и т.д)
5) Если 0 - для выхода из цикла по `break;` и дополнительной переменной типа `bool`
6) Теперь для каждого пункта распишем отдельную функцию
7) Часть функций можно оставить пустыми и дорабатывать их постепенно

