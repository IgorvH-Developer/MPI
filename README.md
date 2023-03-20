# MPI

Необходимо вычислить значения функции Бесселя первого рода J1(x) на сегменте [a,b] с шагом δ (номер 1).

Функции Бесселя первого рода J1(x) имеет вид, где n = 1:

![image](https://user-images.githubusercontent.com/58008126/225900183-d3eea74b-184d-46b6-891a-e425ea4c099e.png)

### Ниже представлены результаты вычислений значений функции на диапозоне с разными шагами:

1) на сегменте [0, 10] с шагом δ = 0.4:

![image](https://user-images.githubusercontent.com/58008126/225904355-56673343-93a6-48b6-95b9-7234055cce2e.png)
![image](https://user-images.githubusercontent.com/58008126/225904434-89d9a042-6e85-484f-9844-99590c7c28af.png)

2)  на сегменте [0, 10] с шагом δ = 0.3:

![image](https://user-images.githubusercontent.com/58008126/225904549-62969c86-a976-46ee-a143-dd6810830a08.png)
![image](https://user-images.githubusercontent.com/58008126/225904606-5069d2e0-4813-4129-9f22-9449a840603f.png)

### Рассмотрим сегмент [0, 10] с шагом δ = 0.3. Посмотрим на время выполнения программы с разным количеством процессов:

1) 8 процессов:

![image](https://user-images.githubusercontent.com/58008126/226442245-bed3fbae-7d68-4aea-b713-9373a53e08dc.png)

2) 4 процесса

![image](https://user-images.githubusercontent.com/58008126/226435846-17804048-1d07-4824-a24b-f08664779152.png)

3) 2 процесса

![image](https://user-images.githubusercontent.com/58008126/226434803-d35141ec-1f50-4cf5-8ce7-be24ee9ef4d6.png)

