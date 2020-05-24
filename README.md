# Project Arkanoid 

## Visual Studio Installation on Windows

### Настройка среды:
##### Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)
1. Скачать и установить Visual Studio 2017
2. Скачать и распаковать по удобному расположению архив: [[SFML: libs, bins, include]](https://drive.google.com/open?id=1PYmDT_LDqlECPm76dn-sFZtU69Yym-Q6)
3. Запустить Visual Studio 2017
4. Создать пустой проект
5. Перейти в меню настроек во вкладу "Проект" и выбрать "Свойства" проекта
6. Выбрать "Все конфигурации" и "Все платформы"
7. С/С++ --> Общие и указать путь до папки "include" 
8. Перейти в раздел "Компановщик", выбрать платформу "Win32" и указать в "Дополнительные каталоги библиотек" путь до "lib x86"
9. Выбрать платформу "x64" и указать в "Дополнительные каталоги библиотек" путь до "lib x64"
10. Выбрать "Все платформы"
11. Выбрать конфигруацию "Debug", перейти в раздел "Компановщик --> Ввод"
12. Вставить в начало названия библиотек: sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-audio-d.lib;
13. Выбрать конфигруацию "Release", перейти в раздел "Компановщик --> Ввод"
14. Вставить в начало названия библиотек: sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib;
15. Запусть каждую из версий (будут ошибки) для генерации исполняяемых файлов
16. Перейти в корень проекта, из файла "bin x86" перенести в папку "Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
17. Перейти в корень проекта, из файла "bin x86" перенести в папку "Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll
18. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
19. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll
20. Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)

### Подключение git:
1. Перейти в проводнике в корень проекта (туда, где будут исполняемые файлы)
2.  git init
3.  git remote add origin https://gitlab.com/nikitaster/project-arkanoid
4.  git pull origin master