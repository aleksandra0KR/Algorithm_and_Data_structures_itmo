# Лаб 5
## Высота дерева
Высотой дерева называется максимальное число вершин дерева в цепочке, начинающейся в корне дерева, заканчивающейся в одном из его листьев, и не содержащей никакую вершину дважды.

Так, высота дерева, состоящего из единственной вершины, равна единице. Высота пустого дерева (да, бывает и такое!) равна нулю.

Дано двоичное дерево поиска. В вершинах этого дерева записаны ключи - целые числа, по абсолютному значению не превышающие 10^9. Для каждой вершины дерева V выполняется следующее условие:

- все ключи вершин из левого поддерева меньше ключа вершины V
- все ключи вершин из правого поддерева больше ключа вершины V

Найдите высоту данного дерева.


## Проверка корректности
Свойство двоичного дерева поиска можно сормулировать следующим образом: для каждой вершины дерева V выполняется следующее условие:

- все ключи вершин из левого поддерева меньше ключа вершины V ;
- все ключи вершин из правого поддерева больше ключа вершины V;

Дано двоичное дерево. Проверьте, выполняется ли для него свойство двоичного дерева поиска.


## Заполнение дерева
Дана структура бинарного дерева. Требуется заполнить её числами от 1 до n так, чтобы получилось корректное бинарное дерево поиска.

## Простое двоичное дерево поиска
Реализуйте двоичное дерево поиска.

## Три друга
Три друга списывают лабораторную работу, каждый из них списывает по n различных задач. Поскольку друзья не очень умные, они не меняют названия отправляемых на проверку файлов.

По истечении времени, отведенного на написание лабораторной, преподаватель запускает бан-машину и ставит баллы по следующим правилам:

- если задача написана только у одного студента, то этот студент получает 3 балла, поскольку эту задачу он не списывал и не давал списывать;
- если задача списана ровно у двух студентов, то каждый из них получает по 1 утешительному баллу;
- если задача списана всеми тремя студентами, то за нее баллы не начисляются никому.
  Выведите финальное количество баллов у каждого студента.

В рамках этой задачи будем считать, что Бан-машина считает решения списанными, если у них полностью совпадают имена файлов.

## Два обхода
Рассмотрим два способа обойти бинарное дерево поиска:

- Вывести значение в текущей вершине и затем рекурсивно запустить процедуру обхода от левого и правого потомка.
- Рекурсивно запустить процедуру обхода от левого и правого потомка и затем вывести значение в текущей вершине.
-
Требуется по результату обхода первым способом получить результат обхода вторым способом.



