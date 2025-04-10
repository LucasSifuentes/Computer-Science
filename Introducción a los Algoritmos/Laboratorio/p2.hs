-- Funcion XD (Un antes y un despues en el uso de (x:xs))
equisd :: [Int] -> Int
equisd (x:xd)= x

-- (3a) Funcion Recursiva Filter para guardar pares
soloPares :: [Int] -> [Int]
soloPares [] = []
soloPares (x:xs) | (mod x 2 == 0) = x : soloPares xs
                 | otherwise = soloPares xs

-- (3b) Funcion Recursiva Filter para guardar mayores que 10
mayorQue10 :: [Int] -> [Int]
mayorQue10 [] = []
mayorQue10 (x:xs) | (x > 10) = x : mayorQue10 xs
                  | otherwise = mayorQue10 xs

-- (3c) Funcion Recursiva Filter para guardar Numeros mayores que un numero n
mayoresQue :: Int -> [Int] -> [Int]
mayoresQue y [] = []
mayoresQue y (x:xs) | (x > y) = x : mayoresQue y xs
                    | otherwise = mayoresQue y xs

-- (4a) Funcion Recursiva Map para sumar 1
sumar1 :: [Int] -> [Int]
sumar1 [] = []
sumar1 (x:xs) = (x + 1) : sumar1 xs

-- (4b)  Funcion Recursiva Map para multiplicar por 2
duplicar :: [Int] -> [Int]
duplicar [] = []
duplicar (x:xs) = (x * 2) : duplicar xs

-- (4c)  Funcion Recursiva Map para multiplicar por n
multiplicar :: Int -> [Int] -> [Int]
multiplicar y [] = []
multiplicar y (x:xs) = (x * y) : multiplicar y xs

-- (5a) Funcion Recursiva Fold para saber si toda una lista es menor a 10
todosMenores10 :: [Int] -> Bool
todosMenores10 [] = True
todosMenores10 (x:xs) = (x < 10) == todosMenores10 xs

-- (5b) Funcion Recursiva Fold para saber si hay 0 en la lista
hay0 :: [Int] -> Bool
hay0 [] = False
hay0 (x:xs) = (x == 0) || hay0 xs

-- (5c) Funcion Recursiva Fold de sumatoria
sumatoria :: [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs

-- (6) Funcion Recursiva Zip
repartir :: [String] -> [String] -> [(String,String)]
repartir [] ys = []
repartir (x:xs) [] = (x," No hay cartas en el mazo rey") : repartir xs []
repartir (x:xs) (y:ys) = (x,y) : repartir xs ys

-- (7) Funcion Recursiva UnZip
apellidos :: [(String, String, Int)] -> [String]
apellidos [] = []
apellidos ((x,y,z):xs) = y : apellidos xs

-- (8) Funcion Length definida recursivamente
lengthRecursiva :: [a] -> Int
lengthRecursiva [] = 0
lengthRecursiva (x:xs) = 1 + length xs

-- (8) Funcion !! definida recursivamente
exclamacionRecursiva :: [a] -> Int -> a
exclamacionRecursiva (x:xs) 0 = x
exclamacionRecursiva (x:xs) y = exclamacionRecursiva xs (y - 1)

-- (8) Funcion take definida recursivamente
takeRecursiva :: Int -> [Int] -> [Int]
takeRecursiva 0 xs = []
takeRecursiva y (x:xs) = x : takeRecursiva (y - 1) xs

-- (8) Funcion drop definida recursivamente
dropRecursiva :: Int -> [Int] -> [Int]
dropRecursiva 0 xs = xs
dropRecursiva y (x:xs) = dropRecursiva (y - 1) xs

-- (8) Funcion ++ definida recursivamente
sumsumRecursiva :: [a] -> [a] -> [a]
sumsumRecursiva [] ys = ys
sumsumRecursiva (x:xs) ys = x : sumsumRecursiva xs ys

-- (9a) Funcion Filter maximo de una lista
maximo :: [Int] -> Int
maximo [x] = x
maximo (x:xs) = max x (maximo xs)

-- (9b) Funcion Fold
sumaDePares :: [(Int,Int)] -> Int
sumaDePares [] = 0
sumaDePares ((x,y):xs) = (x + y) + sumaDePares xs

-- (9c) Funcion Filter?
todo0y1 :: [Int] -> Bool
todo0y1 [] = False
todo0y1 [x] = x == 1 || x == 0
todo0y1 (x:xs) |(x /= 0 && x /= 1) = False
               |otherwise = todo0y1 xs
 
-- (9d) Funcion Filter
quitar0 :: [Int] -> [Int]
quitar0 [] = []
quitar0 (x:xs)|(x /= 0) = x : quitar0 xs
              |otherwise = quitar0 xs

-- (9e) Funcion Fold
ultimoush :: [a] -> a
ultimoush [x] = x
ultimoush (x:xs) = ultimoush xs

-- (9f) Funcion 
repetir :: Int -> Int -> [Int]
repetir 0 n = []
repetir k n = n : repetir (k - 1) n

-- (9g) Funcion Fold
conca :: [[a]] -> [a]
conca [] = []
conca ([]:xs) = conca xs
conca ((y:ys):xs) = y : conca (ys:xs)

-- (9h) Funcion
rev :: [a] -> [a]
rev [] = []
rev (x:xs) = (rev xs) ++ [x]