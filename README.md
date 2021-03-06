# Project Arkanoid 

## Preview
<img src="./preview.gif" width="50%">

## Installer for Windows 
[Google drive](https://drive.google.com/file/d/1-qUNyqh0v8LNjTbJuzK8_DJVlLjEY_0K/view?usp=sharing)

## Visual Studio Installation on Windows

### Клонирование проекта:
##### Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)
1. Скачать и установить Visual Studio 2019
2. Скачать и распаковать по удобному расположению архив: [[SFML: libs, bins, include]](https://drive.google.com/open?id=1PYmDT_LDqlECPm76dn-sFZtU69Yym-Q6)
3. Запустить Visual Studio 2019
4. Склонировать проект по удобному расположению

##### Подключение git:
```Bash
git init
git config --global user.name "Firstname Lastname"
git config --global user.email "email@mail.ru"
git clone https://gitlab.com/nikitaster/project-arkanoid.git
cd project-arkanoid
git checkout develop
```

### Настройка проектов:
#### Arkanoid:
1. Перейти в "файл" -> "Создать проект из существующего кода"
2. Выбрать "Visual C++""
3. Указать путь до папки "Arkanoid"
4. Выбрать консольное приложение
5. Нажать "далее" -> "готово"

#### Тесты:
1. Перейти в "файл" -> "Создать проект из существующего кода"
2. Выбрать "Visual C++""
3. Указать путь до папки "Test"
4. Выбрать консольное приложение
5. Нажать "далее" -> "готово"


### Объединение проектов в одно решение:
1. Открыть существующий проект из шага "Настройка проектов: Arkanoid"
2. Правой кнопкой нажать в обозревателе решение на "Решение" и выбрать "Добавить"
3. Выбрать "Добавить существующий проект"
4. Добавить проект с тестами из шага "Настройка проектов: Тесты"

### Настройка SFML:
1. Перейти в меню настроек во вкладу "Проект" и выбрать "Свойства" проекта
2. Выбрать "Все конфигурации" и "Все платформы"
3. С/С++ --> Общие и указать путь до папки "include" 
4. Перейти в раздел "Компановщик", выбрать платформу "Win32" и указать в "Дополнительные каталоги библиотек" путь до "lib x86"
5. Выбрать платформу "x64" и указать в "Дополнительные каталоги библиотек" путь до "lib x64"
6. Выбрать "Все платформы"
7. Выбрать конфигруацию "Debug", перейти в раздел "Компановщик --> Ввод"
8. Вставить в начало названия библиотек: sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-audio-d.lib;
9. Выбрать конфигруацию "Release", перейти в раздел "Компановщик --> Ввод"
10. Вставить в начало названия библиотек: sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib;
11. Запусть каждую из версий (будут ошибки) для генерации исполняяемых файлов
12. Перейти в корень проекта, из файла "bin x86" перенести в папку "Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
13. Перейти в корень проекта, из файла "bin x86" перенести в папку "Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll
14. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
15. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll
16. Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)

### Запуск Игры: 
1. В обозревателе решений правой кнопкой мыши нажать на "Назначить в качестве запускаемого проекта" на проекте с игрой
2. Запустить локальный отладчик

### Запуск Тестов: 
1. В обозревателе решений правой кнопкой мыши нажать на "Назначить в качестве запускаемого проекта" на проекте с тестами
2. Запустить локальный отладчик
