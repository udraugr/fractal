### [RU][1] Описание проекта на русском
[1]: https://github.com/udraugr/fractal/new/master?readme=1#fractal---%D0%BE%D1%82%D0%BE%D0%B1%D1%80%D0%B0%D0%B6%D0%B5%D0%BD%D0%B8%D0%B5-%D1%84%D1%80%D0%B0%D0%BA%D1%82%D0%B0%D0%BB%D0%B0 "RU"
### [EN][2] Description of the project in English
[2]: https://github.com/udraugr/fractal/new/master?readme=1#fractal---displaying-a-fractal "EN"

# FRACTAL - отображение фрактала
Знакомство с комплексными числами и фракталами.
Реализованы фракталы:
* Julia
* Mandelbrot
* Burning_Ship
* Newton третьей степени
* Newton пятой степени

Проект был выполнен в Школе Программирования 21 (филиал французкой школы "Ecole 42").

# Сборка проекта:
Для компиляции потребуется установить и настроить framework OpenGL и AppKit. 
Для того, чтобы собрать проект, необходимо зайти в корневой каталог проекта и в терминале прописать команду **make**

# Запус проекта:
**./fractal [fractal_name]** (julia, mandelbrot, burning_ship, newton, newton_pro).

# Управление:
* **ECS** выйти из программы
* Стрелочки **вверх/вниз** перемещают изображение вверх/вниз по оси OY
* Стрелочки **влево/вправо** перемещают изображение влево/вправо по оси OX
* Прокручивание колёсика мыши **вверх/вниз** приближает/отдаляет изображение к курсору
* *Зажатая левая кнопка мыши* перетаскивает изображение
* **Работает только для Julia** *Нажатие на правую кнопку мыши* позволяет менять мышкой комплексный параметр, повторное нажатие зафиксирует его.
* *На numpad* цифры **7** и **4** увеличивает и уменьшает количество красного в фрактале
* **8** и **5** -- увеличивает и уменьшает количество зелёного в фрактале
* **9** и **6** -- увеличивает и уменьшает количество синего в фрактале

## Julia
![Scene 1](https://github.com/udraugr/fractal/raw/master/./pictures/Julia.png)

## Julia с добавлением цветов
![Julia 2](https://github.com/udraugr/fractal/raw/master/./pictures/Julia%20colors.png)

## Julia с измененным комплексным параметром
![Julia 3](https://github.com/udraugr/fractal/raw/master/./pictures/julia%20change%20C%202.png)

## Mandelbrot
![Mandelbrot 1](https://github.com/udraugr/fractal/raw/master/./pictures/mandelbrot.png)

## Mandelbrot с приближением
![Mandelbrot 2](https://github.com/udraugr/fractal/raw/master/./pictures/mandelbrot%20tiny%20zoom.png)

## Burning ship
![Burning ship 1](https://github.com/udraugr/fractal/raw/master/./pictures/burning%20ship.png)

## Burning ship с приближением
![Burning ship 2](https://github.com/udraugr/fractal/raw/master/./pictures/burning%20ship%20zoom%20small.png)

### Примечание:
Этот проект полностью написан в школе программирования 21, и принадлежит ей.

# FRACTAL - displaying a fractal
An introduction to complex numbers and fractals.
The fractals are implemented:
* Julia
* Mandelbrot
* Burning_Ship
* Newton of the third degree
* Newton of the fifth degree

The project was done at Programming School 21 (a branch of the French "Ecole 42").

# Build the project:
To compile, you will need to install and configure the OpenGL framework and AppKit.
In order to build the project, you need to go to the root directory of the project and in the terminal type the command **make**

# Run the project:
**./fractal [fractal_name]** (julia, mandelbrot, burning_ship, newton, newton_pro).

# Management:
* **ECS** exit program
* **Up/Down arrows** move the image up/down OY axis
* **Left/right arrows** move the image left/right on the OX axis
* *Scrolling the mouse wheel* **up/Down** moves the image closer/depart the cursor
* **Pressing the left mouse button** drags the image
* **Works only for Julia** *Pressing the right mouse button* allows you to change the mouse complex parameter, pressing it again will fix it.
* *On the numpad* the numbers **7** and **4** increase and decrease the amount of red in the fractal
* **8** and **5** -- increases and decreases the amount of green in the fractal
* **9** and **6** -- increases and decreases amount of blue in a fractal

## Julia
![Scene 1](https://github.com/udraugr/fractal/raw/master/./pictures/Julia.png)

## Julia with the addition of colors
![Julia 2](https://github.com/udraugr/fractal/raw/master/./pictures/Julia%20colors.png)

## Julia with a modified complex parameter
![Julia 3](https://github.com/udraugr/fractal/raw/master/./pictures/julia%20change%20C%202.png)

## Mandelbrot
![Mandelbrot 1](https://github.com/udraugr/fractal/raw/master/./pictures/mandelbrot.png)

## Mandelbrot with zoom
![Mandelbrot 2](https://github.com/udraugr/fractal/raw/master/./pictures/mandelbrot%20tiny%20zoom.png)

## Burning ship
![Burning ship 1](https://github.com/udraugr/fractal/raw/master/./pictures/burning%20ship.png)

## Burning ship with zoom
![Burning ship 2](https://github.com/udraugr/fractal/raw/master/./pictures/burning%20ship%20zoom%20small.png)

### Note:
This project is done at programming School 21, and belongs to it.
