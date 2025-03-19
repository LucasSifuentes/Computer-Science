-- Ejercicio 1a
esCero :: Int -> Bool
esCero x = x==0
{-ejemplos
ghci> esCero 2
False
ghci> esCero 0
True
ghci> esCero (-3)
False
-}


-- Ejercicio 1b
esPositivo :: Int -> Bool 
esPositivo x = x>0
{-ejemplos
ghci> esPositivo 4
True
ghci> esPositivo 0
False
ghci> esPositivo (-1)
False
-}


-- Ejercicio 1c
esVocal :: Char -> Bool
esVocal a = a=='a' || a=='e' || a=='i' || a=='o' || a=='u' 
{-ejemplos
ghci> esVocal 'a'
True
ghci> esVocal 'b'
False
-}


-- Ejercicio 1d
valorAbsoluto :: Int -> Int
valorAbsoluto x |x>=0 = x
                |x<0 = -x
{-ejemplos
ghci> valorAbsoluto 9
9
ghci> valorAbsoluto (-3)
3
ghci> valorAbsoluto 0
0
-}

-- Ejercicio 2a
paraTodo :: [Bool] -> Bool
paraTodo [] = True
paraTodo (x:xs) = (x == True) && paraTodo xs
{-ejemplos
ghci> paraTodo []
True
ghci> paraTodo [True, False]
False
ghci> paraTodo [True, True]
True
-}


-- Ejercicio 2b
sumatoria ::  [Int] -> Int
sumatoria [] = 0
sumatoria (x:xs) = x + sumatoria xs
{-ejemplos
ghci> sumatoria []
0
ghci> sumatoria [1,2,3,4]
10
ghci> sumatoria [1,2,3,(-50)]
-44
-}


-- Ejercicio 2c
productoria::  [Int] -> Int
productoria [] = 1
productoria (x:xs) = x * productoria xs
{-ejemplos
ghci> productoria []
1
ghci> productoria [1,2,3,4,5]
120
ghci> productoria [1,2,3,4,(-22)]
-528
-}


-- Ejercicio 2d
factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)
{-ejemplos
ghci> factorial 0
1
ghci> factorial 5
120
-}


-- Ejercicio 2e
promedio :: [Int] -> Int
promedio [] = 0
promedio (y:ys) = div (sumatoria (y:ys)) (length (y:ys))
{-ejemplos
ghci> promedio []
0
ghci> promedio [2,5,3,7,(-2)]
3
-}

-- Ejercicio 3
pertenece :: Int -> [Int] -> Bool
pertenece n [] = False
pertenece n (x:xs) = x == n || pertenece n xs 
{-ejemplos
ghci> pertenece 4 [1,2,3,4]
True
ghci> pertenece 4 []
False
ghci> pertenece 4 [43,6,1]
False
-}


-- Ejercicio 4a
paraTodo' :: [a] -> (a -> Bool) -> Bool
paraTodo' [] n = True 
paraTodo' (x:xs) n = n (x) && paraTodo' xs n
{-ejemplos
ghci> paraTodo' [] esCero
True
ghci> paraTodo' [0,0,1] esCero
False
ghci> paraTodo' "hola" esVocal
False
-}


-- Ejercicio 4b
existe' :: [a] -> (a -> Bool) -> Bool
existe' [] f = False
existe' (x:xs) f = f x || existe' xs f
{-ejemplos
ghci> existe' [] esCero
False
ghci> existe' [1,2,3,4,0] esCero
True
ghci> existe' [1,2,3] esCero
False
ghci> existe' [0,0,0,0,0] esCero
True
-}


-- Ejercicio 4c
sumatoria' :: [a] -> (a -> Int) -> Int
sumatoria' [] f = 0
sumatoria' (x:xs) f = f x + sumatoria' xs f
{-ejemplos
ghci> sumatoria' [] valorAbsoluto
0
ghci> sumatoria' [1,2,3,(-4),5] valorAbsoluto
15
-}


-- Ejercicio 4d
productoria' :: [a] -> (a -> Int) -> Int
productoria' [] f = 1
productoria' (x:xs) f = f x * productoria' xs f
{-ejemplos
ghci> productoria' [] valorAbsoluto
1
ghci> productoria' [1,2,3] valorAbsoluto
6
ghci> productoria' [(-2),3,1,(-5)] valorAbsoluto
30
-}


