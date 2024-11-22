# project_one
Programa skirta apskaičiuoti galutinį mokinių balą. Programa gali generuoti duomenis, skaityti juos iš failo ir konsolės. Galutinio balo skaičiavimo formulė:
![image](https://github.com/user-attachments/assets/7c2b5979-483c-499d-adc3-0599598e6608)

Programas instaliavimas su cmake

Programos instaliavimui reikia atsiust archiva ir paleist run.bat

Laiko matavimo tyrimo rezultatai:
Kompiuterio charakteristikos:
CPU: Intel Core i5 12500H
GPU: NVIDIA GeForce RTX 4050 Laptop
RAM: 16 GB DDR 5 (Speed 4800 MT/s)
SSD


| std::vector  | std::list |
| ------------- | ------------- |
| ![image](https://github.com/user-attachments/assets/d1ef8409-f51e-43e2-bc81-61763ccded53)| ![image](https://github.com/user-attachments/assets/898bbdae-1735-4b7a-b8a3-2e6c4a3183ff)|
| ![image](https://github.com/user-attachments/assets/3e0a7066-f476-49c2-a53c-e153803c8f71) | ![image](https://github.com/user-attachments/assets/492635b1-797c-446a-8e17-ee9117039ec5)|
|![image](https://github.com/user-attachments/assets/2e80dc3c-e519-425d-9c3b-5371db9717f2)| ![image](https://github.com/user-attachments/assets/238d6685-a798-4546-85c6-b32a857fe70c)|
|![image](https://github.com/user-attachments/assets/2741f725-9522-4e8e-9451-4f84cb665ac0)| ![image](https://github.com/user-attachments/assets/6b75bd4c-0ff6-40d1-8f78-2778ffec1d2a)|
|![image](https://github.com/user-attachments/assets/487ce2a0-58f2-4a27-b349-420bba445f2a)|![image](https://github.com/user-attachments/assets/14b95b45-8f8f-4bc0-9704-adeface9f415)|

![image](https://github.com/user-attachments/assets/5d28887b-ed28-4aac-ad2f-880d71fce377)


3 strategijai buvo panauduota patobulinta 2 strategija su std::stable_partition


| |1 strategija | 2 strategija | 3 strategija |
|-------------|-------------|-------------|-------------|
|std::vector|![image](https://github.com/user-attachments/assets/c7b4aa16-c65e-4acc-8edc-e239648ea815)|![image](https://github.com/user-attachments/assets/cecdc6f6-7db4-41dc-8a61-953ca6077dfb) | ![image](https://github.com/user-attachments/assets/4e6ebe44-45cb-45b0-ba9c-671beab0f6c8)|
|std::list|![image](https://github.com/user-attachments/assets/1c494bc2-1a4b-42d5-935f-b84d00141160)|![image](https://github.com/user-attachments/assets/2a566e41-5264-4485-b605-a5ca794659f8)|![image](https://github.com/user-attachments/assets/1b04d152-b936-44f0-a813-387894da3cc6)|


Class ir Struct palyginimas

| | struct | class |
|-------------|-------------|-------------|
|10^6 studentu|![image](https://github.com/user-attachments/assets/5c7706ac-6a96-4347-85e9-39babc893127)|![image](https://github.com/user-attachments/assets/43403d52-bf5a-444d-b984-6589e5cfa287)|
|10^7 studentu|![image](https://github.com/user-attachments/assets/58989701-b5a7-468a-8260-642c2d91144e)|![image](https://github.com/user-attachments/assets/542db4f3-9a71-4554-ad88-e93c3bdc5a90)|

Greicio palyginimas su flagais o1,o2,o3

| | o1 | o2 | o3 |
|-------------|-------------|-------------|-------------|
|struct|![image](https://github.com/user-attachments/assets/8fd389e8-8a7c-4763-8b06-729945d2ac62)| ![image](https://github.com/user-attachments/assets/cb9c9e77-bead-46f4-9d56-59e08d5b0e3f)| ![image](https://github.com/user-attachments/assets/d05262c6-7c2a-4c22-89ec-d747d5aefe6e)|
|class| | | |


Failo dydzio palyginimas su flagais o1,o2,3
| | o1 | o2 | o3 |
|-------------|-------------|-------------|-------------|
|struct|98 KB |98 KB |98 KB |
|class|![image](https://github.com/user-attachments/assets/82a75129-744e-4670-8bfd-094fc00f8ee1)| ![image](https://github.com/user-attachments/assets/50d91e44-0276-4105-aff2-814c3c751c91)|![image](https://github.com/user-attachments/assets/cc56d64c-a5f3-4601-b011-5a288b54f65a)|





 






