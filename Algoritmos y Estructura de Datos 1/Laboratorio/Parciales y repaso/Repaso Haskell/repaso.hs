type Nombre = String
type Autor = String
type Pagina = Int
type Precio = Int

data Tema = Politica | Filosofia | Ciencia | Historia 

data Genero = DRAMA | ROMABCE | MISTERIO | AVENTURA deriving (Show)

data Estilo = CLASICO | CONT | CIENCIA | EXPERIMENTAL deriving (Show)

data AREA = MATEMATICA | FISICA | ASTRO | COMPU deriving (Show)

data Libro = Novela Nombre Genero Autor Pagina Precio | Ensayo Nombre Tema Autor Pagina Precio | Poesia Nombre Estilo Autor Pagina Precio | Cientifico Nombre Estilo AREA Ayt                                                                                                                                                                                                        