-- Ejercicio 5
paraTodo'' :: [a] -> (a -> Bool) -> Bool
paraTodo'' xs f = paraTodo' xs f
{-ejemplos
ghci> paraTodo'' [1,2,3] esCero
False
ghci> paraTodo'' [0,0,0,0] esCero
True
-}


-- Ejercicio 6a
todosPares :: [Int] -> Bool
todosPares xs = paraTodo' xs even
{-ejemplos
ghci> todosPares [1,2,3,4]
False
ghci> todosPares [6,8,2,4]
True
-}


-- Ejercicio 6b
multiplo :: Int -> Int -> Bool
multiplo x y = mod y x == 0

hayMultiplo :: Int -> [Int] -> Bool
hayMultiplo y xs = existe' xs (multiplo y)
{-ejemplos
ghci> hayMultiplo 3 [1,2,3,4,5,6]
True
ghci> hayMultiplo 3 [1,2,4,5]
False
-}


-- Ejercicio 6c
sumaCuadrados :: Int -> Int
sumaCuadrados x = sumatoria' [0..x] (^2)
{-ejemplos
ghci> sumaCuadrados 5
55
ghci> sumaCuadrados 10
385
-}


-- Ejercicio 6d
multiplo' :: Int -> Int -> Bool
multiplo' x y = mod x y == 0

existeDivisor :: Int -> [Int] -> Bool
existeDivisor y (x:xs) = existe' xs (multiplo' y)
{-ejemplos
ghci> existeDivisor 2 [3,5,7]
False
ghci> existeDivisor 2 [3,5,7,8]
False
ghci> existeDivisor 2 [3,5,7,1]
True
ghci> existeDivisor 2 [3,5,7,2]
True
-}


-- Ejercicio 6e
esPrimo :: Int -> Bool
esPrimo x |x==1 = False
          |x>1 = not (existeDivisor x [1..(x-1)])

{-Esta es la funcion original pero no funciona con 1, entonces hice (teniendo en cuenta que no respeta la consigna de no usar análisis por casos) otra version agregando el caso donde x == 1 para que no de error en la misma ni en las siguientes funciones
esPrimo :: Int -> Bool
esPrimo x = not (existeDivisor x [1..(x-1)])
-}

{-ejemplos
ghci> esPrimo 11
True
ghci> esPrimo 12
False
ghci> esPrimo 13
True
-}


-- Ejercicio 6f
factorial' :: Int -> Int
factorial' x = productoria [2..x]
{-ejemplos
ghci> factorial' 5
120
ghci> factorial' 6
720
-}

-- Ejercicio 6g
{-sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) |x == 1 = sonPrimos xs
                 |esPrimo x = x : sonPrimos xs
                 |otherwise = sonPrimos xs
ESTA FUNCION ESTÁ COMENTADA PORQUE MÁS ADELANTE SE REPITE
-}

multiplicaPrimos :: [Int] -> Int
multiplicaPrimos (x:xs) = productoria' (sonPrimos xs) id
{-ejemplos
ghci> sonPrimos [1,2,3,4,5,6]
[2,3,5]
ghci> multiplicaPrimos [1..7]
210
ghci> multiplicaPrimos [1,2,3,4,5,6]
30
-}

-- Ejercicio 6h
fib :: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x-1) + fib (x-2)

listaFib :: Int -> [Int]
listaFib 0 = []
listaFib 1 = [1]
listaFib x = (fib x) : listaFib (x-1)
-- Crea la lista desde los numeros grandes hasta los mas chicos,
-- Y eso hace que tarde mucho la funcion esFib

esFib :: Int -> Bool
esFib n = existe' (listaFib n) (==n)
--esFib n = pertenece n (map fib [1..n])
{-ejemplos
ghci> esFib 1
True
ghci> esFib 5
True
ghci> esFib 7
False
ghci> esFib 21
True
ghci> esFib 34
True
-}

-- Ejercicio 6i
todosFib :: [Int] -> Bool
todosFib xs = paraTodo' xs esFib
{-ejemplos
ghci> todosFib[1,2,3,4,5]
False
ghci> todosFib[1,2,3,5]
True
-}

