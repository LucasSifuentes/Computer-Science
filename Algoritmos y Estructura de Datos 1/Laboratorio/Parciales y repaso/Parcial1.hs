--Ejercicio 2a 
type Titulo = String
type Precio = Int

data Categoria = Literatura | Infantiles | Autoayuda | Comics
data Editorial = Altea | Minotauro | Panini

type AnioAgenda = Int
data Marca = Monoblock | Paprika

data ArticulosLibreria = Libro Categoria Editorial Titulo Precio |Agenda  Marca AnioAgenda Precio | Cuaderno Marca Precio 

-- Ejercicio 2b 

enPrecio::Precio ->ArticulosLibreria ->Bool
enPrecio p (Libro c e t precio) = precio<=p
enPrecio p (Agenda m a precio) = precio<=p
enPrecio p (Cuaderno m precio) = precio<=p




libros_baratos :: [ArticulosLibreria]-> Precio ->[ArticulosLibreria] 
libros_baratos  [] p = []
libros_baratos (Libro c e t precio: xs ) p | (precio>=p) = Libro c e t precio : libros_baratos xs p
                                         | otherwise = libros_baratos xs p
libros_baratos (Agenda m a precio: xs) p | (precio>=p) = Agenda m a precio : libros_baratos xs p
                                         | otherwise = libros_baratos xs p
libros_baratos (Cuaderno m precio: xs) p | (precio>=p) = Cuaderno m precio : libros_baratos xs p
                                         | otherwise = libros_baratos xs p
--libros_baratos (x:xs) p = libros_baratos p xs 


libros_baratos' xs p = filter (enPrecio p) xs

--Ejercicio 2c

mismaEditorial Altea Altea =True
mismaEditorial Minotauro Minotauro  =True
mismaEditorial Panini Panini=True
mismaEditorial _  _ = False

esLibro :: ArticulosLibreria -> Bool
esLibro (Libro c e t precio) = True
esLibro _ = False

darPrecio :: ArticulosLibreria ->Precio
darPrecio (Libro c e t precio) = precio

darEditorial :: ArticulosLibreria -> Editorial
darEditorial (Libro c e t precio) = e
darEditorial _ = Altea

instance (Eq)
  where l1 == l2 = esLibro l1 && esLibro l2 && darPrecio l1 == darPrecio l2 &&  darEditorial l1 == darEditorial l2
--        (Libro c e t precio) == (Libro c1 e1 t1 precio1) = precio==precio1 && mismaEditorial e e1

