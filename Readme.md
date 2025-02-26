# Домашнее задание по Практикуму на ЭВМ, апрель 2024

Напишите программу, которая моделирует движение лёгких и тяжёлых частиц в двумерной прямоугольной области. Все лёгкие частицы имеют одинаковую массу и радиус, а массы и радиусы тяжёлых частиц могут
отличаться друг от друга. Начальные скорости и положения частиц выбираются произвольным образом. Столкновение частиц абсолютно упругое, т. е. должны быть выполнены законы сохранения энергии и импульса. Так,
например, при столкновении двух лёгких частиц они должны обменяться скоростями. Столкновение с границей области также абсолютно упругое и заключается в изменении знака нормальной компоненты скорости на
противоположный. Расчёты должны производиться с некоторым фиксированным шагом по времени.
В программе должен быть реализован графический пользовательский интерфейс, включающий в себя:
1. Графическое отображение прямоугольной области и частиц, находящейся в ней.
2. Поле ввода с количеством шагов, которые нужно сделать.
3. Кнопку «Сделать шаги», при нажатии на которую происходит перемещение частиц.
4. Кнопки «Добавить частицу» и «Удалить частицу», при нажатии на которые должны появляться диалоговые окна, с помощью которых можно было для текущей конфигурации системы добавить или удалить
частицу.
Требования:
1. В программе должен быть определён абстрактный класс «частица», на основе которого при помощи наследования должны быть построены все классы частиц. Количество реально хранящихся полей данных
для каждой частицы должно быть минимизировано.
2. В программе должен быть определён основной класс «система», содержащий контейнер указателей на
объекты-частицы. Объект класса «система» должен содержать метод, производящий серию из заданного
количества шагов по времени с заданным интервалом.
3. Перемещение частицы с определением скорости после столкновения должно быть реализовано виртуальным методом самой частицы. При этом частице запрещён доступ к контейнеру частиц, взаимодействие с
ним должно осуществляться методами класса «система».
4. Все поля данных должны быть закрытыми, использование ключевого слова friend запрещено.
5. Программа должна считать из командной строки три аргумента: порождающий элемент (seed) для генератора псевдослучайных чисел, количество лёгких частиц и количество тяжёлых частиц.
6. Методам класса «система» запрещается узнавать от частиц какие бы то ни было их параметры: тип,
массу, положение, скорость. Методы класса «система» должны оставаться прежними при добавлении в
программу нового типа частицы (например, такой, столкновение с которой не было бы абсолютно упругим).
7. Для реализации графического интерфейса должна быть использована библиотека FLTK. Краткое руководство по использованию основных инструментов этой библиотеки можно найти в (А. В. Столяров.
Программирование: введение в профессию. Т. 3: Парадигмы. М. : ДМК Пресс, 2021. Раздел 10.11). Более
подробно о библиотеке можно узнать на официальном сайте: https://www.fltk.org/doc-1.3/index.html.
8. Программа должна быть разбита на несколько модулей (.hpp + .cpp).
