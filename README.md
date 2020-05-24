# Project Arkanoid 

## Visual Studio Installation on Windows

##### Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)
1. Скачать и установить Visual Studio 2017
2. Скачать и распаковать по удобному расположению архив: [[SFML: libs, bins, include]](https://drive.google.com/open?id=1PYmDT_LDqlECPm76dn-sFZtU69Yym-Q6)
3. git clone https://gitlab.com/nikitaster/project-arkanoid
4. Запустить Visual Studio 2017
5. Создать пустой проект. Указать путь проекту на склонированный репозиторий
6. Перейти в меню настроек во вкладу "Проект" и выбрать "Свойства" проекта
7. Выбрать "Все конфигурации" и "Все платформы"
8. С/С++ --> Общие и указать путь до папки "include" 
9. Перейти в раздел "Компановщик", выбрать платформу "Win32" и указать в "Дополнительные каталоги библиотек" путь до "lib x86"
10. Выбрать платформу "x64" и указать в "Дополнительные каталоги библиотек" путь до "lib x64"
11. Выбрать "Все платформы"
12. Выбрать конфигруацию "Debug", перейти в раздел "Компановщик --> Ввод"
13. Вставить в начало названия библиотек: sfml-graphics-d.lib;sfml-window-d.lib;sfml-system-d.lib;sfml-audio-d.lib;
14 Выбрать конфигруацию "Release", перейти в раздел "Компановщик --> Ввод"
15. Вставить в начало названия библиотек: sfml-graphics.lib;sfml-window.lib;sfml-system.lib;sfml-audio.lib;
16. Запусть каждую из версий (будут ошибки) для генерации исполняяемых файлов
17. Перейти в корень проекта, из файла "bin x86" перенести в папку "Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
18. Перейти в корень проекта, из файла "bin x86" перенести в папку "Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll
19. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Debug" следующие файлы: 
    * openal32.dll
    * sfml-audio-d-2.dll
    * sfml-graphics-d-2.dll
    * sfml-network-d-2.dll
    * sfml-system-d-2.dll
    * sfml-window-d-2.dll
20. Перейти в корень проекта, из файла "bin x64" перенести в папку "x64 --> Release" следующие файлы: 
    * openal32.dll
    * sfml-audio-2.dll
    * sfml-graphics-2.dll
    * sfml-network-2.dll
    * sfml-system-2.dll
    * sfml-window-2.dll

##### Подбробнее в видео: ["С++ sfml (подключение sfml к Visual Studio 2017)"](https://youtu.be/w339OWGlSo0)