{-Ejercicio 7
a) La función map aplica una funcion f ingresada a una lista xs ingresada,
 devolviendonos otra lista ys con la funcion f aplicada a los elementos de xs.
 Y la funcion filter, que dada una lista xs,
 devuelve una lista ys cuyos elementos satisfacen la funcion f ingresada.

b) Aplica la funcion f "succ" que suma 1 a cada elemento de la lista xs. 
 ej:
 *Main> map succ [1,(-4),6,2,(-8)]
 [2,-3,7,3,-7]
 
c) Aplica la funcion f "esPositivo" a la lista xs y devuelve solo los elementos
 positivos de xs.
 ej:
 *Main> filter esPositivo [1,(-4),6,2,(-8)]
 [1,6,2]
-}


-- Ejercicio 8a
duplicaRecursiva :: [Int]->[Int]
duplicaRecursiva [] = []
duplicaRecursiva (x:xs) = x*2 : duplicaRecursiva xs
{-ejemplos
ghci> duplicaRecursiva [1,2,3,4]
[2,4,6,8]
ghci> duplicaRecursiva []
[]
-}


-- Ejercicio 8b
duplicaMap :: [Int]->[Int]
duplicaMap xs = map (*2) xs
{-ejemplos
ghci> duplicaMap [1,2,3,4]
[2,4,6,8]
ghci> duplicaMap []
[]
-}


-- Ejercicio 9a
sonPrimos :: [Int] -> [Int]
sonPrimos [] = []
sonPrimos (x:xs) |x == 1 = sonPrimos xs
                 |esPrimo x = x : sonPrimos xs
                 |otherwise = sonPrimos xs
{-ejemplos
ghci> sonPrimos [1,2,3,4,5]
[2,3,5]
ghci> sonPrimos []
[]
-}

-- Ejercicio 9b
sonPrimosFilter:: [Int] -> [Int]
sonPrimosFilter xs = filter (esPrimo) xs
{-ejemplos
ghci> sonPrimosFilter [1,2,3,4,5,6]
[2,3,5]
ghci> sonPrimosFilter []
[]
-}


-- Ejercicio 9c
{-Se puede mejorar justamente usando composición
  de funciones que fue lo que hicimos originalmente, 
  definiendo la funcion sonPrimos y 
  llamandola dentro de multiplicaPrimos 
-}

-- Ejercicio 10a
primIgualesA::Eq a => a->[a]->[a]
primIgualesA p [] = []
primIgualesA p (x:xs) |p==x = x : primIgualesA p xs
                      |otherwise = []
{-ejemplos
ghci> primIgualesA 5 [1,2,3,4,5]
[]
ghci> primIgualesA 5 [5,5,5,2,3,4,5]
[5,5,5]
ghci> primIgualesA 2 [2,2,2,45,2,2,2,2]
[2,2,2]
ghci> primIgualesA 's' "sssssagsa"
"sssss"
-}                      


-- Ejercicio 10b
primIgualesA'::Eq a => a->[a]->[a]
primIgualesA' p [] = []
primIgualesA' p (x:xs) = takeWhile (==p)  (x:xs)
{-ejemplos
ghci> primIgualesA' 2 [2,2,2,45,2,2,2,2]
[2,2,2]
ghci> primIgualesA' 5 [1,2,3,4,5]
[]
ghci> primIgualesA' 10 [10,9,8,7,6,5]
[10]
ghci> primIgualesA' 'h' "hhhhasedfasdf"
"hhhh"
-}


-- Ejercicio 11a
primIguales::Eq a =>[a]->[a]
primIguales [] = []
primIguales (x:xs) |x == ((x:xs)!!1) = x : primIguales xs
                     |otherwise = x : []
{-ejemplos
ghci> primIguales [3,3,3,4,1]
[3,3,3]
ghci> primIguales []
[]
ghci> primIguales "qqqqqlaksdkoapsd"
"qqqqq"
-}


-- Ejercicio 11b
primIguales'::Eq a =>[a]->[a]
primIguales' [] = []
primIguales' (x:xs) = primIgualesA (head(x:xs)) (x:xs)
{-ejemplos
ghci> primIguales' "qqqqqlaksdkoapsd"
"qqqqq"
ghci> primIguales' [1,2,3,4,5]
[1]
ghci> primIguales' [9,9,9,9,9,0,1]
[9,9,9,9,9]
-}