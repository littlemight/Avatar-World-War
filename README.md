# Avatar World War
## Struktur File
Untuk update tree foldernya, bisa execute command ini di root
```
tree /f /a
```
kalo mau di copas ke clipboard
```
tree /f /a | clip
```

### Tree
```
+---bin
|       .gitignore
|       avatar-world-war.exe
|       
+---compile
|       main
|       main.bat
|       
+---run
|       main
|       main.bat
|       
\---src
    |   main.c
    |   
    \---adt
        +---boolean
        |       boolean.h
        |       
        +---building
        +---player
        \---queue

```
## Compile

### Windows
```
.\compile\main
../co\run\main
```
### Linux (or Bash)
```
./compile/main
./run/main
```

## Compile and Run

### Windows
```
comprun <nama driver adt/main>
```
contoh
```
comprun main
```
### Linux
```
./comprun <nama driver adt/main>
```
contoh
```
./comprun main
```