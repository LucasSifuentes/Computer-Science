-- Guia 1 de Introduccion a los algoritmos

-- Ejemplo Guardas
numeros :: Int -> String
numeros x |x == 1 = "Uno"
          |x == 2 = "Dos"
          |otherwise = "Otro Numero"

-- Ejemplo Pattern Matching, alternativa a guardas
numerosBis :: Int -> String
numerosBis 1 = "Uno"
numerosBis 2 = "Dos"
numerosBis x = "Otro Numero"

-- Tuplas
sumaPar :: (Int,Int) -> Int
sumaPar (x,y) = x + y

sumaPares :: (Int,Int) -> (Int,Int) -> (Int,Int)
sumaPares (x1,y1) (x2,y2) = (x1+x2,y1+y2)

-- (13a)
f :: Int -> Int
f x = 5 * x

-- (13b)
duplica :: Int -> Int
duplica a = a + a

-- (13c)
por2 :: Int -> Int
por2 y = 2 * y

-- (13d)
multiplicar :: Int -> Int -> Int
multiplicar zz tt = zz * tt 

-- (14) Funcion para promediar dos variables
promedio :: Float -> Float -> Float
promedio x y = (x + y) / 2

-- (17a)
g :: Int -> Int
g y = 8 * y

-- (17b)
h :: Int -> Int -> Int
h z w = z + w

-- (17c)
j :: Int -> Bool
j x = x <= 0

-- (18a)
entre0y9 :: Int -> Bool
entre0y9 x = (0 <= x) && (x <= 9)

-- (18b)
rangoPrecio :: Int -> String
rangoPrecio x | x <= 0 = "Esto no puede ser!"
              | x < 2000 = "muy barato"
              | x > 5000 = "Demaciado caro"
              |(2000 <= x) && (x <= 5000) = "Hay que verlo bien"

-- (18c) Funcion para obtener el valor absoluto de una variable
absoluto :: Int -> Int
absoluto x |(x >= 0) = x
           |(x < 0) = -x
-- Tambien se puede usar la guarda "otherwise = x * (-1)" en el ultimo caso

-- (18d)
esMultiplo2 :: Int -> Bool
esMultiplo2 n = (mod n 2) == 0

-- (19) Funcion para saber si una variable es multiplo de otra
esMultiploDe :: Int -> Int -> Bool
esMultiploDe x y = (mod y x == 0)

-- (20) Funcion para deducir si un año es bisiesto
esBisiesto :: Int -> Bool 
esBisiesto x = ((mod x 400) == 0) || ((mod x 4) == 0) && ((mod x 100) /= 0)

-- (21) Funcion para encontrar los maximos y minimos entre tres numeros y restarlos
dispersion :: Int -> Int -> Int -> Int
dispersion x y z = (max (max x y) z) - (min (min x y) z)

-- (22) Funcion para que, al ingresar un numero como celsius lo pasemos a fahr
celsiusToFahr :: Float -> Float
celsiusToFahr x = x * 1.8 + 32

-- (23) Funcion opuesta a la del punto 22
fahrToCelsius :: Float -> Float
fahrToCelsius x = (x - 32) / 1.8

-- (24) Funcion para poder comparar un valor ingresado con 8
haceFrioF :: Float -> Bool
haceFrioF x = (fahrToCelsius x ) < 8

-- (25a) Funcion dado 3 numeros devuelve el 2do
segundo3 :: (Int,Int,Int) -> Int
segundo3 (x,y,z) = y

-- (25b)
ordena :: (Int,Int) -> (Int,Int)
ordena (x,y) = ((min x y),(max x y))

-- (25c)
rangoPrecioParametrizado :: Int -> (Int,Int) -> String
rangoPrecioParametrizado x (y,z) | x < 0 = "Me das plata por darmela"
                                 | x > (max y z) = "Demasiado caro"
                                 | x < (min y z) = "Una ganga"
                                 | otherwise = "Ta bien"

-- (25d)
mayor3 :: (Int,Int,Int) -> (Bool,Bool,Bool)
mayor3 (x,y,z) = (x > 3,y > 3,z > 3)

-- (25e)
todasIguales :: (Int,Int,Int) -> Bool
todasIguales (x,y,z) = (x == y) && (x == z)