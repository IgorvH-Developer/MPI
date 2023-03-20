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

![image](https://user-images.githubusercontent.com/58008126/226431449-64066786-8cac-4126-975c-4e0fc72df828.png)
![image](https://user-images.githubusercontent.com/58008126/226431513-23007ea1-3829-4ec2-9a20-238aa06161cb.png)

2) 4 процесса

![image](https://user-images.githubusercontent.com/58008126/226432398-8c05697f-b327-400a-aef8-b8f52f8e517d.png)
![image](https://user-images.githubusercontent.com/58008126/226432458-7df5b05d-7d24-4a75-b071-7d05e6b942e8.png)

3) 2 процесса

![image](https://user-images.githubusercontent.com/58008126/226432618-8db4fd95-a4f7-4b89-b501-f80a8c6cf643.png)
![image](https://user-images.githubusercontent.com/58008126/226434440-ca018d3c-dd04-43ce-bd66-703cf1c28394.png)

